#include "mainwindow.h"
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <QString>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <QMessageBox>
#include <QlistWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewFilelist(std::string sPath, QWidget * widget, QTreeView *treepath)
{
   dirmodel = new QFileSystemModel(widget);
   dirmodel->setRootPath(QString::fromStdString(sPath));
   treepath->setModel(dirmodel);
   dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
}
void MainWindow::GetPathFromTree()
//주어진 Tree로 부터 경로를 얻는다.
{
    QModelIndexList list =  treeView->selectionModel()->selectedIndexes();
    foreach (QModelIndex index, list)
    {
       absPath = dirmodel->filePath(index);
       qDebug() << absPath; //For Debug
    }
}

void MainWindow::convertPathToLabel()
{
    pathLabel_2->setText(QApplication::translate("BackupWidget_1",absPath.toUtf8().constData(), 0));
    treeDialog->close();
}

//트리를 띄울 Dialog를 만든다.
void MainWindow::cratePathDialog()
{
    treeDialog = new QDialog();
    treeView = new QTreeView(treeDialog);
    treeView->setObjectName(QStringLiteral("treeView"));
    treeView->setGeometry(QRect(30, 100, 256, 192));
    MainWindow::ViewFilelist("C:/",treeDialog,treeView);
    MainWindow::GetPathFromTree();

    pathDiaButton = new QPushButton(treeDialog);
    pathDiaButton->setObjectName(QStringLiteral("pathDiaButton"));
    pathDiaButton->setGeometry(QRect(100, 340, 75, 23));
    pathDiaButton->setText(QApplication::translate("treeDialog", "click", 0));


     connect(treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(GetPathFromTree()));
     //사용자가 클릭하는 트리 값 받아오기

     connect(pathDiaButton,SIGNAL(clicked(bool)),this,SLOT(convertPathToLabel()));
     //ok 누르면 다이얼로그 종료


     treeDialog->exec();


}

    /*
     * 푸쉬버튼,라인에딧,라벨 등 단순한 것들을 함수화 할 필요가 있어보임(예정)
     *
     */



void MainWindow::on_pushButton_clicked()
{

  QString good = ui->lineEdit->text();
  QString hey = ui->lineEdit_2->text();
 /*  QPixmap pix("C:/backup.png");
  QIcon icon(pix);

   * image
   *
   */
/*  QTransform trans;
     pix= pix.transformed(trans.rotate(-90));
  ui->pushButton->setIcon(icon);
  ui->pushButton->setIconSize(pix.size());
*/
  BackupWidget_1 = new QWidget(this);

 if((QString::compare(good,QString::fromStdString(str1),Qt::CaseSensitive) == 0) && (QString::compare(hey,QString::fromStdString(str2),Qt::CaseSensitive)) == 0)
    {
     QMessageBox msgBox;
     msgBox.setText("fdsa");
     msgBox.setStandardButtons(QMessageBox::Ok);
     msgBox.exec();
     ui->centralWidget->hide();
     BackupWidget_1->resize(1057,634);
     this->setCentralWidget(BackupWidget_1);



     /*     label = new QLabel(BackupWidget_1);
          label->setObjectName(QStringLiteral("label"));
          label->setGeometry(QRect(50, 40, 47, 13));

          label_2 = new QLabel(BackupWidget_1);
          label_2->setObjectName(QStringLiteral("label_2"));
          label_2->setGeometry(QRect(30, 70, 47, 13));

          pushButton = new QPushButton(BackupWidget_1);
          pushButton->setObjectName(QStringLiteral("pushButton"));
          pushButton->setGeometry(QRect(300, 50, 75, 23));

          lineEdit = new QLineEdit(BackupWidget_1);
          lineEdit->setObjectName(QStringLiteral("lineEdit"));
          lineEdit->setGeometry(QRect(130, 40, 113, 20));

          lineEdit_2 = new QLineEdit(BackupWidget_1);
          lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
          lineEdit_2->setGeometry(QRect(130, 70, 113, 20));
*/
     //다이어로그 추가하기


          tabWidget = new QTabWidget(BackupWidget_1);
          tabWidget->setObjectName(QStringLiteral("tabWidget"));
          tabWidget->setGeometry(QRect(30, 100, 391, 171));

          tabWidget->resize( 800,300);


          // 탭에 아이콘을 넣는 부분이다. CSS를 사용해서 넣어줌
          tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{\n"
  "    height: 30px;\n"
  "    width: 120px;\n"
  "}\n"
  "\n"
  "QTabBar::tab:first {\n"
  "     background: url(c:/backup2.png);\n"
  "}\n"
  "\n"
  "\n"
  " QTabBar::tab:middle{\n"
  "   background: url(c:/backup4.png);\n"
  "}\n"
  "\n"
  "QTabBar::tab:first:selected{\n"
  "     background: url(c:/backup.png);\n"
  "}\n"
  "\n"
  "QTabBar::tab:middle:selected{\n"
  "     background: url(c:/backup3.png);\n"
  "}\n"
  "\n"
  "QTabBar::tab:last{\n"
  "     background: url(c:/backup5.png);\n"
  "}\n"
  "QTabBar::tab:last:selected{\n"
  "     background: url(c:/backup6.png);\n"
  "}\n"
  "\n"
  ""));
          //탭 3개를 만드는 부분이다.
          tab = new QWidget();
          tab->setObjectName(QStringLiteral("tab"));
          tabWidget->addTab(tab, QString());

          tab_2 = new QWidget();
          tab_2->setObjectName(QStringLiteral("tab_2"));
          tabWidget->addTab(tab_2, QString());

          tab_3 = new QWidget();
          tab_2->setObjectName(QStringLiteral("tab_3"));
          tabWidget->addTab(tab_3, QString());

          //탭 1에 체크박스와 트리뷰를 넣어주는 부분이다.

          checkBox = new QCheckBox(tab);
          checkBox->setObjectName(QStringLiteral("checkBox"));
          checkBox->setGeometry(QRect(40, 10, 161, 31));
    checkBox->setText(QApplication::translate("BackupWidget_1", "System Backup", 0));

          checkBox_2 = new QCheckBox(tab);
          checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
          checkBox_2->setGeometry(QRect(40, 40, 161, 31));
    checkBox_2->setText(QApplication::translate("BackupWidget_1", "Volume Backup", 0));


          checkBox_3 = new QCheckBox(tab);
          checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
          checkBox_3->setGeometry(QRect(40, 70, 161, 31));
    checkBox_3->setText(QApplication::translate("BackupWidget_1", "File Backup", 0));

    //

    //TreeView를 띄우는 새 창을 만드는 버튼

    pathButton = new QPushButton(tab);
    pathButton->setObjectName(QStringLiteral("pathButton"));
    pathButton->setGeometry(QRect(700, 135, 47, 23));
    pathButton->setText(QApplication::translate("BackupWidget_1", "click", 0));
    connect(pathButton,SIGNAL(clicked()),this,SLOT(cratePathDialog()));


    pathLabel_1 = new QLabel(tab);
    pathLabel_1->setObjectName(QStringLiteral("pathLabel_1"));
    pathLabel_1->setGeometry(QRect(40, 140, 47, 13));
    pathLabel_1->setText(QApplication::translate("BackupWidget_1","PATH", 0));

    //PATH 그 자체;;
    pathLabel_2 = new QLabel(tab);
    pathLabel_2->setObjectName(QStringLiteral("pathLabel_2"));
    pathLabel_2->setGeometry(QRect(120, 95, 540, 103)); // X,Y,width,height

    //실제 PATH 를 띄우는 경로. 사용자가 직접 입력 할 수 있도록 수정이 필요해 보인다.
    //글자도 잘림. 우선 나중에 수정하는걸로.









  //        label_2->setText(QApplication::translate("MainWindow", "password", 0));



      //글씨 넣기
     //     tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "yeah", 0));
           //  tabWidget->setTabIcon(tabWidget->indexOf(tab),icon);
           // tabWidget->setIconSize(pix.size());
          //이미지 넣기

      //      tabWidget->setTabPosition(QTabWidget::West);
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

