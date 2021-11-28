// Diego Rosas A01634154
// Noviembre 22, 2021
// Programa que modifica tablas hash y las regresa modificadas y válidas con el método de chain y quadratic


#include<bits/stdc++.h>
using namespace std;

class Chain
{
    int FILA;

    list<int> *table;
public:
    Chain(int V);

    void insertar(int x);

    int chainFuncion(int x) {
        return (x % FILA);
    }

    void imprimirChain();
};

Chain::Chain(int b)
{
    this->FILA = b;
    table = new list<int>[FILA];
}

// Función que inserta elementos en una tabla. Complejidad: O(N)
void Chain::insertar(int key)
{
    int index = chainFuncion(key);
    table[index].push_back(key);
}

// Función que imprime los elementos de la tabla. Complejidad O(N)
void Chain::imprimirChain() {
for (int i = 0; i < FILA; i++) {
    cout << i;
    for (auto x : table[i])
    cout << " --> " << x;
    cout << endl;
}
}

// Función que imprime los elementos de la tabla. Complejidad O(N)
void imprimirQuadratic(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
 
// Función que crea una tabla hash modificada y válida y la regresa. Complejidad:
// O(N * L) donde n es la longitud del arreglo y l es el tamaño de la tabla hash
void quadratic(int table[], int tsize,
             int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int hv = arr[i] % tsize;
 
        if (table[hv] == -1)
            table[hv] = arr[i];
        else
        {
            for (int j = 0; j < tsize; j++)
            {
                int t = (hv + j * j) % tsize;
                if (table[t] == -1)
                {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    imprimirQuadratic(table, N);
}

int main()
{

// CASO 1
    
// Chain
    
int a[] = {502, 705, 71, 89, 94, 79, 111};
int n = sizeof(a)/sizeof(a[0]);

Chain h(7);
for (int i = 0; i < n; i++)
    h.insertar(a[i]);

h.imprimirChain();
    
// Quadratic

int arr[] = {502, 705, 71, 89, 94, 79, 111};
int N = 7;
 
int L = 7;
int hash_table[7];
 
for (int i = 0; i < L; i++)
{
    hash_table[i] = -1;
}
 
quadratic(hash_table, L, arr, N);
    
cout << " " << endl;
    
// CASO 2
        
    // Chain
        
int a2[] = {39, 501, 67, 80, 89, 70, 125};
int n2 = sizeof(a2)/sizeof(a2[0]);

Chain h2(7);
for (int i = 0; i < n2; i++)
    h2.insertar(a2[i]);

h2.imprimirChain();
        
// Quadratic

int arr2[] = {39, 501, 67, 80, 89, 70, 125};
int N2 = 7;
     
int L2 = 7;
int hash_table2[7];
     
for (int i = 0; i < L; i++)
{
    hash_table2[i] = -1;
}
     
quadratic(hash_table2, L2, arr2, N2);
    
cout << " " << endl;

// CASO 3
        
// Chain
        
int a3[] = {45, 234, 65, 77, 83, 70, 99};
int n3 = sizeof(a3)/sizeof(a3[0]);

Chain h3(7);
for (int i = 0; i < n; i++)
    h3.insertar(a3[i]);

h3.imprimirChain();
        
// Quadratic

int arr3[] = {45, 234, 65, 77, 83, 70, 99};
int N3 = 7;
     
int L3 = 7;
int hash_table3[7];
     
for (int i = 0; i < L; i++)
{
    hash_table3[i] = -1;
}
     
quadratic(hash_table3, L3, arr3, N3);
    
cout << " " << endl;
    
// CASO 4
        
// Chain
        
int a4[] = {20, 300, 70, 80, 90, 78, 100};
int n4 = sizeof(a4)/sizeof(a4[0]);

Chain h4(7);
for (int i = 0; i < n; i++)
    h4.insertar(a4[i]);

h4.imprimirChain();
        
// Quadratic

int arr4[] = {20, 300, 70, 80, 90, 78, 100};
int N4 = 7;
     
int L4 = 7;
int hash_table4[7];
    
for (int i = 0; i < L; i++)
{
    hash_table4[i] = -1;
}
     
quadratic(hash_table4, L4, arr4, N4);
    
cout << " " << endl;
    
return 0;
}




