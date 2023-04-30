#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(500,650);
    itsPaddle = new Paddle();
    itsBall = new Ball();
    itsTimer = new QTimer(this);
    itsKeysState = new QMap<int, bool>;
    start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "[DEBUG] Registered keyPressEvent: " << event->key() << Qt::endl;
    (*itsKeysState)[event->key()] = true;
    QWidget::keyPressEvent(event);
}

void Widget::keyReleaseEvent(QKeyEvent* event)
{
    qDebug() << "[DEBUG] Registered keyReleaseEvent: " << event->key() << Qt::endl;
    (*itsKeysState)[event->key()] = false;
    QWidget::keyReleaseEvent(event);
}

void Widget::handleControls()
{
    if((*itsKeysState)[Qt::Key_Left] && itsPaddle->getRect().x() > 1)
    {
        qDebug() << "[DEBUG] Key_left is true and itsPaddle is within boundaries" << Qt::endl;
        itsPaddle->setSpeed(-1);
    } else if ((*itsKeysState)[Qt::Key_Right] && (itsPaddle->getRect().x()+itsPaddle->getRect().width()) < 499)
    {
        qDebug() << "[DEBUG] Key_Right is true and itsPaddle is within boundaries" << Qt::endl;
        itsPaddle->setSpeed(1);
    } else
    {
        itsPaddle->setSpeed(0);
    }
}

void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter* painter = new QPainter(this);
    itsPaddle->draw(painter);
    delete painter;
}

void Widget::gameLoop()
{
    handleControls();
    update();
}

void Widget::start()
{
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    itsTimer->start(3);
}
