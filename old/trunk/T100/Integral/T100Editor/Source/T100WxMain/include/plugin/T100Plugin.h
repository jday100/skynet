#ifndef T100PLUGIN_H
#define T100PLUGIN_H

#include "T100Common.h"

class T100Plugin;

typedef     T100VOID(*T100PLUGIN_SIGNIN)(T100VOID*);

typedef     T100Plugin*(*T100PLUGIN_LAUNCH)(T100VOID);

class T100Plugin
{
    public:
        T100Plugin();
        virtual ~T100Plugin();

        virtual T100BOOL            Create(T100VOID*) = 0;

    protected:

    private:
};

#endif // T100PLUGIN_H
