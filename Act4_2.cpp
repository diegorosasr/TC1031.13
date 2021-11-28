//  Diego Rosas A01634154
//  19 de Noviembre de 2021
//  Programa que carga un grafo y determina si es un árbol o no

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
        vector<Node*> exits;
        int key;

        Node(int _key){
            key =  _key;
        }

        Node(){

        }

        void addExit(Node* exit){
            exits.push_back(exit);
        }
};

//  Función que carga un grafo. Complejidad: O(|V|+|E|)

void loadGraph(int n, int m, vector<Node*> &list){
    for (int i = 0; i < n; i++){
        int temp;
        cout << "Node key: " << endl;
        cin >> temp;
        list.push_back(new Node(temp));
    }
    for (int i = 0; i < m; i++){
        cout << "Ingresar la llave del nodo principal y del nodo a dirigir en la forma" << endl << "a->b separados por un espacio, ejemplo: a b" << endl;
        int a, b;
        cin >> a >> b;
        Node* node_a = NULL;
        Node* node_b = NULL;
        for(int k = 0; k < n; k++){
            if(list[k]->key == a){
                node_a = list[k];
            }else if(list[k]->key == b){
                node_b = list[k];
            }
        }
        if(node_a && node_b){
            node_a->addExit(node_b);
        }else{
            cout << "Una llave no se encontró" << endl;
            i--;
        }
    }
}

//  Función que imprime un grafo. Complejidad: O(N)
void printList(vector<Node*> list){
    for(int i = 0; i < list.size(); i++){
        cout << list[i]->key;
        for(int k = 0; k < list[i]->exits.size(); k++){
            cout << " -> " << list[i]->exits[k]->key;
        }
        cout << endl;
    }
}

//  Funicón que encuentra el head de un grafo y lo regresa. Complejidad: O(Log(N))
Node* findHead(vector<Node*> list){
    vector<Node*> accessed;
    vector<Node*> notAccessed;
    for (int i = 0; i < list.size(); i++){
        for (int k = 0; k < list[i]->exits.size(); k++){
            accessed.push_back(list[i]->exits[k]);
        }
    }
    for(int i = 0; i < list.size(); i++){
        bool access = false;
        for(int k = 0; k < accessed.size(); k++){
            if(list[i]->key == accessed[k]->key){
                access = true;
            }
        }
        if(access == false){
            notAccessed.push_back(list[i]);
        }
    }

    if(notAccessed.size() != 1){
        return NULL;
    }else{
        return notAccessed[0];
    }
}

//  Función que recorre un grafo. Complejidad: O(N)
bool pass(Node* nodo, vector<int> &accessed){
    if(nodo->exits.size() > 0){
        if(accessed.size() != 0){
            for(int i = 0; i < accessed.size(); i++){
                if(nodo->key==accessed[i]){
                    accessed.push_back(nodo->key);
                    return false;
                }
            }
            accessed.push_back(nodo->key);
        }else{
            accessed.push_back(nodo->key);
        }
        for(int i = 0; i < nodo->exits.size(); i++){
            pass(nodo->exits[i], accessed);
        }
    }
    else{
        accessed.push_back(nodo->key);
        return false;
    }
    return false;
}


// Funcion de ordenamiento merge.

void merge(vector<int> &vect, int izq, int mitad, int der){
    int sizeIzq = mitad - izq + 1;
    int sizeDer = der - mitad;
    vector<int> izquierda;
    vector<int> derecha;
    for(int i = 0; i < sizeIzq; i++){
        izquierda.push_back(vect[izq + i]);
    }
    for(int j = 0; j < sizeDer; j++){
        derecha.push_back(vect[mitad + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < sizeIzq && b < sizeDer){
        if(izquierda[a] <= derecha[b]){
            vect[c] = izquierda[a];
            a++;
        }else{
            vect[c] = derecha[b];
            b++;
        }
        c++;
    }
    while(b < sizeDer){
        vect[c] = derecha[b];
        b++;
        c++;
    }
    while(a < sizeIzq){
        vect[c] = izquierda[a];
        a++;
        c++;
    }
}
// Función de ordenamiento de merge sort. Complejidad: O(log(N))
void ordenaMerge(vector<int> &vect, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMerge(vect, izq, mitad);
        ordenaMerge(vect, mitad + 1, der);
        merge(vect, izq, mitad, der);
    }
}


//  Función que determina si un grafo es árbol o no y regresa un valor booleano.
bool isTree(vector<Node*> list, int n, int m){
    Node* head = findHead(list);
    if(head){
        vector<int> accessed;
        pass(head, accessed);
        ordenaMerge(accessed,0,accessed.size()-1);
        bool duplicates = adjacent_find(accessed.begin(), accessed.end()) != accessed.end();
        if(duplicates){
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}

int main(){
    int n, m;
    vector<Node*> list;
    cout << "Cantidad de vértices: " << endl;
    cin >> n;
    cout << "Cantidad de arcos" << endl;
    cin >> m;
    loadGraph(n,m,list);
    cout << endl;
    printList(list);
    if(isTree(list, n, m)){
        cout << "Es es un árbol" << endl;
    }else{
        cout << "No es un árbol" << endl;
    }
}

//  Caso 1:
//  (12, 0); (0,23); (0,34); (34,45). Es un árbol.

//  Caso 2:
//  (2, 1); (1,3); (3,2); (1,4); (4,5). No es un árbol.

//  Caso 3:
//  (1, 0); (0,2); (0,3); (3,4). Es un árbol.

//  Caso 4:
//  (1, 0); (0,2); (2,1); (0,3); (3,4). No es un árbol.
