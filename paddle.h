#ifndef PADDLE_H
#define PADDLE_H

#include <QPainter>

class Paddle
{
    int itsWidth = 100;
    int itsHeight = 20;
    int itsX = 500/2-itsWidth/2;
    int itsY = 650-10-itsHeight;
    int itsSpeed = 0;
    std::vector<QRect *> itsRects;
public:
    Paddle();
    void setSpeed(int aSpeed);
    void calculatePosition();
    void draw(QPainter* aPainter);
    QRect getRect();
};

#endif // PADDLE_H
