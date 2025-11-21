#ifndef T100DIAGRAM_H
#define T100DIAGRAM_H

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100DiagramInfo.h"
#include "T100DiagramBase.h"

class T100DiagramSourceBase;

class T100Diagram
{
    public:
        T100Diagram();
        virtual ~T100Diagram();

        T100BOOL            Load(T100BufferedFileReader*, T100DiagramInfo*&);

        T100BOOL            Save(T100BufferedFileWriter*, T100DiagramInfo*);

    protected:
        T100DiagramSourceBase*          GetDiagramSource(T100UINT, T100UINT);

    private:
};

#endif // T100DIAGRAM_H
