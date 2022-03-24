#include "templatew1.h"
#include "ui_templatew1.h"


TemplateW1::TemplateW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemplateW1)
{
    ui->setupUi(this);
    m_p_Translator = Ibis_Translator.getTranslator();

    initStringList();
    m_State = 0;
    onStateChanged();
    connect(this,SIGNAL(fullShow(void)),this,SLOT(onShow(void)));
    connect(this,SIGNAL(translate(void)),this,SLOT(onTranslate(void)));
}

TemplateW1::~TemplateW1()
{
    delete ui;
}

void TemplateW1::initStringList()
{

    m_TranslateList.clear();

    ui->retranslateUi(this);

    m_TranslateList.append(QObject::tr("Green Pass for vaccinated people"));
    m_TranslateList.append(QObject::tr("Green Pass for tested people"));
    m_TranslateList.append(QObject::tr("Green Pass for illed people"));


    for (int i=0; i< m_TranslateList.size(); i++){
        qDebug() << "TemplateW1::initStringList() item "
                 << i << " is: "
                 << m_TranslateList.at(i);
    }

}

void TemplateW1::onStateChanged()
{
    initStringList();
    // ui->retranslateUi(this);

    switch (m_State) {
    case 0:
        m_StateString = m_TranslateList.at(m_State);
                //QObject::tr("Green Pass for vaccinated people");
        m_State++;
        break;
    case 1:
        m_StateString = m_TranslateList.at(m_State);
        //QObject::tr("Green Pass for tested people");
        m_State++;
        break;
    case 2:
        m_StateString = m_TranslateList.at(m_State);
        //QObject::tr("Green Pass for illed people");
        m_State = 0;
        break;
    default:
        qDebug() << "TemplateW1::onStateChanged() Error";
        break;
    }

    ui->m_btn_3State->setText(m_StateString);
    qDebug() << "TemplateW1::onStateChanged() text is: " << ui->m_btn_3State->text();
    // ui->retranslateUi(this);

}

void TemplateW1::onShow()
{
    ui->retranslateUi(this);
    qDebug() << "TemplateW1::onShow() text is: " << ui->m_btn_3State->text();
    show();
}

void TemplateW1::onTranslate()
{
    m_file= Ibis_Translator.getFile();
    qDebug() << "TemplateW1::onTranslate() file is: " << m_file;
    qDebug() << "TemplateW1::onTranslate() text (before) is: " << ui->m_btn_3State->text();
    ui->retranslateUi(this);
    qDebug() << "TemplateW1::onTranslate() text (after)  is: " << ui->m_btn_3State->text();
}

void TemplateW1::on_m_btn_Home_clicked()
{
    emit backHome();
}

void TemplateW1::on_m_btn_3State_clicked()
{
    onStateChanged();
}
