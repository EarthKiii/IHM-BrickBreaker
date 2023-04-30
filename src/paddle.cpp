#include "paddle.h"
#include <QDebug>

Paddle::Paddle()
{
    calculatePosition();
}

void Paddle::calculatePosition()
{
    std::vector<QRect* >::iterator it;
    it = itsRects.begin();
    int safeX = (itsX += itsSpeed);
    itsRects.insert(it, new QRect(safeX, itsY, itsWidth, itsHeight));
}

void Paddle::draw(QPainter* aPainter)
{
    QColor paddleColor = QColor(Qt::blue);
    paddleColor.setAlpha(15);
    for (QRect * rect: itsRects)
    {
        aPainter->setBrush(paddleColor);
        aPainter->setPen(Qt::NoPen);
        aPainter->drawRect(*rect);
    }
    if (itsRects.size() >= 15)
    {
        itsRects.pop_back();
    }
    calculatePosition();
    paddleColor.setAlpha(255);
    aPainter->setBrush(paddleColor);
    aPainter->setPen(Qt::NoPen);
    aPainter->drawRect(*itsRects[0]);
}

void Paddle::setSpeed(int aSpeed)
{
    itsSpeed = aSpeed;
    qDebug() << "Paddle's speed :" << itsSpeed << Qt::endl;
}

QRect Paddle::getRect()
{
    return *itsRects[0];
}
