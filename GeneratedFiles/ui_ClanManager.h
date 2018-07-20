/********************************************************************************
** Form generated from reading UI file 'ClanManager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLANMANAGER_H
#define UI_CLANMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClanManagerClass
{
public:
    QAction *actionLoadFreshData;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableView *playerList;
    QRadioButton *donationsRadio;
    QRadioButton *requestsRadio;
    QRadioButton *attacksRadio;
    QLabel *label;
    QRadioButton *defensesRadio;
    QRadioButton *ratioRadio;
    QRadioButton *warStarsRadio;
    QRadioButton *trophiesRadio;
    QRadioButton *versusTrophiesRadio;
    QRadioButton *legendRadio;
    QRadioButton *adjRatioRadio;
    QRadioButton *contributionRadio;
    QRadioButton *activityRadio;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_2;
    QLineEdit *CGscore;
    QLabel *label_3;
    QPushButton *addCGScore;
    QFrame *line_4;
    QLabel *label_4;
    QRadioButton *first1star;
    QRadioButton *first2star;
    QRadioButton *first3star;
    QLineEdit *firstPercent;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QRadioButton *second3star;
    QLineEdit *secondPercent;
    QLabel *label_8;
    QRadioButton *second1star;
    QRadioButton *second2star;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *enemyFirst;
    QSpinBox *enemySecond;
    QCheckBox *noShowFirst;
    QLCDNumber *counter;
    QPushButton *addWarAttacks;
    QFrame *line_5;
    QCheckBox *noShowSecond;
    QComboBox *comboBox;
    QLabel *label_11;
    QPushButton *removePlayer;
    QMenuBar *menuBar;
    QMenu *menuActions;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClanManagerClass)
    {
        if (ClanManagerClass->objectName().isEmpty())
            ClanManagerClass->setObjectName(QStringLiteral("ClanManagerClass"));
        ClanManagerClass->resize(1631, 877);
        QFont font;
        font.setPointSize(10);
        ClanManagerClass->setFont(font);
        actionLoadFreshData = new QAction(ClanManagerClass);
        actionLoadFreshData->setObjectName(QStringLiteral("actionLoadFreshData"));
        actionLoadFreshData->setAutoRepeat(false);
        centralWidget = new QWidget(ClanManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(489, 20, 1121, 751));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        playerList = new QTableView(gridLayoutWidget);
        playerList->setObjectName(QStringLiteral("playerList"));

        gridLayout->addWidget(playerList, 1, 0, 1, 1);

        donationsRadio = new QRadioButton(centralWidget);
        donationsRadio->setObjectName(QStringLiteral("donationsRadio"));
        donationsRadio->setGeometry(QRect(350, 30, 111, 20));
        requestsRadio = new QRadioButton(centralWidget);
        requestsRadio->setObjectName(QStringLiteral("requestsRadio"));
        requestsRadio->setGeometry(QRect(350, 60, 92, 20));
        attacksRadio = new QRadioButton(centralWidget);
        attacksRadio->setObjectName(QStringLiteral("attacksRadio"));
        attacksRadio->setGeometry(QRect(350, 90, 92, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 0, 55, 21));
        defensesRadio = new QRadioButton(centralWidget);
        defensesRadio->setObjectName(QStringLiteral("defensesRadio"));
        defensesRadio->setGeometry(QRect(350, 120, 92, 20));
        ratioRadio = new QRadioButton(centralWidget);
        ratioRadio->setObjectName(QStringLiteral("ratioRadio"));
        ratioRadio->setGeometry(QRect(350, 150, 92, 20));
        warStarsRadio = new QRadioButton(centralWidget);
        warStarsRadio->setObjectName(QStringLiteral("warStarsRadio"));
        warStarsRadio->setGeometry(QRect(350, 180, 92, 20));
        trophiesRadio = new QRadioButton(centralWidget);
        trophiesRadio->setObjectName(QStringLiteral("trophiesRadio"));
        trophiesRadio->setGeometry(QRect(350, 210, 92, 20));
        versusTrophiesRadio = new QRadioButton(centralWidget);
        versusTrophiesRadio->setObjectName(QStringLiteral("versusTrophiesRadio"));
        versusTrophiesRadio->setGeometry(QRect(350, 240, 141, 20));
        legendRadio = new QRadioButton(centralWidget);
        legendRadio->setObjectName(QStringLiteral("legendRadio"));
        legendRadio->setGeometry(QRect(350, 270, 141, 20));
        adjRatioRadio = new QRadioButton(centralWidget);
        adjRatioRadio->setObjectName(QStringLiteral("adjRatioRadio"));
        adjRatioRadio->setGeometry(QRect(350, 300, 131, 20));
        contributionRadio = new QRadioButton(centralWidget);
        contributionRadio->setObjectName(QStringLiteral("contributionRadio"));
        contributionRadio->setGeometry(QRect(350, 330, 111, 20));
        activityRadio = new QRadioButton(centralWidget);
        activityRadio->setObjectName(QStringLiteral("activityRadio"));
        activityRadio->setGeometry(QRect(350, 360, 92, 20));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(330, 390, 161, 20));
        QFont font1;
        font1.setKerning(true);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(320, 0, 21, 401));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(320, 400, 20, 411));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 410, 151, 16));
        CGscore = new QLineEdit(centralWidget);
        CGscore->setObjectName(QStringLiteral("CGscore"));
        CGscore->setGeometry(QRect(340, 440, 101, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 440, 55, 16));
        addCGScore = new QPushButton(centralWidget);
        addCGScore->setObjectName(QStringLiteral("addCGScore"));
        addCGScore->setGeometry(QRect(340, 470, 101, 27));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(330, 510, 161, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 520, 141, 16));
        first1star = new QRadioButton(centralWidget);
        first1star->setObjectName(QStringLiteral("first1star"));
        first1star->setGeometry(QRect(340, 570, 41, 20));
        first1star->setAutoExclusive(false);
        first2star = new QRadioButton(centralWidget);
        first2star->setObjectName(QStringLiteral("first2star"));
        first2star->setGeometry(QRect(390, 570, 41, 20));
        first2star->setAutoExclusive(false);
        first3star = new QRadioButton(centralWidget);
        first3star->setObjectName(QStringLiteral("first3star"));
        first3star->setGeometry(QRect(440, 570, 41, 20));
        first3star->setChecked(true);
        first3star->setAutoExclusive(false);
        firstPercent = new QLineEdit(centralWidget);
        firstPercent->setObjectName(QStringLiteral("firstPercent"));
        firstPercent->setGeometry(QRect(390, 600, 41, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 600, 16, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 600, 55, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 630, 81, 21));
        second3star = new QRadioButton(centralWidget);
        second3star->setObjectName(QStringLiteral("second3star"));
        second3star->setGeometry(QRect(440, 690, 41, 20));
        second3star->setChecked(true);
        second3star->setAutoExclusive(false);
        secondPercent = new QLineEdit(centralWidget);
        secondPercent->setObjectName(QStringLiteral("secondPercent"));
        secondPercent->setGeometry(QRect(390, 720, 41, 22));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(340, 750, 81, 21));
        second1star = new QRadioButton(centralWidget);
        second1star->setObjectName(QStringLiteral("second1star"));
        second1star->setGeometry(QRect(340, 690, 41, 20));
        second1star->setAutoExclusive(false);
        second2star = new QRadioButton(centralWidget);
        second2star->setObjectName(QStringLiteral("second2star"));
        second2star->setGeometry(QRect(390, 690, 41, 20));
        second2star->setAutoExclusive(false);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(440, 720, 16, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(340, 720, 55, 16));
        enemyFirst = new QSpinBox(centralWidget);
        enemyFirst->setObjectName(QStringLiteral("enemyFirst"));
        enemyFirst->setGeometry(QRect(420, 630, 42, 22));
        enemyFirst->setMinimum(3);
        enemyFirst->setMaximum(12);
        enemyFirst->setValue(9);
        enemySecond = new QSpinBox(centralWidget);
        enemySecond->setObjectName(QStringLiteral("enemySecond"));
        enemySecond->setGeometry(QRect(420, 750, 42, 22));
        enemySecond->setMinimum(3);
        enemySecond->setMaximum(12);
        enemySecond->setValue(9);
        noShowFirst = new QCheckBox(centralWidget);
        noShowFirst->setObjectName(QStringLiteral("noShowFirst"));
        noShowFirst->setGeometry(QRect(340, 540, 91, 20));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 12, 12, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 18, 18, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 15, 15, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 6, 6, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 8, 8, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        QBrush brush7(QColor(170, 15, 15, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush8(QColor(170, 11, 11, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        QBrush brush9(QColor(212, 133, 133, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush11);
        noShowFirst->setPalette(palette);
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        noShowFirst->setFont(font2);
        counter = new QLCDNumber(centralWidget);
        counter->setObjectName(QStringLiteral("counter"));
        counter->setGeometry(QRect(490, 0, 64, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        QBrush brush12(QColor(170, 85, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush12);
        QBrush brush13(QColor(255, 128, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush13);
        QBrush brush14(QColor(212, 106, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(85, 42, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(113, 56, 0, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush11);
        QBrush brush17(QColor(212, 170, 127, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush11);
        counter->setPalette(palette1);
        addWarAttacks = new QPushButton(centralWidget);
        addWarAttacks->setObjectName(QStringLiteral("addWarAttacks"));
        addWarAttacks->setGeometry(QRect(340, 780, 141, 27));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(330, 800, 161, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        noShowSecond = new QCheckBox(centralWidget);
        noShowSecond->setObjectName(QStringLiteral("noShowSecond"));
        noShowSecond->setGeometry(QRect(340, 660, 91, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush11);
        noShowSecond->setPalette(palette2);
        noShowSecond->setFont(font2);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 570, 271, 22));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 570, 41, 16));
        removePlayer = new QPushButton(centralWidget);
        removePlayer->setObjectName(QStringLiteral("removePlayer"));
        removePlayer->setGeometry(QRect(510, 780, 111, 27));
        ClanManagerClass->setCentralWidget(centralWidget);
        enemyFirst->raise();
        gridLayoutWidget->raise();
        donationsRadio->raise();
        requestsRadio->raise();
        attacksRadio->raise();
        label->raise();
        defensesRadio->raise();
        ratioRadio->raise();
        warStarsRadio->raise();
        trophiesRadio->raise();
        versusTrophiesRadio->raise();
        legendRadio->raise();
        adjRatioRadio->raise();
        contributionRadio->raise();
        activityRadio->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        label_2->raise();
        CGscore->raise();
        label_3->raise();
        addCGScore->raise();
        line_4->raise();
        label_4->raise();
        first1star->raise();
        first2star->raise();
        first3star->raise();
        firstPercent->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        second3star->raise();
        secondPercent->raise();
        label_8->raise();
        second1star->raise();
        second2star->raise();
        label_9->raise();
        label_10->raise();
        enemySecond->raise();
        noShowFirst->raise();
        counter->raise();
        addWarAttacks->raise();
        line_5->raise();
        noShowSecond->raise();
        comboBox->raise();
        label_11->raise();
        removePlayer->raise();
        menuBar = new QMenuBar(ClanManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1631, 21));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QStringLiteral("menuActions"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        ClanManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClanManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ClanManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClanManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ClanManagerClass->setStatusBar(statusBar);

        menuBar->addAction(menuActions->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuActions->addAction(actionLoadFreshData);

        retranslateUi(ClanManagerClass);

        QMetaObject::connectSlotsByName(ClanManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClanManagerClass)
    {
        ClanManagerClass->setWindowTitle(QApplication::translate("ClanManagerClass", "ClanManager", nullptr));
        actionLoadFreshData->setText(QApplication::translate("ClanManagerClass", "Load fresh data", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionLoadFreshData->setWhatsThis(QApplication::translate("ClanManagerClass", "Load fresh data from a .csv file", nullptr));
#endif // QT_NO_WHATSTHIS
        donationsRadio->setText(QApplication::translate("ClanManagerClass", "Donations", nullptr));
        requestsRadio->setText(QApplication::translate("ClanManagerClass", "Requests", nullptr));
        attacksRadio->setText(QApplication::translate("ClanManagerClass", "Attacks", nullptr));
        label->setText(QApplication::translate("ClanManagerClass", "Sort by:", nullptr));
        defensesRadio->setText(QApplication::translate("ClanManagerClass", "Defenses", nullptr));
        ratioRadio->setText(QApplication::translate("ClanManagerClass", "Ratio", nullptr));
        warStarsRadio->setText(QApplication::translate("ClanManagerClass", "War stars", nullptr));
        trophiesRadio->setText(QApplication::translate("ClanManagerClass", "Trophies", nullptr));
        versusTrophiesRadio->setText(QApplication::translate("ClanManagerClass", "Versus Trophies", nullptr));
        legendRadio->setText(QApplication::translate("ClanManagerClass", "Legend Trophies", nullptr));
        adjRatioRadio->setText(QApplication::translate("ClanManagerClass", "Adjusted Ratio", nullptr));
        contributionRadio->setText(QApplication::translate("ClanManagerClass", "Contribution", nullptr));
        activityRadio->setText(QApplication::translate("ClanManagerClass", "Activity", nullptr));
        label_2->setText(QApplication::translate("ClanManagerClass", "Add CG score:", nullptr));
        label_3->setText(QApplication::translate("ClanManagerClass", "XP", nullptr));
        addCGScore->setText(QApplication::translate("ClanManagerClass", "Add", nullptr));
        label_4->setText(QApplication::translate("ClanManagerClass", "Add war attack(s):", nullptr));
        first1star->setText(QApplication::translate("ClanManagerClass", "1*", nullptr));
        first2star->setText(QApplication::translate("ClanManagerClass", "2*", nullptr));
        first3star->setText(QApplication::translate("ClanManagerClass", "3*", nullptr));
        label_5->setText(QApplication::translate("ClanManagerClass", "%", nullptr));
        label_6->setText(QApplication::translate("ClanManagerClass", "Result:", nullptr));
        label_7->setText(QApplication::translate("ClanManagerClass", "Enemy TH:", nullptr));
        second3star->setText(QApplication::translate("ClanManagerClass", "3*", nullptr));
        label_8->setText(QApplication::translate("ClanManagerClass", "Enemy TH:", nullptr));
        second1star->setText(QApplication::translate("ClanManagerClass", "1*", nullptr));
        second2star->setText(QApplication::translate("ClanManagerClass", "2*", nullptr));
        label_9->setText(QApplication::translate("ClanManagerClass", "%", nullptr));
        label_10->setText(QApplication::translate("ClanManagerClass", "Result:", nullptr));
        noShowFirst->setText(QApplication::translate("ClanManagerClass", "No show", nullptr));
        addWarAttacks->setText(QApplication::translate("ClanManagerClass", "Add Attack(s)", nullptr));
        noShowSecond->setText(QApplication::translate("ClanManagerClass", "No show", nullptr));
        label_11->setText(QApplication::translate("ClanManagerClass", "View:", nullptr));
        removePlayer->setText(QApplication::translate("ClanManagerClass", "Remove Player", nullptr));
        menuActions->setTitle(QApplication::translate("ClanManagerClass", "Actions", nullptr));
        menuOptions->setTitle(QApplication::translate("ClanManagerClass", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClanManagerClass: public Ui_ClanManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLANMANAGER_H
