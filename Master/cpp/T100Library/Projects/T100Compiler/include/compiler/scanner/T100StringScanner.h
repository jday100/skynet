#ifndef T100STRINGSCANNER_H
#define T100STRINGSCANNER_H

#include "T100StringToken.h"
#include "T100CharScanner.h"

namespace T100LIBRARY{

class T100StringScanner : public T100LeafScanner
{
    public:
        T100StringScanner();
        virtual ~T100StringScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100StringToken*                m_token         = T100NULL;
        T100CharToken                   m_item;

        virtual T100BOOL                Run();

    private:
        T100CharScanner*                m_scanner       = T100NULL;
};

}

#endif // T100STRINGSCANNER_H
