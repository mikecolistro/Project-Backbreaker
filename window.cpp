#include "window.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QSize>
#include <QLabel>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>


Window::Window(QWidget *parent) : QWidget(parent)
{
 mainWindow mainWin;
 mainWin.hide();
 rec   = QApplication::desktop()->screenGeometry();
 logoLabel = new QLabel(this);
 pix = QPixmap("C:/Users/mike_/Documents/FirstQTProject/eaglesLogo.jpg");

 logoLabel->setPixmap(pix);

//logoLabel->show();
//logoLabel->setText("Test");

 db = QSqlDatabase::addDatabase("QMYSQL");
 db.setHostName("50.62.209.147");
 db.setDatabaseName("testMySql");
 db.setUserName("mikecolistro");
 db.setPort(3306);
 db.setPassword("Danny2013");
     if(!db.open())
     {
        qDebug()<<("Failed to open Database"+ db.lastError().text());

     }
     else
     {
         qDebug()<<("Connected.....");

     }


//setFixedSize(rec.width() - 200,rec.height() - 200);
setFixedSize(370,400);
qDebug() << width();
qDebug() << height();
winWidth = width();
winHeight = height();



username = new QLineEdit(this);
username->setPlaceholderText("Enter Username Here");
username->setGeometry((winWidth/2) - 55,(winHeight/2),200,20);

password = new QLineEdit(this);
password->setPlaceholderText("Enter Password Here");
password->setGeometry(username->x(),username->y() + 20,200,20);
password->setEchoMode(QLineEdit::Password);

m_button = new QPushButton("Submit", this);
m_button->setGeometry(password->x()+password->width()/2-60,password->y() + 20,80,30);
m_button->setCheckable(true);
m_button->autoDefault();
m_button->setAutoDefault(true);




usernameLabel = new QLabel(this);
usernameLabel->setText("Username:");
usernameLabel->setGeometry(username->x()-70,username->y(),80,20);

passwordLabel = new QLabel(this);
passwordLabel->setText("Password:");
passwordLabel->setGeometry(password->x()-70,password->y(),80,20);

m_counter = 0;

connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
 connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));

 //connect(password,SIGNAL("returnPressed()"),slotButtonClick(bool));
 
}
void Window::slotButtonClicked(bool checked)
{
  QSqlQuery query;
  testValue = "FailedPassword";
  idnum = username->text();
  query.prepare("select password from users where username = :val");
  query.bindValue(":val",idnum);
  query.exec();
  qDebug() << query.size();
  popup = new QMessageBox (this);


  if(query.size() == 1){
     query.first();
     testValue = query.value(0).toString();
     qDebug() << "username matches";
  }else if (query.size() == -1){
      qDebug() << "-1 size";
      testValue = "Username not found!";
      popup->setText(testValue);
      popup->show();
      return;
  }else{
      qDebug() << "To many returns";
      testValue = "Username not found!";
      popup->setText(testValue);
      popup->show();
      return;
  }


  if(testValue == password->text()){
      //set Flag and whatever
      qDebug() << "Success";
      qDebug() << password->text();
      qDebug() << testValue;
       testValue = username->text();
       mainWin.setUser(testValue.toStdString());
       mainWin.show();


      this->hide();
  }else{
      popup->setText("Username or password is incorrect");
      popup->show();
      return;
  }

}
