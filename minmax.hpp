#ifndef MINMAX_HPP
#define MINMAX_HPP
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "nodo.hpp"
#include <math.h>

#define MOVIMIENTOS 8
#define MAX 1
#define MIN 0
#define TOP_RECURSION_LEVEL 8

using namespace std;


class MinMax
{
public:
    MinMax();
    void empezarPartida();
    void pulsaBoton(int f, int c);
    void jugadaMaquina();
    int getRows(void);
    int getCols(void);
    int getGanador();
    int getItems(void);
    int getItemsJ1(void);
    int getItemsJ2(void);
    int **getMatriz(void);
    void setItems(int item);
    void randomChessItems();
    void buildInitMatriz(void);
    void buildMatriz();
    int** copiarMatriz(int** matriz_original);
    bool esNodoHoja(int **board);
    bool verificarMovimiento(int new_mov, Nodo * nodo);
    void hacerMovimiento(int mov, Nodo * nodo);
    int getFilaColumna(int **board, int player, char foc);

    int miniMax(Nodo * nodo, int profundidad, int alfa, int beta);
    bool verificarNodoEnRama(Nodo * nodo, int tipo, int fila, int columna, int p_items);

private:
    int rows;
    int cols;
    int nGanador;
    int items;
    int  maquina_items;
    int jugador_items;
    int **matriz;
    bool gana_max_movimiento;
    Nodo * gana_max_nodo;
    vector<Nodo*> nodos_max_ganador;
    vector<Nodo*> nodos_max_profundidad;
    vector<int> pos_chess_items;
    vector<int> maquina_pos;
    vector<int> jugador_pos;
    vector<Nodo*> expandidos;
};

#endif // MINMAX_HPP
