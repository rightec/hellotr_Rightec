#include "templatew3.h"
#include "ui_templatew3.h"

TemplateW3::TemplateW3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemplateW3)
{
    ui->setupUi(this);
    m_State = 0;
    onStateChanged();
}

TemplateW3::~TemplateW3()
{
    delete ui;
}

void TemplateW3::onStateChanged()
{
    switch (m_State) {
    case 0:
        m_StateString = QObject::tr("Renting House in Holiday");
        m_State++;
        break;
    case 1:
        m_StateString = QObject::tr("Rebuild you home");
        m_State++;
        break;
    case 2:
        m_StateString = QObject::tr("Living in Paradise");
        m_State = 0;
        break;
    default:
        qDebug() << "TemplateW3::onStateChanged() Error";
        break;
    }

    ui->m_btn_3State->setText(m_StateString);
}

void TemplateW3::on_m_btn_Home_clicked()
{
    emit backHome();
}

void TemplateW3::on_m_btn_3State_clicked()
{
    onStateChanged();
}
