#include "T100TestSystem.h"

#include <cstring>
#include "T100Log.h"
#include "T100HintTest.h"
#include "T100StringTools.h"
#include "T100FileTools.h"
#include "T100Font.h"
#include "T100FontFile.h"

#include "T100VFSTable.h"
#include "T100VFSItem.h"
#include "T100VFSDirectory.h"
#include "T100VFSFile.h"
#include "T100VFS.h"
#include "T100VDisk.h"
#include "T100VDiskFileNew.h"


T100STDSTRING       T100TestSystem::m_unit      = "system";


T100TestSystem::T100TestSystem()
    :T100Test(m_unit)
{
    //ctor
}

T100TestSystem::~T100TestSystem()
{
    //dtor
}

T100VOID T100TestSystem::load()
{

}

T100BOOL T100TestSystem::test_all()
{
    T100BOOL        result      = T100TRUE;

    T100Log::info(T100TEST_SYSTEM_TEST_START);

    if(!test_font_file()){
        result = T100FALSE;
    }

    if(!test_font_file_read()){
        result = T100TRUE;
    }

    if(!test_font()){
        result = T100FALSE;
    }

    if(!test_vfs_table()){
        result = T100FALSE;
    }

    if(!test_vfs_item()){
        result = T100FALSE;
    }

    if(!test_vfs_path()){
        result = T100FALSE;
    }

    if(!test_vfs_file()){
        result = T100FALSE;
    }

    //return result;

    /*
    if(!test_vfs()){
        result = T100FALSE;
    }
    */

    if(!test_vdisk_file()){
        result = T100FALSE;
    }

    if(!test_vdisk()){
        result = T100FALSE;
    }

    T100Log::info(T100TEST_SYSTEM_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_font()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_SYSTEM_FONT_TEST_START);

    T100Font        font;

    value = font.load(T100String("test\\temp\\test.fnt"));
    if(!value){
        result = T100FALSE;
    }

    T100Log::info(T100TEST_SYSTEM_FONT_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_font_file()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100FontFile            file(T100String("test\\temp\\test.fnt"));

    T100Log::info(T100TEST_SYSTEM_FONT_FILE_TEST_START);

    if(file.exists()){
        if(!file.remove()){
            result = T100FALSE;
        }
    }

    if(result && file.exists()){
        result = T100FALSE;
    }

    if(result && !file.create()){
        result = T100FALSE;
    }

    if(result && !file.exists()){
        result = T100FALSE;
    }

    if(result){
        value = file.open(T100FILE_WRITE);
        if(value){
            file.setFontName(T100String("TEST"));
            file.setFontWidth(16);
            file.setFontHeight(16);
            file.setRowSize(1);

            if(!file.write_head()){
                result = T100FALSE;
            }

            T100FONTFILE_ROW row;

            memset(&row, 0, sizeof(T100FONTFILE_ROW));

            row.BEGIN   = 0;
            row.END     = 1;
            row.LENGTH  = 1;
            //test
            row.SEEK    = 0;

            if(result && !file.write_row(&row)){
                result = T100FALSE;
            }

            T100WORD*   data;
            T100HWORD   length;     //8

            if(result && !file.allot(data, length)){
                result = T100FALSE;
            }

            if(result){
                data[0] = 1;
                data[1] = 2;
                data[2] = 3;
                data[3] = 4;

                data[4] = 5;
                data[5] = 6;
                data[6] = 7;
                data[7] = 8;
            }

            if(result && !file.write_item(data, length)){
                result = T100FALSE;
            }

            value = file.close();
            if(value){

            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_SYSTEM_FONT_FILE_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vdisk()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VDisk       vdisk("test\\temp\\test.vdk");

    T100Log::info(T100TEST_SYSTEM_VDISK_TEST_START);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.part_create("first", 1, 512, T100TRUE);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_format("first", "test\\scripts\\build\\boot.bin");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_mkdir("first", ":system");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_copy("test\\scripts\\build\\init.bin", "first", ":system:init.bin");
        if(value){
            //value = vdisk.fs_copy("test\\scripts\\build\\kernel.bin", "first", ":system:kernel.bin");
        }

        result = value;
    }

    T100Log::info(T100TEST_SYSTEM_VDISK_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vdisk_file()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VDiskFileNew       vdisk("test\\temp\\test.vdk");

    T100Log::info(T100TEST_SYSTEM_VDISK_FILE_TEST_START);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    T100WORD    source[16384];
    T100WORD    target[16384];
    T100WORD*   data            = T100NULL;

    data = source;

    if(vdisk.open(T100FILE_READWRITE)){
        if(vdisk.opened()){
            for(int i=0;i<16384;i++){
                source[i] = i;
            }
            if(vdisk.write(0, data)){
                data = target;
                if(vdisk.read(0, data)){
                    for(int i=0;i<16384;i++){
                        if(source[i] == target[i]){

                        }else{
                            result = T100FALSE;
                            break;
                        }
                    }
                }else{
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }
            if(!vdisk.close()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    T100Log::info(T100TEST_SYSTEM_VDISK_FILE_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vfs()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VDisk       vdisk("test\\temp\\test.vdk");

    T100Log::info(T100TEST_SYSTEM_VFS_TEST_START);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.part_create("first", 1, 512, T100TRUE);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_format("first", "test\\scripts\\build\\boot.bin");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_mkdir("first", ":system");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_copy("test\\scripts\\build\\init.bin", "first", ":system:init.bin");
        if(value){
            //value = vdisk.fs_copy("test\\scripts\\build\\kernel.bin", "first", ":system:kernel.bin");
        }

        result = value;
    }

    T100Log::info(T100TEST_SYSTEM_VFS_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vfs_item()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_SYSTEM_VFS_ITEM_TEST_START);

    T100VDiskFile   vdisk("test\\temp\\test.vdk");
    T100VDiskPart   part(&vdisk);
    T100VFS         vfs(&vdisk, &part);
    T100VFSItem     item(&vfs);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.open(T100FILE_READWRITE);
        if(value){
            value = part.create(T100String("first"), 1, 512, T100TRUE);
            if(!value){
                result = T100FALSE;
            }

            if(result){
                T100VFS_PART* temp = T100NULL;
                temp = part.search(T100String("first"));

                if(temp){
                    value = item.setPart(temp);
                    if(!value){
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = item.create();
                if(value){
                    T100WORD    buffer[16384];
                    T100WORD*   data;
                    T100WORD    length;

                    if(vdisk.seek(32768)){
                        data = buffer;
                        length = 16384;
                        value = vdisk.read(3, buffer);
                        if(value){
                            for(int i=0;i<16384;i++){
                                if(0 == buffer[i]){

                                }else{
                                    result = T100FALSE;
                                    break;
                                }
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                T100VFS_ITEM_HANDLE     source;
                T100VFS_ITEM_HANDLE     target;

                if(!item.next(source)){
                    result = T100FALSE;
                }

                if(result){
                    T100String name("hello.test");
                    if(T100StringTools::copy(source.ITEM.NAME, name.getRawData(), name.getRawLength())){
                        source.ITEM.PROPERTIES[0] = 1;
                        if(!item.save(source)){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(item.search(T100String("hello.test"), target)){
                        if(0 != strcmp((char*)source.ITEM.NAME, (char*)target.ITEM.NAME)){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(!item.remove(target)){
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(item.search(T100String("hello.test"), target)){
                        result = T100FALSE;
                    }
                }
            }

            if(!vdisk.close()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_SYSTEM_VFS_ITEM_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vfs_table()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_SYSTEM_VFS_TABLE_TEST_START);

    T100VDiskFile   vdisk("test\\temp\\test.vdk");
    T100VDiskPart   part(&vdisk);
    T100VFS         vfs(&vdisk, &part);
    T100VFSTable    table(&vfs);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.open(T100FILE_READWRITE);
        if(value){
            value = part.create(T100String("first"), 1, 512, T100TRUE);
            if(!value){
                result = T100FALSE;
            }

            if(result){
                T100VFS_PART* temp = T100NULL;
                temp = part.search(T100String("first"));

                if(temp){
                    value = table.setPart(temp);
                    if(!value){
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = table.create();
                if(value){
                    T100WORD    buffer[16384];
                    T100WORD*   data;
                    T100WORD    length;

                    if(vdisk.seek(32768)){
                        data = buffer;
                        length = 16384;
                        value = vdisk.read(2, buffer);
                        if(value){
                            for(int i=0;i<16384;i++){
                                if(0 == buffer[i]){

                                }else{
                                    result = T100FALSE;
                                    break;
                                }
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                T100VFS_TABLE_HANDLE    source;
                T100VFS_TABLE_HANDLE    target;

                if(!table.next(source)){
                    result = T100FALSE;
                }

                if(result){
                    source.CELL = 1;
                    if(!table.save(source)){
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(table.search(0, target)){
                        if(source.CELL != target.CELL){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(!table.remove(target)){
                        result = T100FALSE;
                    }
                }

                if(result){
                    if(table.search(0, target)){
                        if(source.CELL == target.CELL){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }
            }

            if(!vdisk.close()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_SYSTEM_VFS_TABLE_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vfs_path()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_SYSTEM_VFS_PATH_TEST_START);

    T100VDiskFile           vdisk("test\\temp\\test.vdk");
    T100VDiskPart           part(&vdisk);
    T100VFS                 vfs(&vdisk, &part);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.open(T100FILE_READWRITE);
        if(value){
            value = part.create(T100String("first"), 1, 512, T100TRUE);
            if(!value){
                result = T100FALSE;
            }

            if(result){
                value = vfs.format("first");
                if(!value){
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.mkdir("first", ":system");
                if(value){
                    T100WORD    buffer[16384];

                    if(vdisk.read(3, buffer)){
                        if(1 != buffer[254]){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.chdir("first", ":system");
                if(!value){
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.rmdir("first", ":system");
                if(value){
                    T100WORD    buffer[16384];

                    if(vdisk.read(3, buffer)){
                        if(0 != buffer[254]){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            value = vdisk.close();
            if(!value){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_SYSTEM_VFS_PATH_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_vfs_file()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_SYSTEM_VFS_FILE_TEST_START);

    T100VDiskFile           vdisk("test\\temp\\test.vdk");
    T100VDiskPart           part(&vdisk);
    T100VFS                 vfs(&vdisk, &part);
    T100VFSFile             file(&vfs, "hello.test");

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.open(T100FILE_READWRITE);
        if(value){
            value = part.create(T100String("first"), 1, 512, T100TRUE);
            if(!value){
                result = T100FALSE;
            }

            if(result){
                value = vfs.format("first");
                if(!value){
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.mkdir("first", ":system");
                if(value){
                    T100WORD    buffer[16384];

                    if(vdisk.read(3, buffer)){
                        if(1 != buffer[254]){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.chdir("first", ":system");
                if(!value){
                    result = T100FALSE;
                }
            }

            if(result){
                value = file.create();
                if(value){
                    T100WORD    buffer[16384];

                    if(vdisk.read(4, buffer)){
                        if(1 != buffer[254]){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = file.open();
                if(value){
                    //8192,16384,8192,32768
                    T100WORD        buffer[65536];
                    T100WORD        length;
                    T100WORD        size;
                    T100WORD*       data;

                    data    = (T100WORD*)&buffer;
                    length  = 65536;
                    for(int i=0;i<length;i++){
                        buffer[i] = i;
                    }

                    size    = 8192;
                    length  = 8192;
                    value   = file.write(data, length);
                    if(value){
                        if(length != size){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }

                    if(result){
                        data    += 8192;
                        size    = 16384;
                        length  = 16384;
                        value   = file.write(data, length);
                        if(value){
                            if(length != size){
                                result = T100FALSE;
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }

                    if(result){
                        data    += 16384;
                        size    = 8192;
                        length  = 8192;
                        value   = file.write(data, length);
                        if(value){
                            if(length != size){
                                result = T100FALSE;
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }

                    if(result){
                        data    += 8192;
                        size    = 32768;
                        length  = 32768;
                        value   = file.write(data, length);
                        if(value){
                            if(length != size){
                                result = T100FALSE;
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }

                    if(result){
                        if(65536 != file.length()){
                            result = T100FALSE;
                        }
                    }

                    //
                    value = file.close();
                    if(!value){
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            if(result){
                value = vfs.rmdir("first", ":system");
                if(value){
                    T100WORD    buffer[16384];

                    if(vdisk.read(3, buffer)){
                        if(0 != buffer[254]){
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }

            value = vdisk.close();
            if(!value){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_SYSTEM_VFS_FILE_TEST_STOP);

    return result;
}

T100BOOL T100TestSystem::test_font_file_read()
{
    T100FontFile    source(T100String("test.fnt"));
    T100FontFile    target(T100String("test.fnt"));

    if(source.exists()){
        if(source.remove()){

        }else{
            return T100FALSE;
        }
    }

    source.setFontName(T100String(u8"字体"));

    if(!source.create()){
        return T100FALSE;
    }

    if(!source.exists()){
        return T100FALSE;
    }

    if(!target.open(T100FILE_READ)){
        return T100FALSE;
    }

    if(T100String(u8"字体") != target.getFontName()){
        return T100FALSE;
    }

    if(!target.close()){
        return T100FALSE;
    }

    return T100TRUE;
}
