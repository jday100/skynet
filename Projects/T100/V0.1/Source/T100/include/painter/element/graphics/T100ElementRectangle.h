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

        T100BOOL                    MouseLeftDown(T100INT, T100INT);
        T100BOOL                    MouseLeftUp(T100INT, T100INT);
        T100BOOL                    MouseMove(T100INT, T100INT);

        T100BOOL                    Update(wxListView*);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100WORD                    m_starting_x;
        T100WORD                    m_starting_y;

        T100WORD                    m_ending_x;
        T100WORD                    m_ending_y;

};

}

#endif // T100ELEMENTRECTANGLE_H
