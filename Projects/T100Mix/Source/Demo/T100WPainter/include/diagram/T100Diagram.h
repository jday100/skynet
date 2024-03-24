#ifndef T100DIAGRAM_H
#define T100DIAGRAM_H

#include "T100File.h"


class T100Diagram
{
    public:
        T100Diagram();
        virtual ~T100Diagram();

        T100BOOL            Load();
        T100BOOL            Save();

    protected:

    private:
};

#endif // T100DIAGRAM_H
