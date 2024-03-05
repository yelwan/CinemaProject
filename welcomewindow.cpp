#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <qpixmap.h>
#include "login.h"
WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    QString strr= QString::number(age);
    QString newname= "hello " +  username + " " + strr;
    ui->setupUi(this);
    ui->adminhello->setText(newname);
    QPixmap pix("C:/Users/Yehia/OneDrive/Documents/CinemaProject/Ressoruces/cinemawelcome.png"); // my pc only read it this way, please change Yehia and OneDrive and DOCUMENTS with what you have
    int w= ui->imagelabel->width();
    int h= ui->imagelabel->height();
    ui->imagelabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logoutpushButton_clicked()
{
    hide();
    Login *log= new Login;
    log->show();

}

