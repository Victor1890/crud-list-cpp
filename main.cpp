#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;
Lista* listaDeLosElementos = new Lista();


void Listar()
{
    cout << endl << endl;
    int indicador = 1;
    Elemento* elementoDeLaLista = listaDeLosElementos->GetPrimer();
    while(elementoDeLaLista != NULL)
    {
        cout << indicador << "- " << elementoDeLaLista->GetNombre() << " " << elementoDeLaLista->GetCantidad() << endl;
        elementoDeLaLista = elementoDeLaLista->GetSiguiente();
        indicador++;
    }
    if(indicador == 1)
        cout << endl << "** Lista vacía **" << endl;

    cout << endl << endl;
}

void Introducir()
{
    string nombre;
    int cantidad;

    cout << "Introducir el nombre del artículo: ";
    cin >> nombre;
    cout << "Introduzca la cantidad del nuevo artículo: ";
    cin >> cantidad;
    Elemento* elemento = new Elemento(nombre, cantidad);
    listaDeLosElementos->Agregar(elemento);
    cout << "-- Artículo Agregado. Presione ENTER para regresar al menú principal--" << endl;
    getline(cin, nombre);
    cout << endl;
}

void Eliminar()
{
    int indice = 0;
    Listar();
    cout << "Elija el artículo a eliminar => ";
    cin >> indice;
    listaDeLosElementos->Eliminar(indice - 1);
    cout << endl;
    Listar();
    cout << endl;
}

int exitNow(int num){
    return num;
}

void MostrarMenu()
{
    int opcion = 0;
    int exit = 0;
    do
    {        
        cout << "1- Listar artículos" << endl;
        cout << "2- Introducir artículo" << endl;
        cout << "3- Eliminar Artículo" << endl;
        cout << "4- Salir" << endl;
        cout << "Elija una opción => ";
        cin >> opcion;
        
        switch(opcion)
        {
            case 1:
                Listar();
            break;
            case 2:
                Introducir();
            break;
            case 3:
                Eliminar();
            break;
            case 4:
                exit = exitNow(0);
            break;
            default:
                cout << "Opción inválida" << endl;
            break;
        }
    }while(opcion != 4 || exit == 0);
}

int main()
{
    MostrarMenu();
    return 0;
}
