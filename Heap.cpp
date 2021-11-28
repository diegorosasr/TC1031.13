// Autor: Diego Rosas A01634154
// Fecha: 22/10/2021
// Programa que crea un árbol heap e inserta, borra, busca y acomoda datos, además, obtiene el elemento de mayor prioridad y el tamaño del árbol. 


#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 
struct PriorityQueue
{
private:
    vector<int> A;
 
    int PADRE(int i) {
        return (i - 1) / 2;
    }
 
    int IZQ(int i) {
        return (2*i + 1);
    }
 
    int DER(int i) {
        return (2*i + 2);
    }
 
    void heapify_abajo(int i)
    {
        int izq = IZQ(i);
        int der = DER(i);
 
        int mayor = i;

        if (der < size() && A[izq] > A[i]) {
            mayor = izq;
        }
 
        if (der < size() && A[der] > A[mayor]) {
            mayor = der;
        }

        if (mayor != i)
        {
            swap(A[i], A[mayor]);
            heapify_abajo(mayor);
        }
    }

    void heapify_arriba(int i)
    {
        if (i && A[PADRE(i)] < A[i])
        {
            swap(A[i], A[PADRE(i)]);
 
            heapify_arriba(PADRE(i));
        }
    }
 
public:
    
//  Función que regresa el tamaño de la lista priorizada. Complejidad: O(N)
    unsigned int size() {
        return A.size();
    }

//  Función que regresa un valor booleano que indica si la fila priorozada está vacía o no. Complejidad: O(N)
    bool empty() {
        return size() == 0;
    }
 
//  Función que agrega un dato a la fila priorizada. Complejidad: O(Log(n))
    void push(int key)
    {
        A.push_back(key);

        int index = size() - 1;
        heapify_arriba(index);
    }
 
//  Función que saca el dato de mayor prioridad de la fila priorizada. Complejidad: O(Log(n))
    
    void pop()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("No se puede realizar la operación ya que la fila priorizada está vacía");
            }

            A[0] = A.back();
            A.pop_back();
 
            heapify_abajo(0);
        }
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }

//  Función que regresa el dato con mayor prioridad. Complejidad: O(Log(N))
    int top()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("No se puede realizar la operación ya que la fila priorizada está vacía");
            }
 
            return A.at(0);
        }
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
            return 0;
    }
};
 
int main()
{
    PriorityQueue pq;
    
//    Se crea la fila priorizada de tres elementos
 
    cout << "Caso 1" << endl;
    pq.push(10);
    pq.push(9);
    pq.push(16);
    
//    Se verifica si la fila priorizada está vacía, en este caso si contiene elementos
    
    cout << boolalpha << pq.empty() << endl;
 
//    Se muestra el número de elementos en la fila priorizada
    
    cout << "Size " << pq.size() << endl;

//    Se muestra el elemento de mayor prioridad y se borra
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
    
//    Se agregan mas elementos a la lista priorizada
 
    pq.push(6);
    pq.push(4);
    pq.push(40);
 
//    Se muestra el nuevo número de elementos en la fila priorizada
    
    cout << endl << "Size " << pq.size() << endl;
    
//    Se muestra el elemento de mayor prioridad de los elementos restantes y posteriormente se borran
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
    
//    Se verifica que la lista priorizada está vacía
 
    cout << endl << boolalpha << pq.empty();
    
//    Se realizan las operaciones con una fila de prioridad vacía, a lo cual se muestra un mensaje indicando que no es posible realizarse ya que la fila está vacía. 
 
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
    
    cout << " " << endl;
    
    PriorityQueue pq2;
    
//    Se crea la fila priorizada de tres elementos
    cout << " " << endl;
    cout << "Caso 2" << endl;
    pq2.push(4);
    pq2.push(3);
    pq2.push(10);
    pq2.push(20);
    
//    Se verifica si la fila priorizada está vacía, en este caso si contiene elementos
    
    cout << boolalpha << pq2.empty() << endl;
 
//    Se muestra el número de elementos en la fila priorizada
    
    cout << "Size " << pq2.size() << endl;

//    Se muestra el elemento de mayor prioridad y se borra
 
    cout << pq2.top() << " ";
    pq2.pop();
 
    cout << pq2.top() << " ";
    pq2.pop();
    
//    Se agregan mas elementos a la lista priorizada
 
    pq2.push(30);
    pq2.push(40);
    pq2.push(50);
    pq2.push(60);
 
//    Se muestra el nuevo número de elementos en la fila priorizada
    
    cout << endl << "Size " << pq2.size() << endl;
    
//    Se muestra el elemento de mayor prioridad de los elementos restantes y posteriormente se borran
 
    cout << pq2.top() << " ";
    pq2.pop();
 
    cout << pq2.top() << " ";
    pq2.pop();
 
    cout << pq2.top() << " ";
    pq2.pop();
 
    cout << pq2.top() << " ";
    pq2.pop();
    
//    Se verifica que la lista priorizada está vacía
 
    cout << endl << boolalpha << pq2.empty();
    
//    Se realizan las operaciones con una fila de prioridad vacía, a lo cual se muestra un mensaje indicando que no es posible realizarse ya que la fila está vacía.
 
    pq2.top();    // top operation on an empty heap
    pq2.pop();    // pop operation on an empty heap
    
    cout << " " << endl;
    
    PriorityQueue pq3;
    
//    Se crea la fila priorizada de tres elementos
    cout << " " << endl;
    cout << "Caso 3" << endl;
    pq3.push(300);
    pq3.push(200);
    pq3.push(150);
    pq3.push(250);
    pq3.push(15);
    
//    Se verifica si la fila priorizada está vacía, en este caso si contiene elementos
    
    cout << boolalpha << pq3.empty() << endl;
 
//    Se muestra el número de elementos en la fila priorizada
    
    cout << "Size " << pq3.size() << endl;

//    Se muestra el elemento de mayor prioridad y se borra
 
    cout << pq3.top() << " ";
    pq3.pop();
 
    cout << pq3.top() << " ";
    pq3.pop();
    
//    Se agregan mas elementos a la lista priorizada
 
    pq3.push(10);
    pq3.push(20);
    pq3.push(45);
    pq3.push(30);
    pq3.push(19);
 
//    Se muestra el nuevo número de elementos en la fila priorizada
    
    cout << endl << "Size " << pq3.size() << endl;
    
//    Se muestra el elemento de mayor prioridad de los elementos restantes y posteriormente se borran
 
    cout << pq3.top() << " ";
    pq3.pop();
 
    cout << pq3.top() << " ";
    pq3.pop();
 
    cout << pq3.top() << " ";
    pq3.pop();
 
    cout << pq3.top() << " ";
    pq3.pop();
    
//    Se verifica que la lista priorizada está vacía
 
    cout << endl << boolalpha << pq3.empty();
    
//    Se realizan las operaciones con una fila de prioridad vacía, a lo cual se muestra un mensaje indicando que no es posible realizarse ya que la fila está vacía.
 
    pq3.top();    // top operation on an empty heap
    pq3.pop();    // pop operation on an empty heap
    
    cout << " " << endl;
    
    PriorityQueue pq4;
    
//    Se crea la fila priorizada de tres elementos
    cout << " " << endl;
    cout << "Caso 4" << endl;
    pq4.push(30);
    pq4.push(20);
    pq4.push(150);
    pq4.push(33);
    pq4.push(29);
    pq4.push(8);
    
//    Se verifica si la fila priorizada está vacía, en este caso si contiene elementos
    
    cout << boolalpha << pq4.empty() << endl;
 
//    Se muestra el número de elementos en la fila priorizada
    
    cout << "Size " << pq4.size() << endl;

//    Se muestra el elemento de mayor prioridad y se borra
 
    cout << pq4.top() << " ";
    pq4.pop();
 
    cout << pq4.top() << " ";
    pq4.pop();
    
//    Se agregan mas elementos a la lista priorizada
 
    pq4.push(5);
    pq4.push(10);
    pq4.push(15);
    pq4.push(30);
    pq4.push(27);
    pq4.push(12);
 
//    Se muestra el nuevo número de elementos en la fila priorizada
    
    cout << endl << "Size " << pq4.size() << endl;
    
//    Se muestra el elemento de mayor prioridad de los elementos restantes y posteriormente se borran
 
    cout << pq4.top() << " ";
    pq4.pop();
 
    cout << pq4.top() << " ";
    pq4.pop();
 
    cout << pq4.top() << " ";
    pq4.pop();
 
    cout << pq4.top() << " ";
    pq4.pop();
    
//    Se verifica que la lista priorizada está vacía
 
    cout << endl << boolalpha << pq4.empty();
    
//    Se realizan las operaciones con una fila de prioridad vacía, a lo cual se muestra un mensaje indicando que no es posible realizarse ya que la fila está vacía.
 
    pq4.top();    // top operation on an empty heap
    pq4.pop();    // pop operation on an empty heap
    
    cout << " " << endl;
    
    
}
