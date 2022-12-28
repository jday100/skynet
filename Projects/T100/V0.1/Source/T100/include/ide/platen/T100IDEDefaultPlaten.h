#ifndef T100IDEDEFAULTPLATEN_H
#define T100IDEDEFAULTPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"

namespace T100IDE{

class T100IDEDefaultPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEDefaultPlaten(T100IDEView*);
        virtual ~T100IDEDefaultPlaten();

        T100BOOL            create();

    protected:
        T100VOID            destroy();

    private:

};

}

#endif // T100IDEDEFAULTPLATEN_H
