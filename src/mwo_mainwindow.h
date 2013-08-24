#ifndef MWO_MAINWINDOW_H_
#define MWO_MAINWINDOW_H_

#include <QtGui/QtGui>

#include "onyx/ui/ui.h"
#include "onyx/ui/ui_utils.h"
//#include "onyx/ui/status_bar.h"
//#include "onyx/data/sketch_proxy.h"
#include "onyx/screen/screen_proxy.h"

#include "mwolib/graffiti_hui.h"

using namespace ui;

class MwoMainwindow : public QWidget
{
    Q_OBJECT

    public:
        MwoMainwindow(QWidget *parent = 0);
        ~MwoMainwindow();

    public:
        bool start();
        bool stop();

        //void attachSketchProxy(sketch::SketchProxy *proxy);
        //void deattachSketchProxy();
        //void updateSketchProxy();

    protected:
        //virtual void paintEvent(QPaintEvent* pe);
        //virtual bool event(QEvent *e);

        //private Q_SLOTS:

    private:
        //scoped_ptr<sketch::SketchProxy> sketch_proxy_;
        scoped_ptr<graffiti::TGraffitiHUI> graffiti_hui;
};

#endif

