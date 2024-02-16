#include "T100VHD.h"

#include <stdio.h>
#include <guiddef.h>
#include <string.h>
#include <sys/time.h>
#include "T100File.h"

#include <windows.h>


T100VHD::T100VHD(T100STRING file, T100INT64 length)
    :m_filename(file), m_length(length)
{
    //ctor
}

T100VHD::~T100VHD()
{
    //dtor
}

T100BOOL T100VHD::create()
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

    memcpy(m_file_head.HEAD.COOKIE, cookie.data(), 8);

    memset(m_file_head.HEAD.FEATURES, 0, 4);

    INT16           major       = 1;
    INT16           minor       = 0;

    memcpy(m_file_head.HEAD.FILE_FORMAT_VERSION, (void*)&major, 2);
    memcpy(m_file_head.HEAD.FILE_FORMAT_VERSION + 2, (void*)&minor, 2);

    memset(m_file_head.HEAD.DATA_OFFSET, 0xff, 8);

    struct timeval  current;

    int     result      = 0;

    result = gettimeofday(&current, T100NULL);

    if(-1 == result){
        return T100FALSE;
    }
    memcpy(m_file_head.HEAD.TIME_STAMP, (void*)&(current.tv_sec), 4);

    std::string     app         = "vpc ";

    memcpy(m_file_head.HEAD.CREATOR_APPLICATION, app.data(), 4);

    major   = 5;
    minor   = 0;

    memcpy(m_file_head.HEAD.CREATOR_VERSION, (void*)&major, 2);
    memcpy(m_file_head.HEAD.CREATOR_VERSION + 2, (void*)&minor, 2);

    std::string     host        = "Wi2k";

    memcpy(m_file_head.HEAD.CREATOR_HOST_OS, host.data(), 4);

    memcpy(m_file_head.HEAD.ORIGINAL_SIZE, (void*)&m_length, 8);
    memcpy(m_file_head.HEAD.CURRENT_SIZE, (void*)&m_length, 8);

    INT16           cylinder        = 2080;

    memcpy(m_file_head.HEAD.DISK_GEOMETRY, (void*)&cylinder, 2);

    m_file_head.HEAD.DISK_GEOMETRY[2]   = 16;
    m_file_head.HEAD.DISK_GEOMETRY[3]   = 63;


    INT32           type        = 2;

    memcpy(m_file_head.HEAD.DISK_TYPE, (void*)&type, 4);

    m_file_head.HEAD.SAVED_STATE    = 0;

    memset(m_file_head.HEAD.RESERVED, 0, 427);

    GUID    guid;

    HRESULT     value   = CoCreateGuid(&guid);

    if(S_OK == value){
        memcpy(m_file_head.HEAD.UNIQUE_ID, (void*)&guid, 8);
    }else{
        return T100FALSE;
    }

    T100BYTE*       index           = T100NULL;

    T100INT32       total           = 0;
    T100INT32       item;


    index   = m_file_head.HEAD.COOKIE;

    for(int i=0;i<16;i++){
        item    = *index;
        total   += item;

        index   += 4;
    }

    index   += 4;
    for(int i=0;i<5;i++){
        item    = *index;
        total   += item;

        index   += 4;
    }

    memcpy(m_file_head.HEAD.CHECKSUM, (void*)&total, 4);

    return T100TRUE;
}
