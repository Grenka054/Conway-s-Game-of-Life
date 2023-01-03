#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include "universe.h"
#include "qevent.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void setFPS(int FPS);
    Universe universe;

protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

signals:

public slots:
    void newGeneration(int count=1);
    void switch_auto_update();
    void clear_field();

private slots:
    void paintGrid(QPainter &pointer);
    void paintUniverse(QPainter &pointer);

private:
    QTimer* timer;
    bool autoUpdateOn;
    void mouseEventHandler(QMouseEvent* event);
};

#endif // GAMEWIDGET_H
