#ifndef T100HINTSYSTEM_H
#define T100HINTSYSTEM_H

#include "T100Hint.h"
#include "T100VFS.h"


static std::string      T100SYSTEM_HINT_FONT_CREATE                     =   "Font is creating...";
static std::string      T100SYSTEM_HINT_FONT_DESTROY                    =   "Font is destroyed.";

static std::string      T100SYSTEM_HINT_VDISK_CREATE                    =   "VDisk is creating...";
static std::string      T100SYSTEM_HINT_VDISK_DESTROY                   =   "VDisk is destroyed.";

static std::string      T100SYSTEM_HINT_VDISK_NO_ITEM                   =   "no file(s)!";


class T100HintSystem : public T100Hint
{
    public:
        T100HintSystem();
        virtual ~T100HintSystem();

        static T100STDSTRING        item_hint(T100VFS_ITEM);

    protected:

    private:
};

#endif // T100HINTSYSTEM_H
