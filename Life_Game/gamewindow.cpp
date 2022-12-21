#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include "logic.h"
#include <QThread>


class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


const int pixelSize = 15;


Field* createBackEnd(int W, int H)
{
    char x[1] = { 3 };
    std::vector<char> born(x, x + sizeof x / sizeof x[0]);
    char y[2] = { 2, 3 };
    std::vector<char> survive(y, y + sizeof y / sizeof x[0]);
    Rules *rules = new Rules(born, survive);
    Field *field = new Field(W, H, rules);
    return field;
}


void GameWindow::createLayout(int x_count, int y_count)
{
    QPixmap pix(":/pics/pics/cell_dead.png");

    QGridLayout* gridlayout = this->ui->gridLayout;
    gridlayout->maximumSize().setWidth(200);
    gridlayout->setSizeConstraint(QLayout::SetMaximumSize);
    QVector<QVector<QLabel*>> labels2DVector(y_count);
    for (int i = 0; i < y_count; i++){
        labels2DVector[i].resize(x_count);
        for(int j = 0; j < x_count; j++){
            QLabel *lab = new QLabel();
            lab->setPixmap(pix.scaled(15,15,Qt::KeepAspectRatio));
            gridlayout->addWidget(lab,i,j);
            labels2DVector[i][j] = lab;
        }
    }
    this->labels = &labels2DVector;
}

void GameWindow::changeLabelValue(int x, int y, int value){
    QPixmap pix_dead(":/pics/pics/cell_dead.png");
    QPixmap pix_alive(":/pics/pics/cell_alive.png");
    QLayout *layout = this->ui->gridLayout;
    QLabel *label = dynamic_cast<QLabel*>(layout->itemAt(y * this->field->get_w() + x)->widget());
    if (value == '1') label->setPixmap(pix_alive);
    else label->setPixmap(pix_dead);
}

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
//    int x_count = 50, y_count = 60; // 3200 cells
    int x_count = 10, y_count = 10;
    createLayout(x_count, y_count);
    Field *field = createBackEnd(x_count, y_count);
    this->field = field;
    QLayout *layout = this->ui->verticalLayout; //this->ui->centralwidget->layout();
    layout->setSizeConstraint(QLayout::SetFixedSize);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::mouseEventHandler(QMouseEvent* event){
    int cell_x = event->pos().x() / pixelSize;
    int cell_y = event->pos().y() / pixelSize;
    if(cell_x < 1 || cell_y < 1 || cell_x > this->field->get_w() || cell_y > this->field->get_h()) return;
    char newValue = '0';
    if(event->buttons() == Qt::LeftButton) newValue = '1';
    qDebug() << cell_x << " " << cell_y;
    this->field->setCell(cell_x - 1, cell_y - 1, newValue);
    this->changeLabelValue(cell_x - 1, cell_y - 1, newValue);
}

void GameWindow::mouseMoveEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}

void GameWindow::mousePressEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}



void GameWindow::on_nextButton_clicked()
{
    this->field->updateState(1);
    for (int y = 0; y < this->field->get_w(); ++y) {
        for (int x = 0; x < this->field->get_h(); ++x) {
            this->changeLabelValue(x, y, this->field->getField()[y][x]);
        }
    }
}


void GameWindow::on_autoButton_clicked()
{
    for (int i = 0; i < 10; ++i) {
        this->field->updateState(1);
        for (int y = 0; y < this->field->get_w(); ++y) {
            for (int x = 0; x < this->field->get_h(); ++x) {
                this->changeLabelValue(x, y, this->field->getField()[y][x]);
            }
        }
        Sleeper::msleep(100);
    }
}

