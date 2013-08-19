#include <QtGui>

#include "onyx/sys/sys_status.h"
#include "mwo_application.h"

int main(int argc, char * argv[])
{

    sys::SysStatus::instance().setSystemBusy(false);
    sys::SysStatus::instance().enableIdle(false);

    MwoApplication myapp(argc, argv);
    myapp.start();

    int ret = myapp.exec();

    sys::SysStatus::instance().enableIdle(true);
    return ret;
}
