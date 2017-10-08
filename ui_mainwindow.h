/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QMenuBar *menuBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *logo;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitPushbutton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *drawpushButton;
    QPushButton *setpushButton;
    QPushButton *undopushButton;
    QPushButton *sourcepushButton;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Nodule_1;
    QLineEdit *lineEdit11;
    QLineEdit *lineEdit12;
    QLineEdit *lineEdit13;
    QLineEdit *lineEdit14;
    QLineEdit *lineEdit15;
    QSpacerItem *verticalSpacer_4;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QPushButton *Nodule_2;
    QLineEdit *lineEdit21;
    QLineEdit *lineEdit22;
    QLineEdit *lineEdit23;
    QLineEdit *lineEdit24;
    QLineEdit *lineEdit25;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_9;
    QPushButton *Nodule_3;
    QLineEdit *lineEdit31;
    QLineEdit *lineEdit32;
    QLineEdit *lineEdit33;
    QLineEdit *lineEdit34;
    QLineEdit *lineEdit35;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1030, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 31));
        MainWindow->setMenuBar(menuBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(417, 468));
        dockWidget->setFocusPolicy(Qt::StrongFocus);
        dockWidget->setAutoFillBackground(true);
        dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        logo = new QPushButton(dockWidgetContents);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setMaximumSize(QSize(200, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        logo->setIcon(icon);
        logo->setIconSize(QSize(150, 75));
        logo->setFlat(true);

        horizontalLayout_7->addWidget(logo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        quitPushbutton = new QPushButton(dockWidgetContents);
        quitPushbutton->setObjectName(QStringLiteral("quitPushbutton"));
        quitPushbutton->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitPushbutton->setIcon(icon1);
        quitPushbutton->setIconSize(QSize(50, 50));
        quitPushbutton->setFlat(true);

        horizontalLayout_7->addWidget(quitPushbutton);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        drawpushButton = new QPushButton(dockWidgetContents);
        drawpushButton->setObjectName(QStringLiteral("drawpushButton"));
        drawpushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));
        drawpushButton->setCheckable(false);

        horizontalLayout_2->addWidget(drawpushButton);

        setpushButton = new QPushButton(dockWidgetContents);
        setpushButton->setObjectName(QStringLiteral("setpushButton"));
        setpushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));

        horizontalLayout_2->addWidget(setpushButton);

        undopushButton = new QPushButton(dockWidgetContents);
        undopushButton->setObjectName(QStringLiteral("undopushButton"));
        undopushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));

        horizontalLayout_2->addWidget(undopushButton);

        sourcepushButton = new QPushButton(dockWidgetContents);
        sourcepushButton->setObjectName(QStringLiteral("sourcepushButton"));
        sourcepushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));

        horizontalLayout_2->addWidget(sourcepushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        groupBox_3 = new QGroupBox(dockWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 9, -1, 9);
        Nodule_1 = new QPushButton(groupBox_3);
        Nodule_1->setObjectName(QStringLiteral("Nodule_1"));
        Nodule_1->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        Nodule_1->setFlat(true);

        verticalLayout_3->addWidget(Nodule_1);

        lineEdit11 = new QLineEdit(groupBox_3);
        lineEdit11->setObjectName(QStringLiteral("lineEdit11"));
        lineEdit11->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(lineEdit11);

        lineEdit12 = new QLineEdit(groupBox_3);
        lineEdit12->setObjectName(QStringLiteral("lineEdit12"));
        lineEdit12->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(lineEdit12);

        lineEdit13 = new QLineEdit(groupBox_3);
        lineEdit13->setObjectName(QStringLiteral("lineEdit13"));
        lineEdit13->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(lineEdit13);

        lineEdit14 = new QLineEdit(groupBox_3);
        lineEdit14->setObjectName(QStringLiteral("lineEdit14"));
        lineEdit14->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(lineEdit14);

        lineEdit15 = new QLineEdit(groupBox_3);
        lineEdit15->setObjectName(QStringLiteral("lineEdit15"));
        lineEdit15->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(lineEdit15);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 1);
        verticalLayout_3->setStretch(5, 1);
        lineEdit11->raise();
        Nodule_1->raise();
        lineEdit12->raise();
        lineEdit13->raise();
        lineEdit14->raise();
        lineEdit15->raise();

        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 3);
        verticalLayout->setStretch(5, 2);

        verticalLayout_2->addLayout(verticalLayout);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidget_2->setAllowedAreas(Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox = new QGroupBox(dockWidgetContents_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(true);
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        Nodule_2 = new QPushButton(groupBox);
        Nodule_2->setObjectName(QStringLiteral("Nodule_2"));
        Nodule_2->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        Nodule_2->setFlat(true);

        verticalLayout_8->addWidget(Nodule_2);

        lineEdit21 = new QLineEdit(groupBox);
        lineEdit21->setObjectName(QStringLiteral("lineEdit21"));
        lineEdit21->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(lineEdit21);

        lineEdit22 = new QLineEdit(groupBox);
        lineEdit22->setObjectName(QStringLiteral("lineEdit22"));
        lineEdit22->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(lineEdit22);

        lineEdit23 = new QLineEdit(groupBox);
        lineEdit23->setObjectName(QStringLiteral("lineEdit23"));
        lineEdit23->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(lineEdit23);

        lineEdit24 = new QLineEdit(groupBox);
        lineEdit24->setObjectName(QStringLiteral("lineEdit24"));
        lineEdit24->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(lineEdit24);

        lineEdit25 = new QLineEdit(groupBox);
        lineEdit25->setObjectName(QStringLiteral("lineEdit25"));
        lineEdit25->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(lineEdit25);

        verticalLayout_8->setStretch(0, 2);
        verticalLayout_8->setStretch(1, 2);
        verticalLayout_8->setStretch(2, 2);
        verticalLayout_8->setStretch(3, 2);
        verticalLayout_8->setStretch(4, 2);
        verticalLayout_8->setStretch(5, 2);

        verticalLayout_10->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);

        groupBox_2 = new QGroupBox(dockWidgetContents_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_9 = new QVBoxLayout(groupBox_2);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        Nodule_3 = new QPushButton(groupBox_2);
        Nodule_3->setObjectName(QStringLiteral("Nodule_3"));
        Nodule_3->setStyleSheet(QLatin1String("font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        Nodule_3->setFlat(true);

        verticalLayout_9->addWidget(Nodule_3);

        lineEdit31 = new QLineEdit(groupBox_2);
        lineEdit31->setObjectName(QStringLiteral("lineEdit31"));
        lineEdit31->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(lineEdit31);

        lineEdit32 = new QLineEdit(groupBox_2);
        lineEdit32->setObjectName(QStringLiteral("lineEdit32"));
        lineEdit32->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(lineEdit32);

        lineEdit33 = new QLineEdit(groupBox_2);
        lineEdit33->setObjectName(QStringLiteral("lineEdit33"));
        lineEdit33->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(lineEdit33);

        lineEdit34 = new QLineEdit(groupBox_2);
        lineEdit34->setObjectName(QStringLiteral("lineEdit34"));
        lineEdit34->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(lineEdit34);

        lineEdit35 = new QLineEdit(groupBox_2);
        lineEdit35->setObjectName(QStringLiteral("lineEdit35"));
        lineEdit35->setStyleSheet(QLatin1String("color: rgb(31, 17, 17);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(lineEdit35);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(1, 2);
        verticalLayout_9->setStretch(2, 2);
        verticalLayout_9->setStretch(3, 2);
        verticalLayout_9->setStretch(4, 2);
        verticalLayout_9->setStretch(5, 2);

        verticalLayout_10->addWidget(groupBox_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);

        verticalLayout_10->setStretch(0, 4);
        verticalLayout_10->setStretch(2, 4);
        verticalLayout_10->setStretch(3, 1);

        gridLayout->addLayout(verticalLayout_10, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        dockWidget->setWindowTitle(QString());
        logo->setText(QString());
        quitPushbutton->setText(QString());
        drawpushButton->setText(QApplication::translate("MainWindow", "Draw", 0));
        setpushButton->setText(QApplication::translate("MainWindow", "Set", 0));
        undopushButton->setText(QApplication::translate("MainWindow", "Undo", 0));
        sourcepushButton->setText(QApplication::translate("MainWindow", "Change Source", 0));
        groupBox_3->setTitle(QString());
        Nodule_1->setText(QApplication::translate("MainWindow", "Nodule_1", 0));
        groupBox->setTitle(QString());
        Nodule_2->setText(QApplication::translate("MainWindow", "Nodule_2", 0));
        groupBox_2->setTitle(QString());
        Nodule_3->setText(QApplication::translate("MainWindow", "Nodule_3", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
