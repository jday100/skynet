#ifndef T100OSSETUP_H
#define T100OSSETUP_H

#include "T100AppSetup.h"


class T100OSSetup : public T100AppSetup
{
    public:
        T100OSSetup();
        virtual ~T100OSSetup();

        static T100String           getTestOS(T100WSTRING);

    protected:

    private:
        static T100String           m_os_path;

};

#endif // T100OSSETUP_H
