#ifndef T100LIBRARY_H
#define T100LIBRARY_H

#include <unordered_map>
#include <minwindef.h>
#include "library\storage\file\T100File.h"

#define     T100LIBRARY_HASH                        std::unordered_map<T100WSTRING, T100Library*>

class T100Library : public T100File
{
    public:
        T100Library(T100WSTRING);
        virtual ~T100Library();


        T100BOOL            Load();

        FARPROC             GetProcedure(T100STRING);

    protected:
        HMODULE             m_module;

    private:
};

#endif // T100LIBRARY_H
