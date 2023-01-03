#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "parser.h"

GameWindow::GameWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game(new GameWidget(this))
{
    ui->setupUi(this);
    connect(ui->clearButton, SIGNAL(clicked()), game, SLOT(clear_field()));
    connect(ui->autoButton, SIGNAL(clicked()), game, SLOT(switch_auto_update()));
    ui->gameLayout->addWidget(game);
    keep_proportions = false;
    emit on_xSizeSlider_valueChanged(ui->xSizeSlider->sliderPosition());
    emit on_ySizeSlider_valueChanged(ui->ySizeSlider->sliderPosition());
    emit on_speedSlider_valueChanged(ui->speedSlider->sliderPosition());
    keep_proportions = true;
    update();
}

GameWindow::~GameWindow()
{
    delete ui;
    delete game;
}

void GameWindow::on_autoButton_clicked()
{
    QString text;
    QFont font;
    if (ui->autoButton->text().compare("Stop")) {
        text = "Stop";
        font = QFont("Segoe UI", 9, 800);
    }
    else text = "Start";

    this->ui->autoButton->setFont(font);
    this->ui->autoButton->setText(text);
}

void GameWindow::on_tickButton_clicked()
{
    QString text;
    this->ui->tickButton->setText("Counting...");
    ui->buttonsFrame->setDisabled(true);
    ui->tickButton->repaint();
    game->newGeneration(ui->tickLine->text().toInt());
    ui->buttonsFrame->setDisabled(false);
    this->ui->tickButton->setText("Tick");
}

void GameWindow::on_dumpButton_clicked()
{
    QString filter = "Life File (*.lif *.life) ;; Text File (*.txt)";
    QString file_name = QFileDialog::getSaveFileName(this, "Save as", QDir::currentPath(), filter);
    if (file_name.isEmpty()) return;
    game->universe.save_to_file(file_name);
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

    Parser::input_read(input_file.toStdString(), name, rules, y_count, x_count, tuples);
    if (name.empty()) return;
    game->universe = Universe(y_count, x_count, rules, tuples, name, "", 0);
    ui->xSizeSlider->setSliderPosition(x_count);
    ui->ySizeSlider->setSliderPosition(y_count);
    //centralWidget()->repaint();
    update();
}

void GameWindow::on_helpButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Help");
    msgBox.setText("Use the left mouse button to draw live cells and use the right mouse button to draw dead cells. Feel like in Paint =)");
    msgBox.exec();
}

void GameWindow::on_speedSlider_valueChanged(int value)
{
    game->setFPS(value);
    ui->FPSLabel->setNum(value);
}


void GameWindow::on_xSizeSlider_valueChanged(int value)
{
    double k = value / ui->xSizeLabel->text().toDouble();
    ui->xSizeLabel->setNum(value);
    game->universe.set_w(value);
    game->universe.field.resize(game->universe.get_h(), value);
    if (keep_proportions) {
        keep_proportions = false;
        ui->ySizeSlider->setSliderPosition(round(k * ui->ySizeLabel->text().toDouble()));
        keep_proportions = true;
    }
    update();
}


void GameWindow::on_ySizeSlider_valueChanged(int value)
{
    double k = value / ui->ySizeLabel->text().toDouble();
    ui->ySizeLabel->setNum(value);
    game->universe.set_h(value);
    game->universe.field.resize(value, game->universe.get_w());
    if (keep_proportions) {
        keep_proportions = false;
        ui->xSizeSlider->setSliderPosition(round(k * ui->xSizeLabel->text().toDouble()));
        keep_proportions = true;
    }
    update();
}


void GameWindow::on_checkBox_stateChanged(int arg1)
{
    keep_proportions = arg1;
}
