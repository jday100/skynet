#ifndef T100FILEDIALOG_H
#define T100FILEDIALOG_H

#include "gui/window/T100SelfLoopWindow.h"

class T100FileDialog : public T100SelfLoopWindow
{
    public:
        T100FileDialog();
        virtual ~T100FileDialog();

    protected:

    private:
        T100VOID            Init();
};

#endif // T100FILEDIALOG_H
