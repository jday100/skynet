#ifndef T100PROJECTLOGIC_H
#define T100PROJECTLOGIC_H

#include <vector>
#include "T100Tree.h"
#include "T100ProjectInfo.h"
#include "T100FileLogic.h"
#include "T100FolderLogic.h"
#include "T100WxFolderInfo.h"

class T100WorkSpaceInfo;

class T100ProjectLogic
{
    public:
        T100ProjectLogic();
        T100ProjectLogic(T100ProjectInfo*);
        virtual ~T100ProjectLogic();

        T100BOOL                    New(const T100WxFolderInfo&, T100WorkSpaceInfo*);
        T100BOOL                    Build(T100WorkSpaceInfo*);











        T100ProjectInfo*            GetProjectInfo();

        T100BOOL                    Check(T100WxFolderInfo*);

        T100BOOL                    Open(const T100WSTRING&);

        T100WSTRING                 GetFileName(const T100WxFolderInfo&);

        T100BOOL                    Open(const T100WSTRING&, T100ProjectInfo*);



    protected:
        T100ProjectInfo*            m_current       = T100NULL;

        T100WSTRING                 GetFolderName(const T100WxFolderInfo&);
        T100WSTRING                 GetBuildName(const T100ProjectInfo*);

        T100BOOL                    Execute(const T100WxFolderInfo&, T100WorkSpaceInfo*);

    protected:
        T100FileLogic*              m_file          = T100NULL;
        T100FolderLogic*            m_folder        = T100NULL;
        T100ProjectInfo*            m_project       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTLOGIC_H
