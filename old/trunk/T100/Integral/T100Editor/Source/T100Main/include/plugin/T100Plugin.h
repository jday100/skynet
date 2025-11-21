#ifndef T100PLUGIN_H
#define T100PLUGIN_H

#include "T100Common.h"


typedef     T100VOID(*T100PLUGIN_SIGNIN)(T100VOID*);

class T100Plugin
{
    public:
        T100Plugin();
        virtual ~T100Plugin();

    protected:

    private:
};

#endif // T100PLUGIN_H
