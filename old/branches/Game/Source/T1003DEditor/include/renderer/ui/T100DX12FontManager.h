#ifndef T100DX12FONTMANAGER_H
#define T100DX12FONTMANAGER_H

#include "T100DX12Font.h"

struct T100DX12FontHeader{
    T100CHAR            FileDescriptor[8];          // "SDFFONT\0"
    T100UINT8           MajorVersion;               // '1'
    T100UINT8           MinorVersion;               // '0'
    T100UINT16          BorderSize;
    T100UINT16          TextureWidth;
    T100UINT16          TextureHeight;
    T100UINT16          FontHeight;
    T100UINT16          AdvanceY;
    T100UINT16          NumGlyphs;
    T100UINT16          SearchDist;
};

class T100DX12FontManager
{
    public:
        T100DX12FontManager();
        virtual ~T100DX12FontManager();

        T100DX12Font*           GetFont(T100WSTRING);

    protected:
        T100VOID                LoadFromBinary(T100UCHAR*, T100UINT);

    private:
};

#endif // T100DX12FONTMANAGER_H
