#ifndef T100CHARSCANNER_H
#define T100CHARSCANNER_H

#include "compiler/scanner/T100CharToken.h"
#include "compiler/scanner/T100ByteScanner.h"
#include "compiler/classifier/T100CharClassifier.h"

namespace T100LIBRARY{

class T100CharScanner : public T100LeafScanner
{
    public:
        T100CharScanner();
        virtual ~T100CharScanner();

        T100LeafState*                  m_state         = T100NULL;
        T100CharToken*                  m_token         = T100NULL;
        T100ByteToken                   m_item;

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100VOID                SetClassifier(T100CharClassifier*);
        virtual T100CharClassifier*     GetClassifier();

        virtual T100BOOL                Read();
        virtual T100BOOL                Append();
        virtual T100BOOL                Clear();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100CharClassifier*             m_classifier    = T100NULL;

        virtual T100BOOL                Run();

    private:
        T100ByteScanner*                m_scanner       = T100NULL;
};

}

#endif // T100CHARSCANNER_H
