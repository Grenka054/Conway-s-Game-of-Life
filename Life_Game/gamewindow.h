#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QMouseEvent>
#include <QMessageBox>
#include "field.h"
#include <QTimer>
#include "parser.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

const int pixSize = 15;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(Field* field, QWidget *parent = nullptr);
    ~GameWindow();
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

public slots:
    void newGeneration(int count=1);

private slots:
    void on_autoButton_clicked();

    void on_clearButton_clicked();

    void on_exitButton_clicked();

    void on_tickButton_clicked();

    void on_dumpButton_clicked();

    void on_openButton_clicked();

    void on_helpButton_clicked();

private:
    void createLayout(int x_count, int y_count);
    void changeLabelValue(int x, int y, int value);
    void mouseEventHandler(QMouseEvent* event);
    Ui::GameWindow *ui;
    QTimer* timer;
    QPixmap pix_alive;
    QPixmap pix_dead;
    bool autoUpdateOn;
    bool ticksOn;
    Field *field;
    QList<QList<QLabel*>>* labels;
};
#endif // GAMEWINDOW_H
