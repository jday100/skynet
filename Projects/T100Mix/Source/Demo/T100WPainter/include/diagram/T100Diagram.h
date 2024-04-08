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
        T100BOOL                            loadInfo();
        T100BOOL                            saveInfo(T100BufferedFile&, T100DiagramInfo&);

        T100BOOL                            saveElement(T100ElementBase*);

        T100ElementBaseSource*              getElementSource(T100ElementBase*);

    private:
        T100DiagramTransducerTarget*        m_target            = T100NULL;
};

#endif // T100DIAGRAM_H
