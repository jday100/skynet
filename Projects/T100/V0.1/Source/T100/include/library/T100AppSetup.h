#ifndef T100APPSETUP_H
#define T100APPSETUP_H

#include "T100Setup.h"

namespace T100Library{

class T100AppSetup : public T100Setup
{
    public:
        T100AppSetup();
        virtual ~T100AppSetup();

        static T100WSTRING          getLog(T100WSTRING);

    protected:

    private:
        static T100WSTRING          m_log;
};

}

#endif // T100APPSETUP_H
