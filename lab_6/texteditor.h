#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include "closewindow.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);

    void setFile_path(QString file_path){
        this->file_path = file_path;
    }
    QString getFile_path(){
        return this->file_path;
    }
    ~TextEditor();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_pushButton_clicked();

    void on_actionClose_triggered();

    void on_pushButton_2_clicked();

public slots:
    void slot();


protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    QString file_path;
    Ui::TextEditor *ui;
    CloseWindow *close;

};
#endif // TEXTEDITOR_H
