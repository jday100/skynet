#ifndef T100DIAGRAMDRAWER_H
#define T100DIAGRAMDRAWER_H

#include "string\T100String32.h"
#include "fs\file\T100FileBufferedReader.h"
#include "fs\file\T100FileBufferedWriter.h"
#include "wx\paint\data\T100DiagramInfo.h"

class T100DiagramDrawer
{
    public:
        T100DiagramDrawer();
        virtual ~T100DiagramDrawer();

        T100BOOL            Load(T100String32, T100DiagramInfo*&);

        T100BOOL            Save(T100String32, T100DiagramInfo*);

    protected:

    private:
};

#endif // T100DIAGRAMDRAWER_H
