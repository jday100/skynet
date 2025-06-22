#ifndef T100TEXTCTRL_H
#define T100TEXTCTRL_H

#include <atomic>
#include "gui/T100Font.h"
#include "gui/T100TextCtrlStyle.h"
#include "gui/control/T100Control.h"

namespace T100WINDOWS{

class T100TextCtrl : public T100Control
{
    public:
        T100TextCtrl();
        T100TextCtrl(T100Window*);
        virtual ~T100TextCtrl();

        virtual T100VOID                Create(T100Window*, T100TextCtrlStyle* = T100NULL);
        virtual T100VOID                Destroy();

        virtual T100VOID                SetValue(const T100WSTRING&);
        virtual const T100WSTRING       GetValue();

        T100VOID                        SetModified(T100BOOL);
        T100BOOL                        IsModified();

        T100VOID                        SetFont(const T100Font&);
        const T100Font&                 GetFont();

        T100WSTRING                     GetSelection();
        T100UINT                        GetLength();

        T100VOID                        Append(const T100WSTRING&);
        T100VOID                        Insert(T100UINT, const T100WSTRING&);
        T100VOID                        Remove(T100UINT, T100UINT);

        T100VOID                        Cut();
        T100VOID                        Copy();
        T100VOID                        Paste();

    protected:
        T100WSTRING                     m_value;
        T100Font                        m_font;

    private:
        std::atomic_bool                m_modified;

        T100VOID                        init(T100Window*);
        T100VOID                        uninit();
};

}

#endif // T100TEXTCTRL_H
