#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QTimerEvent>
#include "ball.h"
#include "paddle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    Ui::Widget *ui;
    Ball* itsBall;
    Paddle* itsPaddle;
    QTimer* itsTimer;
    QMap<int, bool>* itsKeysState;
    void handleControls();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent* event);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void gameLoop();
    void start();
};
#endif // WIDGET_H
