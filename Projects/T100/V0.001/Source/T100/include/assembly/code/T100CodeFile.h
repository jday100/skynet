#ifndef T100CODEFILE_H
#define T100CODEFILE_H

#include <fstream>
#include "T100AsmCommon.h"
#include "T100CodeNew.h"
#include "T100FileData.h"


class T100CodeFile
{
    public:
        T100CodeFile();
        virtual ~T100CodeFile();

        virtual T100BOOL        load(T100FileData*)=0;
        virtual T100BOOL        save(T100STDSTRING)=0;

    protected:
        T100BOOL                count(T100SEGMENTDATA_VECTOR&, T100WORD&, T100WORD&);
        T100BOOL                count(T100SEGMENTDATA_VECTOR&, T100WORD&, T100WORD&, T100WORD&);

    private:
};

#endif // T100CODEFILE_H
