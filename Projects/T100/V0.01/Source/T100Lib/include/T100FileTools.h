#ifndef T100FILETOOLS_H
#define T100FILETOOLS_H

#include "T100Common.h"


class T100FileTools
{
    public:
        T100FileTools();
        virtual ~T100FileTools();

        static T100BOOL             load(T100WSTRING, T100WORD_VECTOR&, T100WORD);

        static T100BOOL             compare(T100WSTRING, T100WSTRING);

    protected:

    private:
};

#endif // T100FILETOOLS_H
