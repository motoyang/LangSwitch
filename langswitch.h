#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class LangSwitch;
}

class LangSwitch : public QWidget
{
    Q_OBJECT

public:
    explicit LangSwitch(QWidget *parent = 0);
    ~LangSwitch();

private slots:
    void changeLang(int index);

private:
    Ui::LangSwitch *ui;

    void createScreen();
    void changeTr(const QString& langCode);
    void refreshLabel();

    QComboBox* combo;
    QLabel* label;
};

#endif // LANGSWITCH_H
