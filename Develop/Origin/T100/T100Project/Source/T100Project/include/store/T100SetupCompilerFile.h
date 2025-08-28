#ifndef T100SETUPCOMPILERFILE_H
#define T100SETUPCOMPILERFILE_H

#include "T100XML.h"

class T100SetupCompilerInfo;

class T100SetupCompilerFile : public T100XML
{
    public:
        T100SetupCompilerFile(const T100WSTRING&);
        virtual ~T100SetupCompilerFile();

        T100BOOL                IsExists();

        T100BOOL                Load(T100SetupCompilerInfo*);
        T100BOOL                Save(T100SetupCompilerInfo*);

    protected:
        T100WSTRING             m_filename;

    private:
};

#endif // T100SETUPCOMPILERFILE_H
