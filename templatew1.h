#ifndef TEMPLATEW1_H
#define TEMPLATEW1_H

#include <QMainWindow>
#include <QDebug>

#include "customnamespace.h"

using namespace ContosoData;
extern TrManager Ibis_Translator;


namespace Ui {
class TemplateW1;
}

class TemplateW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateW1(QWidget *parent = nullptr);
    ~TemplateW1();

private:
    Ui::TemplateW1 *ui;
    int m_State;
    QString m_StateString;
    QTranslator *m_p_Translator;
    QString m_file;
    QStringList m_TranslateList;

    void initStringList();


private slots:
    void onStateChanged();
    void onShow();
    void onTranslate();

    void on_m_btn_Home_clicked();

    void on_m_btn_3State_clicked();

signals:
    void backHome(void);
    void fullShow(void);
    void translate(void);

};

#endif // TEMPLATEW1_H
