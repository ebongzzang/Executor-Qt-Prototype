#ifndef UI_PlanBUIClass_H
#define UI_PlanBUIClass_H

<<<<<<< HEAD
#include "stdafx.h"
=======
#include "stdafx.h";
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412

QT_BEGIN_NAMESPACE

class Ui_PlanBUIClass
{
public:
    QAction *actionDfsdf;
    QAction *actionSfsdfsdfsdf;

    QWidget *centralWidget;
<<<<<<< HEAD
=======
    QLabel *label;
    QLabel *label_2;
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QMenu *menuSetup;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *PlanBUIClass)
    {
            PlanBUIClass->setObjectName(QStringLiteral("PlanBUIClass"));
        PlanBUIClass->resize(1057, 634);

        actionSfsdfsdfsdf = new QAction(PlanBUIClass);
        actionSfsdfsdfsdf->setObjectName(QStringLiteral("actionSfsdfsdfsdf"));

        centralWidget = new QWidget(PlanBUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

        QLabel * label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 47, 13));
<<<<<<< HEAD
        QLabel * label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 47, 13));

        label->setText(QApplication::translate("PlanBUIClass", "id", 0));
        label_2->setText(QApplication::translate("PlanBUIClass", "password", 0));

=======
        QLabel label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 47, 13));

>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 50, 75, 23));

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 40, 113, 20));

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 70, 113, 20));

        PlanBUIClass->setCentralWidget(centralWidget);

        menuBar = new QMenuBar(PlanBUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1057, 21));

        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QStringLiteral("menuSetup"));

        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
<<<<<<< HEAD
=======

>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
        PlanBUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlanBUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PlanBUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlanBUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PlanBUIClass->setStatusBar(statusBar);
        toolBar = new QToolBar(PlanBUIClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        PlanBUIClass->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(PlanBUIClass);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        PlanBUIClass->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuSetup->addSeparator();
        menuSetup->addAction(actionSfsdfsdfsdf);

        retranslateUi(PlanBUIClass);

        QMetaObject::connectSlotsByName(PlanBUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlanBUIClass)
    {
        PlanBUIClass->setWindowTitle(QApplication::translate("PlanBUIClass", "PlanBUIClass", 0));
        actionSfsdfsdfsdf->setText(QApplication::translate("PlanBUIClass", "sfsdfsdfsdf", 0));
<<<<<<< HEAD
=======
        label->setText(QApplication::translate("PlanBUIClass", "id", 0));
        label_2->setText(QApplication::translate("PlanBUIClass", "password", 0));
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
        pushButton->setText(QApplication::translate("PlanBUIClass", "PushButton", 0));
        menuSetup->setTitle(QApplication::translate("PlanBUIClass", "Setup", 0));
        menuHelp->setTitle(QApplication::translate("PlanBUIClass", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("PlanBUIClass", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("PlanBUIClass", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class PlanBUIClass: public Ui_PlanBUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PlanBUIClass_H
