#ifndef T100SOURCEIMPORTFILEINFO_H
#define T100SOURCEIMPORTFILEINFO_H

#include <vector>
#include <unordered_map>
#include "T100Common.h"

#define     T100SOURCE_IMPORT_FILE_INFO_VECTOR                  std::vector<T100SourceImportFileInfo*>
#define     T100SOURCE_IMPORT_FILE_INFO_HASH                    std::unordered_map<T100WSTRING, T100SourceImportFileInfo*>

class T100SourceImportFileInfo
{
    public:
        T100SourceImportFileInfo();
        virtual ~T100SourceImportFileInfo();

        T100WSTRING             FileName;
        T100WSTRING             Parent;
        T100WSTRING             Folder;
        T100WSTRING             Path;

    protected:

    private:
};

#endif // T100SOURCEIMPORTFILEINFO_H
