
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PlanBUIClass w;
	PlanBUIClass g;
    w.show();
	g.show();

    return a.exec();
}
