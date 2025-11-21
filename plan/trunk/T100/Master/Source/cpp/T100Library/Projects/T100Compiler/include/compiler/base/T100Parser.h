#ifndef T100PARSER_H
#define T100PARSER_H

#include "compiler/data/T100FrontInfo.h"
#include "compiler/scanner/T100SourceScanner.h"

namespace T100LIBRARY{

class T100Parser : public T100Class
{
    public:
        T100Parser();
        virtual ~T100Parser();

        T100LeafState*                  m_state             = T100NULL;
        T100SourceToken*                m_token             = T100NULL;

        virtual T100VOID                SetSourceScanner(T100SourceScanner*);
        virtual T100SourceScanner*      GetSourceScanner();

        virtual T100VOID                SetFileScanner(T100FileScanner*);
        virtual T100FileScanner*        GetFileScanner();

        virtual T100BOOL                Parse(const T100WSTRING&, T100FrontInfo&);

    protected:
        T100SourceScanner*              m_sourceScanner     = T100NULL;
        T100FileScanner*                m_fileScanner       = T100NULL;

    private:
};

}

#endif // T100PARSER_H
