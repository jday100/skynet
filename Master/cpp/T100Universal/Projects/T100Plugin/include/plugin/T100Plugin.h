#ifndef T100PLUGIN_H
#define T100PLUGIN_H

#include "dynamiclibrary/T100DynamicLibrary.h"

using namespace T100WINDOWS;

namespace T100UNIVERSAL{

class T100Plugin : public T100Class
{
    public:
        T100Plugin(const T100WSTRING&);
        virtual ~T100Plugin();

        virtual T100VOID            Load();
        virtual T100VOID            Unload();

        T100VOID*                   GetMethod(const T100WSTRING&);

    protected:
        T100DynamicLibrary          m_library;

    private:
};

}

#endif // T100PLUGIN_H
