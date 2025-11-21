#ifndef T100EXTENSIONDIALOG_H
#define T100EXTENSIONDIALOG_H

#include "T100Extension.h"

class wxDialog;

class T100ExtensionDialog : public T100Extension
{
    public:
        T100ExtensionDialog();
        virtual ~T100ExtensionDialog();

        T100VOID            SetDialog(wxDialog*);
        wxDialog*           GetDialog();

        T100VOID            SetHandler(T100Class*, T100CLASS_METHOD);

    protected:
        wxDialog*                       m_dialog        = T100NULL;
        T100CLASS_METHOD_DATA           m_function;

    private:
};

#endif // T100EXTENSIONDIALOG_H
