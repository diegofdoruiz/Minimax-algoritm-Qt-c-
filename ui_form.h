/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *lb_titulo_exp;
    QLabel *label_2;
    QPushButton *btn_1;
    QComboBox *comboBox;
    QPushButton *btn_2;
    QLabel *lb_titulo_time;
    QLabel *lb_titulo_prof;
    QLabel *lb_num_time;
    QLabel *lb_num_arbol;
    QLabel *lb_num_exp;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(674, 506);
        lb_titulo_exp = new QLabel(Form);
        lb_titulo_exp->setObjectName(QStringLiteral("lb_titulo_exp"));
        lb_titulo_exp->setGeometry(QRect(480, 40, 151, 17));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 40, 201, 17));
        btn_1 = new QPushButton(Form);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setEnabled(true);
        btn_1->setGeometry(QRect(300, 30, 131, 31));
        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 60, 211, 41));
        btn_2 = new QPushButton(Form);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setEnabled(true);
        btn_2->setGeometry(QRect(300, 60, 131, 41));
        lb_titulo_time = new QLabel(Form);
        lb_titulo_time->setObjectName(QStringLiteral("lb_titulo_time"));
        lb_titulo_time->setEnabled(true);
        lb_titulo_time->setGeometry(QRect(480, 80, 151, 20));
        lb_titulo_prof = new QLabel(Form);
        lb_titulo_prof->setObjectName(QStringLiteral("lb_titulo_prof"));
        lb_titulo_prof->setGeometry(QRect(480, 60, 151, 17));
        lb_num_time = new QLabel(Form);
        lb_num_time->setObjectName(QStringLiteral("lb_num_time"));
        lb_num_time->setGeometry(QRect(640, 80, 81, 17));
        lb_num_arbol = new QLabel(Form);
        lb_num_arbol->setObjectName(QStringLiteral("lb_num_arbol"));
        lb_num_arbol->setGeometry(QRect(640, 60, 81, 17));
        lb_num_exp = new QLabel(Form);
        lb_num_exp->setObjectName(QStringLiteral("lb_num_exp"));
        lb_num_exp->setGeometry(QRect(640, 40, 81, 17));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        lb_titulo_exp->setText(QApplication::translate("Form", "Items M\303\241quina:", 0));
        label_2->setText(QApplication::translate("Form", "N\303\272mero de items", 0));
        btn_1->setText(QApplication::translate("Form", "Activar Tablero", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "Seleccione", 0)
        );
        btn_2->setText(QApplication::translate("Form", "Iniciar Partida", 0));
        lb_titulo_time->setText(QApplication::translate("Form", "Marcador: ", 0));
        lb_titulo_prof->setText(QApplication::translate("Form", "Items Jugador:", 0));
        lb_num_time->setText(QApplication::translate("Form", "0", 0));
        lb_num_arbol->setText(QApplication::translate("Form", "0", 0));
        lb_num_exp->setText(QApplication::translate("Form", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
