#ifndef T100TESTDIALOG_H
#define T100TESTDIALOG_H

#include "gui/T100Dialog.h"

using namespace T100WINDOWS;

class T100TestDialog : public T100Dialog
{
    public:
        T100TestDialog();
        virtual ~T100TestDialog();

        virtual T100VOID            Create(T100Window*);

    protected:

    private:
};

#endif // T100TESTDIALOG_H
