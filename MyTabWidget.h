#include "stdafx.h"

namespace Ui {
class MyTabWidget;
}

class MyTabWidget:public QTabWidget
{
    Q_OBJECT

public:
    explicit MyTabWidget(QWidget *parent = 0);
    ~MyTabWidget();
    QTabBar* tabBar()
    {
    return QTabWidget::tabBar();
            }

private:
    Ui::MyTabWidget *tab;
};

