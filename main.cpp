#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream miarchivo(nombre_archivo.c_str(),ios::out);
    miarchivo<<num<<endl;
    miarchivo.close();
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream miarchivo(nombre_archivo.c_str(),ios::in);
    int numero;
    miarchivo>>numero;
    return numero;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream miarchivo(nombre_archivo.c_str(),ios::out);
    miarchivo<<str<<endl;
    miarchivo.close();
}
string leerStringTexto(string nombre_archivo)
{
    ifstream miarchivo(nombre_archivo.c_str(),ios::in);
    string leido;
    miarchivo>>leido;
    return leido;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream miarchivo(nombre_archivo.c_str(),ios::out);
    miarchivo.write((char*)&num,4);
    miarchivo.close();
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream miarchivo(nombre_archivo.c_str(),ios::in);
    int numero;
    miarchivo.read((char*)&numero,4);
    miarchivo.close();
    return numero;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream miarchivo(nombre_archivo.c_str(),ios::out);
    miarchivo.write(str.c_str(),10);
    miarchivo.close();
}
string leerStringBinario(string nombre_archivo)
{
    ifstream miarchivo(nombre_archivo.c_str());
    char* leido;
    leido = new char[10];
    miarchivo.read(leido,10);
    miarchivo.close();
    return leido;
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream miarchivo;
    miarchivo.open(nombre_archivo.c_str());
    char* palabra;
    palabra = new char[10];
    miarchivo.read(palabra,10);
    if(palabra==str)
        return true;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream miarchivo;
    miarchivo.open(nombre.c_str());
    int numero;
    miarchivo.seekg(0,ios::end);
    int tamano = miarchivo.tellg()/4;
    miarchivo.seekg(0,ios::beg);
    int mayor = 0;
    for(int i=0;i<tamano;i++)
    {
        miarchivo.read((char*)&numero,4);
        if(numero > mayor)
            mayor = numero;
    }
    return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
