#ifndef T100THISAPPMANAGER_H
#define T100THISAPPMANAGER_H

#include "T100WxAppManager.h"


class T100ThisAppManager : public T100WxWidgets::T100WxAppManager
{
    public:
        T100ThisAppManager();
        virtual ~T100ThisAppManager();

        T100BOOL            start();

        T100BOOL            stop();

    protected:

    private:
};

#endif // T100THISAPPMANAGER_H
