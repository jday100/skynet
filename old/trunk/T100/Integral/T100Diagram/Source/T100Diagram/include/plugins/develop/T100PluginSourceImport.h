#ifndef T100PLUGINSOURCEIMPORT_H
#define T100PLUGINSOURCEIMPORT_H

#include "T100SourceImportInfo.h"
#include "T100SourceImportFileInfo.h"

class T100PluginSourceImport
{
    public:
        T100PluginSourceImport();
        virtual ~T100PluginSourceImport();

        T100SOURCE_IMPORT_FILE_INFO_VECTOR&         GetFiles();

        T100BOOL            Run(T100SourceImportInfo*);

    protected:
        T100BOOL            ScanFolder(T100SourceImportInfo*, T100WSTRING&);
        T100BOOL            Append(T100WSTRING&);

    private:
        T100SOURCE_IMPORT_FILE_INFO_VECTOR          m_files;
        T100SOURCE_IMPORT_FILE_INFO_HASH            m_search;
};

#endif // T100PLUGINSOURCEIMPORT_H
