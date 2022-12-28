#ifndef T100CAPACITYCHARSCANNER_H
#define T100CAPACITYCHARSCANNER_H

#include "T100Scanner.h"
#include "T100CapacityCharToken.h"

namespace T100Library{

class T100CapacityCharScanner : public T100Component::T100Scanner
{
    public:
        T100CapacityCharScanner();
        virtual ~T100CapacityCharScanner();

        T100VOID                        setSource(T100WSTRING);

        T100BOOL                        next(T100Component::T100Token&);

    protected:

    private:
        T100INT                         m_index         = 0;
        T100WSTRING                     m_string;

};

}

#endif // T100CAPACITYCHARSCANNER_H
