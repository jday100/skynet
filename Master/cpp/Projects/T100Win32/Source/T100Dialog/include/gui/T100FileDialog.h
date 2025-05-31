#ifndef T100FILEDIALOG_H
#define T100FILEDIALOG_H

#include "gui/window/T100Window.h"

class T100FileDialog : public T100Window
{
    public:
        T100FileDialog();
        virtual ~T100FileDialog();

        T100VOID            SetDirectory(T100WSTRING);
        T100WSTRING&        GetDirectory();

        T100VOID            SetPath(T100WSTRING);
        T100WSTRING&        GetPath();

        T100VOID            SetFileName(T100WSTRING);
        T100WSTRING&        GetFileName();

    protected:
        T100WSTRING         m_directory;
        T100WSTRING         m_path;
        T100WSTRING         m_fileName;

    private:
        T100VOID            Init();
};

#endif // T100FILEDIALOG_H
