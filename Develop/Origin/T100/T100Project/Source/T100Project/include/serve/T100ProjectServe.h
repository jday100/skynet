#ifndef T100PROJECTSERVE_H
#define T100PROJECTSERVE_H

#include "T100ProjectInfo.h"
#include "T100ProjectLogic.h"

class T100ProjectServe
{
    public:
        T100ProjectServe();
        virtual ~T100ProjectServe();

        T100VOID                                GetProjects(T100PROJECT_INFO_VECTOR&);
        const T100PROJECT_INFO_VECTOR&          GetProjects();

        T100ProjectInfo*                        GetProjectInfo();

        T100BOOL                                Check(T100WxFolderInfo*);

        T100BOOL                                New(const T100WxFolderInfo&);
        T100BOOL                                Open(const T100WSTRING&);

        T100BOOL                                Open(const T100WSTRING_VECTOR&, T100PROJECT_INFO_VECTOR&);

    protected:
        T100ProjectLogic                        m_logic;
        T100PROJECT_INFO_VECTOR*                m_projects      = T100NULL;

    private:
};

#endif // T100PROJECTSERVE_H
