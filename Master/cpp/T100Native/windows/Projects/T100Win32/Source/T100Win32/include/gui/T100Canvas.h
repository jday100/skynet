#ifndef T100CANVAS_H
#define T100CANVAS_H

#include "gui/T100Panel.h"
#include "gui/T100CanvasStyle.h"

namespace T100WINDOWS{

class T100Canvas : public T100Panel
{
    public:
        T100Canvas();
        T100Canvas(T100Window*);
        virtual ~T100Canvas();

        virtual T100VOID            Create(T100Window*, T100CanvasStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:

    private:
        T100VOID                    init(T100Window*, T100CanvasStyle*);
        T100VOID                    uninit();
};

}

#endif // T100CANVAS_H
