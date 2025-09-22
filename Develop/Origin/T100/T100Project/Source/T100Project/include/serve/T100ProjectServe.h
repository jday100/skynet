#ifndef T100PROJECTSERVE_H
#define T100PROJECTSERVE_H

#include "T100ProjectInfo.h"
#include "T100FileLogic.h"
#include "T100FolderLogic.h"
#include "T100ProjectLogic.h"

class T100WorkSpaceInfo;

class T100ProjectServe
{
    public:
        T100ProjectServe();
        virtual ~T100ProjectServe();

        T100FileLogic*                          GetFileLogic();
        T100FolderLogic*                        GetFolderLogic();
        T100ProjectLogic*                       GetProjectLogic();

        T100ProjectInfo*                        GetProjectInfo();

        T100BOOL                                Check(T100WxFolderInfo*);

        T100BOOL                                New(const T100WxFolderInfo&, T100WorkSpaceInfo*);

    protected:
        T100FileLogic*                          m_fileLogic     = T100NULL;
        T100FolderLogic*                        m_folderLogic   = T100NULL;
        T100ProjectLogic*                       m_projectLogic  = T100NULL;

    private:
        T100VOID                                init();
        T100VOID                                uninit();
};

#endif // T100PROJECTSERVE_H
