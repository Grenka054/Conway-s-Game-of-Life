#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include "field.h"
#include <QTimer>

void GameWindow::createLayout(int x_count, int y_count)
{
    QVector<QVector<QLabel*>> labels2DVector(y_count);
    for (int i = 0; i < y_count; i++){
        labels2DVector[i].resize(x_count);
        for (int j = 0; j < x_count; j++){
            QLabel *lab = new QLabel();
            char temp = field->getField()[i][j];
            if (temp == '1')
                lab->setPixmap(pix_alive);
            else lab->setPixmap(pix_dead);
            ui->gridLayout->addWidget(lab,i,j);
            labels2DVector[i][j] = lab;
        }
    }
    this->labels = &labels2DVector;
}

void GameWindow::changeLabelValue(int x, int y, int value){
    QLabel *label = dynamic_cast<QLabel*>(ui->gridLayout->itemAt(y * this->field->get_w() + x)->widget());
    if (value == '1') label->setPixmap(pix_alive);
    else label->setPixmap(pix_dead);
    label->repaint();
}

GameWindow::GameWindow(int x_count, int y_count, Field* field, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    QPixmap pix_alive(":/pics/pics/cell_alive.png");
    this->pix_alive = pix_alive;
    QPixmap pix_dead(":/pics/pics/cell_dead.png");
    this->pix_dead = pix_dead;
    autoUpdateOn = false;
    this->field = field;
    createLayout(x_count, y_count);
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

GameWindow::~GameWindow()
{
    delete field;
    delete ui;
}

void GameWindow::mouseEventHandler(QMouseEvent* event) {
    if (autoUpdateOn) return;
    int cell_x = event->pos().x() / pixSize;
    int cell_y = event->pos().y() / pixSize;
    if (cell_x < 1 || cell_x > this->field->get_w()
            || cell_y < 1 || cell_y > this->field->get_h()) return;
    char newValue = '0';
    if (event->buttons() == Qt::LeftButton) newValue = '1';
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
    for (int y = 0; y < this->field->get_h(); ++y)
        for (int x = 0; x < this->field->get_w(); ++x)
            this->changeLabelValue(x, y, this->field->getField()[y][x]);
}

void GameWindow::newGeneration() {
    if(autoUpdateOn) emit on_nextButton_clicked();
}

void GameWindow::on_autoButton_clicked()
{
    QString text;
    if (autoUpdateOn) {
        timer->stop();
        text = "Start";
    }
    else {
        timer->start();
        text = "Stop";
    }
    autoUpdateOn = !autoUpdateOn;
    this->ui->autoButton->setText(text);
}

void GameWindow::on_clearButton_clicked()
{
    for (int cell_y = 0; cell_y < this->field->get_h(); ++cell_y) {
        for (int cell_x = 0; cell_x < this->field->get_w(); ++cell_x) {
            this->field->setCell(cell_x, cell_y, '0');
            this->changeLabelValue(cell_x, cell_y, '0');
        }
    }

    if (autoUpdateOn)
        emit on_autoButton_clicked();
}
