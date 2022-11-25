#ifndef T100QU32SETUP_H
#define T100QU32SETUP_H

#include "T100AppSetup.h"
#include "T100String.h"
#include "T100QU32Common.h"


namespace T100QU32{

class T100QU32Setup : public T100Library::T100AppSetup
{
    friend class T100Memory32;
    public:
        T100QU32Setup();
        virtual ~T100QU32Setup();

        static T100BOOL                 DEBUG;
        static T100EXECUTOR_MODE        DEBUG_MODE;
        static T100EXECUTOR_STATE       DEBUG_STATE;
        static T100WORD                 MEMORY_WINDOW_BEGIN;
        static T100WORD                 MEMORY_WINDOW_END;
        static T100WORD                 PORT_WINDOW_BEGIN;
        static T100WORD                 PORT_WINDOW_END;

        static T100WORD                 SCREEN_WIDTH;
        static T100WORD                 SCREEN_HEIGHT;

        static T100BOOL                 NEED_LOAD_ROM;

        static T100STRING               getRomFile();
        static T100PRELOAD_VECTOR&      getPreloadFiles();

        static T100STRING               getBuild();
        static T100STRING               getStores();
        static T100STRING               getResources();

        static T100WORD                 getRamBase();
        static T100WORD                 getRamSize();
        static T100WORD                 getRomBase();
        static T100WORD                 getRomSize();

    protected:
        static T100VOID                 setRamBase(T100WORD);
        static T100VOID                 setRamSize(T100WORD);
        static T100VOID                 setRomBase(T100WORD);
        static T100VOID                 setRomSize(T100WORD);

    private:
        static T100WORD                 m_ram_base;
        static T100WORD                 m_ram_size;
        static T100WORD                 m_rom_base;
        static T100WORD                 m_rom_size;

        static T100STRING               m_rom_file;

        static T100STRING               m_build_path;
        static T100STRING               m_stores_path;
        static T100STRING               m_resources_path;

        static T100PRELOAD_VECTOR       m_files;

};

}

#endif // T100QU32SETUP_H
