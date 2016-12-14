
#include "mainwindow.h"
#include "stdafx.h"
//메소드들 페이즈, 기능 별로 분리 필요
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

void MainWindow::viewFilelist(std::string sPath, QWidget * widget, QTreeView *treepath)
{
   dirmodel = new QFileSystemModel(widget);
   dirmodel->setRootPath(QString::fromStdString(sPath));
   treepath->setModel(dirmodel);
   dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
}

void MainWindow::getPathFromTree()
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

void MainWindow::popupMsgbox(const char * text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void MainWindow::goNextPage()
{
         QList<QWidget *> widgets = tabBackup->findChildren<QWidget*>(QString(),Qt::FindDirectChildrenOnly);
         if(tabindex <(widgets.count()-3))
        {
        widgets.at(tabindex)->hide();
         widgets.at(tabindex+1)->show();
        tabindex++;
                 qDebug()<<tabindex;
        }
        else
         {
             popupMsgbox("hey!! it's a last page okay?");
         }

}

void MainWindow::backBeforePage()
{
    if(tabindex != 0)
    {
    QList<QWidget *> widgets = tabBackup->findChildren<QWidget*>(QString(),Qt::FindDirectChildrenOnly);

   widgets.at(tabindex)->hide();
    widgets.at(tabindex-1)->show();
    tabindex--;
                 qDebug()<<tabindex;
    }

    else
    {
        popupMsgbox("do not click alright?");
    }

}

void MainWindow::backupPhase2()
{
    tabPhase2 = new QWidget(tabBackup);

    checkBoxBakOnce = new QCheckBox(tabPhase2);
    checkBoxBakOnce->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce->setGeometry(QRect(40, 10, 161, 31));
    checkBoxBakOnce->setText(QApplication::translate("BackupWidget_1", "Once", 0));

    checkBoxBakPerio = new QCheckBox(tabPhase2);
    checkBoxBakPerio->setObjectName(QStringLiteral("checkBoxBakPerio"));
    checkBoxBakPerio->setGeometry(QRect(40, 40, 161, 31));
    checkBoxBakPerio->setText(QApplication::translate("BackupWidget_1", "Periodic", 0));

    ButtonBakPerio = new QPushButton(tabPhase2);
    ButtonBakPerio->setObjectName(QStringLiteral("ButtonBakPerio"));
    ButtonBakPerio->setGeometry(QRect(60, 80, 210, 70));
    ButtonBakPerio->setText(QApplication::translate("BackupWidget_1", "Setup Period", 0));
    tabPhase2->hide();

   tabPhase3 = new QWidget(tabBackup);
    checkBoxBakOnce2 = new QCheckBox(tabPhase3);
    checkBoxBakOnce2->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce2->setGeometry(QRect(140, 20, 161, 31));
    checkBoxBakOnce2->setText(QApplication::translate("BackupWidget_1", "Once", 0));

    tabPhase3->hide();

    tabPhase4 = new QWidget(tabBackup);

    checkBoxBakOnce3 = new QCheckBox(tabPhase4);
    checkBoxBakOnce3->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce3->setGeometry(QRect(340, 20, 161, 31));
    checkBoxBakOnce3->setText(QApplication::translate("BackupWidget_1", "twice", 0));

    tabPhase4->hide();

    tabPhase5 = new QWidget(tabBackup);

    checkBoxBakOnce4 = new QCheckBox(tabPhase5);
    checkBoxBakOnce4->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce4->setGeometry(QRect(540, 20, 161, 31));
    checkBoxBakOnce4->setText(QApplication::translate("BackupWidget_1", "just like tt", 0));

    tabPhase5->hide();

    tabPhase6 = new QWidget(tabBackup);
    checkBoxBakOnce5 = new QCheckBox(tabPhase6);
    checkBoxBakOnce5->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce5->setGeometry(QRect(440, 20, 161, 31));
    checkBoxBakOnce5->setText(QApplication::translate("BackupWidget_1", "umm it's salty", 0));

    tabPhase6->hide();
}

 //트리를 띄울 Dialog를 만든다.
void MainWindow::cratePathDialog()
{
    treeDialog = new QDialog();
    treeView = new QTreeView(treeDialog);
    treeView->setObjectName(QStringLiteral("treeView"));
    treeView->setGeometry(QRect(30, 100, 256, 192));
    MainWindow::viewFilelist("C:/",treeDialog,treeView);
    MainWindow::getPathFromTree();

    buttonDiaPath = new QPushButton(treeDialog);
    buttonDiaPath->setObjectName(QStringLiteral("buttonDiaPath"));
    buttonDiaPath->setGeometry(QRect(100, 340, 75, 23));
    buttonDiaPath->setText(QApplication::translate("treeDialog", "click", 0));


     connect(treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(getPathFromTree()));
     //사용자가 클릭하는 트리 값 받아오기

     connect(buttonDiaPath,SIGNAL(clicked(bool)),this,SLOT(convertPathToLabel()));
     //ok 누르면 다이얼로그 종료


     treeDialog->exec();
}

    /*
     * 푸쉬버튼,라인에딧,라벨 등 단순한 것들을 함수화 할 필요가 있어보임(예정)
     *
     */



void MainWindow::on_pushButton_clicked()
{

  QString enteredID = ui->lineEdit->text();
  QString enteredPW = ui->lineEdit_2->text();

 if((QString::compare(enteredID,QString::fromStdString(dbID),Qt::CaseSensitive) == 0) && (QString::compare(enteredPW,QString::fromStdString(dbPW),Qt::CaseSensitive)) == 0)
    {
     popupMsgbox("Login Success!!");
     ui->centralWidget->hide();
     //다음 창으로

     BackupWidget_1 = new QWidget(this);
     BackupWidget_1->resize(1057,634);
     this->setCentralWidget(BackupWidget_1);

     //탭 위젯 추가하기
          tabWidget = new QTabWidget(BackupWidget_1);
          tabWidget->setObjectName(QStringLiteral("tabWidget"));
          tabWidget->setGeometry(QRect(30, 100, 391, 171));
          tabWidget->resize( 800,300);

          // 탭에 아이콘을 넣는 부분이다. CSS를 사용해서 넣어줌 * 함수화 필요*
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
          tabBackup = new QWidget();
          tabBackup->setObjectName(QStringLiteral("tabBackup"));
          tabWidget->addTab(tabBackup, QString());

          tabBackupSub = new QWidget(tabBackup);

          tabRecovery = new QWidget();
          tabRecovery->setObjectName(QStringLiteral("tabRecovery"));
          tabWidget->addTab(tabRecovery, QString());

          tabStatus = new QWidget();
          tabStatus->setObjectName(QStringLiteral("tabStatus"));
          tabWidget->addTab(tabStatus, QString());

          //탭 1에 체크박스와 트리뷰를 넣어주는 부분이다.

        checkBoxBakSys = new QCheckBox(tabBackupSub);
         checkBoxBakSys->setObjectName(QStringLiteral("checkBoxBakSys"));
          checkBoxBakSys->setGeometry(QRect(40, 10, 161, 31));
    checkBoxBakSys->setText(QApplication::translate("BackupWidget_1", "System Backup", 0));

          checkBoxBakVol = new QCheckBox(tabBackupSub);
          checkBoxBakVol->setObjectName(QStringLiteral("checkBoxBakVol"));
          checkBoxBakVol->setGeometry(QRect(40, 40, 161, 31));
    checkBoxBakVol->setText(QApplication::translate("BackupWidget_1", "Volume Backup", 0));


          checkBoxBakFile = new QCheckBox(tabBackupSub);
          checkBoxBakFile->setObjectName(QStringLiteral("checkBoxBakFile"));
          checkBoxBakFile->setGeometry(QRect(40, 70, 161, 31));
    checkBoxBakFile->setText(QApplication::translate("BackupWidget_1", "File Backup", 0));

    //

    //TreeView를 띄우는 새 창을 만드는 버튼

    pathButton = new QPushButton(tabBackupSub);
    pathButton->setObjectName(QStringLiteral("pathButton"));
    pathButton->setGeometry(QRect(700, 135, 47, 23));
    pathButton->setText(QApplication::translate("BackupWidget_1", "click", 0));
    connect(pathButton,SIGNAL(clicked()),this,SLOT(cratePathDialog()));


    pathLabel_1 = new QLabel(tabBackupSub);
    pathLabel_1->setObjectName(QStringLiteral("pathLabel_1"));
    pathLabel_1->setGeometry(QRect(40, 140, 47, 13));
    pathLabel_1->setText(QApplication::translate("BackupWidget_1","PATH", 0));

    //PATH 그 자체;;
    pathLabel_2 = new QLabel(tabBackupSub);
    pathLabel_2->setObjectName(QStringLiteral("pathLabel_2"));
    pathLabel_2->setGeometry(QRect(120, 95, 540, 103)); // X,Y,width,height

    backupPhase2();

    nextButtonBackup = new QPushButton(BackupWidget_1);
    nextButtonBackup->setObjectName(QStringLiteral("nextButtonBackup"));
    nextButtonBackup->setGeometry(QRect(650, 200, 80, 40));
    nextButtonBackup->setText(QApplication::translate("BackupWidget_1", "NEXT", 0));
    connect(nextButtonBackup,SIGNAL(clicked()),this,SLOT(goNextPage()));


    prevButtonBackup = new QPushButton(BackupWidget_1);
    prevButtonBackup->setObjectName(QStringLiteral("prevButtonBackup"));
    prevButtonBackup->setGeometry(QRect(550, 200, 80, 40));
    prevButtonBackup->setText(QApplication::translate("BackupWidget_1", "PREV", 0));
    connect(prevButtonBackup,SIGNAL(clicked()),this,SLOT(backBeforePage()));


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

