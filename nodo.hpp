#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>

using namespace std;


class Nodo{
public:
    Nodo(int tipo_nodo, Nodo *padre, Nodo *oponente, int **board, int max_items, int min_items, int nivel_nodo);
    ~Nodo();
    void setFila(int fila);
    void setColumna(int columna);
    void setTipoNodo(int tipo_nodo);
    void setPadre(Nodo *padre);
    void setOponente(Nodo *oponente);
    void setBoard(int **board);
    void setMaxItems(int max_items);
    void setMinItems(int min_items);
    void setNivelNodo(int nivel_nodo);

    int getFila();
    int getColumna();
    int getTipoNodo();
    Nodo *getPadre();
    Nodo *getOponente();
    int **getBoard();
    int getMaxItems();
    int getMinItems();
    int getNivelNodo();

private:
    int fila;
    int columna;
    int tipo_nodo;
    int max_items;
    int min_items;
    Nodo *padre;
    Nodo *oponente;
    int **board;
    int nivel_nodo;
};

#endif // NODO_HPP
