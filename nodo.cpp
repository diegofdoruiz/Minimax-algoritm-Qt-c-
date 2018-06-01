#include "nodo.hpp"

Nodo::Nodo(int tipo_modo, Nodo * padre, Nodo *oponente, int **board, int max_items, int min_items, int nivel_nodo)
{
    this->tipo_nodo = tipo_modo;
    this->padre = padre;
    this->oponente = oponente;
    this->board = board;
    this->max_items = max_items;
    this->min_items = min_items;
    this->nivel_nodo = nivel_nodo;
}

Nodo::~Nodo(){}

void Nodo::setFila(int fila){this->fila = fila;}
void Nodo::setColumna(int columna){this->columna = columna;}
void Nodo::setTipoNodo(int tipo_nodo){this->tipo_nodo = tipo_nodo;}
void Nodo::setPadre(Nodo *padre){this->padre = padre;}
void Nodo::setOponente(Nodo *oponente){this->oponente = oponente;}
void Nodo::setBoard(int **board){this->board = board;}
void Nodo::setMaxItems(int max_items){this->max_items = max_items;}
void Nodo::setMinItems(int min_items){this->min_items = min_items;}
void Nodo::setNivelNodo(int nivel_nodo){this->nivel_nodo = nivel_nodo;}

int Nodo::getFila(){return fila;}
int Nodo::getColumna(){return columna;}
int Nodo::getTipoNodo(){return tipo_nodo;}
Nodo *Nodo::getPadre(){return padre;}
Nodo *Nodo::getOponente(){return oponente;}
int **Nodo::getBoard(){return board;}
int Nodo::getMaxItems(){return max_items;}
int Nodo::getMinItems(){return min_items;}
int Nodo::getNivelNodo(){return nivel_nodo;}




