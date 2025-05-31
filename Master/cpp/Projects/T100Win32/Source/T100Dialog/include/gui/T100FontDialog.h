#ifndef T100FONTDIALOG_H
#define T100FONTDIALOG_H

#include "gui/window/T100SelfLoopWindow.h"
#include "gui/dialog/T100Dialog.h"

class T100FontDialog : public T100Dialog
{
    public:
        T100FontDialog();
        virtual ~T100FontDialog();

        T100VOID            Create(T100Window*);

        T100VOID            SetFont(T100Font);
        T100Font&           GetFont();

    protected:
        T100Font            m_font;

    private:
};

#endif // T100FONTDIALOG_H
