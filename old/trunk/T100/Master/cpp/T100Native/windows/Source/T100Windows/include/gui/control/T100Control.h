#ifndef T100CONTROL_H
#define T100CONTROL_H

#include "gui/T100Window.h"

namespace T100WINDOWS{

class T100Control : public T100Window
{
    public:
        T100Control();
        T100Control(T100Window*);
        virtual ~T100Control();

        virtual T100VOID            Create(T100Window*, T100WindowStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:
        T100UINT                    m_id        = 0;

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100CONTROL_H
