#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "templatew1.h"

using namespace ContosoData;
TrManager Ibis_Translator;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Ibis_Translator.setFile(qApp->applicationDirPath() + "/hellotr_sp.qm");
    m_file= Ibis_Translator.getFile();
    if (QFile::exists(m_file) == true){
        m_p_Translator = Ibis_Translator.getTranslator();
        m_p_Translator->load(m_file);
        qApp->installTranslator(m_p_Translator);
        qDebug() << m_file;
        ui->retranslateUi(this);
        ui->m_btnHelloTr->setText(tr("Hello world!"));
        ui->m_btnHelloTr->resize(100, 100);

    } else {
        qDebug() << "File does not exist";
        ui->m_btnHelloTr->setText("NO TRANSLATION");
    }

    connect(&T1,SIGNAL(backHome(void)),this,SLOT(onBackHomeT1(void)));
    connect(&T2,SIGNAL(backHome(void)),this,SLOT(onBackHomeT2(void)));
    connect(&T3,SIGNAL(backHome(void)),this,SLOT(onBackHomeT3(void)));

    emit T1.translate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBackHomeT1(void)
{
    this->show();
    T1.hide();
}

void MainWindow::onBackHomeT2(void)
{
    this->show();
    T2.hide();
}

void MainWindow::onBackHomeT3(void)
{
    this->show();
    T3.hide();
}

void MainWindow::on_m_btnHelloTr_clicked()
{
    if (m_file.contains("_sp")){
        ui->retranslateUi(this);
        ui->m_btnHelloTr->setText(QObject::tr("Here it is !"));
    } else {
        ui->m_btnHelloTr->setText("No Spanish translation");
    }
}

void MainWindow::on_m_btnOpenW_1_clicked()
{
    this->hide();
    emit T1.fullShow();
}

void MainWindow::on_m_btnOpenW_2_clicked()
{
    this->hide();
    T2.show();
}

void MainWindow::on_m_btnOpenW_3_clicked()
{
    this->hide();
    T3.show();
}
