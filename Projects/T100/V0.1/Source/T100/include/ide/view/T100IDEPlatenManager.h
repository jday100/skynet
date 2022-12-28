#ifndef T100IDEPLATENMANAGER_H
#define T100IDEPLATENMANAGER_H

#include "T100IDEView.h"

namespace T100IDE{
class T100IDEPlatenBase;


class T100IDEPlatenManager
{
    public:
        T100IDEPlatenManager(T100IDEView*);
        virtual ~T100IDEPlatenManager();

        T100IDEPlatenBase*          getDefault();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100IDEView*                m_view          = T100NULL;
        T100IDEPlatenBase*          m_current       = T100NULL;

};

}

#endif // T100IDEPLATENMANAGER_H
