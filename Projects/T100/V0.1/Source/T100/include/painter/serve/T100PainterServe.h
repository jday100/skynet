#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include "T100String.h"
#include "T100PainterCommon.h"

namespace T100Painter{

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100BOOL            NewFile(T100STRING&, T100PAINTER_ELEMENT_VECTOR*&);
        T100BOOL            OpenFile(T100STRING, T100PAINTER_ELEMENT_VECTOR*&);
        T100BOOL            SaveFile();
        T100BOOL            SaveAsFile();
        T100BOOL            CloseFile();

        T100PAINTER_ELEMENT_VECTOR*     GetElements();

    public:
        T100BOOL            SaveFile(T100STRING);
        T100BOOL            LoadFile(T100STRING);

        T100BOOL            IsModified();
        T100VOID            DiscardEdits();


    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100PAINTER_ELEMENT_VECTOR      m_elements;

};

}

#endif // T100PAINTERSERVE_H
