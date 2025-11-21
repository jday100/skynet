#ifndef T100PLUGINEDITORACTUATOR_H
#define T100PLUGINEDITORACTUATOR_H

#include "plugin\T100WxPluginActuator.h"
#include "T100Editor.h"

class T100MainFrame;

class T100PluginEditorActuator : public T100WxPluginActuator
{
    public:
        T100PluginEditorActuator(const wxEvtHandler&);
        virtual ~T100PluginEditorActuator();

        T100VOID                SetFrame(T100MainFrame*);
        T100MainFrame*          GetFrame();

        T100VOID                SignIn();
        T100VOID                SignOut();

        T100VOID                OnFileCreate(wxCommandEvent&);
        T100VOID                OnFileOpen(wxCommandEvent&);
        T100VOID                OnFileClose(wxCommandEvent&);
        T100VOID                OnFileSave(wxCommandEvent&);
        T100VOID                OnFileSaveAs(wxCommandEvent&);


    protected:
        T100Editor              m_editor;
        T100MainFrame*          m_frame         = T100NULL;

    private:
};

#endif // T100PLUGINEDITORACTUATOR_H
