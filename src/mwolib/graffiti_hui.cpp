/*******************************************************************************
 *          graffiti_hui.cpp
 * Description:
 *  graffiti_hui holds the implementation of the class TGraffitiHUI which deals 
 *  with the touch screen staffs.
 * TODO:
 *  pass touch data to TGraffitiCanvas
 * History:
 *  2013-08-25  NEW
 ******************************************************************************/
// system headers
#include <QtGui>

// onyx headers
#include "onyx/sys/platform.h"

// user defined
#include "graffiti_hui.h"

#include <stdio.h>
#define MWO_DEBUG_STRING(var)    do { printf(#var" = %s\n", var); } while(0)
#define MWO_DEBUG_FLOAT(var)     do { printf(#var" = %f\n", var); } while(0)
#define MWO_DEBUG_POINTER(var)   do { printf(#var" = %p\n", var); } while(0)
#define MWO_DEBUG_INT(var)       do { printf(#var" = %d\n", var); } while(0)
#define MWO_DEBUG(var)           MWO_DEBUG_INT(var)

namespace graffiti
{

TGraffitiHUI::TGraffitiHUI()
    : attached_widget(0)
{
    connect(&touch_listener, SIGNAL(touchData(TouchData &)), this, SLOT(OnTouch(TouchData &)));
}

TGraffitiHUI::~TGraffitiHUI()
{
}

void TGraffitiHUI::AttachWidget(QWidget* w)
{
    //w->installEventFilter(this);        // 接管w的事件，以便处理触摸事件

    if (sys::isImx508())                // if $PLATFORM == imx508
    {
        if (w->isVisible())
        {
            // 把touch_listener挂到QWidget上实际上就是把touch_listener使能，以便
            // 触发OnTouch事件。
            // 推测实际上touch_listener是从QIODevice接收事件，而非QWidget。
            touch_listener.addWatcherWidget(w);
        }
    }
    attached_widget = w;
}

void TGraffitiHUI::DeAttachWidget(QWidget * w)
{
    //w->removeEventFilter(this);
    if (sys::isImx508())
    {
        touch_listener.removeWatcherWidget(w);
    }
    attached_widget = 0;
}

void TGraffitiHUI::OnTouch(TouchData & data)
{
    if (attached_widget == 0)
    {
        // qDebug("Not attached to any widget");
        return;
    }

    MWO_DEBUG(data.points[0].x);
    MWO_DEBUG(data.points[0].y);
    MWO_DEBUG(data.points[0].width);        // always 1
    MWO_DEBUG(data.points[0].height);       // always 1
    MWO_DEBUG(data.points[0].pressure);     // will be 1 or 2 if touched. 1 in most cases.
    MWO_DEBUG(data.points[0].buttons);

    // data.points[1] is not used. should be used for multi-touching.
    //MWO_DEBUG(data.points[1].x);
    //MWO_DEBUG(data.points[1].y);
    //MWO_DEBUG(data.points[1].width);
    //MWO_DEBUG(data.points[1].height);
    //MWO_DEBUG(data.points[1].pressure);
    //MWO_DEBUG(data.points[1].buttons);

    // STEP1: 判断按键位置和信息是否可由当前QWidget处理
    // STEP2: 组装一个QEvent鼠标事件
}

}


