// Diego Rosas A01634154
// 25 de Octubre de 2021
// Programa que crea un árbol AVL, permite insertar y borrar elementos, además, se puede consultar el tamaño del mismo así como se puede consultar si un elemento está en el árbol, finalmente, se pueden imprimir los elementos del árbol.


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b);


int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
        height(N->right);
}

//  Función que inserta un nodo al árbol AVL. Complejidad: O(Log(N))

Node* insert(Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    node->height = 1 + max(height(node->left),
                        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


Node * minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

//  Función que borra un nodo del árbol AVL. Complejidad: O(Log(N))

Node* del(Node* root, int key)
{
    
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = del(root->left, key);

    else if( key > root->key )
        root->right = del(root->right, key);

    else
    {
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                        root->left :
                        root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = del(root->right,
                                    temp->key);
        }
    }

    if (root == NULL)
    return root;

    root->height = 1 + max(height(root->left),
                        height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//  Función que regresa el tamaño del árbol AVL. Complejidad: O(N)

int size(Node* root)
{
    if (root == NULL)
        return 0;
    else
        return(size(root->left) + 1 + size(root->right));
}

//  Función que regresa el tamaño del árbol AVL. Complejidad: O(N)

bool b=false;
bool find(struct Node* root, int key)
     {
         if(root!=NULL)
  {  if (root->key == key)
       {
           b=true;
       }
    else if (root->key< key)
       {
           find(root->right, key);
       }else
         {
             find(root->left, key);
         }
  }
  return b;
       }

//  Función que imprime el contenido del arbol. Complejidad: O(N)
void print(struct Node* root)
{
    if (root != NULL)
     {
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
}

int main()
{
Node *root = NULL;
    
    cout << "Caso 1" << endl;

//  Se construye el arbol AVL
    
    root = insert(root, 10);
    root = insert(root, 4);
    root = insert(root, 15);
    root = insert(root, 0);
    root = insert(root, 7);
    root = insert(root, 19);

    preOrder(root);
    
    cout << " " << endl;
//  Se llama la función para obtener el programa:
    
    cout << "Tamaño: " << size(root) << endl;
 
//  Se borra un nodo en específico
    
    root = del(root, 10);

//  Se muestra el árbol sin el nodo borrado y ordenado nuevamente
    
    preOrder(root);
    
//  Se muestra el nuevo tamaño del árbol
    
    cout << " " << endl;
    cout << "Tamaño: " << size(root) << endl;
    
//  Se busca si cierto elemento está presente en el árbol
    
    cout << boolalpha << find(root,10) << endl;

//  Se busca si cierto elemento está presente en el árbol
    
    cout << boolalpha << find(root,15) << endl;
    
// Imprime el árbol en orden ascendente
    
    print(root);
    
    cout << " " << endl;
    
Node *root2 = NULL;
        
        cout << " " << endl;
        cout << "Caso 2" << endl;

    //  Se construye el arbol AVL
        
        root2 = insert(root2, 90);
        root2 = insert(root2, 50);
        root2 = insert(root2, 105);
        root2 = insert(root2, 2);
        root2 = insert(root2, 9);
        root2 = insert(root2, 17);
        root2 = insert(root2, 89);

        preOrder(root2);
        
        cout << " " << endl;
    //  Se llama la función para obtener el programa:
        
        cout << "Tamaño: " << size(root2) << endl;
     
    //  Se borra un nodo en específico
        
        root2 = del(root2, 90);

    //  Se muestra el árbol sin el nodo borrado y ordenado nuevamente
        
        preOrder(root2);
        
    //  Se muestra el nuevo tamaño del árbol
        
        cout << " " << endl;
        cout << "Tamaño: " << size(root2) << endl;
        

    //  Se busca si cierto elemento está presente en el árbol
        
        cout << boolalpha << find(root2,105) << endl;
        
    // Imprime el árbol en orden ascendente
        
        print(root2);
        
        cout << " " << endl;
    
Node *root3 = NULL;
        
        cout << " " << endl;
        cout << "Caso 3" << endl;

        //  Se construye el arbol AVL
            
        root3 = insert(root3, 20);
        root3 = insert(root3, 10);
        root3 = insert(root3, 4);
        root3 = insert(root3, 7);
        root3 = insert(root3, 21);
        root3 = insert(root3, 0);
        root3 = insert(root3, 77);
        root3 = insert(root3, 45);

        preOrder(root3);
        
        cout << " " << endl;
    //  Se llama la función para obtener el programa:
            
        cout << "Tamaño: " << size(root3) << endl;
         
    //  Se borra un nodo en específico
        
        root3 = del(root3, 77);

    //  Se muestra el árbol sin el nodo borrado y ordenado nuevamente
            
        preOrder(root3);
            
    //  Se muestra el nuevo tamaño del árbol
            
        cout << " " << endl;
        cout << "Tamaño: " << size(root3) << endl;

    //  Se busca si cierto elemento está presente en el árbol
            
        cout << boolalpha << find(root3,0) << endl;
            
    // Imprime el árbol en orden ascendente
        
        print(root3);
        
        cout << " " << endl;
    
Node *root4 = NULL;
            
        cout << " " << endl;
        cout << "Caso 4" << endl;

        //  Se construye el arbol AVL
            
        root4 = insert(root4, 89);
        root4 = insert(root4, 52);
        root4 = insert(root4, 101);
        root4 = insert(root4, 5);
        root4 = insert(root4, 67);
        root4 = insert(root4, 119);
        root4 = insert(root4, 0);
        root4 = insert(root4, 1);

        preOrder(root4);
        
        cout << " " << endl;
    //  Se llama la función para obtener el programa:
            
        cout << "Tamaño: " << size(root4) << endl;
         
    //  Se borra un nodo en específico
        
        root4 = del(root4, 101);

    //  Se muestra el árbol sin el nodo borrado y ordenado nuevamente
            
        preOrder(root4);
            
    //  Se muestra el nuevo tamaño del árbol
            
        cout << " " << endl;
        cout << "Tamaño: " << size(root4) << endl;

    //  Se busca si cierto elemento está presente en el árbol
            
        cout << boolalpha << find(root4,119) << endl;
            
        print(root4);
    
        cout << " " << endl;

    return 0;
}
