#ifndef T100ELEMENTRECTANGLE_H
#define T100ELEMENTRECTANGLE_H

#include "T100ElementBase.h"

namespace T100Painter{

class T100ElementRectangle : public T100ElementBase
{
    friend class T100ElementRectangleSource;
    public:
        T100ElementRectangle();
        virtual ~T100ElementRectangle();

        T100VOID                    Clear();
        T100BOOL                    draw(wxDC&);
        T100ElementRectangle*       Clone();
        T100BOOL                    Hit(T100INT, T100INT);
        T100BOOL                    Edit();

        T100BOOL                    Update(wxPropertyGrid*);
        T100BOOL                    Move();
        T100VOID                    Position();

        T100BOOL                    SetPaintStarting(T100INT, T100INT);

        T100BOOL                    PaintMove(T100INT, T100INT);
        T100BOOL                    SelectedMove(T100INT, T100INT);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:

};

}

#endif // T100ELEMENTRECTANGLE_H
