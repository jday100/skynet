#ifndef T100PAINTERTRANSVERTER_H
#define T100PAINTERTRANSVERTER_H

#include "T100StateTransverter.h"

namespace T100Component{

class T100PainterTransverter : public T100StateTransverter
{
    public:
        T100PainterTransverter();
        virtual ~T100PainterTransverter();

        T100BOOL            Change(T100State*);

    protected:

    private:
};

}

#endif // T100PAINTERTRANSVERTER_H
