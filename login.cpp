#include "login.h"
#include "ui_login.h"
#include "welcomewindow.h"
#include "Users.h"
#include "registerwindow.h"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
}


Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    QString passwordss = ui->passwordlabel->text();
    QString usernamess = ui->usernamelabel->text();
    bool found = false;
    for (int i = 0; i < 100; i++) {
        if (passwordss == passwords[i] && usernamess == usernames[i] && !passwordss.isEmpty() && !usernamess.isEmpty() ) {
            int aged = ages[i];
            hide();
            WelcomeWindow *welcomeWindow = new WelcomeWindow(usernamess, aged, this);
            welcomeWindow->show();
            found = true;
            break;
        }
    }
    if (!found) {
        ui->errorlabel->setVisible(true);
    }
}


void Login::on_Register_clicked()
{

    QString passwordss = ui->passwordlabel->text();
    QString usernamess = ui->usernamelabel->text();
    if (passwordss.isEmpty()&&usernamess.isEmpty()) {
     ui->errorlabel->setVisible(true);
    }
    else {
        hide();
        RegisterWindow * reg= new RegisterWindow(usernamess,passwordss,this);
        reg->show();
        return;
    }
}

