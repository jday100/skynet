#ifndef T100PROJECTSERVE_H
#define T100PROJECTSERVE_H

#include "T100WxFolderInfo.h"
#include "T100ProjectInfo.h"

class T100WorkSpaceInfo;
class T100ModuleInfo;

class T100ProjectServe
{
    public:
        T100ProjectServe();
        virtual ~T100ProjectServe();

        T100ProjectInfo*                GetCurrentProject();

        const T100WSTRING               GetFileName(const T100WSTRING&);

        const T100WSTRING               GetFolderName(const T100WSTRING&, const T100WSTRING&);

        T100BOOL                        Check(T100WxFolderInfo*);

        T100BOOL                        Create(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                        Open(T100ProjectInfo*);

        T100BOOL                        Build(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                        Run(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                        Clean(T100WorkSpaceInfo*, T100ProjectInfo*);

        T100BOOL                        ModuleCreate(T100WorkSpaceInfo*, T100ModuleInfo*);

        T100BOOL                        Clear();

    protected:
        T100ProjectInfo*                m_current       = T100NULL;

    private:
};

#endif // T100PROJECTSERVE_H
