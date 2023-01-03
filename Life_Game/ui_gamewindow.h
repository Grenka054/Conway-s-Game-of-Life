/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *gameLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QFrame *buttonsFrame;
    QFormLayout *formLayout;
    QPushButton *tickButton;
    QLineEdit *tickLine;
    QPushButton *autoButton;
    QPushButton *clearButton;
    QPushButton *openButton;
    QPushButton *helpButton;
    QPushButton *dumpButton;
    QPushButton *exitButton;
    QFrame *sizeFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *xSizeLabel;
    QSlider *xSizeSlider;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *ySizeLabel;
    QSlider *ySizeSlider;
    QFrame *FPSFrame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *FPSLayout;
    QLabel *label;
    QLabel *FPSLabel;
    QSlider *speedSlider;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(821, 485);
        GameWindow->setAnimated(false);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 10, 20, 10);
        gameLayout = new QVBoxLayout();
        gameLayout->setObjectName("gameLayout");

        horizontalLayout->addLayout(gameLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonsFrame = new QFrame(centralwidget);
        buttonsFrame->setObjectName("buttonsFrame");
        buttonsFrame->setFrameShape(QFrame::Panel);
        buttonsFrame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(buttonsFrame);
        formLayout->setObjectName("formLayout");
        tickButton = new QPushButton(buttonsFrame);
        tickButton->setObjectName("tickButton");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tickButton->sizePolicy().hasHeightForWidth());
        tickButton->setSizePolicy(sizePolicy);
        tickButton->setMaximumSize(QSize(16666666, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, tickButton);

        tickLine = new QLineEdit(buttonsFrame);
        tickLine->setObjectName("tickLine");
        sizePolicy.setHeightForWidth(tickLine->sizePolicy().hasHeightForWidth());
        tickLine->setSizePolicy(sizePolicy);
        tickLine->setMaximumSize(QSize(75, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, tickLine);

        autoButton = new QPushButton(buttonsFrame);
        autoButton->setObjectName("autoButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(autoButton->sizePolicy().hasHeightForWidth());
        autoButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        autoButton->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, autoButton);

        clearButton = new QPushButton(buttonsFrame);
        clearButton->setObjectName("clearButton");

        formLayout->setWidget(1, QFormLayout::FieldRole, clearButton);

        openButton = new QPushButton(buttonsFrame);
        openButton->setObjectName("openButton");

        formLayout->setWidget(2, QFormLayout::LabelRole, openButton);

        helpButton = new QPushButton(buttonsFrame);
        helpButton->setObjectName("helpButton");

        formLayout->setWidget(2, QFormLayout::FieldRole, helpButton);

        dumpButton = new QPushButton(buttonsFrame);
        dumpButton->setObjectName("dumpButton");

        formLayout->setWidget(3, QFormLayout::LabelRole, dumpButton);

        exitButton = new QPushButton(buttonsFrame);
        exitButton->setObjectName("exitButton");

        formLayout->setWidget(3, QFormLayout::FieldRole, exitButton);


        verticalLayout->addWidget(buttonsFrame);

        sizeFrame = new QFrame(centralwidget);
        sizeFrame->setObjectName("sizeFrame");
        sizeFrame->setFrameShape(QFrame::Panel);
        sizeFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(sizeFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(sizeFrame);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        checkBox = new QCheckBox(sizeFrame);
        checkBox->setObjectName("checkBox");
        checkBox->setChecked(true);

        verticalLayout_4->addWidget(checkBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(sizeFrame);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_3);

        xSizeLabel = new QLabel(sizeFrame);
        xSizeLabel->setObjectName("xSizeLabel");

        horizontalLayout_3->addWidget(xSizeLabel);


        verticalLayout_4->addLayout(horizontalLayout_3);

        xSizeSlider = new QSlider(sizeFrame);
        xSizeSlider->setObjectName("xSizeSlider");
        xSizeSlider->setMinimum(4);
        xSizeSlider->setMaximum(150);
        xSizeSlider->setSliderPosition(20);
        xSizeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(xSizeSlider);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(sizeFrame);
        label_4->setObjectName("label_4");
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_4);

        ySizeLabel = new QLabel(sizeFrame);
        ySizeLabel->setObjectName("ySizeLabel");

        horizontalLayout_5->addWidget(ySizeLabel);


        verticalLayout_4->addLayout(horizontalLayout_5);

        ySizeSlider = new QSlider(sizeFrame);
        ySizeSlider->setObjectName("ySizeSlider");
        ySizeSlider->setMinimum(4);
        ySizeSlider->setMaximum(150);
        ySizeSlider->setSliderPosition(20);
        ySizeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(ySizeSlider);


        verticalLayout->addWidget(sizeFrame);

        FPSFrame = new QFrame(centralwidget);
        FPSFrame->setObjectName("FPSFrame");
        FPSFrame->setFrameShape(QFrame::Panel);
        FPSFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FPSFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        FPSLayout = new QHBoxLayout();
        FPSLayout->setObjectName("FPSLayout");
        label = new QLabel(FPSFrame);
        label->setObjectName("label");
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        FPSLayout->addWidget(label);

        FPSLabel = new QLabel(FPSFrame);
        FPSLabel->setObjectName("FPSLabel");

        FPSLayout->addWidget(FPSLabel);


        verticalLayout_2->addLayout(FPSLayout);

        speedSlider = new QSlider(FPSFrame);
        speedSlider->setObjectName("speedSlider");
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(120);
        speedSlider->setValue(60);
        speedSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(speedSlider);


        verticalLayout->addWidget(FPSFrame);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);
        QObject::connect(exitButton, &QPushButton::clicked, GameWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "GameWindow", nullptr));
#if QT_CONFIG(tooltip)
        tickButton->setToolTip(QCoreApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:700;\">n</span> steps of life</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tickButton->setText(QCoreApplication::translate("GameWindow", "Tick", nullptr));
#if QT_CONFIG(tooltip)
        tickLine->setToolTip(QCoreApplication::translate("GameWindow", "Number of ticks", nullptr));
#endif // QT_CONFIG(tooltip)
        tickLine->setPlaceholderText(QCoreApplication::translate("GameWindow", "Ticks", nullptr));
#if QT_CONFIG(tooltip)
        autoButton->setToolTip(QCoreApplication::translate("GameWindow", "Start / Stop Life", nullptr));
#endif // QT_CONFIG(tooltip)
        autoButton->setText(QCoreApplication::translate("GameWindow", "Start", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("GameWindow", "Clear universe", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("GameWindow", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        openButton->setToolTip(QCoreApplication::translate("GameWindow", "Load universe from file", nullptr));
#endif // QT_CONFIG(tooltip)
        openButton->setText(QCoreApplication::translate("GameWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        helpButton->setToolTip(QCoreApplication::translate("GameWindow", "Show help", nullptr));
#endif // QT_CONFIG(tooltip)
        helpButton->setText(QCoreApplication::translate("GameWindow", "Help", nullptr));
#if QT_CONFIG(tooltip)
        dumpButton->setToolTip(QCoreApplication::translate("GameWindow", "Save universe to file", nullptr));
#endif // QT_CONFIG(tooltip)
        dumpButton->setText(QCoreApplication::translate("GameWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        exitButton->setToolTip(QCoreApplication::translate("GameWindow", "Close app", nullptr));
#endif // QT_CONFIG(tooltip)
        exitButton->setText(QCoreApplication::translate("GameWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "Size", nullptr));
#if QT_CONFIG(tooltip)
        checkBox->setToolTip(QCoreApplication::translate("GameWindow", "Keep cell proportions", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox->setText(QCoreApplication::translate("GameWindow", "Keep proportions", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "X:", nullptr));
        xSizeLabel->setText(QString());
#if QT_CONFIG(tooltip)
        xSizeSlider->setToolTip(QCoreApplication::translate("GameWindow", "Number of cells horizontally", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("GameWindow", "Y:", nullptr));
        ySizeLabel->setText(QString());
#if QT_CONFIG(tooltip)
        ySizeSlider->setToolTip(QCoreApplication::translate("GameWindow", "Number of cells vertically", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("GameWindow", "FPS:", nullptr));
#if QT_CONFIG(tooltip)
        speedSlider->setToolTip(QCoreApplication::translate("GameWindow", "FPS", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
