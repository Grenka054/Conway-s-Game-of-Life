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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *buttonsWidget;
    QFormLayout *formLayout_3;
    QPushButton *tickButton;
    QLineEdit *tickLine;
    QPushButton *autoButton;
    QPushButton *openButton;
    QPushButton *helpButton;
    QPushButton *exitButton;
    QPushButton *dumpButton;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(1000, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWindow->sizePolicy().hasHeightForWidth());
        GameWindow->setSizePolicy(sizePolicy);
        GameWindow->setMinimumSize(QSize(240, 120));
        GameWindow->setAnimated(false);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 851, 395));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setSizeConstraint(QLayout::SetFixedSize);
        mainLayout->setContentsMargins(0, 0, 30, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(15, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 15, 15, 15);

        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        mainLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        buttonsWidget = new QWidget(horizontalLayoutWidget);
        buttonsWidget->setObjectName("buttonsWidget");
        formLayout_3 = new QFormLayout(buttonsWidget);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        formLayout_3->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_3->setHorizontalSpacing(25);
        tickButton = new QPushButton(buttonsWidget);
        tickButton->setObjectName("tickButton");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tickButton->sizePolicy().hasHeightForWidth());
        tickButton->setSizePolicy(sizePolicy1);
        tickButton->setMaximumSize(QSize(16666666, 16777215));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, tickButton);

        tickLine = new QLineEdit(buttonsWidget);
        tickLine->setObjectName("tickLine");
        sizePolicy1.setHeightForWidth(tickLine->sizePolicy().hasHeightForWidth());
        tickLine->setSizePolicy(sizePolicy1);
        tickLine->setMaximumSize(QSize(75, 16777215));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, tickLine);

        autoButton = new QPushButton(buttonsWidget);
        autoButton->setObjectName("autoButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(autoButton->sizePolicy().hasHeightForWidth());
        autoButton->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        autoButton->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, autoButton);

        openButton = new QPushButton(buttonsWidget);
        openButton->setObjectName("openButton");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, openButton);

        helpButton = new QPushButton(buttonsWidget);
        helpButton->setObjectName("helpButton");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, helpButton);

        exitButton = new QPushButton(buttonsWidget);
        exitButton->setObjectName("exitButton");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, exitButton);

        dumpButton = new QPushButton(buttonsWidget);
        dumpButton->setObjectName("dumpButton");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, dumpButton);

        clearButton = new QPushButton(buttonsWidget);
        clearButton->setObjectName("clearButton");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, clearButton);


        verticalLayout_2->addWidget(buttonsWidget);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        mainLayout->addLayout(verticalLayout_2);

        mainLayout->setStretch(0, 12);
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

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
        openButton->setToolTip(QCoreApplication::translate("GameWindow", "Load universe from file", nullptr));
#endif // QT_CONFIG(tooltip)
        openButton->setText(QCoreApplication::translate("GameWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        helpButton->setToolTip(QCoreApplication::translate("GameWindow", "Show help", nullptr));
#endif // QT_CONFIG(tooltip)
        helpButton->setText(QCoreApplication::translate("GameWindow", "Help", nullptr));
#if QT_CONFIG(tooltip)
        exitButton->setToolTip(QCoreApplication::translate("GameWindow", "Close app", nullptr));
#endif // QT_CONFIG(tooltip)
        exitButton->setText(QCoreApplication::translate("GameWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        dumpButton->setToolTip(QCoreApplication::translate("GameWindow", "Save universe to file", nullptr));
#endif // QT_CONFIG(tooltip)
        dumpButton->setText(QCoreApplication::translate("GameWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("GameWindow", "Clear universe", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("GameWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
