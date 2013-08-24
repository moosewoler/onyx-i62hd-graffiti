#include <QtGui/QtGui>
#include <QScreen>

#include "onyx/screen/screen_update_watcher.h"
#include "onyx/ui/screen_rotation_dialog.h"
#include "onyx/sys/sys.h"

#include "onyx/screen/screen_proxy.h"
//#include "onyx/data/sketch_proxy.h"

//#include "mwolib/graffiti_hui.h"
#include "mwo_mainwindow.h"

//#include <sys/time.h>

static const QString TEST_SKETCH_PATH = "test_sketch";


static RotateDegree getSystemRotateDegree()
{
    int degree = 0;
#ifdef BUILD_FOR_ARM
    degree = QScreen::instance()->transformOrientation();
#endif
    return static_cast<RotateDegree>(degree);
}

MwoMainwindow::MwoMainwindow(QWidget *parent)
    : QWidget(0, Qt::FramelessWindowHint)
{
//    // set up status bar, status_bar_ will cause crash.
//    //status_bar_ = new ui::StatusBar(this, ui::MENU | ui::SCREEN_REFRESH | ui::CONNECTION | ui::BATTERY | ui::CLOCK );
//    //status_bar_->setFocusPolicy(Qt::NoFocus);
//    //connect(status_bar_, SIGNAL(menuClicked()), this, SLOT(showMenu()));
//
//    // set up vertical layout
//    //QVBoxLayout *layout = new QVBoxLayout;
//    //layout->setMargin(0);
//    //layout->addWidget(status_bar_);
//    //setLayout(layout);
//
//    // set up popup menu to long press screen
//    SysStatus & sys_status = SysStatus::instance();
//    connect( &sys_status, SIGNAL(mouseLongPress(QPoint, QSize) ), this, SLOT(OnMouseLongPress(QPoint, QSize) ) );
//    
    // set up screen watcher and refresh
    onyx::screen::watcher().addWatcher(this);

    //// MWO:初始化SketchProxy
    //if (0 == sketch_proxy_)
    //{
    //    sketch_proxy_.reset(new sketch::SketchProxy());
    //    // MWO:不需要额外的工作，所以这几个信号先不用
    //    //connect(sketch_proxy_.get(), SIGNAL(strokeStarted()), this, SLOT(onStrokeStarted()));
    //    //connect(sketch_proxy_.get(), SIGNAL(pointAdded(SketchPoint)), this, SLOT(onPointAdded(SketchPoint)));
    //    //connect(sketch_proxy_.get(), SIGNAL(strokeAdded(const Points &)), this, SLOT(onStrokeAdded(const Points &)));
    //}
    //// MWO:连接SketchProxy
    //attachSketchProxy(sketch_proxy_.get());

    if (0 == graffiti_hui)
    {
        graffiti_hui.reset(new graffiti::TGraffitiHUI());
        graffiti_hui->AttachWidget(this);
    }
}

MwoMainwindow::~MwoMainwindow()
{
    graffiti_hui->DeAttachWidget(this);
}

bool MwoMainwindow::start()
{
    showMaximized();
    onyx::screen::instance().flush(0, onyx::screen::ScreenProxy::GC);
    return true;
}

bool MwoMainwindow::stop()
{
    qApp->exit();
    return true;
}

//bool MwoMainwindow::event(QEvent *e)
//{
////    switch (e->type())
////    {
////        case QEvent::HoverMove:
////        case QEvent::HoverEnter:
////        case QEvent::HoverLeave:
////            e->accept();
////            return true;
////        case QEvent::KeyPress:
////        case QEvent::KeyRelease:
////            {
////                QKeyEvent * ke = down_cast<QKeyEvent*>(e);
////                if (ke->key() == Qt::Key_Down ||
////                        ke->key() == Qt::Key_Up ||
////                        ke->key() == Qt::Key_Left ||
////                        ke->key() == Qt::Key_Right ||
////                        ke->key() == Qt::Key_PageDown ||
////                        ke->key() == Qt::Key_PageUp ||
////                        ke->key() == Qt::Key_Enter ||
////                        ke->key() == Qt::Key_Escape ||
////                        ke->key() == Qt::Key_VolumeDown ||
////                        ke->key() == Qt::Key_VolumeUp ||
////                        ke->key() == ui::Device_Menu_Key)
////                {
////                    break;
////                }
////                e->accept();
////                return true;
////            }
////        default:
////            break;
////    }
//    return QWidget::event(e);
//}

//void MwoMainwindow::paintEvent(QPaintEvent* pe)
//{
//    if (sketch_proxy_ != 0)
//    {
//        QPainter painter(this);
//
//        // update zoom factor
//        sketch_proxy_->setZoom(ZOOM_ACTUAL);
//        sketch_proxy_->setContentOrient(ROTATE_0_DEGREE);
//        sketch_proxy_->setWidgetOrient(ROTATE_180_DEGREE);
//
//        // draw sketches in this page
//        // the page number of any image is 0
//        sketch::PageKey page_key;
//        page_key.setNum(0);
//        QRect page_area(QPoint(0, 0), size());
//        printf("%dx%d\n",size().width(), size().height());
//
//        sketch_proxy_->updatePageDisplayRegion(TEST_SKETCH_PATH, page_key, page_area);
//        sketch_proxy_->paintPage(TEST_SKETCH_PATH, page_key, painter);
//    }
//}

//void MwoMainwindow::attachSketchProxy(SketchProxy *proxy)
//{
////    sketch_proxy_->setMode(MODE_SKETCHING);
////    sketch_proxy_->attachWidget(this);
////    updateSketchProxy();
//}

//void MwoMainwindow::deattachSketchProxy()
//{
////    if (sketch_proxy_ != 0)
////    {
////        sketch_proxy_->deattachWidget(this);
////        sketch_proxy_ = 0;
////    }
//}

//void MwoMainwindow::updateSketchProxy()
//{
////    if (sketch_proxy_ != 0)
////    {
////        // deactivate all pages
////        sketch_proxy_->deactivateAll();
////
////        // update zoom factor
////        sketch_proxy_->setZoom(ZOOM_ACTUAL);
////        sketch_proxy_->setContentOrient(ROTATE_0_DEGREE);
////        //printf("%d\n", getSystemRotateDegree());
////        sketch_proxy_->setWidgetOrient(ROTATE_180_DEGREE);
////
////        sketch::PageKey page_key;
////        QRect page_area(QPoint(0, 0), size());
////        printf("%dx%d\n",size().width(), size().height());
////
////        // the page number of any image is 0
////        page_key.setNum(0);
////        sketch_proxy_->activatePage(TEST_SKETCH_PATH, page_key);
////        sketch_proxy_->updatePageDisplayRegion(TEST_SKETCH_PATH, page_key, page_area);
////    }
//}
