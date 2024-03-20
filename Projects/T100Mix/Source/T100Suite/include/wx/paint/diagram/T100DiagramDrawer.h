#ifndef T100DIAGRAMDRAWER_H
#define T100DIAGRAMDRAWER_H

#include "fs\file\T100FileBufferedReader.h"
#include "fs\file\T100FileBufferedWriter.h"
#include "T100PaintElementBase.h"

class T100DiagramDrawer
{
    public:
        T100DiagramDrawer();
        virtual ~T100DiagramDrawer();

        T100BOOL            Load(T100FileBufferedReader*, T100PAINTER_ELEMENT_VECTOR*);

        T100BOOL            Save(T100FileBufferedWriter*, T100PAINTER_ELEMENT_VECTOR*);

    protected:

    private:
};

#endif // T100DIAGRAMDRAWER_H
