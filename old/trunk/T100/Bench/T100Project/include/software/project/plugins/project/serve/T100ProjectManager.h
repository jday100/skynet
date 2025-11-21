#ifndef T100PROJECTMANAGER_H
#define T100PROJECTMANAGER_H

#include "T100Common.h"
#include "T100Project.h"
#include "T100ProjectInfo.h"

class T100ProjectManager
{
    public:
        T100ProjectManager();
        virtual ~T100ProjectManager();

        T100PROJECT_VESSEL&             GetProjects();

        T100VOID                        Create(T100UINT, T100ProjectInfo&);

    protected:
        T100PROJECT_VESSEL              m_projects;

    private:
};

#endif // T100PROJECTMANAGER_H
