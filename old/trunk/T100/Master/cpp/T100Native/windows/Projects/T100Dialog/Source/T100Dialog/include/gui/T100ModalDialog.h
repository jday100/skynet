#ifndef T100MODALDIALOG_H
#define T100MODALDIALOG_H

#include "gui/window/T100SelfLoopWindow.h"

using namespace T100WINDOWS;

namespace T100DIALOG{

class T100ModalDialog : public T100SelfLoopWindow
{
    public:
        T100ModalDialog();
        virtual ~T100ModalDialog();

        virtual T100VOID            Create(T100SelfLoopWindow*);

    protected:

    private:
};

}

#endif // T100MODALDIALOG_H
