#include <QVBoxLayout>
#include <QApplication>
#include <QTranslator>
#include "langswitch.h"
#include "ui_langswitch.h"

LangSwitch::LangSwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LangSwitch)
{
    ui->setupUi(this);

    createScreen();
}

LangSwitch::~LangSwitch()
{
    delete ui;
}

void LangSwitch::createScreen()
{
    combo = new QComboBox;
    combo->addItem("Chinese", "zh");
    combo->addItem("English", "en");
    combo->addItem("Latin", "la");

    label = new QLabel;
    refreshLabel();

    QVBoxLayout* l = new QVBoxLayout;
    l->addWidget(combo, 1);
    l->addWidget(label, 5);

    setLayout(l);

    connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLang(int)));
    changeLang(0);
}

void LangSwitch::refreshLabel()
{
    label->setText(tr("TXT_HELLO_WORLD", "Hello, world!"));
    setWindowTitle(tr("TXT_WINDOW_TITLE", "Main window title"));
}

void LangSwitch::changeLang(int index)
{
    QString langCode = combo->itemData(index).toString();
    changeTr(langCode);
    refreshLabel();
}

void LangSwitch::changeTr(const QString &langCode)
{
    static QTranslator* t = nullptr;

    if (t) {
        qApp->removeTranslator(t);
        delete t;
    }
    t = new QTranslator;
    QString qmFilename = "lang_" + langCode;

    if (t->load(QString("/Users/moto2yang/cpp/qt/LangSwitch/") + qmFilename)) {
        qApp->installTranslator(t);
    }
}
