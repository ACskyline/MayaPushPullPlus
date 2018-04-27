#include "gui2.h"
#include "ui_gui2.h"

gui2::gui2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gui2)
{
    ui->setupUi(this);
    ui->xDoubleSpinBox->setEnabled(false);
    ui->yDoubleSpinBox->setEnabled(false);
    ui->zDoubleSpinBox->setEnabled(false);
}

gui2::~gui2()
{
    freeTree();
    delete ui;
}

void gui2::slot_updateTree(const Skeleton &s)
{
    freeTree();
    ui->skeletonTreeWidget->addTopLevelItem(s.root);
}

void gui2::freeTree()
{
    while(ui->skeletonTreeWidget->topLevelItemCount()!=0)
    {
        ui->skeletonTreeWidget->takeTopLevelItem(0);
    }
}


void gui2::closeEvent(QCloseEvent *e)
{
    QWidget::closeEvent(e);
}

void gui2::slot_setClickJoint(Joint *j)
{
    if(j!=nullptr)
    {
        ui->skeletonTreeWidget->setCurrentItem(j);
        glm::mat4 matW = j->getOverallTransformation();
        glm::vec4 wp = matW*glm::vec4(0,0,0,1);
        glm::mat4 matQ = glm::toMat4(j->rotation);
        glm::quat wr = glm::toQuat(matW*matQ);
        glm::vec4 lp = glm::vec4(j->position,1);
        glm::quat lr = j->rotation;
        QString wps;
        QString wrs;
        QString lps;
        QString lrs;
        QTextStream(&wps) << QString::number(wp.x,'f',2) << "," << QString::number(wp.y,'f',2) << "," << QString::number(wp.z,'f',2);
        QTextStream(&wrs) << QString::number(wr.w,'f',2) << "," << QString::number(wr.x,'f',2) << "," << QString::number(wr.y,'f',2) << "," << QString::number(wr.z,'f',2);
        QTextStream(&lps) << QString::number(lp.x,'f',2) << "," << QString::number(lp.y,'f',2) << "," << QString::number(lp.z,'f',2);
        QTextStream(&lrs) << QString::number(lr.w,'f',2) << "," << QString::number(lr.x,'f',2) << "," << QString::number(lr.y,'f',2) << "," << QString::number(lr.z,'f',2);
        ui->wPositionLabel->setText(wps);
        ui->wRotationLabel->setText(wrs);
        ui->lPositionLabel->setText(lps);
        ui->lRotationLabel->setText(lrs);
        ui->xDoubleSpinBox->setEnabled(true);
        ui->yDoubleSpinBox->setEnabled(true);
        ui->zDoubleSpinBox->setEnabled(true);
        ui->xDoubleSpinBox->setValue(j->position.x);
        ui->yDoubleSpinBox->setValue(j->position.y);
        ui->zDoubleSpinBox->setValue(j->position.z);
    }
    else
    {
        ui->wPositionLabel->setText(QString("N/A"));
        ui->wRotationLabel->setText(QString("N/A"));
        ui->lPositionLabel->setText(QString("N/A"));
        ui->lRotationLabel->setText(QString("N/A"));
        ui->xDoubleSpinBox->setEnabled(false);
        ui->yDoubleSpinBox->setEnabled(false);
        ui->zDoubleSpinBox->setEnabled(false);
    }
}

void gui2::slot_setSkinButton(bool _skinned)
{
    if(_skinned)
    {
        ui->skinningButton->setText("unskin");
    }
    else
    {
        ui->skinningButton->setText("skin");
    }
}

void gui2::on_skeletonTreeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Joint* j = static_cast<Joint*>(item);
    emit selectJoint(j);
    slot_setClickJoint(j);
}

void gui2::on_rotXButton_clicked()
{
    emit rotX();
}

void gui2::on_rotYButton_clicked()
{
    emit rotY();
}

void gui2::on_rotZButton_clicked()
{
    emit rotZ();
}

void gui2::on_skinningButton_clicked()
{
    emit skin();
}

void gui2::on_xDoubleSpinBox_valueChanged(double arg1)
{
    emit changeJX(arg1);
}

void gui2::on_yDoubleSpinBox_valueChanged(double arg1)
{
    emit changeJY(arg1);
}

void gui2::on_zDoubleSpinBox_valueChanged(double arg1)
{
    emit changeJZ(arg1);
}
