#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "gamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_autoButton_clicked();
    void on_tickButton_clicked();
    void on_dumpButton_clicked();
    void on_openButton_clicked();
    void on_helpButton_clicked();
    void on_speedSlider_valueChanged(int value);
    void on_xSizeSlider_valueChanged(int value);
    void on_ySizeSlider_valueChanged(int value);
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::GameWindow *ui;
    GameWidget* game;
    bool keep_proportions;

};
#endif // GAMEWINDOW_H
