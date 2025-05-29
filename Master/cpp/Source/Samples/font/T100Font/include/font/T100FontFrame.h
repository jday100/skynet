#ifndef T100FONTFRAME_H
#define T100FONTFRAME_H

#include "gui/T100Frame.h"

class T100FontFrame : public T100Frame
{
    public:
        T100FontFrame();
        virtual ~T100FontFrame();

        T100VOID            Create(T100Win32Application*);

    protected:
        T100WORD            T100MENU_ID_FONTS           = T100MENU_ID_USER + 1;
        T100WORD            T100MENU_ID_FONT_DIALOG     = T100MENU_ID_USER + 2;
        T100WORD            T100MENU_ID_QUIT            = T100MENU_ID_USER + 3;

        T100VOID            OnMenuFonts(T100CommandEvent&);
        T100VOID            OnMenuFontDialog(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

        T100VOID            OnFramePaint(T100PaintEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100FONTFRAME_H
