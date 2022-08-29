#ifndef T100HINTQU32_H
#define T100HINTQU32_H

#include "T100Hint.h"
#include "T100OrderTypes.h"


static std::string      T100QU32_HINT_START                             = "The compute is starting...";
static std::string      T100QU32_HINT_STOP                              = "The computer is stoped.";

static std::string      T100DEVICE_HINT_AU_DEVICE_LOAD                  = "AU device is loading...";
static std::string      T100DEVICE_HINT_AU_DEVICE_UNLOAD                = "AU device is unloaded.";

static std::string      T100DEVICE_HINT_CU_DEVICE_LOAD                  = "CU device is loading...";
static std::string      T100DEVICE_HINT_CU_DEVICE_UNLOAD                = "CU device is unloaded.";

static std::string      T100DEVICE_HINT_IO_DEVICE_LOAD                  = "IO device is loading...";
static std::string      T100DEVICE_HINT_IO_DEVICE_UNLOAD                = "IO device is unloaded.";

static std::string      T100DEVICE_HINT_MEMORY_DEVICE_LOAD              = "Memory device is loading...";
static std::string      T100DEVICE_HINT_MEMORY_DEVICE_UNLOAD            = "Memory device is unloaded.";

static std::string      T100DEVICE_HINT_DISK_LOAD                       = "Disk is loading...";
static std::string      T100DEVICE_HINT_DISK_UNLOAD                     = "Disk is unloaded.";

static std::string      T100DEVICE_HINT_DISK_LOADED                     = "Disk is loaded.";

static std::string      T100DEVICE_HINT_DISPLAY_LOAD                    = "Display is loading...";
static std::string      T100DEVICE_HINT_DISPLAY_UNLOAD                  = "Display is unloaded.";

static std::string      T100DEVICE_HINT_KEYBOARD_LOAD                   = "Keyboard is loading...";
static std::string      T100DEVICE_HINT_KEYBOARD_UNLOAD                 = "Keyboard is unloaded.";

static std::string      T100DEVICE_HINT_MOUSE_LOAD                      = "Mouse is loading...";
static std::string      T100DEVICE_HINT_MOUSE_UNLOAD                    = "Mouse is unloaded.";


static std::string      T100QU32_HINT_MANAGER_START                     = "The Manager is starting...";
static std::string      T100QU32_HINT_MANAGER_STOP                      = "The Manager is stoped.";

static std::string      T100QU32_HINT_MANAGER_ADD_DEVICE                = "Add device of Manager is running...";
static std::string      T100QU32_HINT_MANAGER_REMOVE_DEVICE             = "Remove device of Manager is running...";


class T100HintQU32 : public T100Hint
{
    public:
        T100HintQU32();
        virtual ~T100HintQU32();

        static T100STDSTRING        vpc_hint(T100STDSTRING);

        static T100STDSTRING        order_hint(T100WORD, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100OPERATOR_DOUBLE&, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100OPERATOR_DOUBLE&, T100OPERATOR_DOUBLE&, T100STDSTRING);
        //
        static T100STDSTRING        cmt_hint(T100WORD, T100WORD, T100WORD, T100STDSTRING);
        //
    protected:

    private:
};

#endif // T100HINTQU32_H
