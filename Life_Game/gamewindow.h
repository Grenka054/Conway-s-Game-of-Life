#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "logic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    Field *field;
    QVector<QVector<QLabel*>>* labels;
    void createLayout(int x_count, int y_count);
    void changeLabelValue(int x, int y, int value);
    void mouseEventHandler(QMouseEvent* event);

private slots:
    void on_nextButton_clicked();

    void on_autoButton_clicked();

private:
    Ui::GameWindow *ui;
};
#endif // GAMEWINDOW_H
