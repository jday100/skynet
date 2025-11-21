#ifndef T100FUNCTIONSCANNER_H
#define T100FUNCTIONSCANNER_H

#include "T100FunctionToken.h"
#include "T100SegmentScanner.h"

namespace T100LIBRARY{

class T100FunctionScanner : public T100LeafScanner
{
    public:
        T100FunctionScanner();
        virtual ~T100FunctionScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state             = T100NULL;
        T100FunctionToken*              m_token             = T100NULL;
        T100SegmentToken                m_item;

        virtual T100BOOL                Run();

    private:
        T100SegmentScanner*             m_scanner           = T100NULL;
};

}

#endif // T100FUNCTIONSCANNER_H
