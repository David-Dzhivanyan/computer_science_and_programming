#include "person.h"
#include "ui_person.h"
#include <QDebug>

Person::Person(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Person)
{
    ui->setupUi(this);
}

Person::~Person()
{
    delete ui;
}


void Person::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}


void Person::on_pushButton_clicked()
{
    Pers person;
    QString familia = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    bool sex = ui->radioButton->isChecked();
    bool work = ui->checkBox_2->isChecked();
    bool study = ui->checkBox->isChecked();

    person.setName(name);
    person.setFamilia(familia);
    person.setSex(sex);
    person.setWork(work);
    person.setStudy(study);
    person.printInfo();
}

