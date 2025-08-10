#ifndef T100WORKSPACESERVE_H
#define T100WORKSPACESERVE_H

#include <atomic>
#include "T100Common.h"
#include "T100ProjectServe.h"
#include "T100WxFolderInfo.h"
#include "T100WorkSpaceInfo.h"

class T100WorkSpaceServe
{
    public:
        T100WorkSpaceServe();
        virtual ~T100WorkSpaceServe();

        T100ProjectServe*                       GetProjectServe();

        T100VOID                                GetProjects(T100PROJECT_INFO_VECTOR&);

        T100WorkSpaceInfo*                      GetWorkSpaceInfo();

        T100VOID                                GetFolderInfo(T100WxFolderInfo&);


        T100BOOL                                IsOpened();


        T100VOID                                Close();
        T100BOOL                                Save();


        T100BOOL                                New(const T100WxFolderInfo&);
        T100BOOL                                Open(const T100WxFolderInfo&);



        virtual T100VOID                        Create(T100WorkSpaceInfo*);
        virtual T100VOID                        Open(T100WorkSpaceInfo*);
        virtual T100VOID                        Close(T100WorkSpaceInfo*);

        virtual T100VOID                        Save(T100WorkSpaceInfo*);
        virtual T100VOID                        SaveAs(T100WorkSpaceInfo*);

        virtual T100VOID                        Build();

        virtual T100VOID                        Clear();

    protected:
        T100WSTRING                             GetFileName(const T100WxFolderInfo&);
        T100BOOL                                Open(const T100WSTRING_VECTOR&, T100PROJECT_INFO_VECTOR&);

    protected:
        std::atomic_bool                        m_opened;
        T100WorkSpaceInfo*                      m_info          = T100NULL;
        T100ProjectServe                        m_projectServe;

    private:
        T100VOID                                init();
        T100VOID                                uninit();

        T100VOID                                OpenWorkSpace(T100WorkSpaceInfo*);
};

#endif // T100WORKSPACESERVE_H
