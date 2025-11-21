#ifndef T100PROJECTLOGIC_H
#define T100PROJECTLOGIC_H

#include "T100Common.h"

class T100PluginProject;

class T100ProjectLogic
{
    public:
        T100ProjectLogic(T100PluginProject*);
        virtual ~T100ProjectLogic();

        virtual T100VOID            Create();

    protected:
        T100PluginProject*          m_plugin        = T100NULL;

    private:
};

#endif // T100PROJECTLOGIC_H
