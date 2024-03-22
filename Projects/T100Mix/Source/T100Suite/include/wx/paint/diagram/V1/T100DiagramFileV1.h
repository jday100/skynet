#ifndef T100DIAGRAMFILEV1_H
#define T100DIAGRAMFILEV1_H

#include "fs\file\T100FileBufferedReader.h"
#include "fs\file\T100FileBufferedWriter.h"

#include "T100DiagramInfoV1.h"

class T100DiagramFileV1
{
    public:
        T100DiagramFileV1();
        virtual ~T100DiagramFileV1();

        T100BOOL            Load(T100FileBufferedReader*, T100DiagramInfoV1*);

        T100BOOL            Save(T100FileBufferedWriter*, T100DiagramInfoV1*);

    protected:

    private:
};

#endif // T100DIAGRAMFILEV1_H
