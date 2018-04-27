/********************************************************************************
** Form generated from reading UI file 'gui2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI2_H
#define UI_GUI2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui2
{
public:
    QTreeWidget *skeletonTreeWidget;
    QPushButton *rotXButton;
    QPushButton *rotYButton;
    QPushButton *rotZButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *wPositionLabel;
    QLabel *wRotationLabel;
    QLabel *lPositionLabel;
    QLabel *lRotationLabel;
    QLabel *label_11;
    QPushButton *skinningButton;
    QDoubleSpinBox *xDoubleSpinBox;
    QDoubleSpinBox *yDoubleSpinBox;
    QDoubleSpinBox *zDoubleSpinBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *gui2)
    {
        if (gui2->objectName().isEmpty())
            gui2->setObjectName(QStringLiteral("gui2"));
        gui2->resize(403, 332);
        skeletonTreeWidget = new QTreeWidget(gui2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        skeletonTreeWidget->setHeaderItem(__qtreewidgetitem);
        skeletonTreeWidget->setObjectName(QStringLiteral("skeletonTreeWidget"));
        skeletonTreeWidget->setGeometry(QRect(10, 10, 381, 161));
        skeletonTreeWidget->header()->setVisible(false);
        rotXButton = new QPushButton(gui2);
        rotXButton->setObjectName(QStringLiteral("rotXButton"));
        rotXButton->setGeometry(QRect(20, 240, 75, 23));
        rotYButton = new QPushButton(gui2);
        rotYButton->setObjectName(QStringLiteral("rotYButton"));
        rotYButton->setGeometry(QRect(20, 270, 75, 23));
        rotZButton = new QPushButton(gui2);
        rotZButton->setObjectName(QStringLiteral("rotZButton"));
        rotZButton->setGeometry(QRect(20, 300, 75, 23));
        label = new QLabel(gui2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 210, 91, 21));
        QFont font;
        font.setFamily(QStringLiteral("Magneto"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(gui2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 210, 121, 21));
        label_2->setFont(font);
        label_3 = new QLabel(gui2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 71, 21));
        label_4 = new QLabel(gui2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 71, 21));
        label_5 = new QLabel(gui2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(210, 170, 81, 21));
        label_6 = new QLabel(gui2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 190, 71, 21));
        wPositionLabel = new QLabel(gui2);
        wPositionLabel->setObjectName(QStringLiteral("wPositionLabel"));
        wPositionLabel->setGeometry(QRect(90, 170, 111, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Gill Sans MT Condensed"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        wPositionLabel->setFont(font1);
        wRotationLabel = new QLabel(gui2);
        wRotationLabel->setObjectName(QStringLiteral("wRotationLabel"));
        wRotationLabel->setGeometry(QRect(290, 170, 101, 21));
        wRotationLabel->setFont(font1);
        lPositionLabel = new QLabel(gui2);
        lPositionLabel->setObjectName(QStringLiteral("lPositionLabel"));
        lPositionLabel->setGeometry(QRect(90, 190, 111, 21));
        lPositionLabel->setFont(font1);
        lRotationLabel = new QLabel(gui2);
        lRotationLabel->setObjectName(QStringLiteral("lRotationLabel"));
        lRotationLabel->setGeometry(QRect(290, 190, 101, 21));
        lRotationLabel->setFont(font1);
        label_11 = new QLabel(gui2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(290, 210, 101, 20));
        label_11->setFont(font);
        skinningButton = new QPushButton(gui2);
        skinningButton->setObjectName(QStringLiteral("skinningButton"));
        skinningButton->setGeometry(QRect(300, 240, 75, 23));
        xDoubleSpinBox = new QDoubleSpinBox(gui2);
        xDoubleSpinBox->setObjectName(QStringLiteral("xDoubleSpinBox"));
        xDoubleSpinBox->setGeometry(QRect(170, 240, 91, 22));
        xDoubleSpinBox->setMinimum(-100000);
        xDoubleSpinBox->setMaximum(100000);
        xDoubleSpinBox->setSingleStep(0.5);
        yDoubleSpinBox = new QDoubleSpinBox(gui2);
        yDoubleSpinBox->setObjectName(QStringLiteral("yDoubleSpinBox"));
        yDoubleSpinBox->setGeometry(QRect(170, 270, 91, 22));
        yDoubleSpinBox->setMinimum(-100000);
        yDoubleSpinBox->setMaximum(100000);
        yDoubleSpinBox->setSingleStep(0.5);
        zDoubleSpinBox = new QDoubleSpinBox(gui2);
        zDoubleSpinBox->setObjectName(QStringLiteral("zDoubleSpinBox"));
        zDoubleSpinBox->setGeometry(QRect(170, 300, 91, 22));
        zDoubleSpinBox->setMinimum(-100000);
        zDoubleSpinBox->setMaximum(100000);
        zDoubleSpinBox->setSingleStep(0.5);
        label_7 = new QLabel(gui2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 240, 41, 21));
        label_8 = new QLabel(gui2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 270, 41, 21));
        label_9 = new QLabel(gui2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(120, 300, 41, 21));

        retranslateUi(gui2);

        QMetaObject::connectSlotsByName(gui2);
    } // setupUi

    void retranslateUi(QWidget *gui2)
    {
        gui2->setWindowTitle(QApplication::translate("gui2", "Editor2", 0));
        rotXButton->setText(QApplication::translate("gui2", "x-axis", 0));
        rotYButton->setText(QApplication::translate("gui2", "y-axis", 0));
        rotZButton->setText(QApplication::translate("gui2", "z-axis", 0));
        label->setText(QApplication::translate("gui2", "Rotation", 0));
        label_2->setText(QApplication::translate("gui2", "Translation", 0));
        label_3->setText(QApplication::translate("gui2", "World Position:", 0));
        label_4->setText(QApplication::translate("gui2", "Local Position:", 0));
        label_5->setText(QApplication::translate("gui2", "World Rotation:", 0));
        label_6->setText(QApplication::translate("gui2", "Local Rotation:", 0));
        wPositionLabel->setText(QApplication::translate("gui2", "N/A", 0));
        wRotationLabel->setText(QApplication::translate("gui2", "N/A", 0));
        lPositionLabel->setText(QApplication::translate("gui2", "N/A", 0));
        lRotationLabel->setText(QApplication::translate("gui2", "N/A", 0));
        label_11->setText(QApplication::translate("gui2", "Skinning", 0));
        skinningButton->setText(QApplication::translate("gui2", "skin", 0));
        label_7->setText(QApplication::translate("gui2", "Local X:", 0));
        label_8->setText(QApplication::translate("gui2", "Local Y:", 0));
        label_9->setText(QApplication::translate("gui2", "Local Z:", 0));
    } // retranslateUi

};

namespace Ui {
    class gui2: public Ui_gui2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI2_H
