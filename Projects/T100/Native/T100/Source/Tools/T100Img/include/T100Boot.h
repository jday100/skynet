#ifndef T100BOOT_H
#define T100BOOT_H

#include "T100ImgFile.h"


typedef union{
    char            BYTES[512];
    struct{
    };
}FAT_BOOT;



class T100Boot
{
    public:
        T100Boot();
        virtual ~T100Boot();

        int             build(T100ImgFile&);

    protected:
        char            m_buffer[512];

    private:
        int             init();
};

#endif // T100BOOT_H
