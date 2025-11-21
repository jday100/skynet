#ifndef T100FILESCANNER_H
#define T100FILESCANNER_H

#include "compiler/scanner/T100FileToken.h"
#include "compiler/base/T100LeafScanner.h"
#include "storage/file/binary/T100BinaryFile.h"

namespace T100LIBRARY{

class T100FileScanner : public T100LeafScanner
{
    public:
        T100FileScanner();
        virtual ~T100FileScanner();

        virtual T100VOID                    SetFile(const T100WSTRING&);
        virtual const T100WSTRING&          GetFile();

        virtual T100BOOL                    Open();
        virtual T100BOOL                    Close();

        virtual T100BOOL                    Read();
        virtual T100BOOL                    Clear();

        virtual T100BOOL                    Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                      m_state         = T100NULL;
        T100FileToken*                      m_token         = T100NULL;

        virtual T100BOOL                    Run();

    private:
        T100WSTRING                         m_filename;
        T100BinaryFile*                     m_file          = T100NULL;
        T100BinaryFileReader*               m_reader        = T100NULL;
};

}

#endif // T100FILESCANNER_H
