#include "closewindow.h"
#include "ui_closewindow.h"
#include "texteditor.h"

CloseWindow::CloseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloseWindow)
{
    ui->setupUi(this);
}

CloseWindow::~CloseWindow()
{
    delete ui;
}

void CloseWindow::on_pushButton_3_clicked()
{
    close();
}


void CloseWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}


void CloseWindow::on_pushButton_clicked()
{
    emit signal();
}

