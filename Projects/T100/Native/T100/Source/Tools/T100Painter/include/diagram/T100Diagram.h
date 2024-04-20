#ifndef T100DIAGRAM_H
#define T100DIAGRAM_H

#include "T100BufferedFile.h"
#include "T100DiagramInfo.h"
#include "T100ElementBaseSource.h"
#include "T100DiagramTransducerTarget.h"

class T100Diagram
{
    public:
        T100Diagram();
        virtual ~T100Diagram();

        T100BOOL                            load(T100STRING, T100DiagramInfo&);
        T100BOOL                            save(T100STRING, T100DiagramInfo&);

    protected:
        T100BOOL                            loadDiagramInfo(T100DiagramInfo&, T100DiagramTransducerTarget&);
        T100BOOL                            saveDiagramInfo(T100DiagramInfo&, T100DiagramTransducerTarget&);




        T100BOOL                            loadDiagramInfo(T100BufferedFile&, T100DiagramInfo&);
        T100BOOL                            saveDiagramInfo(T100BufferedFile&, T100DiagramInfo&);

        T100BOOL                            loadElement(T100ElementBase*);
        T100BOOL                            saveElement(T100ElementBase*);

        T100ElementBaseSource*              getElementSource(T100WORD);

    private:
        T100DiagramTransducerTarget*        m_target            = T100NULL;
};

#endif // T100DIAGRAM_H
