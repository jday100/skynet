#ifndef T100DIAGRAM_H
#define T100DIAGRAM_H

#include "T100BufferedFile.h"
#include "T100DiagramInfo.h"

class T100Diagram
{
    public:
        T100Diagram();
        virtual ~T100Diagram();

        T100BOOL            load(T100STRING, T100DiagramInfo&);
        T100BOOL            save(T100STRING, T100DiagramInfo&);

    protected:
        T100BOOL            loadInfo();
        T100BOOL            saveInfo(T100BufferedFile&, T100DiagramInfo&);
    private:
};

#endif // T100DIAGRAM_H
