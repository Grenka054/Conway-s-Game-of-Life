#include "gamewidget.h"
#include "parser.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent},
    timer(new QTimer(this))
{
    universe = Universe::create_universe();
    if (Parser::is_offline()){
        universe.update_state(universe.get_ticks_count());
        universe.save_to_file();
        exit(0);
    }
    autoUpdateOn = false;
    setWindowTitle(QString::fromStdString(universe.get_name()));
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

void GameWidget::setFPS(int FPS){
    timer->setInterval(1000 / FPS);
}

void GameWidget::switch_auto_update() {
        if (autoUpdateOn) {
            autoUpdateOn = false;
            timer->stop();
        }
        else {
            autoUpdateOn = true;
            timer->start();
        }
}

void GameWidget::clear_field() {
        for (int cell_y = 0; cell_y < this->universe.get_h(); ++cell_y)
            for (int cell_x = 0; cell_x < this->universe.get_w(); ++cell_x) {
                this->universe.field.set_value(cell_y, cell_x, 0);
            }

        if (autoUpdateOn) switch_auto_update();
        update();
}

void GameWidget::newGeneration(const int count) {
    this->universe.update_state(count);
    update();
}

void GameWidget::mouseEventHandler(QMouseEvent* event) {
    if (autoUpdateOn) return;
    double cellWidth = (double)width() / universe.get_w();
    double cellHeight = (double)height() / universe.get_h();
    int cell_y = floor(event->pos().y() / cellHeight);
    int cell_x = floor(event->pos().x() / cellWidth);
    if (cell_x < 0 || cell_x >= this->universe.get_w()
            || cell_y < 0 || cell_y >= this->universe.get_h()) return;
    char newValue = 0;
    if (event->buttons() == Qt::LeftButton) newValue = 1;
    this->universe.field.set_value(cell_y, cell_x, newValue);
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}

void GameWidget::mousePressEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}

void GameWidget::paintGrid(QPainter &pointer)
{
    QRect borders(0, 0, width()-1, height()-1); // borders of the universe
    pointer.drawRect(borders);
    pointer.setPen(QColor(0, 0, 0, 50)); // borders of cells
    double cellWidth = (double)width() / universe.get_w(); // width of the widget / number of cells at one row
    for(double k = cellWidth; k <= width(); k += cellWidth)
        pointer.drawLine(k, 0, k, height());
    double cellHeight = (double)height() / universe.get_h(); // height of the widget / number of cells at one row
    for(double k = cellHeight; k <= height(); k += cellHeight)
        pointer.drawLine(0, k, width(), k);
}

void GameWidget::paintUniverse(QPainter &pointer)
{
    double cellWidth = (double)width() / universe.get_w();
    double cellHeight = (double)height() / universe.get_h();
    for(int k = 0; k < universe.get_h(); k++) {
        for(int j = 0; j < universe.get_w(); j++) {
            if (universe.field.get_value(k, j)) { // if there is any sense to paint it
                qreal left = (qreal)(cellWidth*j); // margin from left
                qreal top  = (qreal)(cellHeight*k); // margin from top
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                pointer.fillRect(r, QBrush(Qt::black));
            }
        }
    }
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    paintGrid(painter);
    paintUniverse(painter);
}
