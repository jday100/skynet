#ifndef T100BUFFERSCANNER_H
#define T100BUFFERSCANNER_H

#include "T100BufferToken.h"
#include "T100FileScanner.h"

namespace T100LIBRARY{

class T100BufferScanner : public T100LeafScanner
{
    public:
        T100BufferScanner();
        virtual ~T100BufferScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Read();
        virtual T100BOOL                Append();
        virtual T100BOOL                Clear();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100BufferToken*                m_token         = T100NULL;
        T100FileToken                   m_item;

        virtual T100BOOL                Run();

    private:
        T100INT                         m_index         = -1;
        T100UINT                        m_length        = 1024;
        T100FileScanner*                m_scanner       = T100NULL;

        T100VOID                        init();
        T100VOID                        uninit();
};

}

#endif // T100BUFFERSCANNER_H
