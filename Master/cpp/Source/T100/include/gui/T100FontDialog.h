#ifndef T100FONTDIALOG_H
#define T100FONTDIALOG_H

#include "gui/window/T100SelfLoopWindow.h"
#include "gui/dialog/T100Dialog.h"

class T100FontDialog : public T100Dialog
{
    public:
        T100FontDialog(T100SelfLoopWindow*);
        virtual ~T100FontDialog();

    protected:

    private:
        T100VOID            Init();
};

#endif // T100FONTDIALOG_H
