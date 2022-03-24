#ifndef TEMPLATEW3_H
#define TEMPLATEW3_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class TemplateW3;
}

class TemplateW3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateW3(QWidget *parent = nullptr);
    ~TemplateW3();

private:
    Ui::TemplateW3 *ui;
    int m_State;
    QString m_StateString;


signals:
    void backHome(void);

private slots:
    void onStateChanged();

    void on_m_btn_Home_clicked();
    void on_m_btn_3State_clicked();
};

#endif // TEMPLATEW3_H
