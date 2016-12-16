#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMessageBox>

#include "snake.h"
#include "apple.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *k);

private slots:

    void update();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *mainScene;
    QTimer gameTimer;

    Snake *snake;
    Apple *apple;

    int score = 0;

    void draw();


};

#endif // MAINWINDOW_H
