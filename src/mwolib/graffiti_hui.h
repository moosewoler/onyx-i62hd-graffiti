#ifndef _GRAFFITI_HUI_H_
#define _GRAFFITI_HUI_H_

#include "onyx/touch/touch_listener.h"

namespace graffiti
{
    class TGraffitiHUI : public QObject
    {
        Q_OBJECT
        public:
            TGraffitiHUI();
            ~TGraffitiHUI();

        public:
            // 如果不挂到QWidget上，touch_listener就处在未使能状态，OnTouch事件就
            // 无法被触发
            void AttachWidget(QWidget* w);
            void DeAttachWidget(QWidget* w);

        private Q_SLOTS:
            void OnTouch(TouchData & data);

        private:
            TouchEventListener touch_listener;
            QWidget*           attached_widget;
    };

};

#endif
