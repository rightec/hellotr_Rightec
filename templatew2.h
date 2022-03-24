#ifndef TEMPLATEW2_H
#define TEMPLATEW2_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class TemplateW2;
}

class TemplateW2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateW2(QWidget *parent = nullptr);
    ~TemplateW2();

private slots:
    void onStateChanged();

    void on_m_btn_Home_clicked();

    void on_m_btn_3State_clicked();

private:
    Ui::TemplateW2 *ui;
    int m_State;
    QString m_StateString;


signals:
    void backHome(void);

};

#endif // TEMPLATEW2_H
