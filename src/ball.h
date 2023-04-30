#ifndef BALL_H
#define BALL_H

#include <QPainter>

class Ball
{
    int itsX;
    int itsY;
    int itsDiameter;
    int itsXSpeed;
    int itsYSpeed;
    QImage itsImage;
public:
    Ball();
    void setXSpeed(int aSpeed);
    void setYSpeed(int aSpeed);
    void calculatePosition();
    void draw(QPainter* aPainter);
    void reverseXSpeed();
    void reverseYSpeed();
    bool intersect(QRect anObstacle);
};

#endif // BALL_H
