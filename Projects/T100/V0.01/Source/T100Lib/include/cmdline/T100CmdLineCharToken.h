#ifndef T100CMDLINECHARTOKEN_H
#define T100CMDLINECHARTOKEN_H

#include "T100Token.h"


class T100CmdLineCharToken : public T100Token
{
    public:
        T100CmdLineCharToken();
        virtual ~T100CmdLineCharToken();

        T100WCHAR           value;

        T100WSTRING         exec;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100CMDLINECHARTOKEN_H
