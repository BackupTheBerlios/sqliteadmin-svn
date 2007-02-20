#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *action_About;
    QAction *action_Open;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *mainSplitter;
    QSplitter *leftSplitter;
    QWidget *widget;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QTreeView *databaseTreeView;
    QWidget *widget1;
    QVBoxLayout *vboxLayout1;
    QLabel *tableLabel;
    QTabWidget *tableTabWidget;
    QWidget *fieldTab;
    QGridLayout *gridLayout1;
    QTableView *tableFieldTableView;
    QTabWidget *centalTabWidget;
    QWidget *sqlTab;
    QGridLayout *gridLayout2;
    QSplitter *rightSplitter;
    QWidget *widget2;
    QVBoxLayout *vboxLayout2;
    QLabel *label_2;
    QTextEdit *sqlTextEdit;
    QWidget *widget3;
    QVBoxLayout *vboxLayout3;
    QLabel *label_3;
    QTableView *resultTableView;
    QWidget *historyTab;
    QGridLayout *gridLayout3;
    QTextEdit *textEdit_3;
    QMenuBar *menubar;
    QMenu *menu_Help;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainWindow)
    {
    mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
    mainWindow->resize(QSize(673, 774).expandedTo(mainWindow->minimumSizeHint()));
    action_About = new QAction(mainWindow);
    action_About->setObjectName(QString::fromUtf8("action_About"));
    action_Open = new QAction(mainWindow);
    action_Open->setObjectName(QString::fromUtf8("action_Open"));
    centralwidget = new QWidget(mainWindow);
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
    widget = new QWidget(leftSplitter);
    widget->setObjectName(QString::fromUtf8("widget"));
    vboxLayout = new QVBoxLayout(widget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(widget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setBaseSize(QSize(200, 0));
    label->setTextFormat(Qt::AutoText);

    vboxLayout->addWidget(label);

    databaseTreeView = new QTreeView(widget);
    databaseTreeView->setObjectName(QString::fromUtf8("databaseTreeView"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(databaseTreeView->sizePolicy().hasHeightForWidth());
    databaseTreeView->setSizePolicy(sizePolicy1);
    databaseTreeView->setBaseSize(QSize(200, 400));

    vboxLayout->addWidget(databaseTreeView);

    leftSplitter->addWidget(widget);
    widget1 = new QWidget(leftSplitter);
    widget1->setObjectName(QString::fromUtf8("widget1"));
    vboxLayout1 = new QVBoxLayout(widget1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    tableLabel = new QLabel(widget1);
    tableLabel->setObjectName(QString::fromUtf8("tableLabel"));

    vboxLayout1->addWidget(tableLabel);

    tableTabWidget = new QTabWidget(widget1);
    tableTabWidget->setObjectName(QString::fromUtf8("tableTabWidget"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(tableTabWidget->sizePolicy().hasHeightForWidth());
    tableTabWidget->setSizePolicy(sizePolicy2);
    tableTabWidget->setBaseSize(QSize(200, 0));
    tableTabWidget->setTabPosition(QTabWidget::North);
    fieldTab = new QWidget();
    fieldTab->setObjectName(QString::fromUtf8("fieldTab"));
    gridLayout1 = new QGridLayout(fieldTab);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    tableFieldTableView = new QTableView(fieldTab);
    tableFieldTableView->setObjectName(QString::fromUtf8("tableFieldTableView"));

    gridLayout1->addWidget(tableFieldTableView, 0, 0, 1, 1);

    tableTabWidget->addTab(fieldTab, QApplication::translate("mainWindow", "Fields", 0, QApplication::UnicodeUTF8));

    vboxLayout1->addWidget(tableTabWidget);

    leftSplitter->addWidget(widget1);
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
    widget2 = new QWidget(rightSplitter);
    widget2->setObjectName(QString::fromUtf8("widget2"));
    vboxLayout2 = new QVBoxLayout(widget2);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    label_2 = new QLabel(widget2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy3);

    vboxLayout2->addWidget(label_2);

    sqlTextEdit = new QTextEdit(widget2);
    sqlTextEdit->setObjectName(QString::fromUtf8("sqlTextEdit"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy4.setHorizontalStretch(1);
    sizePolicy4.setVerticalStretch(1);
    sizePolicy4.setHeightForWidth(sqlTextEdit->sizePolicy().hasHeightForWidth());
    sqlTextEdit->setSizePolicy(sizePolicy4);
    sqlTextEdit->setMinimumSize(QSize(0, 100));
    sqlTextEdit->setMaximumSize(QSize(16777215, 16777215));
    sqlTextEdit->setBaseSize(QSize(0, 100));

    vboxLayout2->addWidget(sqlTextEdit);

    rightSplitter->addWidget(widget2);
    widget3 = new QWidget(rightSplitter);
    widget3->setObjectName(QString::fromUtf8("widget3"));
    vboxLayout3 = new QVBoxLayout(widget3);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(0);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    label_3 = new QLabel(widget3);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    vboxLayout3->addWidget(label_3);

    resultTableView = new QTableView(widget3);
    resultTableView->setObjectName(QString::fromUtf8("resultTableView"));

    vboxLayout3->addWidget(resultTableView);

    rightSplitter->addWidget(widget3);

    gridLayout2->addWidget(rightSplitter, 0, 0, 1, 1);

    centalTabWidget->addTab(sqlTab, QApplication::translate("mainWindow", "SQL", 0, QApplication::UnicodeUTF8));
    historyTab = new QWidget();
    historyTab->setObjectName(QString::fromUtf8("historyTab"));
    gridLayout3 = new QGridLayout(historyTab);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    textEdit_3 = new QTextEdit(historyTab);
    textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

    gridLayout3->addWidget(textEdit_3, 0, 0, 1, 1);

    centalTabWidget->addTab(historyTab, QApplication::translate("mainWindow", "History", 0, QApplication::UnicodeUTF8));
    mainSplitter->addWidget(centalTabWidget);

    gridLayout->addWidget(mainSplitter, 0, 0, 1, 1);

    mainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(mainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 673, 29));
    menu_Help = new QMenu(menubar);
    menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
    menu_File = new QMenu(menubar);
    menu_File->setObjectName(QString::fromUtf8("menu_File"));
    mainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(mainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    mainWindow->setStatusBar(statusbar);

    menubar->addAction(menu_File->menuAction());
    menubar->addAction(menu_Help->menuAction());
    menu_Help->addAction(action_About);
    menu_File->addAction(action_Open);
    retranslateUi(mainWindow);

    centalTabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
    mainWindow->setWindowTitle(QApplication::translate("mainWindow", "3WDG SQLite Admin", 0, QApplication::UnicodeUTF8));
    action_About->setText(QApplication::translate("mainWindow", "&About", 0, QApplication::UnicodeUTF8));
    action_Open->setText(QApplication::translate("mainWindow", "&Open", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("mainWindow", "Database", 0, QApplication::UnicodeUTF8));
    tableLabel->setText(QApplication::translate("mainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    tableTabWidget->setTabText(tableTabWidget->indexOf(fieldTab), QApplication::translate("mainWindow", "Fields", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("mainWindow", "SQL", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("mainWindow", "Result - Table Edit", 0, QApplication::UnicodeUTF8));
    centalTabWidget->setTabText(centalTabWidget->indexOf(sqlTab), QApplication::translate("mainWindow", "SQL", 0, QApplication::UnicodeUTF8));
    centalTabWidget->setTabText(centalTabWidget->indexOf(historyTab), QApplication::translate("mainWindow", "History", 0, QApplication::UnicodeUTF8));
    menu_Help->setTitle(QApplication::translate("mainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    menu_File->setTitle(QApplication::translate("mainWindow", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

#endif // MAINWINDOW_H
