#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL) //se verifica si hay algo en la raiz
    return 0; // sino hay nada ponemos cero

    int suma_total = raiz->num; // creamos una variable para que guarde el valor de la raiz
    suma_total += suma(raiz->hijo_der) + suma(raiz->hijo_izq); // sumando raiz hijo_izq y hijo_der usando recursividad

    return suma_total; // ver el total de la suma
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int contador =0; // declaro la variable que contora todos los nodos

    if(raiz==NULL) // revisa si hay algun valor en la raiz
    return 0;  // sino hay le ponemos cero

    contador++; // se va a ir sumando por 1 al contador
    contador += cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq); // usando recursividad se suma nodo dderecho y e izquierdo

    return contador; // vemos la cantidad de nodos
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz)/cantidadNodos(raiz); // usamos las funiones suma y cantidad de nodos que ya teniamos y asi sacamos el promedio
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int contador =1; // se declara esta variable para que cuente los pasos
    if(raiz==NULL) // se revisa si hay raiz
    return contador; // sino no hay le ponemos cero

    if(raiz->num == num) // si el valor de la raiz es igual al num que retorne el contador
        return contador; // retorna 1


    if(num>raiz->num) // vemos el numero mayor de la raiz
        contador += cuantosPasos(raiz->hijo_der,num); // se buscar el hijo derecho que son los numeros mayores

    if(num<raiz->num) // vemos el numero menor de la raiz
        contador += cuantosPasos(raiz->hijo_izq,num); // se busca el hijo izquierdo que son los numeros menores

    return contador; // que me de los pasos
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
bool esAVL(NodoArbolBinario* raiz)
{
    if(raiz==NULL) // vemos si el arbol esta vacio
    return true; // le damos true pensando si esta ordenado

        if(raiz->hijo_izq !=NULL && raiz->hijo_izq->num>raiz->num or raiz->hijo_der!=NULL && raiz->hijo_der->num<raiz->num) // viendo si existe hijo derecho o izquierdo y negando el orden AVL por ambos lados
            return false; // si nos da incorrecto entonces el arbol no esta ordenado

        return esAVL(raiz->hijo_izq) && esAVL(raiz->hijo_der); // recorremos mediante recursividad

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
