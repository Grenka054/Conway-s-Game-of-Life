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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *nextButton;
    QPushButton *autoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(926, 310);
        GameWindow->setAnimated(false);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 907, 251));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setSizeConstraint(QLayout::SetFixedSize);
        mainLayout->setContentsMargins(0, 0, 30, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(0, 15, 15, 15);

        mainLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        nextButton = new QPushButton(horizontalLayoutWidget);
        nextButton->setObjectName("nextButton");

        verticalLayout->addWidget(nextButton);

        autoButton = new QPushButton(horizontalLayoutWidget);
        autoButton->setObjectName("autoButton");

        verticalLayout->addWidget(autoButton);


        mainLayout->addLayout(verticalLayout);

        mainLayout->setStretch(0, 5);
        GameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 926, 22));
        GameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GameWindow);
        statusbar->setObjectName("statusbar");
        GameWindow->setStatusBar(statusbar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "GameWindow", nullptr));
        nextButton->setText(QCoreApplication::translate("GameWindow", "Next", nullptr));
        autoButton->setText(QCoreApplication::translate("GameWindow", "Auto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
