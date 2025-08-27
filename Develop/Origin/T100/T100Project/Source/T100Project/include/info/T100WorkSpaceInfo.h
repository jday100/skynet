#ifndef T100WORKSPACEINFO_H
#define T100WORKSPACEINFO_H

#include "T100Common.h"
#include "T100ProjectInfo.h"

class T100WorkSpaceInfo
{
    public:
        T100WorkSpaceInfo();
        virtual ~T100WorkSpaceInfo();

        T100VOID                        SetLabel(const T100WSTRING&);
        const T100WSTRING&              GetLabel();

        T100VOID                        SetPath(const T100WSTRING&);
        const T100WSTRING&              GetPath();

        T100VOID                        SetFileName(const T100WSTRING&);
        const T100WSTRING&              GetFileName();

        T100VOID                        SetPythonFile(const T100WSTRING&);
        const T100WSTRING&              GetPythonFile();

        T100PROJECT_INFO_VECTOR&        GetProjects();
        T100FILE_INFO_VECTOR&           GetFiles();
        T100FOLDER_INFO_VECTOR&         GetFolders();

    protected:
        T100WSTRING                     m_label;
        T100WSTRING                     m_path;
        T100WSTRING                     m_filename;
        T100WSTRING                     m_pythonFile;

        T100PROJECT_INFO_VECTOR         m_projects;
        T100FILE_INFO_VECTOR            m_files;
        T100FOLDER_INFO_VECTOR          m_folders;

    private:
};

#endif // T100WORKSPACEINFO_H
