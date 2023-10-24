#ifndef PAINTER_H
#define PAINTER_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Painter; }
QT_END_NAMESPACE

class Painter : public QMainWindow
{
    Q_OBJECT

public:
    Painter(QWidget *parent = nullptr);
    ~Painter();

private:
    Ui::Painter *ui;

protected:
    void paintEvent(QPaintEvent *e) override;
};
#endif // PAINTER_H
