#include "gamewindow.h"
#include "ui_gamewindow.h"

void GameWindow::createLayout(const int y_count, const int x_count) {
    QList<QList<QLabel*>> labels2DVector(y_count, QList<QLabel*>(x_count));
    for (int i = 0; i < y_count; i++){
        for (int j = 0; j < x_count; j++){
            labels2DVector[i][j] = new QLabel();
            if (universe.get_field().get_value(i, j))
                labels2DVector[i][j]->setPixmap(pix_alive);
            else labels2DVector[i][j]->setPixmap(pix_dead);
            ui->gridLayout->addWidget(labels2DVector[i][j],i,j);
        }
    }
    this->labels = labels2DVector;
    setWindowTitle(QString::fromStdString(universe.get_name()));
    this->setFixedSize(QSize((universe.get_w() + 2) * pixSize + 260, std::max((universe.get_h() + 2) * pixSize, 150)));
}

void GameWindow::changeLabelValue(const int x, const int y, const int value) {
    QLabel *label = dynamic_cast<QLabel*>(ui->gridLayout->itemAt(y * this->universe.get_w() + x)->widget());
    if (value) label->setPixmap(pix_alive);
    else label->setPixmap(pix_dead);
    label->repaint();
}

GameWindow::GameWindow(const Universe universe, QWidget *parent):
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
    ticksOn = false;
    this->universe = universe;
    createLayout(this->universe.get_h(), this->universe.get_w());
    connect(&timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    timer.setInterval(100);
}

GameWindow::~GameWindow()
{
    for (int i = 0; i < universe.get_h(); ++i)
        for(int j = 0; j < universe.get_w(); ++j){
            QLabel *label = dynamic_cast<QLabel*>(ui->gridLayout->itemAt(i * this->universe.get_w() + j)->widget());
            label->deleteLater();
        }
    delete ui;
}

void GameWindow::mouseEventHandler(QMouseEvent* event) {
    if (autoUpdateOn) return;
    if (ticksOn) return;
    int cell_x = event->pos().x() / pixSize;
    int cell_y = event->pos().y() / pixSize;
    if (cell_x < 1 || cell_x > this->universe.get_w()
            || cell_y < 1 || cell_y > this->universe.get_h()) return;
    char newValue = 0;
    if (event->buttons() == Qt::LeftButton) newValue = 1;
    this->universe.set_cell(cell_x - 1, cell_y - 1, newValue);
    this->changeLabelValue(cell_x - 1, cell_y - 1, newValue);
}

void GameWindow::mouseMoveEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}

void GameWindow::mousePressEvent(QMouseEvent* event) {
    mouseEventHandler(event);
}

void GameWindow::newGeneration(const int count) {
    this->universe.update_state(count);
    for (int y = 0; y < this->universe.get_h(); ++y)
        for (int x = 0; x < this->universe.get_w(); ++x)
            this->changeLabelValue(x, y, this->universe.get_field().get_value(y, x));
}

void GameWindow::on_autoButton_clicked()
{
    QString text;
    if (autoUpdateOn) {
        autoUpdateOn = false;
        timer.stop();
        text = "Start";
        this->ui->autoButton->setFont(QFont());
    }
    else {
        autoUpdateOn = true;
        timer.start();
        text = "Stop";
        this->ui->autoButton->setFont(QFont("Segoe UI", 9, 800));
    }
    this->ui->autoButton->setText(text);
}

void GameWindow::on_clearButton_clicked()
{
    for (int cell_y = 0; cell_y < this->universe.get_h(); ++cell_y)
        for (int cell_x = 0; cell_x < this->universe.get_w(); ++cell_x) {
            this->universe.set_cell(cell_x, cell_y, 0);
            this->changeLabelValue(cell_x, cell_y, 0);
        }

    if (autoUpdateOn)
        emit on_autoButton_clicked();
}

void GameWindow::on_exitButton_clicked()
{
    exit(0);
}

void GameWindow::on_tickButton_clicked()
{
    ticksOn = true;
    int count = ui->tickLine->text().toInt();
    if (count < 1) count = 1;
    ui->tickButton->setText("Counting...");
    ui->buttonsWidget->setDisabled(true);
    ui->tickButton->repaint();
    newGeneration(count);
    ui->tickButton->setText("Tick");
    ui->buttonsWidget->setDisabled(false);
    ticksOn = false;
}

void GameWindow::on_dumpButton_clicked()
{
    QString filter = "Life File (*.lif *.life) ;; Text File (*.txt)";
    QString file_name = QFileDialog::getSaveFileName(this, "Save as", QDir::currentPath(), filter);
    if (file_name.isEmpty()) return;
    universe.save_to_file(file_name);
    setWindowTitle(file_name);
}

void GameWindow::on_openButton_clicked()
{
    QString filter = "Life File (*.lif *.life) ;; Text File (*.txt)";
    QString input_file = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), filter);
    if (input_file.isEmpty()) return;
    std::string name;
    Rules rules;
    int x_count = 20, y_count = 20;
    std::set<std::tuple<int, int>> tuples;
    for (int i = 0; i < universe.get_h(); ++i)
        for(int j = 0; j < universe.get_w(); ++j){
            QWidget *label = (ui->gridLayout->itemAt(i * this->universe.get_w() + j)->widget());
            label->deleteLater();
        }

    Parser::input_read(input_file.toStdString(), name, rules, x_count, y_count, tuples);
    if (name.empty()) return;
    //delete universe;
    universe = Universe(x_count, y_count, rules, tuples, name, "", 0);
    createLayout(y_count, x_count);
    centralWidget()->repaint();
}

void GameWindow::on_helpButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Help");
    msgBox.setText("Use the left mouse button to draw live cells and use the right mouse button to draw dead cells. Feel like in Paint =)");
    msgBox.exec();
}
