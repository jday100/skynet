#ifndef T100PROJECTSKELETALBASE_H
#define T100PROJECTSKELETALBASE_H

#include "T100ProjectView.h"
#include "T100WorkSpaceServe.h"

class T100WxFolderInfo;
class T100ProjectInfo;
class T100WorkSpaceInfo;

class T100ProjectSkeletalBase
{
    public:
        T100ProjectSkeletalBase();
        virtual ~T100ProjectSkeletalBase();

        T100BOOL                    WorkSpaceCreate(T100WorkSpaceInfo*);
        T100BOOL                    WorkSpaceOpen(T100WxFolderInfo*);
        T100BOOL                    WorkSpaceClose();
        T100BOOL                    WorkSpaceSave();

        T100BOOL                    ProjectCreate(T100ProjectInfo*);
        T100BOOL                    ProjectBuild(T100WorkSpaceInfo*, T100ProjectInfo*);
        T100BOOL                    ProjectRun(T100WorkSpaceInfo*, T100ProjectInfo*);
        T100BOOL                    ProjectClean(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                    FileCreate();
        T100BOOL                    FileRemove();
        T100BOOL                    FileOpen();
        T100BOOL                    FileSaveAs();

    protected:
        T100ProjectView*            m_view      = T100NULL;
        T100WorkSpaceServe*         m_serve     = T100NULL;

    private:
};

#endif // T100PROJECTSKELETALBASE_H
