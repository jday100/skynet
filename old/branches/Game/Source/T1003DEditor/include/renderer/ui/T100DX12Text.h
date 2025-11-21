#ifndef T100DX12TEXT_H
#define T100DX12TEXT_H

#include "T100DX12Header.h"
#include "T100DX12Font.h"

class T100DX12Text
{
    public:
        T100DX12Text();
        virtual ~T100DX12Text();

        T100VOID                SetFont(T100DX12Font*);
        T100DX12Font*           GetFont();

        T100VOID                SetSize(T100FLOAT);
        T100FLOAT               GetSize();

    protected:
        T100DX12Font*           m_font          = T100NULL;
        T100FLOAT               m_size          = 0.0f;

    private:
};

#endif // T100DX12TEXT_H
