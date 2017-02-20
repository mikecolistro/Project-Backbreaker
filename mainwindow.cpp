#include "mainwindow.h"
#include "window.h"
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QSize>
#include <QLabel>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>

mainWindow::mainWindow(QWidget *parent) : QWidget(parent)
{


//setFixedSize(rec.width() - 200,rec.height() - 200);
setFixedSize(370,400);
qDebug() << width();
qDebug() << height();


/*
testButton = new QPushButton("Submit", this);
testButton->setGeometry(20,20,80,30);
testButton->setCheckable(true);
*/


Button1 = new QPushButton("Button1",this);
Button1->setGeometry(50,150,100,50);
Button2 = new QPushButton("Button2",this);
Button2->setGeometry(50,225,100,50);
Button3 = new QPushButton("Button3",this);
Button3->setGeometry(50,300,100,50);
Button4 = new QPushButton("Button4",this);
Button4->setGeometry(200,150,100,50);
Button5 = new QPushButton("Button5",this);
Button5->setGeometry(200,225,100,50);
Button6 = new QPushButton("Admin Settings",this);
Button6->setGeometry(200,300,100,50);
Button6->setEnabled(false);

//connect(testButton, SIGNAL (clicked(bool)), this, SLOT (slotButton2Clicked(bool)));

connect(Button1, SIGNAL (clicked(bool)), this, SLOT (Button1Clicked(bool)));
connect(Button2, SIGNAL (clicked(bool)), this, SLOT (Button2Clicked(bool)));
connect(Button3, SIGNAL (clicked(bool)), this, SLOT (Button3Clicked(bool)));
connect(Button4, SIGNAL (clicked(bool)), this, SLOT (Button4Clicked(bool)));
connect(Button5, SIGNAL (clicked(bool)), this, SLOT (Button5Clicked(bool)));
connect(Button6, SIGNAL (clicked(bool)), this, SLOT (Button6Clicked(bool)));


}

void mainWindow::Button1Clicked(bool checked)
{
    qDebug() << "Button 1 clicked";
}
void mainWindow::Button2Clicked(bool checked)
{
    qDebug() << "Button 2 clicked";
}
void mainWindow::Button3Clicked(bool checked)
{
    qDebug() << "Button 3 clicked";
}
void mainWindow::Button4Clicked(bool checked)
{
    qDebug() << "Button 4 clicked";
}
void mainWindow::Button5Clicked(bool checked)
{
    qDebug() << "Button 5 clicked";
}
void mainWindow::Button6Clicked(bool checked)
{
    qDebug() << "Button 6 clicked";
}

void mainWindow::setUser(std::string s){
loggedInUsername = QString::fromStdString(s);
qDebug() << loggedInUsername;

if (loggedInUsername == "admin"){
    Button6->setEnabled(true);
}else{
    Button6->setEnabled(false);
}
}
