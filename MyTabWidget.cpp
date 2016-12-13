#include "MyTabWidget.h"
#include "stdafx.h"

MyTabWidget::MyTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    setParent(parent);

}

MyTabWidget::~MyTabWidget()
{
    delete tab;
}

void MainWindow::on_pushButton_clicked()
{

  QString good = ui->lineEdit->text();
  QString hey = ui->lineEdit_2->text();
  QPixmap pix("C:/backup.png");
  QIcon icon(pix);
  /*
   * image
   *
   */
/*  QTransform trans;
     pix= pix.transformed(trans.rotate(-90));
  ui->pushButton->setIcon(icon);
  ui->pushButton->setIconSize(pix.size());
*/
  std::string str1 = "hi";
  std::string str2 = "hello";
  QWidget *TestWidget;
  QLabel *label;
  QLabel *label_2;
  QPushButton *pushButton;
  QLineEdit *lineEdit;
  QLineEdit *lineEdit_2;
  QTabWidget *tabWidget;
  QTabBar *tabbar;

  QWidget *tab;
  QListWidget *listWidget;
  QWidget *tab_2;
  TestWidget = new QWidget(this);


 if((QString::compare(good,QString::fromStdString(str1),Qt::CaseSensitive) == 0) && (QString::compare(hey,QString::fromStdString(str2),Qt::CaseSensitive)) == 0)
    {
     QMessageBox msgBox;
     msgBox.setText("fdsa");
     msgBox.setStandardButtons(QMessageBox::Ok);
     msgBox.exec();
     ui->centralWidget->hide();

     this->setCentralWidget(TestWidget);

          label = new QLabel(TestWidget);
          label->setObjectName(QStringLiteral("label"));
          label->setGeometry(QRect(50, 40, 47, 13));

          label_2 = new QLabel(TestWidget);
          label_2->setObjectName(QStringLiteral("label_2"));
          label_2->setGeometry(QRect(30, 70, 47, 13));

          pushButton = new QPushButton(TestWidget);
          pushButton->setObjectName(QStringLiteral("pushButton"));
          pushButton->setGeometry(QRect(300, 50, 75, 23));

          lineEdit = new QLineEdit(TestWidget);
          lineEdit->setObjectName(QStringLiteral("lineEdit"));
          lineEdit->setGeometry(QRect(130, 40, 113, 20));

          lineEdit_2 = new QLineEdit(TestWidget);
          lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
          lineEdit_2->setGeometry(QRect(130, 70, 113, 20));

          tabWidget = new QTabWidget(TestWidget);
          tabWidget->setObjectName(QStringLiteral("tabWidget"));
          tabWidget->setGeometry(QRect(30, 100, 391, 171));

          //tabbar = QTabWidget::tabBar();
         // tabWidget->setStyleSheet(QLatin1String("QTabWidget::tab-bar\n"
  //"{\n"
  //"alignment: left;\n"
 // "}"));
          tabWidget->setTabPosition(QTabWidget::West);
          tab = new QWidget();
          tab->setObjectName(QStringLiteral("tab"));
          listWidget = new QListWidget(tab);
          listWidget->setObjectName(QStringLiteral("listWidget"));
          listWidget->setGeometry(QRect(30, 0, 256, 192));
          tabWidget->addTab(tab, QString());
          tab_2 = new QWidget();
          tab_2->setObjectName(QStringLiteral("tab_2"));
          tabWidget->addTab(tab_2, QString());
         // tab->set
          label->setText(QApplication::translate("MainWindow", "id", 0));
          label_2->setText(QApplication::translate("MainWindow", "password", 0));
          pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
      //글씨 넣기       tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "yeah", 0));
             tabWidget->setTabIcon(tabWidget->indexOf(tab),icon);
            tabWidget->setIconSize(pix.size());
            tabWidget->setTabPosition(QTabWidget::West);
         //   QStyleOptionTab opt(*tabbar);
          //  opt.shape = QTabBar::RoundedNorth;
    }
  else

 {
      QMessageBox msgBox;
      msgBox.setText("아이디 혹은 비밀번호가 일치하지 않습니다.");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();
 }



}
