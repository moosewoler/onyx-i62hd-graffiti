#include "onyx/data/configuration.h"
#include "onyx/ui/languages.h"
#include "mwo_application.h"

MwoApplication::MwoApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setApplicationName("Graffiti");

    // 设置Translator
    QTranslator t;
    t.load(QLocale::system().name());
    installTranslator(&t);
    ui::loadTranslator(QLocale::system().name());

}

MwoApplication::~MwoApplication(void)
{
}

bool MwoApplication::start()
{
    main_window_.start();
    return true;
}

bool MwoApplication::stop()
{
    return true;
}
