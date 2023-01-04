#ifndef T100IDEPLATENBASE_H
#define T100IDEPLATENBASE_H

#include "T100Common.h"

namespace T100IDE{
class T100IDEView;


class T100IDEPlatenBase
{
    public:
        T100IDEPlatenBase(T100IDEView*);
        virtual ~T100IDEPlatenBase();

        virtual T100BOOL            create() = 0;

        virtual T100BOOL            show() = 0;

    protected:
        T100IDEView*                m_view          = T100NULL;

    private:

};

}

#endif // T100IDEPLATENBASE_H
