#ifndef T100SAVEDIALOG_H
#define T100SAVEDIALOG_H

#include "gui/T100Dialog.h"

namespace T100WINDOWS{

class T100SaveDialog : public T100Dialog
{
    public:
        T100SaveDialog();
        virtual ~T100SaveDialog();

        T100BOOL                    Show();

        T100VOID                    SetDirectory(const T100WSTRING&);
        const T100WSTRING&          GetDirectory();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

        T100VOID                    SetFileName(const T100WSTRING&);
        const T100WSTRING&          GetFileName();

    protected:
        T100WSTRING                 m_directory;
        T100WSTRING                 m_path;
        T100WSTRING                 m_filename;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100SAVEDIALOG_H
