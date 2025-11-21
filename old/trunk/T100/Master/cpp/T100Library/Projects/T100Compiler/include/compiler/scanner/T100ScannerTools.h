#ifndef T100SCANNERTOOLS_H
#define T100SCANNERTOOLS_H

#include "T100SourceScanner.h"

namespace T100LIBRARY{

class T100ScannerTools : public T100Class
{
    public:
        T100ScannerTools();
        virtual ~T100ScannerTools();

        static T100BOOL         CreateScanner(T100SourceScanner*&, T100FileScanner*&);

    protected:

    private:
};

}

#endif // T100SCANNERTOOLS_H
