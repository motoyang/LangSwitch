#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QWidget>

namespace Ui {
class LangSwitch;
}

class LangSwitch : public QWidget
{
    Q_OBJECT

public:
    explicit LangSwitch(QWidget *parent = 0);
    ~LangSwitch();

private:
    Ui::LangSwitch *ui;
};

#endif // LANGSWITCH_H
