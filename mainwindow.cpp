
#include "mainwindow.h"
//#include "./ui_mainwindow.h"
QString value = "", total = "";
int fNum, sNum;

bool addBool = false, subtractBool = false, multiplyBool = false, divideBool = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    label = new QLabel("0", this);
    label->setGeometry(QRect(QPoint(75,25), QSize(50, 200)));



    /*clearBtn = new QPushButton("C ", this);

    clearBtn->setGeometry(QRect(QPoint(125,300),QSize(50,50)));

    connect(clearBtn,SIGNAL(released()), this,SLOT(clear()));

    addBtn = new QPushButton(" + ", this);
    addBtn->setGeometry(QRect(QPoint(225,150),QSize(50,50)));
    connect(addBtn,SIGNAL(released()), this,SLOT(add()));

    subtractBtn = new QPushButton(" - ", this);
    subtractBtn->setGeometry(QRect(QPoint(225,200),QSize(50,50)));
    connect(subtractBtn,SIGNAL(released()), this,SLOT(subtract()));

    multiplyBtn = new QPushButton(" X ", this);
    multiplyBtn->setGeometry(QRect(QPoint(225,250),QSize(50,50)));
    connect(multiplyBtn,SIGNAL(released()), this,SLOT(multiply()));

    divideBtn = new QPushButton(" ÷ ", this);
    divideBtn->setGeometry(QRect(QPoint(225,300),QSize(50,50)));
    connect(divideBtn,SIGNAL(released()), this,SLOT(divide()));

    equalsBtn = new QPushButton(" = ", this);
    equalsBtn->setGeometry(QRect(QPoint(175,300),QSize(50,50)));
    connect(equalsBtn,SIGNAL(released()), this,SLOT(equals()));*/
    for(int i = 0; i < 6; i++)
    {
        QString operations[] = {"C","-","+","X","÷","="};
        operationButton[i] = new QPushButton(operations[i], this);
        if(i == 5 )
        {
             connect(operationButton[i], SIGNAL(released()), this, SLOT(equals()));
        } else{
             connect(operationButton[i], SIGNAL(released()), this, SLOT(operationPushed()));}
    }

    for(int i = 0; i < 10; i++)
    {
        QString digit = QString::number(i);
        buttons[i] = new QPushButton(digit, this);
        connect(buttons[i], SIGNAL(released()), this, SLOT(btnPushed()));
    }
    setGeo();


}

MainWindow::~MainWindow()
{
}

void MainWindow::operationPushed()
{
    QPushButton *btn = (QPushButton *)sender();
    fNum = value.toInt();
    if( btn->text()== "C")
    {
        value = " ";
        fNum = 0;
        sNum = 0;
    }
    if( btn->text()== "+")
    {
        addBool = true;
    }
    if( btn->text()== "-")
    {
        subtractBool = true;
    }
    if(btn->text() == "X")
    {
        multiplyBool = true;
    }
    if( btn->text() == "÷")
    {
        divideBool = true;
    }
    value = "";
    label->setText(value);
    //addBool = true;
}

/*void MainWindow::clear()
{
    value = "";
    label->setText(value);
}

void MainWindow::add()
{

}

void MainWindow::subtract()
{
    fNum = value.toInt();
    value = "";
    label->setText(value);
    subtractBool = true;
}

void MainWindow::divide()
{
    fNum = value.toInt();
    value = "";
    label->setText(value);
    divideBool = true;
}

void MainWindow::multiply()
{
    fNum = value.toInt();
    value = "";
    label->setText(value);
    multiplyBool = true;
}
*/
void MainWindow::equals()
{
    sNum = value.toInt();
    if(addBool){
        total =QString::number( fNum + sNum );
        label->setText(total);
        addBool = false;
    }
    if(subtractBool)
    {
        total =QString::number( fNum - sNum );
        label->setText(total);
        subtractBool = false;
    }
    if(divideBool)
    {
        total =QString::number( fNum / sNum );
        label->setText(total);
        divideBool = false;
    }
    if(multiplyBool)
    {
        total =QString::number( fNum * sNum );
        label->setText(total);
        multiplyBool = false;
    }

    fNum = 0;
    sNum = 0;
    value = "";
    total = "";
}

void MainWindow::btnPushed()
{
    QPushButton *btn = (QPushButton *)sender();
    emit numberEmitted(btn->text()[0].digitValue());
    value += QString::number(btn->text()[0].digitValue());
    label->setText(value);
}

void MainWindow::setGeo()
{
    for(int i = 0; i <1; i++)
    {
        buttons[i] ->setGeometry(QRect(QPoint(50,300), QSize(50,50)));
        operationButton[i] ->setGeometry(QRect(QPoint(100,300), QSize(50,50)));
        operationButton[i + 1] ->setGeometry(QRect(QPoint(150,300), QSize(50,50)));
        operationButton[i + 2 ] ->setGeometry(QRect(QPoint(200,300), QSize(50,50)));
    }
    for(int i = 1; i <4; i++)
    {
        buttons[i] ->setGeometry(QRect(QPoint(50*i,250), QSize(50,50)));
        if(i == 3){
        operationButton[i] ->setGeometry(QRect(QPoint(200,250), QSize(50,50)));
        }
    }
    for(int i = 4; i <7; i++)
    {
        buttons[i] ->setGeometry(QRect(QPoint(50*(i-3),200), QSize(50,50)));
        if(i == 4){
        operationButton[i] ->setGeometry(QRect(QPoint(200,200), QSize(50,50)));
        }
    }
    for(int i = 7; i <10; i++)
    {
        buttons[i] ->setGeometry(QRect(QPoint(50*(i-6),150), QSize(50,50)));
        if(i == 7){
        operationButton[i - 2] ->setGeometry(QRect(QPoint(200,150), QSize(50,50)));
        }
    }

}


