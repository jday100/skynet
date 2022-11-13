#ifndef T100CLASSPATHDRAWER_H
#define T100CLASSPATHDRAWER_H

#include "T100Common.h"
#include "T100String.h"

namespace T100Assembly{

class T100ClassPathDrawer
{
    public:
        T100ClassPathDrawer();
        virtual ~T100ClassPathDrawer();

        T100VOID                setRoot(T100STRING);
        T100STRING              getRoot();

        T100BOOL                append(T100STRING&);

        T100BOOL                find(T100STRING, T100STRING&);

        T100BOOL                clear();

    protected:

    private:
        T100STRING              m_root;
        T100STRING_VECTOR       m_paths;

};

}

#endif // T100CLASSPATHDRAWER_H
