#ifndef T100CXSCANNERTOOLS_H
#define T100CXSCANNERTOOLS_H

#include "compiler/scanner/T100SourceScanner.h"

using namespace T100LIBRARY;

class T100CXScannerTools : public T100Class
{
    public:
        T100CXScannerTools();
        virtual ~T100CXScannerTools();

        static T100BOOL             CreateScanner(T100SourceScanner*&, T100FileScanner*&);

    protected:

    private:
};

#endif // T100CXSCANNERTOOLS_H
