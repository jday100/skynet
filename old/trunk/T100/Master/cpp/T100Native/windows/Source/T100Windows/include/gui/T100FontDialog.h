#ifndef T100FONTDIALOG_H
#define T100FONTDIALOG_H

#include "gui/T100Font.h"
#include "gui/T100Dialog.h"

namespace T100WINDOWS{

class T100FontDialog : public T100Dialog
{
    public:
        T100FontDialog();
        T100FontDialog(T100Window*);
        virtual ~T100FontDialog();

        T100BOOL                    Show();

        virtual T100VOID            Create(T100Window*);
        virtual T100VOID            Destroy();

        T100VOID                    SetFont(const T100Font&);
        const T100Font&             GetFont();

    protected:
        T100Font                    m_font;

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100FONTDIALOG_H
