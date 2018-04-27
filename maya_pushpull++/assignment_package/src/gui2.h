#ifndef GUI2_H
#define GUI2_H

#include <QWidget>
#include "skeleton.h"

namespace Ui {
class gui2;
}

class gui2 : public QWidget
{
    Q_OBJECT

public:
    explicit gui2(QWidget *parent = 0);
    void freeTree();
    ~gui2();

private:
    Ui::gui2 *ui;
    void closeEvent(QCloseEvent *e);
public slots:
    void slot_setClickJoint(Joint* j);
    void slot_updateTree(const Skeleton& s);
    void slot_setSkinButton(bool _skinned);
private slots:
    void on_skeletonTreeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_rotXButton_clicked();

    void on_rotYButton_clicked();

    void on_rotZButton_clicked();

    void on_skinningButton_clicked();

    void on_xDoubleSpinBox_valueChanged(double arg1);

    void on_yDoubleSpinBox_valueChanged(double arg1);

    void on_zDoubleSpinBox_valueChanged(double arg1);

signals:
    void selectJoint(Joint* j);
    void rotX();
    void rotY();
    void rotZ();
    void skin();
    void changeJX(double x);
    void changeJY(double Y);
    void changeJZ(double Z);
};

#endif // GUI2_H
