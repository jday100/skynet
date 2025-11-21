#ifndef T100CONSOLELOG_H
#define T100CONSOLELOG_H

#include "T100ConsoleBase.h"

namespace T100NATIVE{

class T100ConsoleLog : public T100ConsoleBase
{
    public:
        T100ConsoleLog();
        virtual ~T100ConsoleLog();

        T100VOID            Print(T100WSTRING&);

        T100VOID            Outline(T100WSTRING&);
        T100VOID            Getline(T100WSTRING&);

    protected:

    private:
};

}

#endif // T100CONSOLELOG_H
