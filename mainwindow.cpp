#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include <QString>
#include <QLabel>
#include <iostream>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    m_thread = new DuThread(MILISECONDS,this);
    moviendose = false;
    m_thread->start();
    setComboBoxOptions();
    iniciarLogica(0);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(enableBtn()));
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(prepararTablero()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(iniciarPartida()));
    //Conexión para permitir el movimiento por el table mediante m_thread(timer)
    connect(m_thread, &DuThread::timeOut, this, [&](){
        recorridoMario(); //Configurar nuevo tablero gráfico para volverlo a pintar
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarLogica(int items){
    moviendose = false;
    minmax = new MinMax();
    rows = minmax->getRows();
    cols = minmax->getCols();
    if(items == 0){
        initTablero();
    }else{
        minmax->setItems(items);
        minmax->empezarPartida();
        matriz = minmax->getMatriz();
        paintTablero();
        ui->btn_1->setEnabled(false);
    }
}

void MainWindow::recorridoMario(){
    if(moviendose){
        if(mov > 0){
        }
        if(mov<=0){
            moviendose = false;  //Variable que controla el timmer para que no anime el tablero
        }
    }
}

void MainWindow::initTablero(){
    QString name = "label_";
    int x=40, y=100;
    int count_background;
    QString color1, color2;
    for(int i=0; i<rows; i++){
        count_background = 0;
        if(i%2 == 0){
            color1 = "QPushButton{border:1px solid black; background:#086A87}";
            color2 = "QPushButton{border:1px solid black; background:#D8D8D8}";
        }else{
            color1 = "QPushButton{border:1px solid black; background:#D8D8D8}";
            color2 = "QPushButton{border:1px solid black; background:#086A87}";
        }
        for(int j=0; j<cols; j++){
            name = name+QString::number(i)+QString::number(j);
            QPushButton *button = new QPushButton();
            button->setObjectName(name);
            button->setParent(this);
            button->setGeometry(x,y,100,90);
            if(count_background%2 == 0)
                button->setStyleSheet(color1);
            else
                button->setStyleSheet(color2);
            x += 100;
            name = "label_";
            count_background++;
        }
        x=40;
        y+=90;
    }
}

void MainWindow::reiniciarTablero(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matriz[i][j] = -1;
        }
    }
    paintTablero();
}

void MainWindow::paintTablero(){
    QString name = "label_";
    QString path= "/Users/diegoruiz/Documents/ProyectoIA1/ProyectoIA1/images/";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            name = name+QString::number(i)+QString::number(j);
            T[i][j] = this->findChild<QPushButton *>(name);
            connect(T[i][j],SIGNAL(clicked(bool)),this,SLOT(pulsaBoton()));
            switch(matriz[i][j]){
            /*case -1:
                //path += path+"none.png";
                T[i][j]->setText("N/A");
                break;*/
            case 1:
                path = path+"chess-white.png";
                break;
            case 0:
                path = path+"chess-black.png";
                break;
            case 5:
                path = path+"fruit.png";
                break;
            default:
                break;
            }
            QPixmap buttonImage(path);
            QIcon Icon;
            Icon.addPixmap ( buttonImage, QIcon::Normal, QIcon::Off );
            T[i][j]->setIcon(Icon);
            T[i][j]->setIconSize(QSize(90,85));
            name = "label_";
            path = "/Users/diegoruiz/Documents/ProyectoIA1/ProyectoIA1/images/";
        }
    }
}

void MainWindow::prepararTablero(){
    if(ui->btn_1->text() == "Reiniciar"){
        ui->btn_1->setText("Iniciar");
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox->setEnabled(true);
        ui->btn_1->setEnabled(false);
        ui->btn_2->setEnabled(false);
        ui->lb_num_exp->setText("0");
        ui->lb_num_arbol->setText("0");
        ui->lb_num_time->setText("");
        reiniciarTablero();
        iniciarLogica(0);
    }else{
        ui->btn_1->setText("Reiniciar");
        iniciarLogica(ui->comboBox->itemText(ui->comboBox->currentIndex()).toInt());
        ui->comboBox->setEnabled(false);
        ui->btn_2->setEnabled(true);
    }
}

void MainWindow::iniciarPartida(){
    ui->btn_2->setEnabled(false);
    ui->btn_1->setEnabled(true);
    minmax->setItems(ui->comboBox->itemText(ui->comboBox->currentIndex()).toInt());
    minmax->jugadaMaquina();
    matriz = minmax->getMatriz();
    paintTablero();
}

void MainWindow::setComboBoxOptions(){
    ui->comboBox->clear();
    QString s = "Seleccione";
    ui->comboBox->addItem(s);
    s = "1";
    ui->comboBox->addItem(s);
    s = "3";
    ui->comboBox->addItem(s);
    s = "5";
    ui->comboBox->addItem(s);
    ui->comboBox->setCurrentIndex(0);
    ui->btn_1->setEnabled(false);
    ui->btn_2->setEnabled(false);
    ui->comboBox->setEnabled(true);
}

void MainWindow::enableBtn(){
    ui->btn_1->setEnabled(true);
}

void MainWindow::pulsaBoton(){
    QObject* btn = sender();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(T[i][j] == btn){
                minmax->pulsaBoton(i,j);
                minmax->getMatriz();
                paintTablero();
                int nGanador = minmax->getGanador();
                int jugador_items = minmax->getItemsJ2();
                int maquina_items = minmax->getItemsJ1();
                ui->lb_num_exp->setText(QString::number(maquina_items));
                ui->lb_num_arbol->setText(QString::number(jugador_items));
                if(nGanador == 0){
                    ui->lb_num_time->setText("Ganaste");
                }else if(nGanador == 1){
                    ui->lb_num_time->setText("Perdiste");
                }
            }
        }
    }
}

