#ifndef T100DIALOG_H
#define T100DIALOG_H

#include "gui/window/T100SelfLoopWindow.h"

namespace T100WINDOWS{

class T100Dialog : public T100SelfLoopWindow
{
    public:
        T100Dialog();
        virtual ~T100Dialog();

        virtual T100VOID            Create(T100Window*);
        virtual T100VOID            Destroy();

    protected:

    private:
};

}

#endif // T100DIALOG_H
