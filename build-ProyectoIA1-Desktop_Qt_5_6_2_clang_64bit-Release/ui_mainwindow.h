/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioncerrar;
    QWidget *centralWidget;
    QPushButton *btn_1;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *lb_titulo_exp;
    QLabel *lb_titulo_prof;
    QLabel *lb_titulo_time;
    QLabel *lb_num_exp;
    QLabel *lb_num_arbol;
    QLabel *lb_num_time;
    QPushButton *btn_2;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(681, 657);
        MainWindow->setMinimumSize(QSize(663, 0));
        actioncerrar = new QAction(MainWindow);
        actioncerrar->setObjectName(QStringLiteral("actioncerrar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        btn_1 = new QPushButton(centralWidget);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setEnabled(true);
        btn_1->setGeometry(QRect(260, 0, 131, 31));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 30, 211, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 201, 17));
        lb_titulo_exp = new QLabel(centralWidget);
        lb_titulo_exp->setObjectName(QStringLiteral("lb_titulo_exp"));
        lb_titulo_exp->setGeometry(QRect(440, 10, 151, 17));
        lb_titulo_prof = new QLabel(centralWidget);
        lb_titulo_prof->setObjectName(QStringLiteral("lb_titulo_prof"));
        lb_titulo_prof->setGeometry(QRect(440, 30, 151, 17));
        lb_titulo_time = new QLabel(centralWidget);
        lb_titulo_time->setObjectName(QStringLiteral("lb_titulo_time"));
        lb_titulo_time->setEnabled(true);
        lb_titulo_time->setGeometry(QRect(440, 50, 151, 20));
        lb_num_exp = new QLabel(centralWidget);
        lb_num_exp->setObjectName(QStringLiteral("lb_num_exp"));
        lb_num_exp->setGeometry(QRect(600, 10, 81, 17));
        lb_num_arbol = new QLabel(centralWidget);
        lb_num_arbol->setObjectName(QStringLiteral("lb_num_arbol"));
        lb_num_arbol->setGeometry(QRect(600, 30, 81, 17));
        lb_num_time = new QLabel(centralWidget);
        lb_num_time->setObjectName(QStringLiteral("lb_num_time"));
        lb_num_time->setGeometry(QRect(600, 50, 81, 17));
        btn_2 = new QPushButton(centralWidget);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setEnabled(true);
        btn_2->setGeometry(QRect(260, 40, 131, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 681, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(btn_1, comboBox);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actioncerrar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actioncerrar->setText(QApplication::translate("MainWindow", "cerrar", 0));
        btn_1->setText(QApplication::translate("MainWindow", "Activar Tablero", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Seleccione", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "N\303\272mero de items", 0));
        lb_titulo_exp->setText(QApplication::translate("MainWindow", "Items M\303\241quina:", 0));
        lb_titulo_prof->setText(QApplication::translate("MainWindow", "Items Jugador:", 0));
        lb_titulo_time->setText(QApplication::translate("MainWindow", "Marcador: ", 0));
        lb_num_exp->setText(QApplication::translate("MainWindow", "0", 0));
        lb_num_arbol->setText(QApplication::translate("MainWindow", "0", 0));
        lb_num_time->setText(QApplication::translate("MainWindow", "0", 0));
        btn_2->setText(QApplication::translate("MainWindow", "Iniciar Partida", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
