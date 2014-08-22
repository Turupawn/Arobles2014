#include <iostream>

using namespace std;

class NodoArbol
{
public:
    int num;
    NodoArbol* hijo_izq;
    NodoArbol* hijo_der;

    NodoArbol(int num)
    {
        this->num = num;
        hijo_der = NULL;
        hijo_izq = NULL;
    }
};

void imprimirArbol(NodoArbol* raiz)
{
    if(raiz==NULL)
        return;
    cout<<raiz->num<<endl;
    imprimirArbol(raiz->hijo_der);
    imprimirArbol(raiz->hijo_izq);
}

bool existe(NodoArbol* raiz, int num)
{
    if(raiz==NULL)
        return false;

    bool existe_por_la_derecha = existe(raiz->hijo_der,num);
    bool existe_por_la_izquierda = existe(raiz->hijo_izq,num);
    if(raiz->num==num
            || existe_por_la_derecha
            || existe_por_la_izquierda)
        return true;
    return false;
}

int main()
{
    NodoArbol *n1 = new NodoArbol(1);
    NodoArbol *n2 = new NodoArbol(2);
    NodoArbol *n3 = new NodoArbol(3);
    NodoArbol *n4 = new NodoArbol(4);
    NodoArbol *n5 = new NodoArbol(5);

    n1->hijo_izq = n2;
    n1->hijo_der = n5;
    n2->hijo_izq = n3;
    n2->hijo_der = n4;

    cout<<existe(n1,7)<<endl;
    cout<<existe(n1,2)<<endl;


    return 0;
}
