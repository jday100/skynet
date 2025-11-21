#ifndef T100PLUGINMAINMENU_H
#define T100PLUGINMAINMENU_H

#include <wx/frame.h>
#include "T100Plugin.h"

class T100ExtensionMenu;
class T100ExtensionFrame;

class T100PluginMainMenu : public T100Plugin
{
    public:
        T100PluginMainMenu();
        virtual ~T100PluginMainMenu();

        virtual T100VOID            Init(T100ExtensionManager*);

    protected:
        T100VOID                    OnQuit(wxCommandEvent&);

    private:
        T100VOID                    Load();
        T100VOID                    CreateMenu(T100ExtensionFrame*, T100ExtensionMenu*);
};

#endif // T100PLUGINMAINMENU_H
