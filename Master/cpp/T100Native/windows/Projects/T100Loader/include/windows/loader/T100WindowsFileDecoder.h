#ifndef T100WINDOWSFILEDECODER_H
#define T100WINDOWSFILEDECODER_H

#include <windows.h>
#include "T100WindowsFileInfo.h"

namespace T100WINDOWS{

class T100WindowsFile;

class T100WindowsFileDecoder
{
    public:
        T100WindowsFileDecoder(T100WindowsFile*);
        virtual ~T100WindowsFileDecoder();

        virtual T100BOOL            Decode(T100WindowsFileInfo&);

    protected:
        virtual T100BOOL            Verify(IMAGE_DOS_HEADER*, T100WindowsFileInfo&);
        virtual T100BOOL            VerifyPE(IMAGE_NT_HEADERS*, T100WindowsFileInfo&);

        virtual T100BOOL            VerifyFile(T100BYTE*, T100WindowsFileInfo&);

    private:
        T100WindowsFile*            m_binaryFile        = T100NULL;
};

}

#endif // T100WINDOWSFILEDECODER_H
