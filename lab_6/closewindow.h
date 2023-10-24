#ifndef CLOSEWINDOW_H
#define CLOSEWINDOW_H

#include <QDialog>

namespace Ui {
class CloseWindow;
}

class CloseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CloseWindow(QWidget *parent = nullptr);
    ~CloseWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CloseWindow *ui;

signals:
    void signal();
};

#endif // CLOSEWINDOW_H
