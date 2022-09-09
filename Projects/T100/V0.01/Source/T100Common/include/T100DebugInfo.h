#ifndef T100DEBUGINFO_H
#define T100DEBUGINFO_H

#include "T100String.h"
#include "T100File.h"

typedef struct{
    T100DWORD           BUILD_TIME;
}T100BUILD_INFO;


typedef struct{
    T100FILE_HEAD       HEAD;
    T100String          NAME;
    T100BUILD_INFO      BUILD;
}T100SYMBOL_FILE_HEAD;


typedef struct{
    T100String          NAME;
    T100WORD            OFFSET;
    T100WORD            TYPE;
    T100String          INITIAL;
}T100SYMBOL_VARIABLE_INFO;

typedef struct{
    T100String          NAME;
    T100WORD            OFFSET;
}T100SYMBOL_LABEL_INFO;

typedef struct{
    T100String          NAME;
    T100WORD            OFFSET;
    T100WORD            LENGTH;
}T100SYMBOL_PROCEDURE_INFO;

typedef struct{
    T100String          NAME;
    T100WORD            OFFSET;
    T100WORD            TYPE;
    T100WORD            LOCATION;
    T100WORD            LENGTH;
    T100WORD            LIMIT;
}T100SYMBOL_SEGMENT_INFO;


class T100DebugInfo
{
    public:
        T100DebugInfo();
        virtual ~T100DebugInfo();

    protected:

    private:
};

#endif // T100DEBUGINFO_H
