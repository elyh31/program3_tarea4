#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
//me ayude de esta pagina http://c.conclase.net/curso/?cap=039

//abre el archivo para ingresar un dato
    ofstream arc(nombre_archivo.c_str(),ios::in);
//ingrese el numero al archivo
    arc<<num<<endl;
//cierre el archivo
    arc.close();
}
int leerNumeroTexto(string nombre_archivo)
{
//se crea un variable para asignar el valor guardado en el archivo
    int num_salida;
//se abre archivo para leer los datos
    ifstream arc(nombre_archivo.c_str(),ios::out);
//se devuelve lo almasenado en el archivo a la variable creada
    arc>>num_salida;
//devuelve el valor almacenado en la variable
    return num_salida;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
//abre el archivo para ingresar los datos
    ofstream arc(nombre_archivo.c_str(),ios::in);
//ingresa al archivo los datos almacenado en la variable str
    arc<<str<<endl;
//cierra el archivo
    arc.close();
}
string leerStringTexto(string nombre_archivo)
{
//crea una variable para regresar lo guardado en el archivo
    string str_salida;
//abre el archivo para leer lo almacenado
    ifstream arc(nombre_archivo.c_str(),ios::out);
//regresa lo almacenado en el archivo a la variable creada
    arc>>str_salida;
//regresa lo almacenado en la variable
    return str_salida;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
//abre el archivo para ingresar un dato
    ofstream arc(nombre_archivo.c_str(),ios::in);
//ingrese el numero al archivo
    arc.write((char*)&num,4);
//cierre el archivo
    arc.close();
}
int leerNumeroBinario(string nombre_archivo)
{
//se crea un variable para asignar el valor guardado en el archivo
    int num_salida;
//se abre archivo para leer los datos
    ifstream arc(nombre_archivo.c_str(),ios::out);
//se devuelve lo almasenado en el archivo a la variable creada
    arc.read((char*)&num_salida,4);
//devuelve el valor almacenado en la variable
    return num_salida;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
//abre el archivo para ingresar los datos
    ofstream arc(nombre_archivo.c_str(),ios::in);
//ingresa al archivo los datos almacenado en la variable str
    arc.write(str.c_str(),10);
//cierra el archivo
    arc.close();
}
string leerStringBinario(string nombre_archivo)
{
//crea una variable para regresar lo guardado en el archivo
    char* str_salida;
    str_salida=new char[10];
//abre el archivo para leer lo almacenado
    ifstream arc(nombre_archivo.c_str(),ios::out);
//regresa lo almacenado en el archivo a la variable creada
    arc>>str_salida;
//regresa lo almacenado en la variable
    return str_salida;
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
//crea un variable tipo strieng para almacenar el archivo
    string str_salida;
//se carga el archivo en tipolectura
    ifstream arc(nombre_archivo.c_str(),ios::out);
//se crea un ciclo pra recorrer el archivo
    for(int i=0; i<0; i++)
    {
//al entrar al ciclo le asigna el string de la posicion actual a la variable
//al asignar una palabra el apuntador del archivo se detiene y esta lista para leer la siguiente palabra
    arc>>str_salida;
//comprara los dos string si son iguales devuelve true
    if (str_salida == str)
    return true;
//al llegar al final del archivo devolvera false porque ya no habra string para comparar
    else
    return false;
    }
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
//declaramos las variables a usar
    int num_leido;
    int mayor = 0;
    int tamano;
//abrimos el archivo en modo de lectura
    ifstream arc(nombre.c_str(),ios::out);
//nos movemos al final del archivo para guardar su tamaño
//y volvemos al principio pra recorrerlo
    arc.seekg(0,ios::end);
    tamano=arc.tellg();
    arc.seekg(0,ios::beg);
    for(int i=0; i<tamano; i++)
    {
//mientras recoremos el archivo vomos asignando el valor optenido ala variable
    arc.read((char*)&num_leido,4);
    if(mayor<num_leido)
//sy el numero leido es mayor al numero almasenado este pasa a ser el numero mayor
        mayor=num_leido;
    }
//regresamos el numero mayor
    return mayor;
}
int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
