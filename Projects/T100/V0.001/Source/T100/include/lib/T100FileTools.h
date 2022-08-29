#ifndef T100FILETOOLS_H
#define T100FILETOOLS_H

#include "T100Common.h"


class T100FileTools
{
    public:
        T100FileTools();
        virtual ~T100FileTools();

        static T100BOOL         compare(T100String, T100String);

        static T100BOOL         load(T100String, T100WORD_VECTOR&, T100WORD);

    protected:

    private:
};

#endif // T100FILETOOLS_H
