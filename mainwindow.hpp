#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <vector>
#include "duthread.hpp"
#include "minmax.hpp"

#define MILISECONDS 250

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void iniciarLogica(int items);
    void initTablero();
    void connectLabelsBoard();
    void reiniciarTablero();
    void paintTablero();
    void recorridoMario();
    void moverCaballo1();
    void moverCaballo2();
    void repaint();

signals:

private slots:
    void prepararTablero();
    void setComboBoxOptions();
    void enableBtn();
    void pulsaBoton();
    void iniciarPartida();


private:
    Ui::MainWindow *ui;
    int rows;
    int cols;
    int mov;
    QHBoxLayout *vbl;
    QPushButton *T[6][6];
    MinMax *minmax;
    int ** matriz;
    int ** matriz_original;
    DuThread *m_thread;
    vector<vector<int>> ruta;
    bool flor, moviendose;
};

#endif // MAINWINDOW_HPP
