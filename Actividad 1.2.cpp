//
//  Actividad 1.2
//  TC1031
//
//  Autor: Diego Rosas
//  Matrícula: A01634154
//  Fecha de modificación: 8/30/21.
//
//  Programa que ordena un vector con números enteros por los métodos de inserción, burbuja y merge; además, realiza una búsqueda binaria y una búsqueda secuencial de cierto número entero dentro del vector.

#include <stdio.h>
#include<iostream>
using namespace std;
#include <vector>


//Función que ordena de menor a mayor por el método de inserción. Complejidad: O(n^2).
void ordenaIntercambio(vector<int> &vect){
    int temp = 0;
    for(int i = 0; i < vect.size(); i++){
        int j = i;
        while(j-1 >= 0 && vect[j] < vect[j-1]){
            temp = vect[j-1];
            vect[j-1] = vect[j];
            vect[j] = temp;
            j-=1;
        }
    }
}

//Función que ordena de menor a mayor por el método de burbuja. Complejidad: O(n^2).
void ordenaBurbuja(vector<int> &vect){
    int temp = 0;
    for(int i = 0; i < vect.size()-1; i++){
        for(int j = 0; j < vect.size()-i-1; j++){
            if (vect[j] > vect[j+1]){
                temp = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = temp;
            }
        }
    }
}

//Función auxiliar para el ordenamiento por merge.
void merge(vector<int> &vect, int izq, int mit, int der){
    int totalIzq = mit - izq + 1;
    int totalDer = der - mit;
    vector<int> izquierda;
    vector<int> derecha;
    for(int i = 0; i < totalIzq; i++){
        izquierda.push_back(vect[izq + i]);
    }
    for(int j = 0; j < totalDer; j++){
        derecha.push_back(vect[mit + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < totalIzq && b < totalDer){
        if(izquierda[a] <= derecha[b]){
            vect[c] = izquierda[a];
            a++;
        }else{
            vect[c] = derecha[b];
            b++;
        }
        c++;
    }
    while(b < totalDer){
        vect[c] = derecha[b];
        b++;
        c++;
    }
    while(a < totalIzq){
        vect[c] = izquierda[a];
        a++;
        c++;
    }
}

//Función que ordena de menor a mayor con el método de en merge sort. Complejidad: O(n log(n))
void ordenaMerge(vector<int> &vect, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMerge(vect, izq, mitad);
        ordenaMerge(vect, mitad + 1, der);
        merge(vect, izq, mitad, der);
    }
}

//Función que realiza una búsqueda secuancial de un número entero dentro de un vector ordenado. Complejidad: O(n)
int busqSecuencial(vector<int> vect, int valor){
    for(int i=0; i < vect.size(); i++){
        if(vect[i] == valor){
            return i;
        }
    }
    return -1;
}

//Función que realiza una búsqueda binaria de un número entero dentro de un vector ordenado. Complejidad: O(ln(n))
int busqBinaria(vector<int> vect, int val){
    int izq = 0;
    int der = vect.size()-1;
    while(izq <= der){
        int mit = (der + izq)/2;
        if(val == vect[mit]){
            return mit;
        }else if(val < vect[mit]){
            der = mit - 1;
        }else{
            izq = mit + 1;
        }
    }
    return -1;
}

//Función que imprime todos los elementos de un vector. Complejidad: O(n)
void imprimeVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> vector1{2,6,4,10,8};
    
    cout << "Caso 1" << endl;
    cout << " " << endl;
    cout << "Lista de números sin ordenar: " << endl;
    imprimeVector(vector1);
    cout << " " << endl;

    cout << "Lista ordenada por inserción:" << endl;
    ordenaIntercambio(vector1);
    imprimeVector(vector1);
    cout << " " << endl;

    cout << "Lista ordenada por método de burbuja: " << endl;
    ordenaBurbuja(vector1);
    imprimeVector(vector1);
    cout << " " << endl;

    cout << "Lista ordenada por método de Merge Sort:" << endl;
    ordenaMerge(vector1, 0, vector1.size()-1);
    imprimeVector(vector1);
    cout << " " << endl;
    
    int cant_busq;
    cout << "Cantidad de búsquedas a realizar: ";
    cin >> cant_busq;
    
    for (int i = 0; i < cant_busq; i++){
        int num;
        cout << "Número a buscar: " << endl;
        cin >> num;
        cout << "Resultado de la busqueda secuencial: el número se encuentra en la posición: " << busqSecuencial(vector1, num) << " de la lista" << endl;
        cout << "Resultado de la busqueda binaria: el número se encuentra en la posición: " << busqBinaria(vector1, num) << " de la lista " << endl;
        cout << endl << endl;
    }
    
    vector<int> vector2{400,500,100,300,200};
    
    cout << "Caso 2" << endl;
    cout << " " << endl;
    cout << "Lista de números sin ordenar: " << endl;
    imprimeVector(vector2);
    cout << " " << endl;

    cout << "Lista ordenada por inserción:" << endl;
    ordenaIntercambio(vector2);
    imprimeVector(vector2);
    cout << " " << endl;

    cout << "Lista ordenada por método de burbuja: " << endl;
    ordenaBurbuja(vector2);
    imprimeVector(vector2);
    cout << " " << endl;

    cout << "Lista ordenada por método de Merge Sort:" << endl;
    ordenaMerge(vector2, 0, vector2.size()-1);
    imprimeVector(vector2);
    cout << " " << endl;
    
    int cant_busq2;
    cout << "Cantidad de búsquedas a realizar: ";
    cin >> cant_busq2;
    
    for (int i = 0; i < cant_busq2; i++){
        int num;
        cout << "Número a buscar: " << endl;
        cin >> num;
        cout << "Resultado de la busqueda secuencial: el número se encuentra en la posición: " << busqSecuencial(vector2, num) << " de la lista" << endl;
        cout << "Resultado de la busqueda binaria: el número se encuentra en la posición: " << busqBinaria(vector2, num) << " de la lista " << endl;
        cout << endl << endl;
    }
    
    vector<int> vector3{1,10,2,9,3,8,4,7,5,6};
    
    cout << "Caso 3" << endl;
    cout << " " << endl;
    cout << "Lista de números sin ordenar: " << endl;
    imprimeVector(vector3);
    cout << " " << endl;

    cout << "Lista ordenada por inserción:" << endl;
    ordenaIntercambio(vector3);
    imprimeVector(vector3);
    cout << " " << endl;

    cout << "Lista ordenada por método de burbuja: " << endl;
    ordenaBurbuja(vector3);
    imprimeVector(vector3);
    cout << " " << endl;

    cout << "Lista ordenada por método de Merge Sort:" << endl;
    ordenaMerge(vector3, 0, vector3.size()-1);
    imprimeVector(vector3);
    cout << " " << endl;
    
    int cant_busq3;
    cout << "Cantidad de búsquedas a realizar: ";
    cin >> cant_busq3;
    
    for (int i = 0; i < cant_busq3; i++){
        int num;
        cout << "Número a buscar: " << endl;
        cin >> num;
        cout << "Resultado de la busqueda secuencial: el número se encuentra en la posición: " << busqSecuencial(vector3, num) << " de la lista" << endl;
        cout << "Resultado de la busqueda binaria: el número se encuentra en la posición: " << busqBinaria(vector3, num) << " de la lista " << endl;
        cout << endl << endl;
    }
    
    vector<int> vector4{1000,1,100,500,10};
    
    cout << "Caso 4" << endl;
    cout << " " << endl;
    cout << "Lista de números sin ordenar: " << endl;
    imprimeVector(vector4);
    cout << " " << endl;

    cout << "Lista ordenada por inserción:" << endl;
    ordenaIntercambio(vector4);
    imprimeVector(vector4);
    cout << " " << endl;

    cout << "Lista ordenada por método de burbuja: " << endl;
    ordenaBurbuja(vector4);
    imprimeVector(vector4);
    cout << " " << endl;

    cout << "Lista ordenada por método de Merge Sort:" << endl;
    ordenaMerge(vector4, 0, vector4.size()-1);
    imprimeVector(vector4);
    cout << " " << endl;
    
    int cant_busq4;
    cout << "Cantidad de búsquedas a realizar: ";
    cin >> cant_busq4;
    
    for (int i = 0; i < cant_busq4; i++){
        int num;
        cout << "Número a buscar: " << endl;
        cin >> num;
        cout << "Resultado de la busqueda secuencial: el número se encuentra en la posición: " << busqSecuencial(vector4, num) << " de la lista" << endl;
        cout << "Resultado de la busqueda binaria: el número se encuentra en la posición: " << busqBinaria(vector4, num) << " de la lista " << endl;
        cout << endl << endl;
    }
}



