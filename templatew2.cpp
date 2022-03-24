#include "templatew2.h"
#include "ui_templatew2.h"

TemplateW2::TemplateW2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemplateW2)
{
    ui->setupUi(this);
    m_State = 0;
    onStateChanged();
}

TemplateW2::~TemplateW2()
{
    delete ui;
}

void TemplateW2::on_m_btn_Home_clicked()
{
    emit backHome();
}

void TemplateW2::onStateChanged()
{
    switch (m_State) {
    case 0:
        m_StateString = QObject::tr("Selling arm to Ukraine");
        m_State++;
        break;
    case 1:
        m_StateString = QObject::tr("Receiving Refugees");
        m_State++;
        break;
    case 2:
        m_StateString = QObject::tr("Kill all tribes");
        m_State = 0;
        break;
    default:
        qDebug() << "TemplateW2::onStateChanged() Error";
        break;
    }

    ui->m_btn_3State->setText(m_StateString);
}

void TemplateW2::on_m_btn_3State_clicked()
{
    onStateChanged();
}
