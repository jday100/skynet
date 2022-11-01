#ifndef T100IDE_H
#define T100IDE_H

#include "T100WxApp.h"

namespace T100IDE{

class T100IDE : public T100WxWidgets::T100WxApp
{
    public:
        T100IDE(T100WxWidgets::T100WxAppManager*);
        virtual ~T100IDE();

    protected:

    private:
};

}

#endif // T100IDE_H
