#include "minmax.hpp"

MinMax::MinMax()
{
    rows = 6;
    cols = 6;
    maquina_items = 0;
    jugador_items = 0;
}

/*
 * Init board
 * */
void MinMax::empezarPartida(){
    srand(time(NULL));
    randomChessItems();
    buildInitMatriz();
    //buildMatriz();
    nGanador = -1;
}

/************************************************************************
 *                               Sets
 ************************************************************************/
int MinMax::getCols(){ return cols;}
int MinMax::getRows(){ return rows;}
int MinMax::getItems(){ return items;}
int MinMax::getGanador(){return nGanador;}
int MinMax::getItemsJ1(){ return maquina_items;}
int MinMax::getItemsJ2(){return jugador_items;}
int **MinMax::getMatriz(){return matriz;}

/************************************************************************
 *                                Gets
 ************************************************************************/
void MinMax::setItems(int items){
    this->items = items;
}

void MinMax::pulsaBoton(int f, int c){
    if(f>=0 && c>=0 && f<rows && c<cols && (matriz[f][c] == -1 || matriz[f][c] == 5)){
        if(matriz[f][c] == 5){
            jugador_items ++;
        }
        matriz[f][c] = MIN;
        matriz[jugador_pos[0]][jugador_pos[1]] = -1;
        jugador_pos[0] = f;
        jugador_pos[1] = c;
        if(jugador_items > ceil(items/2)){
            nGanador = MIN;
        }else{
            jugadaMaquina();
        }
    }
}

void MinMax::jugadaMaquina(){
    int ** board = matriz;
    Nodo * nodo = new Nodo(MAX,NULL, NULL,board, maquina_items, jugador_items, 0);
    cout << "pos juga: " <<"("<<jugador_pos[0]<<","<<jugador_pos[1]<<")"<<endl;
    cout << "maq juga: " <<"("<<maquina_pos[0]<<","<<maquina_pos[1]<<")"<<endl;
    cout << "items maq - jug: "<< maquina_items <<" - "<<jugador_items << endl;
    gana_max_movimiento = false;
    int resultado = miniMax(nodo, TOP_RECURSION_LEVEL, INT_MIN, INT_MAX); //El algoritmo minmax principal para que la jugada decida
    cout << "Finaliza algoritmo, fila: "<<gana_max_nodo->getFila()<<" columna: "<<gana_max_nodo->getColumna()<<" Max items: "<<gana_max_nodo->getMaxItems()<<" Min items: "<<gana_max_nodo->getMinItems()<< endl;
    matriz[maquina_pos[0]][maquina_pos[1]] = -1;
    maquina_pos[0] = gana_max_nodo->getFila();
    maquina_pos[1] = gana_max_nodo->getColumna();
    if(matriz[maquina_pos[0]][maquina_pos[1]] == 5)
        maquina_items ++;
    matriz[maquina_pos[0]][maquina_pos[1]] = MAX;
    if(maquina_items > ceil(items/2)){
        nGanador = MAX;
    }
    /*for(int i=0; i<(int)expandidos.size(); i++){
        delete expandidos[i];
        expandidos[i] = NULL;
    }*/
    /*delete nodo;
    nodo = NULL;
    delete board;
    board = NULL;*/
}

int** MinMax::copiarMatriz(int **matrix_original){
    int **copia;
    copia = new int*[rows];
    for(int i=0; i<rows; i++){
        copia[i] = new int[cols];
        for(int j=0; j<cols; j++){
            copia[i][j] = matrix_original[i][j];
        }
    }
    return copia;
}

/************************************************************************
 *                           Algoritmo minimax
 ************************************************************************/
bool MinMax::esNodoHoja(int **board){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == 5){
                return false;
            }
        }
    }
    return true;
}

int MinMax::miniMax(Nodo * nodo, int profundidad, int alfa, int beta){
    if(esNodoHoja(nodo->getBoard())){
        int max_items = nodo->getMaxItems();
        int min_items = nodo->getMinItems();
        if(max_items > min_items){
            return INT_MAX;
        }else if(max_items == min_items){
            return 0;
        }else{
            return INT_MIN;
        }
    }else if(profundidad <= 0){
        int max_items = nodo->getMaxItems();
        int min_items = nodo->getMinItems();
        return max_items-min_items;
    }else{
        if(nodo->getTipoNodo() == MAX){
            int best = INT_MIN;
            for(int i=1; i<=MOVIMIENTOS; i++){
                if(verificarMovimiento(i, nodo)){
                    // Datos para generar un nuevo nodo hijo
                    int tipo = !nodo->getTipoNodo();
                    Nodo * padre;
                    Nodo * oponente;
                    int** board_copia = copiarMatriz(nodo->getBoard()); //Board heredada del padre
                    int max_items = nodo->getMaxItems();
                    int min_items = nodo->getMinItems();
                    int nivel_nodo = nodo->getNivelNodo()+1;

                    if(nodo->getNivelNodo()  == 0){//se va a crear un nodo del nivel 1
                        padre = NULL;//El padre del nuevo nodo es aquel que tiene el mismo tipo, por eso es el oponente del nodo que llega
                        oponente = nodo;//El oponente es el nodo que está expandiendo este hijo, porque es de otro tipo
                    }else {//se va a crear un nodo de nivel 2 en adelante
                        padre = nodo->getOponente();
                        oponente = nodo;
                    }

                    Nodo * new_nodo = new Nodo(tipo, padre, oponente,board_copia, max_items, min_items, nivel_nodo);
                    hacerMovimiento(i, new_nodo);
                    int val = miniMax(new_nodo, profundidad-1, alfa, beta);
                    //best = max(best, val);
                    if(val > best){
                        if(profundidad == TOP_RECURSION_LEVEL){
                            gana_max_nodo = new_nodo;
                        }
                        best = val;
                    }
                    alfa = max(alfa,best);
                    if(beta <= alfa)
                        break;
                }
            }
            /*delete nodo;
            nodo = NULL;*/
            return best;
        }else{
            int best = MAX;
            for(int i=1; i<=MOVIMIENTOS; i++){
                if(verificarMovimiento(i, nodo)){
                    // Datos para generar un nuevo nodo hijo
                    int tipo = !nodo->getTipoNodo();
                    Nodo * padre;
                    Nodo * oponente;
                    int** board_copia = copiarMatriz(nodo->getBoard()); //Board heredada del padre
                    int max_items = nodo->getMaxItems();
                    int min_items = nodo->getMinItems();
                    int nivel_nodo = nodo->getNivelNodo()+1;

                    if(nodo->getNivelNodo()  == 0){//se va a crear un nodo del nivel 1
                        padre = NULL;//El padre del nuevo nodo es aquel que tiene el mismo tipo, por eso es el oponente del nodo que llega
                        oponente = nodo;//El oponente es el nodo que está expandiendo este hijo, porque es de otro tipo
                    }else {//se va a crear un nodo de nivel 2 en adelante
                        padre = nodo->getOponente();
                        oponente = nodo;
                    }

                    Nodo * new_nodo = new Nodo(tipo, padre, oponente,board_copia, max_items, min_items, nivel_nodo);
                    hacerMovimiento(i, new_nodo);
                    int val = miniMax(new_nodo, profundidad-1, alfa, beta);
                    //best = min(best, val);
                    if(val < best){
                        best = val;
                    }
                    beta = min(beta, best);
                    if(beta <= alfa)
                        break;
                }
            }
            /*delete nodo;
            nodo = NULL;*/
            return best;
        }
        delete nodo;
        nodo = NULL;
    }//end else
}

bool MinMax::verificarNodoEnRama(Nodo * nodo, int tipo, int fila, int columna, int items){
    if(nodo == NULL){
        return false;
    }else{
        if(tipo == MAX){
            if(nodo->getFila() == fila && nodo->getColumna() == columna && nodo->getTipoNodo() == tipo && nodo->getMaxItems() == items){
                return true;
            }else{
                return verificarNodoEnRama(nodo->getPadre(), tipo, fila, columna, items);
            }
        }else{
            if(nodo->getFila() == fila && nodo->getColumna() == columna && nodo->getTipoNodo() == tipo && nodo->getMinItems() == items){
                return true;
            }else{
                return verificarNodoEnRama(nodo->getPadre(), tipo, fila, columna, items);
            }
        }
    }
    return true;
}

void MinMax::hacerMovimiento(int mov, Nodo * nodo){
    int tipo_nodo_que_se_esta_generando = nodo->getTipoNodo();
    int tipo_jugador_que_se_mueve_ahora = !tipo_nodo_que_se_esta_generando;
    int fila_actual = getFilaColumna(nodo->getBoard(), tipo_jugador_que_se_mueve_ahora, 'f');
    int columna_actual = getFilaColumna(nodo->getBoard(), tipo_jugador_que_se_mueve_ahora, 'c');
    int proxima_fila=-7, proxima_columna=-7; //Próxima posición del jugador. se inicia con valor negativo
    switch (mov) {
    case 1: //Up right
        proxima_fila = fila_actual-2;
        proxima_columna = columna_actual+1;
        break;
    case 2: //Up left
        proxima_fila = fila_actual-2;
        proxima_columna = columna_actual-1;
        break;
    case 3: //Right up
        proxima_fila = fila_actual-1;
        proxima_columna = columna_actual+2;
        break;
    case 4: //Right down
        proxima_fila = fila_actual+1;
        proxima_columna = columna_actual+2;
        break;
    case 5: //Down right
        proxima_fila = fila_actual+2;
        proxima_columna = columna_actual+1;
        break;
    case 6: //Down left
        proxima_fila = fila_actual+2;
        proxima_columna = columna_actual-1;
        break;
    case 7: //Left up
        proxima_fila = fila_actual-1;
        proxima_columna = columna_actual-2;
        break;
    case 8: //Left down
        proxima_fila = fila_actual+1;
        proxima_columna = columna_actual-2;
        break;
    default:
        break;
    }

    //cout << "De :"<<fila_actual<<","<<columna_actual<<" a: "<< proxima_fila<< "," << proxima_columna<< endl;
    if(nodo->getBoard()[proxima_fila][proxima_columna] == 5){
        if(tipo_jugador_que_se_mueve_ahora == MAX){
            nodo->setMaxItems(nodo->getMaxItems()+1);
        }else{
            nodo->setMinItems(nodo->getMinItems()+1);
        }
    }
    nodo->getBoard()[proxima_fila][proxima_columna] = tipo_jugador_que_se_mueve_ahora;
    nodo->getBoard()[fila_actual][columna_actual] = -1;
    nodo->setFila(proxima_fila);
    nodo->setColumna(proxima_columna);
}


/************************************************************************
 *                          Métodos auxiliares
 ************************************************************************/

/*
 * Llenar la matriz teniendo en cuenta el vector de posiciones aleatorias
 * */
void MinMax::buildInitMatriz(){
    cout << "Matrix" << endl;
    int count = 0;
    matriz = new int*[rows]; //Filas para la matriz 1 de punteros
    for(int i=0; i<rows; i++){
        matriz[i] = new int[cols]; //columnas para la fila i de la matriz 1
        for(int j=0; j<cols; j++){
            int value = -1;
            for(int k=0; k<(int)pos_chess_items.size();k++){
                if(pos_chess_items[k]==count){
                    if(k==0){
                        value = MAX; //Valor para representar la máquina
                        maquina_pos.push_back(i);
                        maquina_pos.push_back(j);
                    }else if(k==1){
                        value = MIN; //Valor para representar el jugador
                        jugador_pos.push_back(i);
                        jugador_pos.push_back(j);
                    }else{
                        value = 5; //Valor para representar los items
                    }
                    break;
                }
            }//end for k
            matriz[i][j] = value;
            cout << matriz[i][j] << "\t";
            count++;
        }//rnd for j
        cout << endl;
    }//end for i
}

void MinMax::buildMatriz(){
    matriz = new int*[rows];
    for(int i=0; i<rows; i++){
        matriz[i] = new int[cols];
        for(int j=0; j<cols; j++){
            matriz[i][j] = -1;
        }
    }
    maquina_pos.push_back(1);
    maquina_pos.push_back(1);
    jugador_pos.push_back(5);
    jugador_pos.push_back(5);
    matriz[1][1] = MAX;
    matriz[5][5] = MIN;
    matriz[2][3] = 5;
}
/*
 * asignar una posoción aleatoria para cada caballo y para cada item, el número aleatorio está entre
 * 0 y rows*cols, vector con cada posición aleatoria para cada item = {pos_caballo1, pos_caballo2, pos_item1, pos_item2, ... ,pos_itemn}.
 * Se evita que a cada item se asigne una misma posición.
 * */
void MinMax::randomChessItems(){
    bool exit = false;
    int  pos = -1;
    //Se crea un vector para los dos caballos y los items, se asigna -1 a cada pos para iniciar el vector
    for(int i=0; i<items+2; i++){
        pos_chess_items.push_back(-1);
    }
    for(int i=0; i<(int)pos_chess_items.size(); i++){
        while (true) {
            pos = 0+rand()%((rows*cols)-0); //número aleatorio entre 0 y rows*cols
            exit = false;
            for(int j=0; j<(int)pos_chess_items.size(); j++){
                if(pos_chess_items[j] == pos){
                    exit = true;
                    break;
                }
            }
            if(!exit){
                pos_chess_items[i] = pos;
                exit = false;
                break;
            }
        }
    }
}

/*
 * Si llega un nodo MAX es porque se pretende construir un nodo min, por lo tanto el nodo MAX
 * es hijo de un nodo MIN, entonces lo que se necesita es las coordenadas del jugador MIN
 * que se encuentran guardadas en MAX para ver en qué dirección posiblemente se puede mover MIN
 * y validar si es válido el movimiento.
 *
 * El nodo max se usa en este método:
 *  -Para Tomar la posición del jugador MAX y evitar que min se mueva a esa posición.
 *  -Para enviarlo al método verificarNodoEnRama como padre y buscar en su padre, luego en el padre de su padre
 *   y evitar que se forme un ciclo
 *  -Para tomar la posición del oponente de MAX quien es el que se pretende crear y ver dónde se puede mover.
 * */
bool MinMax::verificarMovimiento(int new_mov, Nodo * nodo){//Este nodo es el anterior
    int tipo = nodo->getTipoNodo(); //Nodo que va a generar un nuevo nodo
    int tipo_nuevo_nodo_generado = !tipo; //un nodo generado siempre es generado por uno de tipo opuesto

    //Fila y columna donde posiblemente se va a mover el próximo jugador.
    int p_jugador; //tipo de jugador que se va a mover
    int p_fila;
    int p_columna;
    int p_items;

    if(tipo_nuevo_nodo_generado == MAX)
        p_jugador = MIN; //cuando se genera un nuevo nodo, en este se va a mover un jugador de tipo contrario
    else
        p_jugador = MAX;

    int Fila_actual_jugador = getFilaColumna(nodo->getBoard(), p_jugador, 'f');
    int columna_actual_jugador = getFilaColumna(nodo->getBoard(), p_jugador, 'c');
    int items_actuales_jugador;
    if(p_jugador == MAX)
        items_actuales_jugador = nodo->getMaxItems();
    else
        items_actuales_jugador = nodo->getMinItems();

    bool resultado = false;
    switch (new_mov) {
    case 1: //Up right
        p_fila = Fila_actual_jugador-2;
        p_columna = columna_actual_jugador+1;
        if(p_fila >= 0 && p_columna < cols){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 2: //Up left
        p_fila = Fila_actual_jugador-2;
        p_columna = columna_actual_jugador-1;
        if(p_fila >= 0 && p_columna >= 0){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 3: //Right up
        p_fila = Fila_actual_jugador-1;
        p_columna = columna_actual_jugador+2;
        if(p_fila >= 0 && p_columna < cols){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 4: //Right down
        p_fila = Fila_actual_jugador+1;
        p_columna = columna_actual_jugador+2;
        if(p_fila < rows && p_columna < cols){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<p_fila<<"," << p_columna<<endl;
                resultado = true;
            }
        }
        break;
    case 5: //Down right
        p_fila = Fila_actual_jugador+2;
        p_columna = columna_actual_jugador+1;
        if(p_fila < rows && p_columna < cols){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 6: //Down left
        p_fila = Fila_actual_jugador+2;
        p_columna = columna_actual_jugador-1;
        if(p_fila < rows && p_columna >= 0){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 7: //Left up
        p_fila = Fila_actual_jugador-1;
        p_columna = columna_actual_jugador-2;
        if(p_fila >= 0 && p_columna >= 0){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    case 8: //Left down
        p_fila = Fila_actual_jugador+1;
        p_columna = columna_actual_jugador-2;
        if(p_fila < rows && p_columna >= 0){
            if(nodo->getBoard()[p_fila][p_columna] == 5){
                p_items = 1;
            }else{
                p_items = 0;
            }
            p_items = p_items + items_actuales_jugador;
            if(nodo->getBoard()[p_fila][p_columna] != !p_jugador && !verificarNodoEnRama(nodo, p_jugador, p_fila, p_columna, p_items)){
                //cout<<"llega: envía para el mov: "<< new_mov<<endl;
                resultado = true;
            }
        }
        break;
    default:
        break;
    }
    return resultado;
}

int MinMax::getFilaColumna(int **board, int player, char foc){
    int resultado = -1000;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == player){
                if(foc == 'f'){
                    resultado = i;
                }else{
                    resultado = j;
                }
                break;
            }
        }
        if(resultado != -1000){
            break;
        }
    }
    if(resultado == -1000)
        cout << "Hay un movimiento inválido"<<endl;
    return resultado;
}




