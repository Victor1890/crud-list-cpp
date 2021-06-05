#include "Lista.h"
#include <iostream>

Lista::Lista(): _primer(NULL) , _ultimo(NULL){}

int sizeGlobal = 0;

void Lista::Agregar(Elemento* elementoDeLaListaTarea)
{
	/*IMPLEMENTE ESTE METODO
		Dado un objeto de tipo puntero a Elemento agréguelo a la lista.

		Tenga pendiente que el atributo _primer guarda un puntero al primer elemento de la lista y que _ultimo es un puntero al al último elemento de la lista
	*/

	if(_primer != NULL){
		_ultimo-> SetSiguiente(elementoDeLaListaTarea);
		sizeGlobal++;
		_ultimo = elementoDeLaListaTarea;
	} else{
		_primer = elementoDeLaListaTarea;
		_ultimo = _primer;
	}
}

bool Lista::Eliminar(int indicadorDeLaTarea)
{
	/*
	IMPLEMENTE ESTE METODO
	Dado un indice entero elimine el objeto en esa posición.  Ejemplo si el parámetro indice es igual a 0 se eliminará el primer elemento.

	Esta función retorna un booleano,  retorno verdadero si el índice está contenido en la lista.

	Ejemplo, si la lista tiene 4 elementos y se pide eliminar el índice 9 este método retornará falso porque ese índice no está contenido en la lista.

	*/

	Elemento* elementoDeLaListaTarea;

	if(indicadorDeLaTarea <= sizeGlobal){

		if(indicadorDeLaTarea != 0){
			Elemento* elementoDeListaPaPu = _primer;
			Elemento* removerElemento = elementoDeListaPaPu->GetSiguiente();
			elementoDeListaPaPu->SetSiguiente(removerElemento->GetSiguiente());
			delete removerElemento;
			return true;
		} else {
			elementoDeLaListaTarea = _primer;
			_primer = _primer->GetSiguiente();
			delete elementoDeLaListaTarea;
			return true;
		}
	}
	return false;
}
