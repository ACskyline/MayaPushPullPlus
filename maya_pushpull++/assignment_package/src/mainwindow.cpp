#include "mainwindow.h"
#include <ui_mainwindow.h>
#include <QDesktopWidget>
#include <QFileDialog>
#include "cameracontrolshelp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    g(new gui()),
    g2(new gui2())
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    g->show();
    g->move(QApplication::desktop()->screen()->rect().center() + QPoint(this->rect().width()/2, -this->rect().height()/2));
    g->updateFaceList(ui->mygl->m_geomMesh.fVector);
    g->updateHalfEdgeList(ui->mygl->m_geomMesh.hVector);
    g->updateVertexList(ui->mygl->m_geomMesh.vVector);

    g2->show();
    g2->move(QApplication::desktop()->screen()->rect().center() + QPoint(-(this->rect().width()/2+g2->rect().width()+10), -this->rect().height()/2));

    connectSignalSlot();
}

MainWindow::~MainWindow()
{
    if(g!=nullptr)
    {
        delete g;
    }
    if(g2!=nullptr)
    {
        delete g2;
    }
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    g->close();
    g2->close();
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    g->close();
    g2->close();
    QMainWindow::closeEvent(e);
}

void MainWindow::on_actionEditor_triggered()
{
    g->close();
    delete g;
    g = new gui();
    g->show();
    g->move(QApplication::desktop()->screen()->rect().center() + QPoint(this->rect().width()/2, -this->rect().height()/2));
    g->updateFaceList(ui->mygl->m_geomMesh.fVector);
    g->updateHalfEdgeList(ui->mygl->m_geomMesh.hVector);
    g->updateVertexList(ui->mygl->m_geomMesh.vVector);
    g->slot_setClickFace(ui->mygl->curF);
    g->slot_setClickHalfEdge(ui->mygl->curH);
    g->slot_setClickVertex(ui->mygl->curV);

    connectSignalSlot();
}


void MainWindow::on_actionEditor2_triggered()
{
    g2->close();
    delete g2;
    g2 = new gui2();
    g2->show();
    g2->move(QApplication::desktop()->screen()->rect().center() + QPoint(-(this->rect().width()/2+g2->rect().width()+10), -this->rect().height()/2));
    g2->slot_updateTree(ui->mygl->m_Skeleton);
    g2->slot_setClickJoint(ui->mygl->curJ);

    connectSignalSlot();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"../",tr("Obj Files (*.obj)"));
    if(fileName!=QString::null)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        // clear previous stuff
        ui->mygl->curF = nullptr;
        ui->mygl->curH = nullptr;
        ui->mygl->curV = nullptr;
        if(g!=nullptr)
        {
            g->freeList();
        }
        ///////////////////////
        ui->mygl->m_geomMesh.parseFile(&file);
        ui->mygl->update();
        g->slot_updateList(ui->mygl->m_geomMesh.vVector,ui->mygl->m_geomMesh.hVector,ui->mygl->m_geomMesh.fVector);
        ui->mygl->skinned = false;
        g2->slot_setSkinButton(false);
        g->slot_setClickFace(ui->mygl->curF);
        g->slot_setClickHalfEdge(ui->mygl->curH);
        g->slot_setClickVertex(ui->mygl->curV);
    }
}

void MainWindow::on_actionOpen_JSON_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"../",tr("Json Files (*.json)"));
    if(fileName!=QString::null)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
            return;

        // clear previous stuff
        ui->mygl->curJ = nullptr;
        if(g2!=nullptr)
        {
            g2->freeTree();
        }
        ///////////////////////
        ui->mygl->m_Skeleton.parseFile(&file);
        ui->mygl->m_geomMarkerSet.setUp(ui->mygl->m_Skeleton);
        ui->mygl->updateShaderSkeletonMatrix();
        ui->mygl->update();
        g2->slot_updateTree(ui->mygl->m_Skeleton);
        ui->mygl->skinned = false;
        g2->slot_setSkinButton(false);
        g2->slot_setClickJoint(ui->mygl->curJ);
    }
}

void MainWindow::connectSignalSlot()
{
    connect(g,SIGNAL(selectFace(Face*)), ui->mygl, SLOT(slot_setCurrentFace(Face*)));
    connect(g,SIGNAL(selectHalfEdge(HalfEdge*)), ui->mygl, SLOT(slot_setCurrentHalfEdge(HalfEdge*)));
    connect(g,SIGNAL(selectVertex(Vertex*)), ui->mygl, SLOT(slot_setCurrentVertex(Vertex*)));
    connect(g,SIGNAL(splitEdge()),ui->mygl,SLOT(slot_spiltEdge()));
    connect(g,SIGNAL(triangulateFace()),ui->mygl,SLOT(slot_triangulateFace()));
    connect(g,SIGNAL(subdivide()),ui->mygl,SLOT(slot_subdivide()));
    connect(g,SIGNAL(extrude()),ui->mygl,SLOT(slot_extrude()));
    connect(g,SIGNAL(bevelEdge()),ui->mygl,SLOT(slot_bevelEdge()));
    connect(g,SIGNAL(changeFR(double)),ui->mygl,SLOT(slot_changeFR(double)));
    connect(g,SIGNAL(changeFG(double)),ui->mygl,SLOT(slot_changeFG(double)));
    connect(g,SIGNAL(changeFB(double)),ui->mygl,SLOT(slot_changeFB(double)));
    connect(g,SIGNAL(changeVX(double)),ui->mygl,SLOT(slot_changeVX(double)));
    connect(g,SIGNAL(changeVY(double)),ui->mygl,SLOT(slot_changeVY(double)));
    connect(g,SIGNAL(changeVZ(double)),ui->mygl,SLOT(slot_changeVZ(double)));

    connect(g,SIGNAL(pushPullPP(glm::vec3,float,glm::vec3,glm::vec3)),ui->mygl,SLOT(slot_pushPullPP(glm::vec3,float,glm::vec3,glm::vec3)));

    connect(g2,SIGNAL(selectJoint(Joint*)), ui->mygl, SLOT(slot_setCurrentJoint(Joint*)));
    connect(g2,SIGNAL(rotX()),ui->mygl,SLOT(slot_rotX()));
    connect(g2,SIGNAL(rotY()),ui->mygl,SLOT(slot_rotY()));
    connect(g2,SIGNAL(rotZ()),ui->mygl,SLOT(slot_rotZ()));
    connect(g2,SIGNAL(skin()),ui->mygl,SLOT(slot_skin()));
    connect(g2,SIGNAL(changeJX(double)),ui->mygl,SLOT(slot_changeJX(double)));
    connect(g2,SIGNAL(changeJY(double)),ui->mygl,SLOT(slot_changeJY(double)));
    connect(g2,SIGNAL(changeJZ(double)),ui->mygl,SLOT(slot_changeJZ(double)));


    connect(ui->mygl,SIGNAL(setClickFace(Face*)),g,SLOT(slot_setClickFace(Face*)));
    connect(ui->mygl,SIGNAL(setClickHalfEdge(HalfEdge*)),g,SLOT(slot_setClickHalfEdge(HalfEdge*)));
    connect(ui->mygl,SIGNAL(setClickVertex(Vertex*)),g,SLOT(slot_setClickVertex(Vertex*)));
    connect(ui->mygl,SIGNAL(updateList(std::vector<Vertex*>&,std::vector<HalfEdge*>&,std::vector<Face*>&)),
            g,SLOT(slot_updateList(std::vector<Vertex*>&,std::vector<HalfEdge*>&,std::vector<Face*>&)));

    connect(ui->mygl,SIGNAL(setClickJoint(Joint*)),g2,SLOT(slot_setClickJoint(Joint*)));
    connect(ui->mygl,SIGNAL(setSkinButton(bool)),g2,SLOT(slot_setSkinButton(bool)));
}
