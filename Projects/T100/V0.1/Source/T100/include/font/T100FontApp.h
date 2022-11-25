#ifndef T100FONTAPP_H
#define T100FONTAPP_H

#include "T100WxApp.h"
class T100ThisAppManager;

namespace T100FontBuilder{
class T100FontBuilder;


class T100FontApp : public T100WxWidgets::T100WxApp
{
    public:
        T100FontApp(T100ThisAppManager*);
        virtual ~T100FontApp();

        T100VOID                show();

        T100FontBuilder*        getFontBuilder();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100FontBuilder*        m_builder           = T100NULL;

};

}

#endif // T100FONTAPP_H
