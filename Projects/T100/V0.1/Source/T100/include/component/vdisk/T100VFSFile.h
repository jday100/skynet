#ifndef T100VFSFILE_H
#define T100VFSFILE_H

#include "T100VFS.h"

namespace T100Component{

class T100VFSFile
{
    public:
        T100VFSFile(T100VFS*, T100STRING);
        virtual ~T100VFSFile();

        T100BOOL                    create();
        T100BOOL                    remove();

        T100BOOL                    exists();
        T100DWORD                   length();

        T100BOOL                    open();
        T100BOOL                    close();

        T100BOOL                    seek(T100DWORD);

        T100BOOL                    read(T100WORD*, T100WORD&);
        T100BOOL                    write(T100WORD*, T100WORD);

    protected:
        T100BOOL                    save(T100VFS_FILE_HANDLE*);

        T100BOOL                    m_opened            = T100FALSE;
        T100DWORD                   m_seek              = 0;
        T100VFS_FILE_HANDLE*        m_handle            = T100NULL;

    private:
        T100STRING                  m_file;
        T100VFS*                    m_vfs               = T100NULL;

};

}

#endif // T100VFSFILE_H
