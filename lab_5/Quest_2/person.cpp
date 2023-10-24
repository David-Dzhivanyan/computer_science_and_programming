#include "person.h"
#include "ui_person.h"
#include <QDebug>

Person::Person(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Person)
{
    ui->setupUi(this);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
}

Person::~Person()
{
    delete ui;
}


void Person::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}


void Person::on_pushButton_clicked()
{
    Pers person;
    QString familia = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    int series = ui->lineEdit_3->text().toInt();
    int number = ui->lineEdit_4->text().toInt();
    bool sex = ui->radioButton->isChecked();
    bool work = ui->checkBox_2->isChecked();
    bool study = ui->checkBox->isChecked();

    bool flag_s = true;
    bool flag_n = true;

    if(series <= 1000 || series > 10000){
        flag_s = false;
    }

    if(number <= 100000 || number > 1000000){
        flag_n = false;
    }
    if(flag_s && flag_n){
        person.setName(name);
        person.setFamilia(familia);
        person.setSeries(series);
        person.setNumber(number);
        person.setSex(sex);
        person.setWork(work);
        person.setStudy(study);
        person.printInfo();
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
    }else {
        if(!flag_s){
            ui->label_5->setVisible(true);
        } else{
            ui->label_5->setVisible(false);
        }
        if(!flag_n){
            ui->label_6->setVisible(true);
        }else{
            ui->label_6->setVisible(false);
        }
    }
}

