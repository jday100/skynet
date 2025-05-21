#ifndef T100PLUGIN_H
#define T100PLUGIN_H

#include "base/T100Class.h"
#include "dynamiclibrary/T100DynamicLibrary.h"

class T100Plugin : public T100Class
{
    public:
        T100Plugin(T100WSTRING);
        virtual ~T100Plugin();

        virtual T100VOID            Load();
        virtual T100VOID            Unload();

    protected:
        T100WSTRING                 m_label;

        T100DynamicLibrary*         m_library       = T100NULL;

    private:
};

#endif // T100PLUGIN_H
