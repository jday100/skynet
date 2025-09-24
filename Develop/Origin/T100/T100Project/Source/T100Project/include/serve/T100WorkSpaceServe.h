#ifndef T100WORKSPACESERVE_H
#define T100WORKSPACESERVE_H

#include <atomic>
#include "T100WxFolderInfo.h"
#include "T100WorkSpaceInfo.h"
#include "T100FileServe.h"
#include "T100FolderServe.h"
#include "T100ProjectServe.h"

class T100WorkSpaceServe
{
    public:
        T100WorkSpaceServe();
        virtual ~T100WorkSpaceServe();

        T100FileServe&              GetFileServe();
        T100FolderServe&            GetFolderServe();
        T100ProjectServe&           GetProjectServe();

        T100VOID                    SetOpened(T100BOOL);
        T100BOOL                    IsOpened();

        T100BOOL                    Create();
        T100WorkSpaceInfo*          GetWorkSpaceInfo();

        virtual T100BOOL            CheckWorkSpaceFolder(const T100WSTRING&);
        virtual T100BOOL            CheckWorkSpaceFile(T100WxFolderInfo*);

        virtual T100BOOL            CreateWorkSpace(T100WorkSpaceInfo*);
        virtual T100BOOL            CreateWorkSpaceFile(T100WorkSpaceInfo*);

        virtual T100BOOL            OpenWorkSpace(T100WorkSpaceInfo*);
        virtual T100BOOL            OpenWorkSpaceFile(T100WorkSpaceInfo*);

        T100BOOL                    CloseWorkSpace();

    protected:
        std::atomic_bool            m_opened;
        T100WorkSpaceInfo*          m_workspace     = T100NULL;

        T100FileServe               m_serveFile;
        T100FolderServe             m_serveFolder;
        T100ProjectServe            m_serveProject;

    private:
        T100WSTRING                 GetFileName(const T100WSTRING&);
};

#endif // T100WORKSPACESERVE_H
