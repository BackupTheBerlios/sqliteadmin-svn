/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Sun Feb 11 00:57:01 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *action_About;
    QAction *action_Open;
    QAction *actionC_lose;
    QAction *action_Quit;
    QAction *action_New;
    QAction *actionAdd_Table;
    QAction *actionDelete_Table;
    QAction *actionOpen_SQL_File;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *mainSplitter;
    QSplitter *leftSplitter;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QLabel *databaseLabel;
    QListWidget *tablesList;
    QWidget *layoutWidget1;
    QVBoxLayout *vboxLayout1;
    QLabel *tableLabel;
    QTabWidget *tableTabWidget;
    QWidget *fieldTab;
    QGridLayout *gridLayout1;
    QTableView *fieldsTableView;
    QTabWidget *centalTabWidget;
    QWidget *sqlTab;
    QGridLayout *gridLayout2;
    QSplitter *rightSplitter;
    QWidget *layoutWidget2;
    QVBoxLayout *vboxLayout2;
    QLabel *label_2;
    QTextEdit *sqlTextEdit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *saveSqlButton;
    QPushButton *clearSqlButton;
    QPushButton *runSqlButton;
    QWidget *layoutWidget3;
    QVBoxLayout *vboxLayout3;
    QLabel *label_3;
    QTableView *resultTableView;
    QWidget *historyTab;
    QGridLayout *gridLayout3;
    QListWidget *historyList;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QPushButton *clearHistoryButton;
    QPushButton *saveHistoryButton;
    QMenuBar *menubar;
    QMenu *menu_Help;
    QMenu *menu_Edit;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    action_About = new QAction(MainWindow);
    action_About->setObjectName(QString::fromUtf8("action_About"));
    action_Open = new QAction(MainWindow);
    action_Open->setObjectName(QString::fromUtf8("action_Open"));
    actionC_lose = new QAction(MainWindow);
    actionC_lose->setObjectName(QString::fromUtf8("actionC_lose"));
    action_Quit = new QAction(MainWindow);
    action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
    action_New = new QAction(MainWindow);
    action_New->setObjectName(QString::fromUtf8("action_New"));
    actionAdd_Table = new QAction(MainWindow);
    actionAdd_Table->setObjectName(QString::fromUtf8("actionAdd_Table"));
    actionDelete_Table = new QAction(MainWindow);
    actionDelete_Table->setObjectName(QString::fromUtf8("actionDelete_Table"));
    actionOpen_SQL_File = new QAction(MainWindow);
    actionOpen_SQL_File->setObjectName(QString::fromUtf8("actionOpen_SQL_File"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    mainSplitter = new QSplitter(centralwidget);
    mainSplitter->setObjectName(QString::fromUtf8("mainSplitter"));
    mainSplitter->setOrientation(Qt::Horizontal);
    leftSplitter = new QSplitter(mainSplitter);
    leftSplitter->setObjectName(QString::fromUtf8("leftSplitter"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(1);
    sizePolicy.setHeightForWidth(leftSplitter->sizePolicy().hasHeightForWidth());
    leftSplitter->setSizePolicy(sizePolicy);
    leftSplitter->setBaseSize(QSize(100, 0));
    leftSplitter->setOrientation(Qt::Vertical);
    layoutWidget = new QWidget(leftSplitter);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    databaseLabel = new QLabel(layoutWidget);
    databaseLabel->setObjectName(QString::fromUtf8("databaseLabel"));
    databaseLabel->setBaseSize(QSize(200, 0));
    databaseLabel->setTextFormat(Qt::AutoText);

    vboxLayout->addWidget(databaseLabel);

    tablesList = new QListWidget(layoutWidget);
    tablesList->setObjectName(QString::fromUtf8("tablesList"));
    tablesList->setAlternatingRowColors(true);
    tablesList->setSelectionBehavior(QAbstractItemView::SelectRows);
    tablesList->setSortingEnabled(true);

    vboxLayout->addWidget(tablesList);

    leftSplitter->addWidget(layoutWidget);
    layoutWidget1 = new QWidget(leftSplitter);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    vboxLayout1 = new QVBoxLayout(layoutWidget1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    tableLabel = new QLabel(layoutWidget1);
    tableLabel->setObjectName(QString::fromUtf8("tableLabel"));

    vboxLayout1->addWidget(tableLabel);

    tableTabWidget = new QTabWidget(layoutWidget1);
    tableTabWidget->setObjectName(QString::fromUtf8("tableTabWidget"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(tableTabWidget->sizePolicy().hasHeightForWidth());
    tableTabWidget->setSizePolicy(sizePolicy1);
    tableTabWidget->setBaseSize(QSize(200, 0));
    tableTabWidget->setTabPosition(QTabWidget::North);
    fieldTab = new QWidget();
    fieldTab->setObjectName(QString::fromUtf8("fieldTab"));
    gridLayout1 = new QGridLayout(fieldTab);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    fieldsTableView = new QTableView(fieldTab);
    fieldsTableView->setObjectName(QString::fromUtf8("fieldsTableView"));
    fieldsTableView->setAlternatingRowColors(true);

    gridLayout1->addWidget(fieldsTableView, 0, 0, 1, 1);

    tableTabWidget->addTab(fieldTab, QApplication::translate("MainWindow", "Fields", 0, QApplication::UnicodeUTF8));

    vboxLayout1->addWidget(tableTabWidget);

    leftSplitter->addWidget(layoutWidget1);
    mainSplitter->addWidget(leftSplitter);
    centalTabWidget = new QTabWidget(mainSplitter);
    centalTabWidget->setObjectName(QString::fromUtf8("centalTabWidget"));
    centalTabWidget->setTabPosition(QTabWidget::North);
    sqlTab = new QWidget();
    sqlTab->setObjectName(QString::fromUtf8("sqlTab"));
    gridLayout2 = new QGridLayout(sqlTab);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    rightSplitter = new QSplitter(sqlTab);
    rightSplitter->setObjectName(QString::fromUtf8("rightSplitter"));
    rightSplitter->setOrientation(Qt::Vertical);
    layoutWidget2 = new QWidget(rightSplitter);
    layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
    vboxLayout2 = new QVBoxLayout(layoutWidget2);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    label_2 = new QLabel(layoutWidget2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy2);

    vboxLayout2->addWidget(label_2);

    sqlTextEdit = new QTextEdit(layoutWidget2);
    sqlTextEdit->setObjectName(QString::fromUtf8("sqlTextEdit"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy3.setHorizontalStretch(1);
    sizePolicy3.setVerticalStretch(1);
    sizePolicy3.setHeightForWidth(sqlTextEdit->sizePolicy().hasHeightForWidth());
    sqlTextEdit->setSizePolicy(sizePolicy3);
    sqlTextEdit->setMinimumSize(QSize(0, 100));
    sqlTextEdit->setMaximumSize(QSize(16777215, 16777215));
    sqlTextEdit->setBaseSize(QSize(0, 100));

    vboxLayout2->addWidget(sqlTextEdit);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    saveSqlButton = new QPushButton(layoutWidget2);
    saveSqlButton->setObjectName(QString::fromUtf8("saveSqlButton"));
    saveSqlButton->setEnabled(false);

    hboxLayout->addWidget(saveSqlButton);

    clearSqlButton = new QPushButton(layoutWidget2);
    clearSqlButton->setObjectName(QString::fromUtf8("clearSqlButton"));
    clearSqlButton->setEnabled(false);

    hboxLayout->addWidget(clearSqlButton);

    runSqlButton = new QPushButton(layoutWidget2);
    runSqlButton->setObjectName(QString::fromUtf8("runSqlButton"));
    runSqlButton->setEnabled(false);

    hboxLayout->addWidget(runSqlButton);


    vboxLayout2->addLayout(hboxLayout);

    rightSplitter->addWidget(layoutWidget2);
    layoutWidget3 = new QWidget(rightSplitter);
    layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
    vboxLayout3 = new QVBoxLayout(layoutWidget3);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(0);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    label_3 = new QLabel(layoutWidget3);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    vboxLayout3->addWidget(label_3);

    resultTableView = new QTableView(layoutWidget3);
    resultTableView->setObjectName(QString::fromUtf8("resultTableView"));
    resultTableView->setAlternatingRowColors(true);
    resultTableView->setSortingEnabled(true);

    vboxLayout3->addWidget(resultTableView);

    rightSplitter->addWidget(layoutWidget3);

    gridLayout2->addWidget(rightSplitter, 0, 0, 1, 1);

    centalTabWidget->addTab(sqlTab, QApplication::translate("MainWindow", "SQL", 0, QApplication::UnicodeUTF8));
    historyTab = new QWidget();
    historyTab->setObjectName(QString::fromUtf8("historyTab"));
    gridLayout3 = new QGridLayout(historyTab);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    historyList = new QListWidget(historyTab);
    historyList->setObjectName(QString::fromUtf8("historyList"));

    gridLayout3->addWidget(historyList, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    clearHistoryButton = new QPushButton(historyTab);
    clearHistoryButton->setObjectName(QString::fromUtf8("clearHistoryButton"));
    clearHistoryButton->setEnabled(false);

    hboxLayout1->addWidget(clearHistoryButton);

    saveHistoryButton = new QPushButton(historyTab);
    saveHistoryButton->setObjectName(QString::fromUtf8("saveHistoryButton"));
    saveHistoryButton->setEnabled(false);

    hboxLayout1->addWidget(saveHistoryButton);


    gridLayout3->addLayout(hboxLayout1, 1, 0, 1, 1);

    centalTabWidget->addTab(historyTab, QApplication::translate("MainWindow", "History", 0, QApplication::UnicodeUTF8));
    mainSplitter->addWidget(centalTabWidget);

    gridLayout->addWidget(mainSplitter, 0, 0, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 783, 29));
    menu_Help = new QMenu(menubar);
    menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
    menu_Edit = new QMenu(menubar);
    menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
    menu_File = new QMenu(menubar);
    menu_File->setObjectName(QString::fromUtf8("menu_File"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setOrientation(Qt::Horizontal);
    MainWindow->addToolBar(static_cast<Qt::ToolBarArea>(4), toolBar);
    label_2->setBuddy(sqlTextEdit);

    menubar->addAction(menu_File->menuAction());
    menubar->addAction(menu_Edit->menuAction());
    menubar->addAction(menu_Help->menuAction());
    menu_Help->addAction(action_About);
    menu_Edit->addAction(actionAdd_Table);
    menu_Edit->addAction(actionDelete_Table);
    menu_File->addAction(action_Open);
    menu_File->addAction(actionOpen_SQL_File);
    menu_File->addAction(action_New);
    menu_File->addAction(actionC_lose);
    menu_File->addSeparator();
    menu_File->addAction(action_Quit);

    retranslateUi(MainWindow);

    QSize size(783, 767);
    size = size.expandedTo(MainWindow->minimumSizeHint());
    MainWindow->resize(size);

    QObject::connect(actionC_lose, SIGNAL(triggered()), tablesList, SLOT(clear()));
    QObject::connect(actionC_lose, SIGNAL(triggered()), fieldsTableView, SLOT(reset()));
    QObject::connect(actionC_lose, SIGNAL(triggered()), databaseLabel, SLOT(clear()));
    QObject::connect(actionC_lose, SIGNAL(triggered()), resultTableView, SLOT(reset()));

    centalTabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3WDG SQLite Admin", 0, QApplication::UnicodeUTF8));
    action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
    action_Open->setText(QApplication::translate("MainWindow", "&Open Database File...", 0, QApplication::UnicodeUTF8));
    actionC_lose->setText(QApplication::translate("MainWindow", "C&lose", 0, QApplication::UnicodeUTF8));
    action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
    action_New->setText(QApplication::translate("MainWindow", "&New Database", 0, QApplication::UnicodeUTF8));
    actionAdd_Table->setText(QApplication::translate("MainWindow", "Add Table", 0, QApplication::UnicodeUTF8));
    actionDelete_Table->setText(QApplication::translate("MainWindow", "Delete Table", 0, QApplication::UnicodeUTF8));
    actionOpen_SQL_File->setText(QApplication::translate("MainWindow", "Open &SQL File...", 0, QApplication::UnicodeUTF8));
    databaseLabel->setText(QApplication::translate("MainWindow", "Database", 0, QApplication::UnicodeUTF8));
    tableLabel->setText(QString());
    tableTabWidget->setTabText(tableTabWidget->indexOf(fieldTab), QApplication::translate("MainWindow", "Fields", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "SQL &Editor", 0, QApplication::UnicodeUTF8));
    saveSqlButton->setText(QApplication::translate("MainWindow", "Sa&ve", 0, QApplication::UnicodeUTF8));
    clearSqlButton->setText(QApplication::translate("MainWindow", "&Clear", 0, QApplication::UnicodeUTF8));
    runSqlButton->setText(QApplication::translate("MainWindow", "&Run SQL", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Result - Table Edit", 0, QApplication::UnicodeUTF8));
    centalTabWidget->setTabText(centalTabWidget->indexOf(sqlTab), QApplication::translate("MainWindow", "SQL", 0, QApplication::UnicodeUTF8));
    clearHistoryButton->setText(QApplication::translate("MainWindow", "&Clear", 0, QApplication::UnicodeUTF8));
    saveHistoryButton->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
    centalTabWidget->setTabText(centalTabWidget->indexOf(historyTab), QApplication::translate("MainWindow", "History", 0, QApplication::UnicodeUTF8));
    menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
    menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // MAINWINDOW_H
