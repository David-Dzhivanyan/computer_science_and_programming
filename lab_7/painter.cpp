#include "painter.h"
#include "ui_painter.h"

Painter::Painter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Painter)
{
    ui->setupUi(this);
}

Painter::~Painter()
{
    delete ui;
}

void Painter::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);

    QPen pen_green, pen_purple, pen_orenge;
    pen_green.setColor(QColor(0,255,0));
    pen_green.setWidth(3);
    pen_purple.setColor(QColor(192,0,255));
    pen_purple.setWidth(3);
    pen_orenge.setColor(QColor(255,132,0));
    pen_orenge.setWidth(3);

    painter.setPen(pen_green);
    painter.drawRect(10,10,360,300);
    painter.setPen(pen_purple);
    painter.drawEllipse(10,145,360,30);
    painter.setPen(pen_orenge);
    painter.drawEllipse(180,10,30,300);

    painter.end();
}

