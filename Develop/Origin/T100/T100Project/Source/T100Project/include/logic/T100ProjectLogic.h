#ifndef T100PROJECTLOGIC_H
#define T100PROJECTLOGIC_H

#include <vector>
#include "T100Tree.h"
#include "T100ProjectInfo.h"
#include "T100FileLogic.h"
#include "T100FolderLogic.h"
#include "T100WxFolderInfo.h"

class T100WorkSpaceInfo;
class T100ModuleInfo;

class T100ProjectLogic
{
    public:
        T100ProjectLogic();
        T100ProjectLogic(T100ProjectInfo*);
        virtual ~T100ProjectLogic();

        T100ProjectInfo*            GetCurrent();
        T100WSTRING                 GetFileName(const T100WxFolderInfo&);

        T100BOOL                    Check(T100WxFolderInfo*);

        T100BOOL                    Create(const T100WxFolderInfo&, T100WorkSpaceInfo*);
        T100BOOL                    Remove(T100ProjectInfo*);

        T100BOOL                    Open(const T100WSTRING&, T100ProjectInfo*);
        T100BOOL                    Close(T100ProjectInfo*);

        T100BOOL                    Rename(T100ProjectInfo*);

        T100BOOL                    Run(T100WorkSpaceInfo*, T100ProjectInfo*);
        T100BOOL                    Clean(T100ProjectInfo*);
        T100BOOL                    Build(T100WorkSpaceInfo*, T100ProjectInfo*);
        T100BOOL                    Rebuild(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                    CreateModule(T100WorkSpaceInfo*, T100ModuleInfo*);

    protected:
        T100WSTRING                 GetFolderName(const T100WxFolderInfo&);
        T100WSTRING                 GetBuildName(const T100ProjectInfo*);

        T100BOOL                    Execute(T100WorkSpaceInfo*, T100ProjectInfo*);

    protected:
        T100FileLogic*              m_file          = T100NULL;
        T100FolderLogic*            m_folder        = T100NULL;
        T100ProjectInfo*            m_current       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTLOGIC_H
