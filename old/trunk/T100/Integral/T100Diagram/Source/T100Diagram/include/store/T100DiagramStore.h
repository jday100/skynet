#ifndef T100DIAGRAMSTORE_H
#define T100DIAGRAMSTORE_H

#include "T100DiagramInfo.h"

class T100DiagramStore
{
    public:
        T100DiagramStore();
        virtual ~T100DiagramStore();

        T100BOOL            Load(T100WSTRING&, T100DiagramInfo*&);
        T100BOOL            Save(T100WSTRING&, T100DiagramInfo*);

    protected:

    private:
};

#endif // T100DIAGRAMSTORE_H
