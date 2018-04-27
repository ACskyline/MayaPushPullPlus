/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QListWidget *faceList;
    QListWidget *halfEdgeList;
    QListWidget *vertexList;
    QLabel *faceLabel;
    QLabel *halfEdgeLabel;
    QLabel *vertexLabel;
    QPushButton *splitEdgeButton;
    QPushButton *triangulateFaceButton;
    QLabel *label;
    QPushButton *subdivideButton;
    QPushButton *extrudeButton;
    QPushButton *bevelEdgeButton;
    QDoubleSpinBox *rDoubleSpinBox;
    QDoubleSpinBox *gDoubleSpinBox;
    QLabel *rLabel;
    QLabel *gLabel;
    QDoubleSpinBox *bDoubleSpinBox;
    QLabel *bLabel;
    QLabel *xLabel;
    QDoubleSpinBox *xDoubleSpinBox;
    QLabel *yLabel;
    QDoubleSpinBox *yDoubleSpinBox;
    QLabel *zLabel;
    QDoubleSpinBox *zDoubleSpinBox;
    QPushButton *pushPullPPButton;
    QDoubleSpinBox *pushPullPPDX;
    QDoubleSpinBox *pushPullPPDY;
    QDoubleSpinBox *pushPullPPDZ;
    QDoubleSpinBox *pushPullPPTheta;
    QDoubleSpinBox *pushPullPPPX;
    QDoubleSpinBox *pushPullPPPY;
    QDoubleSpinBox *pushPullPPPZ;
    QDoubleSpinBox *pushPullPPPNX;
    QDoubleSpinBox *pushPullPPPNY;
    QDoubleSpinBox *pushPullPPPNZ;
    QLabel *dxLabel;
    QLabel *dyLabel;
    QLabel *dzLabel;
    QLabel *thetaLabel;
    QLabel *planeLabel;
    QLabel *planeNormalLabel;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QStringLiteral("gui"));
        gui->resize(494, 541);
        QFont font;
        font.setFamily(QStringLiteral("Magneto"));
        gui->setFont(font);
        faceList = new QListWidget(gui);
        faceList->setObjectName(QStringLiteral("faceList"));
        faceList->setGeometry(QRect(10, 60, 141, 331));
        halfEdgeList = new QListWidget(gui);
        halfEdgeList->setObjectName(QStringLiteral("halfEdgeList"));
        halfEdgeList->setGeometry(QRect(170, 60, 151, 331));
        vertexList = new QListWidget(gui);
        vertexList->setObjectName(QStringLiteral("vertexList"));
        vertexList->setGeometry(QRect(340, 60, 141, 331));
        faceLabel = new QLabel(gui);
        faceLabel->setObjectName(QStringLiteral("faceLabel"));
        faceLabel->setGeometry(QRect(40, 10, 71, 31));
        QFont font1;
        font1.setPointSize(20);
        faceLabel->setFont(font1);
        faceLabel->setTextFormat(Qt::AutoText);
        halfEdgeLabel = new QLabel(gui);
        halfEdgeLabel->setObjectName(QStringLiteral("halfEdgeLabel"));
        halfEdgeLabel->setGeometry(QRect(170, 10, 141, 31));
        halfEdgeLabel->setFont(font1);
        vertexLabel = new QLabel(gui);
        vertexLabel->setObjectName(QStringLiteral("vertexLabel"));
        vertexLabel->setGeometry(QRect(360, 10, 91, 31));
        vertexLabel->setFont(font1);
        splitEdgeButton = new QPushButton(gui);
        splitEdgeButton->setObjectName(QStringLiteral("splitEdgeButton"));
        splitEdgeButton->setGeometry(QRect(210, 400, 81, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ebrima"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        splitEdgeButton->setFont(font2);
        triangulateFaceButton = new QPushButton(gui);
        triangulateFaceButton->setObjectName(QStringLiteral("triangulateFaceButton"));
        triangulateFaceButton->setGeometry(QRect(10, 400, 81, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Ebrima"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        triangulateFaceButton->setFont(font3);
        label = new QLabel(gui);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 421, 16));
        QFont font4;
        font4.setFamily(QStringLiteral("Corbel"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        subdivideButton = new QPushButton(gui);
        subdivideButton->setObjectName(QStringLiteral("subdivideButton"));
        subdivideButton->setGeometry(QRect(400, 400, 81, 31));
        subdivideButton->setFont(font3);
        extrudeButton = new QPushButton(gui);
        extrudeButton->setObjectName(QStringLiteral("extrudeButton"));
        extrudeButton->setGeometry(QRect(100, 400, 101, 31));
        extrudeButton->setFont(font3);
        bevelEdgeButton = new QPushButton(gui);
        bevelEdgeButton->setObjectName(QStringLiteral("bevelEdgeButton"));
        bevelEdgeButton->setGeometry(QRect(300, 400, 91, 31));
        bevelEdgeButton->setFont(font3);
        rDoubleSpinBox = new QDoubleSpinBox(gui);
        rDoubleSpinBox->setObjectName(QStringLiteral("rDoubleSpinBox"));
        rDoubleSpinBox->setGeometry(QRect(20, 440, 61, 22));
        QFont font5;
        font5.setFamily(QStringLiteral("Fixedsys"));
        font5.setPointSize(6);
        rDoubleSpinBox->setFont(font5);
        rDoubleSpinBox->setMaximum(1);
        rDoubleSpinBox->setSingleStep(0.01);
        gDoubleSpinBox = new QDoubleSpinBox(gui);
        gDoubleSpinBox->setObjectName(QStringLiteral("gDoubleSpinBox"));
        gDoubleSpinBox->setGeometry(QRect(100, 440, 62, 22));
        gDoubleSpinBox->setFont(font5);
        gDoubleSpinBox->setMaximum(1);
        gDoubleSpinBox->setSingleStep(0.01);
        rLabel = new QLabel(gui);
        rLabel->setObjectName(QStringLiteral("rLabel"));
        rLabel->setGeometry(QRect(10, 440, 16, 21));
        rLabel->setFont(font5);
        gLabel = new QLabel(gui);
        gLabel->setObjectName(QStringLiteral("gLabel"));
        gLabel->setGeometry(QRect(90, 440, 16, 21));
        gLabel->setFont(font5);
        bDoubleSpinBox = new QDoubleSpinBox(gui);
        bDoubleSpinBox->setObjectName(QStringLiteral("bDoubleSpinBox"));
        bDoubleSpinBox->setGeometry(QRect(180, 440, 62, 22));
        bDoubleSpinBox->setFont(font5);
        bDoubleSpinBox->setMaximum(1);
        bDoubleSpinBox->setSingleStep(0.01);
        bLabel = new QLabel(gui);
        bLabel->setObjectName(QStringLiteral("bLabel"));
        bLabel->setGeometry(QRect(170, 440, 16, 21));
        bLabel->setFont(font5);
        xLabel = new QLabel(gui);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(250, 440, 16, 21));
        xLabel->setFont(font5);
        xDoubleSpinBox = new QDoubleSpinBox(gui);
        xDoubleSpinBox->setObjectName(QStringLiteral("xDoubleSpinBox"));
        xDoubleSpinBox->setGeometry(QRect(260, 440, 62, 22));
        xDoubleSpinBox->setFont(font5);
        xDoubleSpinBox->setMinimum(-1e+41);
        xDoubleSpinBox->setMaximum(1e+100);
        yLabel = new QLabel(gui);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(330, 440, 16, 21));
        yLabel->setFont(font5);
        yDoubleSpinBox = new QDoubleSpinBox(gui);
        yDoubleSpinBox->setObjectName(QStringLiteral("yDoubleSpinBox"));
        yDoubleSpinBox->setGeometry(QRect(340, 440, 62, 22));
        yDoubleSpinBox->setFont(font5);
        yDoubleSpinBox->setMinimum(-1e+41);
        yDoubleSpinBox->setMaximum(1e+100);
        zLabel = new QLabel(gui);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setGeometry(QRect(410, 440, 16, 21));
        zLabel->setFont(font5);
        zDoubleSpinBox = new QDoubleSpinBox(gui);
        zDoubleSpinBox->setObjectName(QStringLiteral("zDoubleSpinBox"));
        zDoubleSpinBox->setGeometry(QRect(420, 440, 62, 22));
        zDoubleSpinBox->setFont(font5);
        zDoubleSpinBox->setMinimum(-1e+41);
        zDoubleSpinBox->setMaximum(1e+100);
        pushPullPPButton = new QPushButton(gui);
        pushPullPPButton->setObjectName(QStringLiteral("pushPullPPButton"));
        pushPullPPButton->setGeometry(QRect(10, 470, 81, 31));
        pushPullPPButton->setFont(font3);
        pushPullPPDX = new QDoubleSpinBox(gui);
        pushPullPPDX->setObjectName(QStringLiteral("pushPullPPDX"));
        pushPullPPDX->setGeometry(QRect(120, 470, 62, 31));
        pushPullPPDX->setFont(font5);
        pushPullPPDX->setMinimum(-1e+26);
        pushPullPPDX->setMaximum(1e+40);
        pushPullPPDY = new QDoubleSpinBox(gui);
        pushPullPPDY->setObjectName(QStringLiteral("pushPullPPDY"));
        pushPullPPDY->setGeometry(QRect(210, 470, 62, 31));
        pushPullPPDY->setFont(font5);
        pushPullPPDY->setMinimum(-1e+114);
        pushPullPPDY->setMaximum(1e+114);
        pushPullPPDZ = new QDoubleSpinBox(gui);
        pushPullPPDZ->setObjectName(QStringLiteral("pushPullPPDZ"));
        pushPullPPDZ->setGeometry(QRect(300, 470, 62, 31));
        pushPullPPDZ->setFont(font5);
        pushPullPPDZ->setMinimum(-1e+114);
        pushPullPPDZ->setMaximum(1e+114);
        pushPullPPTheta = new QDoubleSpinBox(gui);
        pushPullPPTheta->setObjectName(QStringLiteral("pushPullPPTheta"));
        pushPullPPTheta->setGeometry(QRect(420, 470, 62, 31));
        pushPullPPTheta->setFont(font5);
        pushPullPPTheta->setMinimum(-1e+114);
        pushPullPPTheta->setMaximum(1e+114);
        pushPullPPPX = new QDoubleSpinBox(gui);
        pushPullPPPX->setObjectName(QStringLiteral("pushPullPPPX"));
        pushPullPPPX->setGeometry(QRect(50, 510, 62, 22));
        pushPullPPPX->setFont(font5);
        pushPullPPPX->setMinimum(-1e+114);
        pushPullPPPX->setMaximum(1e+114);
        pushPullPPPY = new QDoubleSpinBox(gui);
        pushPullPPPY->setObjectName(QStringLiteral("pushPullPPPY"));
        pushPullPPPY->setGeometry(QRect(110, 510, 62, 22));
        pushPullPPPY->setFont(font5);
        pushPullPPPY->setMinimum(-1e+114);
        pushPullPPPY->setMaximum(1e+114);
        pushPullPPPZ = new QDoubleSpinBox(gui);
        pushPullPPPZ->setObjectName(QStringLiteral("pushPullPPPZ"));
        pushPullPPPZ->setGeometry(QRect(170, 510, 62, 22));
        pushPullPPPZ->setFont(font5);
        pushPullPPPZ->setMinimum(-1e+114);
        pushPullPPPZ->setMaximum(1e+114);
        pushPullPPPNX = new QDoubleSpinBox(gui);
        pushPullPPPNX->setObjectName(QStringLiteral("pushPullPPPNX"));
        pushPullPPPNX->setGeometry(QRect(300, 510, 62, 22));
        pushPullPPPNX->setFont(font5);
        pushPullPPPNX->setMinimum(-1e+114);
        pushPullPPPNX->setMaximum(1e+114);
        pushPullPPPNY = new QDoubleSpinBox(gui);
        pushPullPPPNY->setObjectName(QStringLiteral("pushPullPPPNY"));
        pushPullPPPNY->setGeometry(QRect(360, 510, 62, 22));
        pushPullPPPNY->setFont(font5);
        pushPullPPPNY->setMinimum(-1e+114);
        pushPullPPPNY->setMaximum(1e+114);
        pushPullPPPNZ = new QDoubleSpinBox(gui);
        pushPullPPPNZ->setObjectName(QStringLiteral("pushPullPPPNZ"));
        pushPullPPPNZ->setGeometry(QRect(420, 510, 62, 22));
        pushPullPPPNZ->setFont(font5);
        pushPullPPPNZ->setMinimum(-1e+114);
        pushPullPPPNZ->setMaximum(1e+114);
        dxLabel = new QLabel(gui);
        dxLabel->setObjectName(QStringLiteral("dxLabel"));
        dxLabel->setGeometry(QRect(100, 470, 21, 31));
        QFont font6;
        font6.setFamily(QStringLiteral("Fixedsys"));
        font6.setPointSize(6);
        font6.setBold(false);
        font6.setWeight(50);
        dxLabel->setFont(font6);
        dyLabel = new QLabel(gui);
        dyLabel->setObjectName(QStringLiteral("dyLabel"));
        dyLabel->setGeometry(QRect(190, 470, 21, 31));
        dyLabel->setFont(font5);
        dzLabel = new QLabel(gui);
        dzLabel->setObjectName(QStringLiteral("dzLabel"));
        dzLabel->setGeometry(QRect(280, 470, 21, 31));
        dzLabel->setFont(font5);
        thetaLabel = new QLabel(gui);
        thetaLabel->setObjectName(QStringLiteral("thetaLabel"));
        thetaLabel->setGeometry(QRect(370, 470, 41, 31));
        thetaLabel->setFont(font5);
        planeLabel = new QLabel(gui);
        planeLabel->setObjectName(QStringLiteral("planeLabel"));
        planeLabel->setGeometry(QRect(10, 510, 41, 21));
        planeLabel->setFont(font5);
        planeNormalLabel = new QLabel(gui);
        planeNormalLabel->setObjectName(QStringLiteral("planeNormalLabel"));
        planeNormalLabel->setGeometry(QRect(250, 510, 51, 21));
        planeNormalLabel->setFont(font5);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QApplication::translate("gui", "Editor", 0));
        faceLabel->setText(QApplication::translate("gui", "Face", 0));
        halfEdgeLabel->setText(QApplication::translate("gui", "HalfEdge", 0));
        vertexLabel->setText(QApplication::translate("gui", "Vertex", 0));
        splitEdgeButton->setText(QApplication::translate("gui", "Split Edge", 0));
        triangulateFaceButton->setText(QApplication::translate("gui", "Split Face", 0));
        label->setText(QApplication::translate("gui", "Please use LMB to select vertex, RMB to select half edge and MMB to select face.", 0));
        subdivideButton->setText(QApplication::translate("gui", "Subdivide", 0));
        extrudeButton->setText(QApplication::translate("gui", "Extrude Face", 0));
        bevelEdgeButton->setText(QApplication::translate("gui", "Bevel Edge", 0));
        rLabel->setText(QApplication::translate("gui", "R", 0));
        gLabel->setText(QApplication::translate("gui", "G", 0));
        bLabel->setText(QApplication::translate("gui", "B", 0));
        xLabel->setText(QApplication::translate("gui", "X", 0));
        yLabel->setText(QApplication::translate("gui", "Y", 0));
        zLabel->setText(QApplication::translate("gui", "Z", 0));
        pushPullPPButton->setText(QApplication::translate("gui", "PushPull++", 0));
        dxLabel->setText(QApplication::translate("gui", "DX", 0));
        dyLabel->setText(QApplication::translate("gui", "DY", 0));
        dzLabel->setText(QApplication::translate("gui", "DZ", 0));
        thetaLabel->setText(QApplication::translate("gui", "Theta", 0));
        planeLabel->setText(QApplication::translate("gui", "Plane", 0));
        planeNormalLabel->setText(QApplication::translate("gui", "Normal", 0));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
