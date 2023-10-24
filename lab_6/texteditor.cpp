#include "texteditor.h"
#include "closewindow.h"
#include "ui_texteditor.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionOpen_triggered()
{
    ui->statusbar->showMessage("Open");
    QString file_open = QFileDialog::getOpenFileName(this,"enter file", QDir::currentPath(), "*.txt");

    QFile file(file_open);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray text = file.readAll();

        this->setFile_path(file_open);

        qDebug() << this->getFile_path();

        ui->textEdit->setText(QString::fromUtf8(text));
        file.close();
    }
    else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
    }
}


void TextEditor::on_actionSave_triggered()
{
    ui->statusbar->showMessage("Save");
    if(this->file_path == ""){
        this->on_actionSave_as_triggered();
    } else{
        QFile file(getFile_path());

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();

            this->setFile_path(getFile_path());

            file.close();
        }
        else {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        }
    }
}


void TextEditor::on_actionSave_as_triggered()
{
    QString file_open = QFileDialog::getOpenFileName(this,"enter file", QDir::currentPath(), "*.txt");
    QFile file(file_open);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();

        this->setFile_path(file_open);

        qDebug() << this->getFile_path();

        file.close();
    }
    else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
    }

    ui->statusbar->showMessage("Save as...");
}


void TextEditor::on_pushButton_clicked()
{
    this->on_actionSave_triggered();
}


void TextEditor::on_actionClose_triggered()
{
    close = new CloseWindow;
    close->show();

    connect(close, &CloseWindow::signal, this, &TextEditor::slot);
}


void TextEditor::on_pushButton_2_clicked()
{
    this->on_actionClose_triggered();
}

void TextEditor::slot()
{
    this->on_actionSave_triggered();
}

void TextEditor::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        this->on_actionClose_triggered();
    }

    if(e->key() == Qt::Key_S && e->modifiers() == Qt::ControlModifier){
        this->on_actionSave_triggered();
    }
}

