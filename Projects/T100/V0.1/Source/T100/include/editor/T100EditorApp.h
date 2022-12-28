#ifndef T100EDITORAPP_H
#define T100EDITORAPP_H

#include "T100WxApp.h"
class T100ThisAppManager;

namespace T100Editor{
class T100Editor;


class T100EditorApp : public T100WxWidgets::T100WxApp
{
    public:
        T100EditorApp(T100ThisAppManager*, T100BOOL = T100FALSE);
        virtual ~T100EditorApp();

        T100VOID            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100Editor*         m_editor            = T100NULL;

};

}

#endif // T100EDITORAPP_H
