#ifndef T100ELEMENTMODULE_H
#define T100ELEMENTMODULE_H

#include "T100ElementBase.h"

class T100ElementModule : public T100ElementBase
{
    friend class T100ElementModuleSource;
    public:
        T100ElementModule();
        virtual ~T100ElementModule();

        T100BOOL            Draw(wxDC&);
        T100BOOL            Hit(T100INT, T100INT);
        T100BOOL            Edit(wxWindow*);

        T100BOOL            Cross(T100UINT, T100UINT, T100UINT&, T100UINT&);

        T100VOID            Resize(wxDC&);

    protected:
        T100UINT            m_width     = 0;
        T100UINT            m_height    = 0;

        T100UINT            m_nameX     = 0;
        T100UINT            m_nameY     = 0;

        T100UINT            m_tailX     = 0;
        T100UINT            m_tailY     = 0;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100ELEMENTMODULE_H
