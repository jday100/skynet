#ifndef T100STRING32TOOLS_H
#define T100STRING32TOOLS_H

#include "T100Common.h"
#include "T100String.h"


class T100String32Tools
{
    public:
        T100String32Tools();
        virtual ~T100String32Tools();

        static T100String32         to_string(T100WORD*, T100WORD);

        static T100BOOL             copy(T100WORD*, T100WORD*, T100WORD);

        static T100BOOL             split(T100String, T100String, T100STRING_VECTOR&);

        static T100BOOL             compare(T100WORD*, T100WORD, T100String&);

    protected:

    private:
};

#endif // T100STRING32TOOLS_H
