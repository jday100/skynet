#ifndef T100DYNAMICLIBRARY_H
#define T100DYNAMICLIBRARY_H

#include "T100Common.h"
#include <libloaderapi.h>

class T100DynamicLibrary
{
    public:
        T100DynamicLibrary(T100WSTRING);
        virtual ~T100DynamicLibrary();

        T100BOOL            Exists();

        T100VOID            Load();
        T100VOID            Unload();

        T100VOID*           Get(T100WSTRING);

    protected:
        T100WSTRING         m_fileName;
        T100WSTRING         m_path;

    private:
        HMODULE             m_module;
};

#endif // T100DYNAMICLIBRARY_H
