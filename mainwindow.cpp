#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(402, 402);

    mainScene = new QGraphicsScene();

    mainScene->setSceneRect(0, 0, 400, 400);

    ui->graphicsView->setScene(mainScene);

    snake = new Snake;
    apple = new Apple;


    gameTimer.setInterval(200);

    connect(&gameTimer, SIGNAL(timeout()), this, SLOT(update()));

    gameTimer.start();

    draw();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if (snake->checkCollisions()) {
        gameTimer.stop();
        QMessageBox msgBox;
        msgBox.setText("GAME OVER!!!");
        msgBox.exec();
    }

    if (snake->eat(apple)) {
        delete apple;
        apple = new Apple;
        score++;

    } else snake->move();

    mainScene->clear();

    draw();
}

void MainWindow::draw()
{
    mainScene->addRect(apple->x *20, apple->y *20, 20, 20, QPen(Qt::black), QBrush(Qt::red, Qt::SolidPattern));

    for (int i = 0; i < snake->cellList.size(); i++){
        mainScene->addRect(snake->cellList[i].x * 20, snake->cellList[i].y * 20, 20, 20, QPen(Qt::black), QBrush(Qt::green, Qt::SolidPattern));
    }

    QString scoreLabel = "SCORE : " + QString::number(score);
    mainScene->addText(scoreLabel, QFont("ARIAL", 10, QFont::Normal));
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch (k->key()) {
    case Qt::Key_A:
        if (snake->direction != RIGHT)snake->direction = LEFT;
        break;

    case Qt::Key_W:
        if (snake->direction != DOWN) snake->direction = TOP;
        break;

    case Qt::Key_D:
        if (snake->direction != LEFT) snake->direction = RIGHT;
        break;

    case Qt::Key_S:
        if (snake->direction != TOP) snake->direction = DOWN;
        break;

    case Qt::Key_Escape:
        this->close();
        break;

    default:
        break;
    }
}
