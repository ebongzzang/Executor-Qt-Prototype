
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	PlanBUIClass UI;
	UI.mainLayout->setMainLayout(); //set Menu, title, etc..
	UI.myWidget = UI.mainLayout->getCentralWidget();
	UI.execLogin("hi", "hello");
	UI.show();
    return a.exec();
}
