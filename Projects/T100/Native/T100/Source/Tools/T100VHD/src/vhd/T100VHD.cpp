#include "T100VHD.h"

#include <stdio.h>
#include <guiddef.h>
#include <string.h>
#include <sys/time.h>
#include "T100File.h"
#include "T100ByteTools.h"

#include <windows.h>

#include "T100VHDTest.h"

typedef union{
    T100BYTE        DATA[16];
    GUID            VALUE;
}T100GUID_MIX;


T100VHD::T100VHD(T100STRING file, T100INT64 length)
    :m_filename(file), m_length(length)
{
    //ctor
}

T100VHD::~T100VHD()
{
    //dtor
}

T100BOOL T100VHD::create(T100VHD_STORAGE_TYPE type)
{
    T100BOOL        result;
    T100File        file(m_filename);

    result      = file.create();

    if(result){
        result  = file.seek(m_length);

        if(result){
            result  = fixed();

            if(result){
                result  = file.write(m_file_head.DATA, 512);

                if(result){

                }else{
                    result  = file.remove();
                }
            }else{
                result  = file.remove();
            }
        }else{
            result  = file.remove();
        }
    }


    return result;
}


T100BOOL T100VHD::fixed()
{
    std::string     cookie      = "conectix";

    memset(m_file_head.DATA, 0, 512);
    memcpy(m_file_head.HEAD.COOKIE, cookie.data(), 8);

    memset(m_file_head.HEAD.FEATURES, 0, 4);

    INT16           major       = 1;
    INT16           minor       = 0;

    INT16           majvalue;
    INT16           minvalue;

    majvalue    = ntohs(major);
    minvalue    = ntohs(minor);

    memcpy(m_file_head.HEAD.FILE_FORMAT_VERSION, (void*)&majvalue, 2);
    memcpy(m_file_head.HEAD.FILE_FORMAT_VERSION + 2, (void*)&minvalue, 2);

    memset(m_file_head.HEAD.DATA_OFFSET, 0xff, 8);

    struct timeval  current;

    int     result      = 0;

    result = gettimeofday(&current, T100NULL);

    if(-1 == result){
        return T100FALSE;
    }

    T100INT32       sec;

    sec     = ntohl(current.tv_sec);
    memcpy(m_file_head.HEAD.TIME_STAMP, (void*)&sec, 4);

    std::string     app         = "win ";

    memcpy(m_file_head.HEAD.CREATOR_APPLICATION, app.data(), 4);

    major   = 5;
    minor   = 0;

    majvalue    = ntohs(major);
    minvalue    = ntohs(minor);

    memcpy(m_file_head.HEAD.CREATOR_VERSION, (void*)&majvalue, 2);
    memcpy(m_file_head.HEAD.CREATOR_VERSION + 2, (void*)&minvalue, 2);

    std::string     host        = "Wi2k";

    memcpy(m_file_head.HEAD.CREATOR_HOST_OS, host.data(), 4);

    T100INT64       size;

    size = T100ByteTools::swop(m_length);

    memcpy(m_file_head.HEAD.ORIGINAL_SIZE, (void*)&size, 8);
    memcpy(m_file_head.HEAD.CURRENT_SIZE, (void*)&size, 8);

    INT16           cylinder        = 2080;
    INT16           temp;

    temp    = ntohs(cylinder);

    memcpy(m_file_head.HEAD.DISK_GEOMETRY, (void*)&temp, 2);

    m_file_head.HEAD.DISK_GEOMETRY[2]   = 16;
    m_file_head.HEAD.DISK_GEOMETRY[3]   = 63;


    INT32           type        = 2;
    INT32           tvalue;

    tvalue  = ntohl(type);

    memcpy(m_file_head.HEAD.DISK_TYPE, (void*)&tvalue, 4);

    m_file_head.HEAD.SAVED_STATE    = 0;

    memset(m_file_head.HEAD.RESERVED, 0, 427);

    GUID    guid;

    HRESULT     value   = CoCreateGuid(&guid);

    if(S_OK == value){
        T100GUID_MIX    source;
        T100GUID_MIX    target;

        source.VALUE    = guid;

        T100ByteTools::swop(source.DATA, target.DATA, 16);
        memcpy(m_file_head.HEAD.UNIQUE_ID, (void*)&target.VALUE, 16);
    }else{
        return T100FALSE;
    }

    T100BYTE*       index           = T100NULL;

    T100INT32       total           = 0;
    T100INT32       item;


    index   = m_file_head.HEAD.COOKIE;

    for(int i=0;i<512;i++){
        total   += *index;
        index++;
    }

    item    = ntohl(~total);

    memcpy(m_file_head.HEAD.CHECKSUM, (void*)&item, 4);

    return T100TRUE;
}
