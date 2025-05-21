#ifndef T100PROJECTAPPLICATION_H
#define T100PROJECTAPPLICATION_H

#include "plugin/T100PluginApplication.h"

class T100ProjectApplication : public T100PluginApplication
{
    public:
        T100ProjectApplication();
        virtual ~T100ProjectApplication();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:

    private:
};

#endif // T100PROJECTAPPLICATION_H
