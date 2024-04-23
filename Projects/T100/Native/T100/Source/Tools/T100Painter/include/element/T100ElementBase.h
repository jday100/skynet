#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include <vector>
#include <wx/dc.h>
#include "T100Common.h"


#define     T100PAINTER_ELEMENT_VECTOR          std::vector<T100ElementBase*>


class T100ElementBase
{
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

        T100WORD                        getType();

        virtual T100BOOL                Draw(wxDC&) = 0;

        virtual T100VOID                SetStartingPoint(T100INT, T100INT);
        virtual T100VOID                SetTerminalPoint(T100INT, T100INT);

        virtual T100VOID                Position();

    protected:
        T100WORD                        m_type              = 0;

        T100INT                         m_starting_x        = 0;
        T100INT                         m_starting_y        = 0;

        T100INT                         m_terminal_x        = 0;
        T100INT                         m_terminal_y        = 0;

    private:
};

#endif // T100ELEMENTBASE_H
