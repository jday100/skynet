#ifndef T100CAPACITYSCANNER_H
#define T100CAPACITYSCANNER_H

#include "T100CapacityToken.h"
#include "T100CapacityCharScanner.h"

namespace T100Library{

class T100CapacityScanner : public T100Component::T100Scanner
{
    public:
        T100CapacityScanner();
        virtual ~T100CapacityScanner();

        T100VOID                        setSource(T100CapacityCharScanner*);
        T100CapacityCharScanner*        getSource();

        T100BOOL                        next(T100Component::T100Token&);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

        T100CapacityToken*              m_token         = T100NULL;
        T100CapacityCharToken           m_item;

    private:
        T100CapacityCharScanner*        m_scanner       = T100NULL;

};

}

#endif // T100CAPACITYSCANNER_H
