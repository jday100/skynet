#ifndef T100CONSOLENORMAL_H
#define T100CONSOLENORMAL_H

#include "console/T100ConsoleBase.h"

namespace T100LIBRARY{

class T100ConsoleNormal : public T100ConsoleBase
{
    public:
        T100ConsoleNormal();
        virtual ~T100ConsoleNormal();

        virtual T100VOID            OutLine(const T100WSTRING&);
        virtual T100VOID            GetLine(const T100WSTRING&);

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100CONSOLENORMAL_H
