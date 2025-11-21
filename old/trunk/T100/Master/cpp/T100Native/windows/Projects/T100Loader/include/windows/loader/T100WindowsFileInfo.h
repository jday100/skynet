#ifndef T100WINDOWSFILEINFO_H
#define T100WINDOWSFILEINFO_H

#include <windows.h>
#include "T100Common.h"
#include "windows/common/T100FileCommon.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100WindowsFileInfo
{
    public:
        T100WindowsFileInfo();
        virtual ~T100WindowsFileInfo();

        IMAGE_DOS_HEADER            DosHeader;
        IMAGE_NT_HEADERS            NTHeader;
        IMAGE_OPTIONAL_HEADER64     OptionalHeader64;

        T100FILE_TYPE               Type;
        T100FILE_TYPE2              Type2;

    protected:

    private:
};

}

#endif // T100WINDOWSFILEINFO_H
