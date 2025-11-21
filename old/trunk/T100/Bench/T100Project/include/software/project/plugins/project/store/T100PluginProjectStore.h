#ifndef T100PLUGINPROJECTSTORE_H
#define T100PLUGINPROJECTSTORE_H

#include "T100Project.h"
#include "T100ProjectInfo.h"

class T100PluginProjectStore
{
    public:
        T100PluginProjectStore();
        virtual ~T100PluginProjectStore();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

        T100VOID                    Load(T100PROJECT_VESSEL&);

        T100VOID                    Create(T100ProjectInfo&);

    protected:
        T100WSTRING                 m_path;

    private:
        T100VOID                    CreateProject(const T100Project&);
};

#endif // T100PLUGINPROJECTSTORE_H
