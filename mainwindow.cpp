#include "mainwindow.h"
#include "stdafx.h"
//메소드들 페이즈, 기능 별로 분리 필요
PlanBUIClass::PlanBUIClass(QWidget *parent) :
    QMainWindow (parent),
    ui(new Ui::PlanBUIClass)
{
    ui->setupUi(this);
}

PlanBUIClass::~PlanBUIClass()
{
    delete ui;
}
bool PlanBUIClass::loginCheck(QString ID, QString PW)
{


   if((QString::compare(ID,QString::fromStdString(dbID),Qt::CaseSensitive) == 0) && (QString::compare(PW,QString::fromStdString(dbPW),Qt::CaseSensitive)) == 0)
      {
       return true;
      }
   else
   {
    return false;
   }

}

void PlanBUIClass::viewFilelist(std::string sPath, QWidget * widget, QTreeView *treePath)
{
   dirmodel = new QFileSystemModel(widget);
   dirmodel->setRootPath(QString::fromStdString(sPath));
   treePath->setModel(dirmodel);
   dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
}

void PlanBUIClass::getPathFromTree()
//주어진 Tree로 부터 경로를 얻는다. * 인자 받는 수정 필요 *
{
    QModelIndexList list =  treeView->selectionModel()->selectedIndexes();
    foreach (QModelIndex index, list)
    {
       absPath = dirmodel->filePath(index);
       qDebug() << absPath; //For Debug
    }
}

void PlanBUIClass::convertPathToLabel()
{
    pathLabel_2->setText(QApplication::translate("BackupWidget_1",absPath.toUtf8().constData(), 0));
    treeDialog->close();
}

void PlanBUIClass::popupMsgbox(const char * text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void PlanBUIClass::goNextPage(QWidget * currentTab)
{

    QList<QWidget *> widgets = currentTab->findChildren<QWidget*>(QString(),Qt::FindDirectChildrenOnly);
            if(tabindex <(widgets.count()-1))
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


void PlanBUIClass::backBeforePage(QWidget * currentTab)
{
    if(tabindex != 0)
      {
      QList<QWidget *> widgets = currentTab->findChildren<QWidget*>(QString(),Qt::FindDirectChildrenOnly);

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
bool PlanBUIClass::backgroundTab(void)
{
    BackupWidget_1 = new QWidget(this);
    BackupWidget_1->resize(850,434);
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

         tabRecoverySub = new QWidget(tabRecovery);

         tabStatus = new QWidget();
         tabStatus->setObjectName(QStringLiteral("tabStatus"));
         tabWidget->addTab(tabStatus, QString());

         tabStatusSub = new QWidget(tabStatus);

         return true;

}
int PlanBUIClass::getValueFromCheckbox(QButtonGroup * buttonGroup)
{
<<<<<<< HEAD
    int num=0;
=======
    int num;
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
    connect(buttonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),this,[=](int num)->int{num = buttonGroup->checkedId(); qDebug() << num; return num;});
    return num;
}

bool PlanBUIClass::backupPhase1(void)
{
   QButtonGroup * checkBoxBakGroup = new QButtonGroup(tabBackupSub);
<<<<<<< HEAD

     QCheckBox * checkBoxBakSys = new QCheckBox(tabBackupSub);
    checkBoxBakSys->setObjectName(QStringLiteral("checkBoxBakSys"));
    checkBoxBakSys->setGeometry(QRect(40, 10, 161, 31));
    checkBoxBakSys->setText(QApplication::translate("BackupWidget_1", "System Backup", 0));
=======

    QCheckBox * checkBoxBakSys = new QCheckBox(tabBackupSub);
     checkBoxBakSys->setObjectName(QStringLiteral("checkBoxBakSys"));
      checkBoxBakSys->setGeometry(QRect(40, 10, 161, 31));
      checkBoxBakSys->setText(QApplication::translate("BackupWidget_1", "System Backup", 0));

     QCheckBox * checkBoxBakVol = new QCheckBox(tabBackupSub);
      checkBoxBakVol->setObjectName(QStringLiteral("checkBoxBakVol"));
      checkBoxBakVol->setGeometry(QRect(40, 40, 161, 31));
    checkBoxBakVol->setText(QApplication::translate("BackupWidget_1", "Volume Backup", 0));
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412

    QCheckBox * checkBoxBakVol = new QCheckBox(tabBackupSub);
    checkBoxBakVol->setObjectName(QStringLiteral("checkBoxBakVol"));
    checkBoxBakVol->setGeometry(QRect(40, 40, 161, 31));
    checkBoxBakVol->setText(QApplication::translate("BackupWidget_1", "Volume Backup", 0));

<<<<<<< HEAD

    QCheckBox  * checkBoxBakFile = new QCheckBox(tabBackupSub);
    checkBoxBakFile->setObjectName(QStringLiteral("checkBoxBakFile"));
    checkBoxBakFile->setGeometry(QRect(40, 70, 161, 31));
    checkBoxBakFile->setText(QApplication::translate("BackupWidget_1", "File Backup", 0));

    checkBoxBakGroup->addButton(checkBoxBakSys);
    checkBoxBakGroup->addButton(checkBoxBakVol);
    checkBoxBakGroup->addButton(checkBoxBakFile);
=======
    QCheckBox  * checkBoxBakFile = new QCheckBox(tabBackupSub);
      checkBoxBakFile->setObjectName(QStringLiteral("checkBoxBakFile"));
      checkBoxBakFile->setGeometry(QRect(40, 70, 161, 31));
    checkBoxBakFile->setText(QApplication::translate("BackupWidget_1", "File Backup", 0));

    checkBoxBakGroup->addButton(checkBoxBakSys);
    checkBoxBakGroup->addButton(checkBoxBakVol);
    checkBoxBakGroup->addButton(checkBoxBakFile);

    checkedvalue = getValueFromCheckbox(checkBoxBakGroup); // 백업 종류를 리턴
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412

    backupType = getValueFromCheckbox(checkBoxBakGroup); // 백업 종류를 리턴

    QPushButton *pathButton = new QPushButton(tabBackupSub);
    pathButton->setObjectName(QStringLiteral("pathButton"));
    pathButton->setGeometry(QRect(700, 135, 47, 23));
    pathButton->setText(QApplication::translate("BackupWidget_1", "click", 0));
    connect(pathButton,SIGNAL(clicked()),this,SLOT(cratePathDialog()));

<<<<<<< HEAD

    QLabel * pathLabel_1 = new QLabel(tabBackupSub);
    pathLabel_1->setObjectName(QStringLiteral("pathLabel_1"));
    pathLabel_1->setGeometry(QRect(40, 140, 47, 13));
    pathLabel_1->setText(QApplication::translate("BackupWidget_1","PATH", 0));
=======
QLabel * pathLabel_1 = new QLabel(tabBackupSub);
pathLabel_1->setObjectName(QStringLiteral("pathLabel_1"));
pathLabel_1->setGeometry(QRect(40, 140, 47, 13));
pathLabel_1->setText(QApplication::translate("BackupWidget_1","PATH", 0));
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412

//PATH 그 자체;;
    pathLabel_2 = new QLabel(tabBackupSub);
    pathLabel_2->setObjectName(QStringLiteral("pathLabel_2"));
    pathLabel_2->setGeometry(QRect(120, 95, 540, 103)); // X,Y,width,height


if(backupType == Indexes::NOTFOUND)
{
    return false;
}
else
{
    return true;
}


<<<<<<< HEAD
}

bool PlanBUIClass::backupPhase2(void)
=======

if(checkedvalue == Indexes::NOTFOUND)
{
    return false;
}
else
{
    return true;
}


}

void PlanBUIClass::backupPhase2(void)
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
{

    tabPhase2 = new QWidget(tabBackup);

<<<<<<< HEAD

=======
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
    QCheckBox * checkBoxBakOnce = new QCheckBox(tabPhase2);
    checkBoxBakOnce->setObjectName(QStringLiteral("checkBoxBakOnce"));
    checkBoxBakOnce->setGeometry(QRect(40, 10, 161, 31));
    checkBoxBakOnce->setText(QApplication::translate("BackupWidget_1", "Once", 0));

    QCheckBox * checkBoxBakPerio = new QCheckBox(tabPhase2);
    checkBoxBakPerio->setObjectName(QStringLiteral("checkBoxBakPerio"));
    checkBoxBakPerio->setGeometry(QRect(40, 40, 161, 31));
    checkBoxBakPerio->setText(QApplication::translate("BackupWidget_1", "Periodic", 0));

    QButtonGroup *checkBoxBakGroup = new QButtonGroup(tabPhase2);

    checkBoxBakGroup->addButton(checkBoxBakOnce);
    checkBoxBakGroup->addButton(checkBoxBakPerio);

    backupPeriod = getValueFromCheckbox(checkBoxBakGroup);

    ButtonBakPerio = new QPushButton(tabPhase2);
    ButtonBakPerio->setObjectName(QStringLiteral("ButtonBakPerio"));
    ButtonBakPerio->setGeometry(QRect(60, 80, 210, 70));
    ButtonBakPerio->setText(QApplication::translate("BackupWidget_1", "Setup Period", 0));
    tabPhase2->hide();

<<<<<<< HEAD
    if(backupPeriod == Indexes::NOTFOUND)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void PlanBUIClass::addRowToRecoveryTable(QTableWidget *tableWidget,const char * title,const char * path, const char * time)
=======


}

void PlanBUIClass::addRowToRecoveryTable(const char * title,const char * path, const char * time)
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
{

                     tableWidget->setItem(rowindex,Indexes::Title,new QTableWidgetItem(title));
                     tableWidget->setItem(rowindex,Indexes::Path,new QTableWidgetItem(path));
                     tableWidget->setItem(rowindex,Indexes::Time,new QTableWidgetItem(time));
                     tableWidget->setCellWidget(rowindex,Indexes::Select,new QCheckBox(tableWidget));
                     rowindex++;
}
//오버로드 필요할 수도 있음.

void PlanBUIClass::delRowToRecvoeryTable(const char * title)
{
    QList<QTableWidgetItem *> list = table->findItems(title,Qt::MatchExactly);
    table->removeRow(list.at(0)->row());
}


void PlanBUIClass::recoveryPhase1(void)
{
    table = new QTableWidget(tabRecoverySub);
    table->resize(700,200);
    table->setRowCount(10);
    table->setColumnCount(4);
  table->setHorizontalHeaderLabels(QString("Title;Path;Time;Select").split(";")); //column

    addRowToRecoveryTable(table,"asdf","c:\\","2016-10-25"); // 이 메소드를 사용하여 테이블에 값 추가
    addRowToRecoveryTable(table,"yeah","c:\\cc","2016-16-31");
    addRowToRecoveryTable(table,"yeah","c:\\cc","2016-16-31");


    QButtonGroup *checkBoxBakGroup = new QButtonGroup();
    QList<QCheckBox *> list = table->findChildren<QCheckBox*>(NULL,Qt::FindChildrenRecursively);
    Q_FOREACH (QCheckBox * checkbox, list )
    {
            checkBoxBakGroup->addButton(checkbox);
    }
    recoverRow = getValueFromCheckbox(checkBoxBakGroup);



  //    delRowToRecvoeryTable("asdf"); // 이 메소드를 통하여 테이블의 값 삭제

    table->show();
}


 //트리를 띄울 Dialog를 만든다.
void PlanBUIClass::cratePathDialog()
{
    treeDialog = new QDialog();
    treeView = new QTreeView(treeDialog);
    treeView->setObjectName(QStringLiteral("treeView"));
    treeView->setGeometry(QRect(30, 100, 256, 192));
    PlanBUIClass::viewFilelist("C:/",treeDialog,treeView);
  //  PlanBUIClass::getPathFromTree();

    QPushButton * buttonDiaPath = new QPushButton(treeDialog);
    buttonDiaPath->setObjectName(QStringLiteral("buttonDiaPath"));
    buttonDiaPath->setGeometry(QRect(100, 340, 75, 23));
    buttonDiaPath->setText(QApplication::translate("treeDialog", "click", 0));

     connect(treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this,SLOT(getPathFromTree()));
     //사용자가 클릭하는 트리 값 받아오기

     connect(buttonDiaPath,SIGNAL(clicked(bool)),this,SLOT(convertPathToLabel()));
     //ok 누르면 다이얼로그 종료

     treeDialog->exec();
}

    /*
     * 푸쉬버튼,라인에딧,라벨 등 단순한 것들을 함수화 할 필요가 있어보임(예정)
     *
     */

void PlanBUIClass::execTrayIcon(void)
{


    trayIcon = new QSystemTrayIcon(this);
    trayMenu = new QMenu();
    QIcon icon("c:\\tray.png");

    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Plan B Tray Icon");
    trayIcon->setContextMenu(trayMenu);

    trayIcon->show();
    this->hide();

    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Plan B Tray Icon");
    trayIcon->setContextMenu(trayMenu);

    showaction = new QAction(tr("&show"),trayMenu);
    exitaction = new QAction(tr("&exit"),trayMenu);


    trayMenu->addAction(showaction);
    trayMenu->addAction(exitaction);

    connect(showaction,SIGNAL(triggered(bool)),trayIcon,SLOT(hide()));
    connect(showaction,SIGNAL(triggered(bool)),this,SLOT(show()));

    connect(exitaction,SIGNAL(triggered(bool)),trayIcon,SLOT(hide()));
    connect(exitaction,SIGNAL(triggered(bool)),this,SLOT(hide()));




}

void PlanBUIClass::mapNextBackButton(void)
{
    qDebug() << tabWidget->currentIndex();
    switch(tabWidget->currentIndex())
        {
            case 0: //tabBackup
        nextButtonBackup->disconnect(); //이전 시그널을 끊어줘야 함.
        prevButtonBackup->disconnect();
         tabindex = 0;
                connect(nextButtonBackup,&QPushButton::clicked,this,[this]{goNextPage(tabBackup); });
                connect(prevButtonBackup,&QPushButton::clicked,this,[this]{backBeforePage(tabBackup); });
                qDebug() << tabWidget->currentIndex() << "hi";
            break;
            case 1: //tabRecovery
         tabindex = 0;
         nextButtonBackup->disconnect();
         prevButtonBackup->disconnect();
                connect(prevButtonBackup,&QPushButton::clicked,this,[this]{backBeforePage(tabRecovery); });
                connect(nextButtonBackup,&QPushButton::clicked,this,[this]{goNextPage(tabRecovery); });
                qDebug() << tabWidget->currentIndex() << "hello";
            break;
            case 2: //tabStatus
         tabindex = 0;
         nextButtonBackup->disconnect();
         prevButtonBackup->disconnect();
                connect(prevButtonBackup,&QPushButton::clicked,this,[this]{backBeforePage(tabStatus); });
                connect(nextButtonBackup,&QPushButton::clicked,this,[this]{goNextPage(tabStatus); });
                qDebug() << tabWidget->currentIndex() << "good";
            break;
        }
}

void PlanBUIClass::closeEvent(QCloseEvent *event) //프로그램을 종료시 처리
{
    if(((this->isVisible()) == false) && ((trayIcon->isVisible()) == false))
    {
            event->accept();
    }
    else
    {
        execTrayIcon();
        event->ignore();
    }

}

void PlanBUIClass::on_pushButton_clicked() //사실상의 메인함수
{
    QString enteredID = ui->lineEdit->text();
    QString enteredPW = ui->lineEdit_2->text();

    if(loginCheck(enteredID,enteredPW))
    {
        popupMsgbox("Login Success!!");
        ui->centralWidget->hide();

        backgroundTab();

        backupPhase1();

        backupPhase2();

        recoveryPhase1();

        nextButtonBackup = new QPushButton(BackupWidget_1);
        nextButtonBackup->setObjectName(QStringLiteral("nextButtonBackup"));
        nextButtonBackup->setGeometry(QRect(650, 500, 80, 40));
        nextButtonBackup->setText(QApplication::translate("BackupWidget_1", "NEXT", 0));


        prevButtonBackup = new QPushButton(BackupWidget_1);
        prevButtonBackup->setObjectName(QStringLiteral("prevButtonBackup"));
        prevButtonBackup->setGeometry(QRect(550, 500, 80, 40));
<<<<<<< HEAD
        prevButtonBackup->setText(QApplication::translate("BackupWidget_1" , "PREV", 0));
=======
        prevButtonBackup->setText(QApplication::translate("BackupWidget_1", "PREV", 0)); //ui_PlanBUIClass.h 헤더 꺼내기
>>>>>>> 3b407f9df3ee8680e213a8e6136e78d8624ed412
        /*
         * 탭 위젯 바깥에 만들지, 아니면 탭 위젯 안에 만들어 메소드화 한 뒤 관리할건지 필요함.
         *
        */

        connect(nextButtonBackup,&QPushButton::clicked,this,[this]{goNextPage(tabBackup); });
        connect(prevButtonBackup,&QPushButton::clicked,this,[this]{backBeforePage(tabBackup); });

        connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(mapNextBackButton()));
    }
    else
    {
        popupMsgbox("incorrect id or password.");
    }


}
