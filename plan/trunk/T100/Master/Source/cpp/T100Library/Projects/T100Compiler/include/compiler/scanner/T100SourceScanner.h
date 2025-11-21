#ifndef T100SOURCESCANNER_H
#define T100SOURCESCANNER_H

#include "T100SourceToken.h"
#include "T100FunctionScanner.h"

namespace T100LIBRARY{

class T100SourceScanner : public T100LeafScanner
{
    public:
        T100SourceScanner();
        virtual ~T100SourceScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100SourceToken*                m_token         = T100NULL;
        T100FunctionToken               m_item;

        virtual T100BOOL                Run();

    private:
        T100FunctionScanner*            m_scanner       = T100NULL;
};

}

#endif // T100SOURCESCANNER_H
