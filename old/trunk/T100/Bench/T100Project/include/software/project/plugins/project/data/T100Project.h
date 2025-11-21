#ifndef T100PROJECT_H
#define T100PROJECT_H

#include "T100Common.h"
#include "T100Tree.h"

#define     T100PROJECT_VESSEL          T100Vessel<T100WSTRING, T100Project*>

class T100Project
{
    public:
        T100Project(const T100WSTRING&);
        virtual ~T100Project();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

    protected:
        T100WSTRING             m_label;
        T100WSTRING             m_path;
        T100UINT                m_type;

        T100WSTRING             m_includePath;
        T100WSTRING             m_sourcePath;

        T100Tree                m_includeFiles;
        T100Tree                m_sourceFiles;

    private:
};

#endif // T100PROJECT_H
