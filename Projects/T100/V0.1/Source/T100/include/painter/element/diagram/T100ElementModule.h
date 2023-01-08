#ifndef T100ELEMENTMODULE_H
#define T100ELEMENTMODULE_H

#include "T100ElementBase.h"

namespace T100Painter{

class T100ElementModule : public T100ElementBase
{
    friend class T100ElementModuleSource;
    public:
        T100ElementModule();
        virtual ~T100ElementModule();

        T100VOID                Clear();
        T100BOOL                draw(wxDC&);
        T100ElementModule*      Clone();
        T100BOOL                Hit(T100INT, T100INT);

        T100BOOL                MouseLeftDown(T100INT, T100INT);
        T100BOOL                MouseLeftUp(T100INT, T100INT);
        T100BOOL                MouseMove(T100INT, T100INT);

        T100BOOL                Update(wxPropertyGrid*);
        T100BOOL                Update(wxPropertyGridEvent&);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WORD                m_starting_x;
        T100WORD                m_starting_y;

        T100WORD                m_ending_x;
        T100WORD                m_ending_y;

};

}

#endif // T100ELEMENTMODULE_H
