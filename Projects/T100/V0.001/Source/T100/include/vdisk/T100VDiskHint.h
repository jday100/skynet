#ifndef T100VDISKHINT_H
#define T100VDISKHINT_H

#include "T100Hint.h"
#include "T100VFS.h"


static std::string      T100VDISK_HINT_APP_START                        =   "VDisk Manager is starting...";
static std::string      T100VDISK_HINT_APP_STOP                         =   "VDisk Manager is stopped.";

static std::string      T100VDISK_HINT_CONSOLE_START                    =   "VDisk Console is starting...";
static std::string      T100VDISK_HINT_CONSOLE_STOP                     =   "VDisk Console is stopped.";

static std::string      T100VDISK_HINT_VFS_PART_EMPTY                   =   "no part!";


class T100VDiskHint : public T100Hint
{
    public:
        T100VDiskHint();
        virtual ~T100VDiskHint();

        static T100STDSTRING        part_hint();
        static T100STDSTRING        part_hint(T100VFS_PART);

        static T100STDSTRING        item_hint(T100VFS_ITEM);

    protected:

    private:
};

#endif // T100VDISKHINT_H
