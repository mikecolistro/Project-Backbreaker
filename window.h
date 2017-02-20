#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtSql>
#include "mainwindow.h"

class QPushButton;
class QLineEdit;
class Qsize;
class QLabel;
class QMessageBox;
class mainWindow;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    QSqlDatabase db;
signals:
    void counterReached();
private slots:
    void slotButtonClicked(bool checked);
private:
    int m_counter;
    int winHeight;
    int winWidth;
    QString testValue;
    QPushButton *m_button;
    QRect rec;
    QLineEdit *username;
    QLineEdit *password;
    Qsize *size;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *logoLabel;
    QPixmap pix;
    QMessageBox *popup;
    QString idnum;
    mainWindow mainWin;

};


#endif // WINDOW_H
