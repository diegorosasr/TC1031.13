//
//  Programa que realiza la sumatoria desde 1 hasta n utilizando los métodos alterativo, recursivo y directo
//
// Autor: Diego Rosas A01634154
// 8/19/21
//

#include <iostream>

using namespace std;

int sumaRecursiva(int n);
int sumalterativa(int n, int sum);
int sumaDirecta(int n);

int main() {
    int sum = 0;
    int n = 0;

    //  Caso de prueba 1:
    n = 5;
    cout << "Suma recursiva =  " << sumaRecursiva(n) << endl;
    cout << "Suma alterativa =  " << sumalterativa(n, sum) << endl;
    cout << "Suma directa =  " << sumaDirecta(n) << endl;
    cout << " " << endl;

    //  Caso de prueba 2:
    
    n = 10;
    cout << "Suma recursiva =  " << sumaRecursiva(n) << endl;
    cout << "Suma alterativa =  " << sumalterativa(n, sum) << endl;
    cout << "Suma directa =  " << sumaDirecta(n) << endl;
    cout << " " << endl;
    
    //  Caso de prueba 3:
    
    n = 50;
    cout << "Suma recursiva =  " << sumaRecursiva(n) << endl;
    cout << "Suma alterativa =  " << sumalterativa(n, sum) << endl;
    cout << "Suma directa =  " << sumaDirecta(n) << endl;
    cout << " " << endl;
    
    //  Caso de prueba 4:
    
    n = 100;
    cout << "Suma recursiva =  " << sumaRecursiva(n) << endl;
    cout << "Suma alterativa =  " << sumalterativa(n, sum) << endl;
    cout << "Suma directa =  " << sumaDirecta(n) << endl;
    cout << " " << endl;
    

}

// Función que recibe la variable n y realiza una sumatoria desde 1 hasta n recursivamente. La función regresa el total de la sumatoria. Complejidad: O(n) ya que se suma cada elemento.

int sumaRecursiva(int n) {
    if(n != 0)
        return n + sumaRecursiva(n - 1);
    return 0;
}

// Función que recibe la variable n y realiza una sumatoria desde 1 hasta n directamente. La función regresa el total de la sumatoria. Complejidad: O(1) ya que se realiza solo una operación.

int sumaDirecta(int n) {
    n = ((n*(n+1))/2);
    return n;
}

// Función que recibe las variable n y sum, realiza una sumatoria desde 1 hasta n alterativamente. La función regresa "sum", el total de la sumatoria. Complejidad: O(n) ya que se suma cada elemento.

int sumalterativa(int n, int sum) {
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    return sum;
}
    

