#ifndef T100THISAPPSETUP_H
#define T100THISAPPSETUP_H

#include "T100String.h"
#include "T100AppSetup.h"


class T100ThisAppSetup : public T100Library::T100AppSetup
{
    public:
        T100ThisAppSetup();
        virtual ~T100ThisAppSetup();

        static T100STRING           getTestResources(T100STRING);

    protected:

    private:
        static T100STRING           m_resources;
        static T100STRING           m_build;
        static T100STRING           m_stores;
        static T100STRING           m_work;

};

#endif // T100THISAPPSETUP_H
