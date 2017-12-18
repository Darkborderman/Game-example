#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1201, 871)),
    timer(new QTimer)
{
    ui->setupUi(this);
    //setup view screen and choose use which QgraphicsScene
    ui->graphicsView->setScene(scene);
    //spawn a item
    item = new QGraphicsPixmapItem(QPixmap(":/res/black_bullet.png"));
    //add to scene
    scene->addItem(item);
    item->setPos(200, 200);
    //setup timer, 10ms trigger 1 time
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_W:
        item->setPos(item->x(), item->y() - 10);
        break;
    case Qt::Key_S:
        item->setPos(item->x(), item->y() + 10);
        break;
    case Qt::Key_A:
        item->setPos(item->x() - 10, item->y());
        break;
    case Qt::Key_D:
        item->setPos(item->x() + 10, item->y());
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    //spawn a bullet when press mouse
    bullet *b = new bullet(item->x(),item->y());
    scene->addItem(b);
    //connect to timer, so it will call fly() each 10ms
    b->connect(timer, SIGNAL(timeout()),b,SLOT(fly()));
}


































