#include "gui.h"
#include "ui_gui.h"

gui::gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gui)
{
    ui->setupUi(this);
    ui->rDoubleSpinBox->setEnabled(false);
    ui->gDoubleSpinBox->setEnabled(false);
    ui->bDoubleSpinBox->setEnabled(false);
    ui->xDoubleSpinBox->setEnabled(false);
    ui->yDoubleSpinBox->setEnabled(false);
    ui->zDoubleSpinBox->setEnabled(false);
}

gui::~gui()
{
    freeList();
    delete ui;
}

void gui::freeList()
{
    while(ui->faceList->count()!=0)
    {
        ui->faceList->takeItem(0);
    }
    while(ui->halfEdgeList->count()!=0)
    {
        ui->halfEdgeList->takeItem(0);
    }
    while(ui->vertexList->count()!=0)
    {
        ui->vertexList->takeItem(0);
    }
}

void gui::updateFaceList(std::vector<Face*> &fV)
{
    //ui->faceList->clear();
    //should not use clear since it delete the exact memory of the items
    //which should be managed by MyGL
    while(ui->faceList->count()!=0)
    {
        ui->faceList->takeItem(0)->text().toLatin1();
    }
    for(int i = 0;i<fV.size();i++)
    {
        ui->faceList->addItem(fV.at(i));
    }
}

void gui::updateHalfEdgeList(std::vector<HalfEdge*> &hV)
{
    //ui->halfEdgeList->clear();
    //should not use clear since it delete the exact memory of the items
    //which should be managed by MyGL
    while(ui->halfEdgeList->count()!=0)
    {
        ui->halfEdgeList->takeItem(0);
    }
    for(int i = 0;i<hV.size();i++)
    {
        ui->halfEdgeList->addItem(hV.at(i));
    }
}

void gui::updateVertexList(std::vector<Vertex*> &vV)
{
    //ui->vertexList->clear();
    //should not use clear since it delete the exact memory of the items
    //which should be managed by MyGL
    while(ui->vertexList->count()!=0)
    {
        ui->vertexList->takeItem(0);
    }
    for(int i = 0;i<vV.size();i++)
    {
        ui->vertexList->addItem(vV.at(i));
    }
}

void gui::on_faceList_itemClicked(QListWidgetItem *item)
{
    Face* f = static_cast<Face*>(item);
    emit selectFace(f);
    ui->rDoubleSpinBox->setEnabled(true);
    ui->gDoubleSpinBox->setEnabled(true);
    ui->bDoubleSpinBox->setEnabled(true);
    ui->rDoubleSpinBox->setValue(f->col.r);
    ui->gDoubleSpinBox->setValue(f->col.g);
    ui->bDoubleSpinBox->setValue(f->col.b);
}

void gui::on_halfEdgeList_itemClicked(QListWidgetItem *item)
{
    HalfEdge* h = static_cast<HalfEdge*>(item);
    emit selectHalfEdge(h);
}

void gui::on_vertexList_itemClicked(QListWidgetItem *item)
{
    Vertex* v = static_cast<Vertex*>(item);
    emit selectVertex(v);
    ui->xDoubleSpinBox->setEnabled(true);
    ui->yDoubleSpinBox->setEnabled(true);
    ui->zDoubleSpinBox->setEnabled(true);
    ui->xDoubleSpinBox->setValue(v->position.x);
    ui->yDoubleSpinBox->setValue(v->position.y);
    ui->zDoubleSpinBox->setValue(v->position.z);
}

void gui::slot_setClickFace(Face* f)
{
    if(f!=nullptr)
    {
        ui->faceList->setCurrentItem(f);
        ui->rDoubleSpinBox->setEnabled(true);
        ui->gDoubleSpinBox->setEnabled(true);
        ui->bDoubleSpinBox->setEnabled(true);
        ui->rDoubleSpinBox->setValue(f->col.r);
        ui->gDoubleSpinBox->setValue(f->col.g);
        ui->bDoubleSpinBox->setValue(f->col.b);
    }
    else
    {
        ui->faceList->setCurrentItem(f);
        ui->rDoubleSpinBox->setEnabled(false);
        ui->gDoubleSpinBox->setEnabled(false);
        ui->bDoubleSpinBox->setEnabled(false);
    }
}

void gui::slot_setClickHalfEdge(HalfEdge* h)
{
    if(h!=nullptr)
    {
        ui->halfEdgeList->setCurrentItem(h);
    }
}

void gui::slot_setClickVertex(Vertex* v)
{
    if(v!=nullptr)
    {
        ui->vertexList->setCurrentItem(v);
        ui->xDoubleSpinBox->setEnabled(true);
        ui->yDoubleSpinBox->setEnabled(true);
        ui->zDoubleSpinBox->setEnabled(true);
        ui->xDoubleSpinBox->setValue(v->position.x);
        ui->yDoubleSpinBox->setValue(v->position.y);
        ui->zDoubleSpinBox->setValue(v->position.z);
    }
    else
    {
        ui->vertexList->setCurrentItem(v);
        ui->xDoubleSpinBox->setEnabled(false);
        ui->yDoubleSpinBox->setEnabled(false);
        ui->zDoubleSpinBox->setEnabled(false);
    }
}

void gui::on_splitEdgeButton_clicked()
{
    emit splitEdge();
}

void gui::on_triangulateFaceButton_clicked()
{
    emit triangulateFace();
}

void gui::on_subdivideButton_clicked()
{
    emit subdivide();
}

void gui::on_extrudeButton_clicked()
{
    emit extrude();
}

void gui::on_bevelEdgeButton_clicked()
{
    emit bevelEdge();
}

void gui::slot_updateList(std::vector<Vertex*> &vV, std::vector<HalfEdge*> &hV, std::vector<Face*> &fV)
{
    freeList();
    updateVertexList(vV);
    updateHalfEdgeList(hV);
    updateFaceList(fV);
}

void gui::closeEvent(QCloseEvent *e)
{
    freeList();
    QWidget::closeEvent(e);
}

void gui::on_rDoubleSpinBox_valueChanged(double arg1)
{
    emit changeFR(arg1);
}

void gui::on_gDoubleSpinBox_valueChanged(double arg1)
{
    emit changeFG(arg1);
}

void gui::on_bDoubleSpinBox_valueChanged(double arg1)
{
    emit changeFB(arg1);
}

void gui::on_xDoubleSpinBox_valueChanged(double arg1)
{
    emit changeVX(arg1);
}

void gui::on_yDoubleSpinBox_valueChanged(double arg1)
{
    emit changeVY(arg1);
}

void gui::on_zDoubleSpinBox_valueChanged(double arg1)
{
    emit changeVZ(arg1);
}

void gui::on_pushPullPPButton_clicked()
{
    glm::vec3 d(ui->pushPullPPDX->value(),ui->pushPullPPDY->value(),ui->pushPullPPDZ->value());
    float theta = ui->pushPullPPTheta->value();
    glm::vec3 p(ui->pushPullPPPX->value(),ui->pushPullPPPY->value(),ui->pushPullPPPZ->value());
    glm::vec3 n(ui->pushPullPPPNX->value(),ui->pushPullPPPNY->value(),ui->pushPullPPPNZ->value());
//    qDebug() << d.x << "," << d.y << "," << d.z;
//    qDebug() << theta;
//    qDebug() << p.x << "," << p.y << "," << p.z;
//    qDebug() << n.x << "," << n.y << "," << n.z;
    emit pushPullPP(d, theta, p, n);
}
