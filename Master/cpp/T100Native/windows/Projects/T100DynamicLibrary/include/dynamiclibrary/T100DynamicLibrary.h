#ifndef T100DYNAMICLIBRARY_H
#define T100DYNAMICLIBRARY_H

#include "base/T100Class.h"
#include <libloaderapi.h>

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100DynamicLibrary : public T100Class
{
    public:
        T100DynamicLibrary(const T100WSTRING&);
        virtual ~T100DynamicLibrary();

        virtual T100VOID            Load();
        virtual T100VOID            Unload();

        T100VOID*                   GetMethod(const T100WSTRING&);

    protected:
        T100WSTRING                 m_filename;
        HMODULE                     m_module;

    private:
};

}

#endif // T100DYNAMICLIBRARY_H
