#ifndef T100PLUGINEDITOR_H
#define T100PLUGINEDITOR_H

#include "plugin\T100Plugin.h"
#include "T100PluginEditorActuator.h"

class T100PluginEditor : public T100Plugin
{
    public:
        T100PluginEditor();
        virtual ~T100PluginEditor();

        virtual T100BOOL            Create(T100VOID*);

    protected:
        T100PluginEditorActuator    m_actuator;

    private:
};

#endif // T100PLUGINEDITOR_H
