#ifndef T100CLASSPATHDRAWER_H
#define T100CLASSPATHDRAWER_H

#include "T100Common.h"
#include "T100String.h"


class T100ClassPathDrawer
{
    public:
        T100ClassPathDrawer();
        virtual ~T100ClassPathDrawer();

        T100VOID                setRoot(T100String);
        T100String              getRoot();

        T100BOOL                append(T100String&);

        T100BOOL                find(T100String, T100String&);

        T100BOOL                clear();

    protected:

    private:
        T100String              m_root;
        T100STRING_VECTOR       m_paths;

};

#endif // T100CLASSPATHDRAWER_H
