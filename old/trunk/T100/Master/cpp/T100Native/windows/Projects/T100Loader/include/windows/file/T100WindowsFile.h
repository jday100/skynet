#ifndef T100WINDOWSFILE_H
#define T100WINDOWSFILE_H

#include <windows.h>
#include "storage/file/binary/T100BinaryFile.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100WindowsFile : public T100BinaryFile
{
    public:
        T100WindowsFile(const T100WSTRING&);
        virtual ~T100WindowsFile();

        virtual T100BOOL            Load();

    protected:

    private:
        T100VOID                    PrintDosHeader(IMAGE_DOS_HEADER*);
        T100VOID                    PrintOptionalHeader(IMAGE_OPTIONAL_HEADER64*);
};

}

#endif // T100WINDOWSFILE_H
