#ifndef T100PARSERBASE_H
#define T100PARSERBASE_H

#include "state/T100Scanner.h"

class T100ParserBase : public T100Scanner
{
    public:
        T100ParserBase();
        virtual ~T100ParserBase();

        virtual T100VOID            setSource(T100ParserBase*) = 0;
        virtual T100ParserBase*     getSource() = 0;

    protected:

    private:
};

#endif // T100PARSERBASE_H
