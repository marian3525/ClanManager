/********************************************************************************
** Form generated from reading UI file 'DetailWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILWINDOW_H
#define UI_DETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailWindow
{
public:
    QListView *warAttacksList;
    QLabel *label;
    QFrame *line;
    QLabel *labelTitle;
    QLabel *donations;
    QLabel *requests;
    QLabel *ratio;
    QLabel *contribution;
    QLabel *avgWarScore;
    QLabel *avgWarStars;
    QLabel *cgScore;
    QLabel *avgCGScore;
    QLabel *activity;
    QLabel *role;
    QLabel *specialRole;
    QLabel *label_14;
    QLabel *donationsLabel;
    QLabel *requestsLabel;
    QLabel *ratiosLabel;
    QLabel *contributionsLabel;
    QLabel *avgWarScoreLabel;
    QLabel *avgWarStarsLabel;
    QLabel *cgScores;
    QLabel *avgCgScoreLabel;
    QLabel *activitiesLabel;
    QLabel *roleLabel;
    QTextEdit *notes;
    QLineEdit *specialRoleInput;

    void setupUi(QWidget *DetailWindow)
    {
        if (DetailWindow->objectName().isEmpty())
            DetailWindow->setObjectName(QStringLiteral("DetailWindow"));
        DetailWindow->resize(534, 433);
        warAttacksList = new QListView(DetailWindow);
        warAttacksList->setObjectName(QStringLiteral("warAttacksList"));
        warAttacksList->setGeometry(QRect(10, 30, 251, 391));
        label = new QLabel(DetailWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        line = new QFrame(DetailWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(250, 0, 41, 431));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        labelTitle = new QLabel(DetailWindow);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(280, 10, 261, 16));
        donations = new QLabel(DetailWindow);
        donations->setObjectName(QStringLiteral("donations"));
        donations->setGeometry(QRect(270, 40, 71, 16));
        requests = new QLabel(DetailWindow);
        requests->setObjectName(QStringLiteral("requests"));
        requests->setGeometry(QRect(270, 60, 55, 16));
        ratio = new QLabel(DetailWindow);
        ratio->setObjectName(QStringLiteral("ratio"));
        ratio->setGeometry(QRect(270, 80, 55, 16));
        contribution = new QLabel(DetailWindow);
        contribution->setObjectName(QStringLiteral("contribution"));
        contribution->setGeometry(QRect(270, 100, 81, 16));
        avgWarScore = new QLabel(DetailWindow);
        avgWarScore->setObjectName(QStringLiteral("avgWarScore"));
        avgWarScore->setGeometry(QRect(270, 120, 91, 16));
        avgWarStars = new QLabel(DetailWindow);
        avgWarStars->setObjectName(QStringLiteral("avgWarStars"));
        avgWarStars->setGeometry(QRect(270, 140, 91, 16));
        cgScore = new QLabel(DetailWindow);
        cgScore->setObjectName(QStringLiteral("cgScore"));
        cgScore->setGeometry(QRect(270, 160, 61, 16));
        avgCGScore = new QLabel(DetailWindow);
        avgCGScore->setObjectName(QStringLiteral("avgCGScore"));
        avgCGScore->setGeometry(QRect(270, 180, 91, 16));
        activity = new QLabel(DetailWindow);
        activity->setObjectName(QStringLiteral("activity"));
        activity->setGeometry(QRect(270, 200, 55, 16));
        role = new QLabel(DetailWindow);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(270, 220, 55, 16));
        specialRole = new QLabel(DetailWindow);
        specialRole->setObjectName(QStringLiteral("specialRole"));
        specialRole->setGeometry(QRect(270, 240, 71, 16));
        label_14 = new QLabel(DetailWindow);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(270, 300, 55, 16));
        donationsLabel = new QLabel(DetailWindow);
        donationsLabel->setObjectName(QStringLiteral("donationsLabel"));
        donationsLabel->setGeometry(QRect(340, 40, 191, 20));
        requestsLabel = new QLabel(DetailWindow);
        requestsLabel->setObjectName(QStringLiteral("requestsLabel"));
        requestsLabel->setGeometry(QRect(340, 60, 191, 20));
        ratiosLabel = new QLabel(DetailWindow);
        ratiosLabel->setObjectName(QStringLiteral("ratiosLabel"));
        ratiosLabel->setGeometry(QRect(320, 80, 211, 20));
        contributionsLabel = new QLabel(DetailWindow);
        contributionsLabel->setObjectName(QStringLiteral("contributionsLabel"));
        contributionsLabel->setGeometry(QRect(360, 100, 171, 20));
        avgWarScoreLabel = new QLabel(DetailWindow);
        avgWarScoreLabel->setObjectName(QStringLiteral("avgWarScoreLabel"));
        avgWarScoreLabel->setGeometry(QRect(370, 120, 161, 16));
        avgWarStarsLabel = new QLabel(DetailWindow);
        avgWarStarsLabel->setObjectName(QStringLiteral("avgWarStarsLabel"));
        avgWarStarsLabel->setGeometry(QRect(370, 140, 161, 20));
        cgScores = new QLabel(DetailWindow);
        cgScores->setObjectName(QStringLiteral("cgScores"));
        cgScores->setGeometry(QRect(340, 160, 191, 16));
        avgCgScoreLabel = new QLabel(DetailWindow);
        avgCgScoreLabel->setObjectName(QStringLiteral("avgCgScoreLabel"));
        avgCgScoreLabel->setGeometry(QRect(360, 180, 171, 16));
        activitiesLabel = new QLabel(DetailWindow);
        activitiesLabel->setObjectName(QStringLiteral("activitiesLabel"));
        activitiesLabel->setGeometry(QRect(330, 200, 201, 16));
        roleLabel = new QLabel(DetailWindow);
        roleLabel->setObjectName(QStringLiteral("roleLabel"));
        roleLabel->setGeometry(QRect(310, 220, 221, 16));
        notes = new QTextEdit(DetailWindow);
        notes->setObjectName(QStringLiteral("notes"));
        notes->setGeometry(QRect(270, 320, 251, 81));
        specialRoleInput = new QLineEdit(DetailWindow);
        specialRoleInput->setObjectName(QStringLiteral("specialRoleInput"));
        specialRoleInput->setGeometry(QRect(350, 240, 171, 22));

        retranslateUi(DetailWindow);

        QMetaObject::connectSlotsByName(DetailWindow);
    } // setupUi

    void retranslateUi(QWidget *DetailWindow)
    {
        DetailWindow->setWindowTitle(QApplication::translate("DetailWindow", "DetailWindow", nullptr));
        label->setText(QApplication::translate("DetailWindow", "War Attacks:", nullptr));
        labelTitle->setText(QApplication::translate("DetailWindow", "Statistics for the last 3 cycles(recent first):", nullptr));
        donations->setText(QApplication::translate("DetailWindow", "Donations:", nullptr));
        requests->setText(QApplication::translate("DetailWindow", "Requests:", nullptr));
        ratio->setText(QApplication::translate("DetailWindow", "Ratios:", nullptr));
        contribution->setText(QApplication::translate("DetailWindow", "Contributions:", nullptr));
        avgWarScore->setText(QApplication::translate("DetailWindow", "Avg. war score:", nullptr));
        avgWarStars->setText(QApplication::translate("DetailWindow", "Avg. war stars:", nullptr));
        cgScore->setText(QApplication::translate("DetailWindow", "CG scores:", nullptr));
        avgCGScore->setText(QApplication::translate("DetailWindow", "Avg. CG score:", nullptr));
        activity->setText(QApplication::translate("DetailWindow", "Activities:", nullptr));
        role->setText(QApplication::translate("DetailWindow", "Role:", nullptr));
        specialRole->setText(QApplication::translate("DetailWindow", "Special role:", nullptr));
        label_14->setText(QApplication::translate("DetailWindow", "Notes:", nullptr));
        donationsLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        requestsLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        ratiosLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        contributionsLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        avgWarScoreLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        avgWarStarsLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        cgScores->setText(QApplication::translate("DetailWindow", "None", nullptr));
        avgCgScoreLabel->setText(QApplication::translate("DetailWindow", "None", nullptr));
        activitiesLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
        roleLabel->setText(QApplication::translate("DetailWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailWindow: public Ui_DetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILWINDOW_H
