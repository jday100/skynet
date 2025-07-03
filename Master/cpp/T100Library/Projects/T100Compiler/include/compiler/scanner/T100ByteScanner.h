#ifndef T100BYTESCANNER_H
#define T100BYTESCANNER_H

#include "compiler/scanner/T100ByteToken.h"
#include "compiler/scanner/T100BufferScanner.h"
#include "compiler/classifier/T100ByteClassifier.h"

namespace T100LIBRARY{

class T100ByteScanner : public T100LeafScanner
{
    public:
        T100ByteScanner();
        virtual ~T100ByteScanner();

        T100LeafState*                  m_state         = T100NULL;
        T100ByteToken*                  m_token         = T100NULL;
        T100BufferToken                 m_item;

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100VOID                SetClassifier(T100ByteClassifier*);
        virtual T100ByteClassifier*     GetClassifier();

        virtual T100BOOL                Read();
        virtual T100BOOL                Append();
        virtual T100BOOL                Clear();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100ByteClassifier*             m_classifier    = T100NULL;

        virtual T100BOOL                Run();

    private:
        T100BufferScanner*              m_scanner       = T100NULL;

};

}

#endif // T100BYTESCANNER_H
