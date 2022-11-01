#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100WxApp.h"

namespace T100Editor{

class T100Editor : public T100WxWidgets::T100WxApp
{
    public:
        T100Editor(T100WxWidgets::T100WxAppManager*);
        virtual ~T100Editor();

    protected:

    private:
};

}

#endif // T100EDITOR_H
