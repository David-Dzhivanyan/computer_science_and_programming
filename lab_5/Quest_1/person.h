#ifndef PERSON_H
#define PERSON_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Person; }
QT_END_NAMESPACE

class Person : public QMainWindow
{
    Q_OBJECT

public:
    Person(QWidget *parent = nullptr);
    ~Person();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Person *ui;
};

class Pers {
private:
    QString name;
    QString familia;
    bool sex;
    bool work;
    bool study;
public:
    void setName(QString name){
        this->name = name;
    }
    void setFamilia(QString familia){
        this->familia = familia;
    }
    void setSex(bool sex){
        this->sex = sex;
    }
    void setWork(bool work){
        this->work = work;
    }
    void setStudy(bool study){
        this->study = study;
    }

    void printInfo(){
        qDebug() << this->name << " " << this->familia << " sex:" << this->sex << " work:" << this->work << " study:" << this->study << " ";

        QFile file("E:\\Project\\programming\\Lab_5\\person.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << "Name: " << this->name << "\n";
            stream << "Familia: " << this->familia << "\n";
            stream << "Sex: " << this->sex << "\n";
            stream << "Work: " << this->work << "\n";
            stream << "Study: " << this->study << "\n";
            file.close();
            //QMessageBox::information(this, "Сохранение", "Информация сохранена в файле person.txt");
        }
        else {
            //QMessageBox::critical(this, "Ошибка", "Не удалось сохранить информацию в файл");
        }
    }
};
#endif // PERSON_H
