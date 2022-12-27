#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include "field.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

const int pixSize = 15;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(int x_count, int y_count, Field* field, QWidget *parent = nullptr);
    ~GameWindow();
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private slots:
    void on_nextButton_clicked();
    void on_autoButton_clicked();
    void newGeneration();

    void on_clearButton_clicked();

    void on_exitButton_clicked();

private:
    void createLayout(int x_count, int y_count);
    void changeLabelValue(int x, int y, int value);
    void mouseEventHandler(QMouseEvent* event);
    Ui::GameWindow *ui;
    QTimer* timer;
    QPixmap pix_alive;
    QPixmap pix_dead;
    bool autoUpdateOn;
    Field *field;
    QVector<QVector<QLabel*>>* labels;
};
#endif // GAMEWINDOW_H
