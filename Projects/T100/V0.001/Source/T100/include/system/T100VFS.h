#ifndef T100VFS_H
#define T100VFS_H


#include "T100Common.h"
class T100VDiskFile;
class T100VDiskPart;
class T100VFSDirectory;
class T100VFSTable;
class T100VFSItem;

/*
0       <-location
1       <-table begin
.
.
.
m       <-table end
n      0<-root
.           d
.           a
.           t
.           a
x      z<-length
*/


#define     T100VFS_BLOCK_SIZE              16 * 1024
#define     T100VFS_CLUSTER_SIZE            16
#define     T100VFS_ITEM_SIZE               256 - 1
#define     T100VFS_ITEM_NAME_LENGTH        248
#define     T100VFS_ITEM_DATA_LENGTH        16 * 1024
#define     T100VFS_FILE_BUFFER_LENGTH      16 * 1024
#define     T100VFS_TABLE_SIZE              512
#define     T100VFS_TABLE_DATA_LENGTH       16 * 1024
#define     T100VFS_PART_LABEL_LENGTH       16
#define     T100VFS_PART_SIZE               512
#define     T100VFS_PART_DATA_LENGTH        16 * 1024


typedef     T100DWORD                       T100VFS_HANDLE;


enum T100VFS_ITEM_TYPE{
    T100VFS_ITEM_NONE       = 0,
    T100VFS_ITEM_BAD        = 0xffffffffffffffff,
    T100VFS_ITEM_END        = 0xffffffffffffff00
};

typedef struct{
    T100WORD                LABEL[18];
    T100DWORD               LOCATION;
    T100DWORD               LENGTH;
    T100WORD                USED;
    T100WORD                BOOT;
    T100WORD                RESERVE[8];
}T100VFS_PART;


#define     T100VFS_PART_VECTOR         std::vector<T100VFS_PART>
#define     T100VFS_ITEM_VECTOR         std::vector<T100VFS_ITEM*>


typedef union{
    T100VFS_PART            PARTS[T100VFS_PART_SIZE];
    T100WORD                DATA[T100VFS_PART_DATA_LENGTH];
}T100VFS_PART_INFO;

typedef struct{
    T100WORD                NAME[202];
    T100WORD                RESERVE[48];
    T100DWORD               LOCATION;
    T100DWORD               LENGTH;
    T100WORD                PROPERTIES[2];
}T100VFS_ITEM;

typedef union{
    struct{
        T100VFS_ITEM        ITEMS[T100VFS_ITEM_SIZE];
        T100WORD            RESERVE[256 - 2];
        T100DWORD           LOCATION;
    };
    T100WORD                DATA[T100VFS_ITEM_DATA_LENGTH];
}T100VFS_ITEM_INFO;

typedef union{
    T100DWORD               CELLS[T100VFS_TABLE_SIZE];
    T100WORD                DATA[T100VFS_TABLE_DATA_LENGTH];
}T100VFS_TABLE_INFO;

typedef struct{
    T100DWORD               LOCATION;
    T100WORD                OFFSET;
    T100VFS_ITEM            ITEM;
}T100VFS_ITEM_HANDLE;

typedef struct{
    T100DWORD               LOCATION;
    T100WORD                OFFSET;
    T100DWORD               CELL;
}T100VFS_TABLE_HANDLE;

typedef struct{
    T100VFS_ITEM_HANDLE     ITEM;
    T100DWORD               CURRENT;
    T100DWORD               SEEK;
    T100DWORD_VECTOR        CLUSTERS;
    T100WORD                BUFFER[T100VFS_FILE_BUFFER_LENGTH];
}T100VFS_FILE_HANDLE;



class T100VFS
{
    friend class T100VFSItem;
    friend class T100VFSTable;
    friend class T100VFSFile;
    friend class T100VFSDirectory;
    public:
        T100VFS(T100VDiskFile*, T100VDiskPart*);
        virtual ~T100VFS();

        T100BOOL            format(T100STDSTRING);
        T100BOOL            format(T100STDSTRING, T100STDSTRING);

        T100BOOL            mkdir(T100STDSTRING, T100STDSTRING);
        T100BOOL            chdir(T100STDSTRING, T100STDSTRING);
        T100BOOL            rmdir(T100STDSTRING, T100STDSTRING);

        T100BOOL            create(T100STDSTRING, T100STDSTRING);
        T100BOOL            remove(T100STDSTRING, T100STDSTRING);

        T100BOOL            list(T100STDSTRING, T100STDSTRING);
        T100BOOL            copy(T100STDSTRING, T100STDSTRING, T100STDSTRING);

        T100BOOL            read(T100DWORD, T100WORD*);
        T100BOOL            write(T100DWORD, T100WORD*);

        T100BOOL            clear(T100DWORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            change_part(T100VFS_PART*);

        T100DWORD           absolute(T100DWORD);
        T100DWORD           relative(T100DWORD);
        T100DWORD           transform(T100DWORD, T100WORD);

    private:
        T100VDiskFile*      m_vdisk         = T100NULL;
        T100VDiskPart*      m_part          = T100NULL;

        T100VFSDirectory*   m_path          = T100NULL;

        T100VFSItem*        m_item          = T100NULL;
        T100VFSTable*       m_table         = T100NULL;
};

#endif // T100VFS_H
