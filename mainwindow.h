#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>


class QPushButton;
class QLineEdit;
class Qsize;
class QLabel;
class QMessageBox;
class Qstring;

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = 0);


public slots:
    void setUser(std::string s);
signals:

private slots:
    void Button1Clicked(bool checked);
    void Button2Clicked(bool checked);
    void Button3Clicked(bool checked);
    void Button4Clicked(bool checked);
    void Button5Clicked(bool checked);
    void Button6Clicked(bool checked);

private:
    QPushButton *testButton;
    QString loggedInUsername;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
};



#endif // MAINWINDOW_H
