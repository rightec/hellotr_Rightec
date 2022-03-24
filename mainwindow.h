#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>

#include "customnamespace.h"
#include "templatew1.h"
#include "templatew2.h"
#include "templatew3.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBackHomeT1(void);

    void onBackHomeT2(void);

    void onBackHomeT3(void);

    void on_m_btnHelloTr_clicked();

    void on_m_btnOpenW_1_clicked();

    void on_m_btnOpenW_2_clicked();

    void on_m_btnOpenW_3_clicked();

private:
    Ui::MainWindow *ui;
    QString m_file;
    QTranslator *m_p_Translator;



    TemplateW1 T1;
    TemplateW2 T2;
    TemplateW3 T3;

};

#endif // MAINWINDOW_H
