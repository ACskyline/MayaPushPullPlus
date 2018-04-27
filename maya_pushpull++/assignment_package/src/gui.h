#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "face.h"

namespace Ui {
class gui;
}

class gui : public QWidget
{
    Q_OBJECT
public:
    explicit gui(QWidget *parent = 0);
    ~gui();

    Ui::gui *ui;

    void updateFaceList(std::vector<Face*> &fV);
    void updateHalfEdgeList(std::vector<HalfEdge*> &hV);
    void updateVertexList(std::vector<Vertex*> &vV);
    void freeList();
    void closeEvent(QCloseEvent *e);

private slots:
    void on_faceList_itemClicked(QListWidgetItem *item);
    void on_halfEdgeList_itemClicked(QListWidgetItem *item);
    void on_vertexList_itemClicked(QListWidgetItem *item);
    void on_splitEdgeButton_clicked();
    void on_triangulateFaceButton_clicked();
    void on_subdivideButton_clicked();
    void on_extrudeButton_clicked();

    void on_bevelEdgeButton_clicked();

    void on_rDoubleSpinBox_valueChanged(double arg1);

    void on_gDoubleSpinBox_valueChanged(double arg1);

    void on_bDoubleSpinBox_valueChanged(double arg1);

    void on_xDoubleSpinBox_valueChanged(double arg1);

    void on_yDoubleSpinBox_valueChanged(double arg1);

    void on_zDoubleSpinBox_valueChanged(double arg1);

    void on_pushPullPPButton_clicked();

public slots:
    void slot_setClickFace(Face* f);
    void slot_setClickHalfEdge(HalfEdge* h);
    void slot_setClickVertex(Vertex* v);
    void slot_updateList(std::vector<Vertex*> &vV, std::vector<HalfEdge*> &hV, std::vector<Face*> &fV);

signals:
    void selectFace(Face *item);
    void selectHalfEdge(HalfEdge *item);
    void selectVertex(Vertex *item);
    void splitEdge();
    void triangulateFace();
    void subdivide();
    void extrude();
    void bevelEdge();
    void changeFR(double r);
    void changeFG(double g);
    void changeFB(double b);
    void changeVX(double x);
    void changeVY(double y);
    void changeVZ(double z);
    void pushPullPP(glm::vec3 d, float theta, glm::vec3 p, glm::vec3 n);
};

#endif // GUI_H
