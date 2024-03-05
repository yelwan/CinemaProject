#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QString userl, QString passwordl, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->usernamelinedit->setText(userl);
    ui->passwordeditline->setText(passwordl);
    ui->alreadyexistingerrorlabel->setVisible(false);
    ui->notmatchingerrorlabel->setVisible(false);
    ui->agelesstan12errorlabel->setVisible(false);
    ui->fieldsnotfielderrorlabel->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterpushButton_clicked()
{
    ui->alreadyexistingerrorlabel->setVisible(false);
    ui->notmatchingerrorlabel->setVisible(false);
    ui->agelesstan12errorlabel->setVisible(false);
    ui->fieldsnotfielderrorlabel->setVisible(false);
    QString user= ui->usernamelinedit->text();
    QString password= ui->passwordeditline->text();
    QString retypePassword= ui->lineEditRetypePassword->text();
    QString chosencombo= ui->monthcombobox->currentText();
    bool mradiobutton= ui->maleradiobutton->isChecked();
    bool fradiobutton= ui->femaleradioButton->isChecked();
    bool uradiobutton= ui->UserradioButton->isChecked();
    bool aradiobutton= ui->adminradioButton->isChecked();
    bool acheckbox= ui->actioncheckBox->isChecked();
    bool ccheckbox= ui->comedycheckBox->isChecked();
    bool rcheckbox= ui->romancecheckBox->isChecked();
    bool dcheckbox= ui->DramacheckBox->isChecked();
    bool hcheckbox= ui->horrorcheckBox->isChecked();
    bool ocheckbox= ui->othercheckBox->isChecked();
    QString agess  = ui->yearlineedit->text();
    QString days= ui->daylineedit->text();
    int age= agess.toInt();
    if (user.isEmpty() || password.isEmpty() || retypePassword.isEmpty() || chosencombo.isEmpty() || agess.isEmpty() || days.isEmpty() || (!mradiobutton && !fradiobutton && !uradiobutton && !aradiobutton) || (!acheckbox && !ccheckbox && !rcheckbox && !dcheckbox && !hcheckbox && !ocheckbox)) {
        ui->fieldsnotfielderrorlabel->setVisible(true);
        return;
    }

    if (password != retypePassword) {
        ui->notmatchingerrorlabel->setVisible(true);
        return;
    }
    if ((2024-age)<12) {
        ui->agelesstan12errorlabel->setVisible(true);
        return;
    }
    int j = 0;
    usernames[j] = user;
    passwords[j] = password;
    ages[j] = age;
    j++;
    hide();
    WelcomeWindow *welcomeWindow = new WelcomeWindow(user, age, this);
    welcomeWindow->show();
}
