#ifndef T100FAT_H
#define T100FAT_H

#include "T100ImgFile.h"


typedef union{
    char        BYTES[32];
    struct{
        char    NAME[11];
        char    ATTRS;
        char    RESERVED[10];
        short   TIME;
        short   DATE;
        short   CLUSTEID;
        int     FILESIZE;
    };
}FAT_ENTRY;


class T100FAT
{
    public:
        T100FAT();
        virtual ~T100FAT();

        int         build(T100ImgFile&);

    protected:

    private:
};

#endif // T100FAT_H
