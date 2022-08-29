#ifndef T100VDISKPART_H
#define T100VDISKPART_H

#include "T100Common.h"
#include "T100VFS.h"
#include "T100VDiskFile.h"



class T100VDiskPart
{
    public:
        T100VDiskPart(T100VDiskFile*);
        virtual ~T100VDiskPart();

        T100BOOL                load();
        T100BOOL                save();

        T100BOOL                create(T100String, T100DWORD, T100DWORD, T100BOOL);
        T100BOOL                remove(T100String);
        T100BOOL                list(T100VFS_PART_VECTOR&);
        T100BOOL                boot(T100String, T100BOOL);

        T100VFS_PART*           search(T100String);

    protected:
        T100VOID                start();
        T100VOID                stop();

        T100VFS_PART_INFO       m_parts;

    private:
        T100VDiskFile*          m_vdisk         = T100NULL;

};

#endif // T100VDISKPART_H
