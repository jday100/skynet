#include "T100VHD.h"

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "T100ByteTools.h"

#include <windows.h>

#include "T100VHDTest.h"
#include "T100VHDCallback.h"


typedef union{
    T100BYTE        DATA[16];
    GUID            VALUE;
}T100GUID_MIX;


T100VHD::T100VHD(T100STRING file, T100INT64 length)
    :T100VHDBase(), m_filename(file), m_length(length)
{
    //ctor
}

T100VHD::~T100VHD()
{
    //dtor
}

T100VOID T100VHD::setValue(T100VOID* value)
{
    m_value     = value;
}

T100BOOL T100VHD::setCookie()
{
    T100STRING      cookie      = "conectix";

    memcpy(m_file_head.FOOTER.COOKIE, cookie.data(), 8);

    return T100TRUE;
}

T100BOOL T100VHD::setFeatures()
{
    m_file_head.FOOTER.FEATURES = 0;
    return T100TRUE;
}

T100BOOL T100VHD::setFileFormatVersion()
{
    T100INT16       major       = 1;
    T100INT16       minor       = 0;

    T100INT16       value;

    value   = T100ByteTools::swop(major);
    m_file_head.FOOTER.FILE_FORMAT_MAJOR    = value;
    m_file_head.FOOTER.FILE_FORMAT_MINOR    = minor;

    return T100TRUE;
}

T100BOOL T100VHD::setDataOffset()
{
    memset(m_file_head.FOOTER.DATA_OFFSET, 0xff, 8);
    return T100TRUE;
}

T100BOOL T100VHD::setTimeStamp()
{
    int     result      = 0;
    struct timeval      current;

    result  = gettimeofday(&current, T100NULL);

    if(-1 == result){
        return T100FALSE;
    }

    T100INT32       value;

    value   = current.tv_sec;
    m_file_head.FOOTER.TIME_STAMP   = T100ByteTools::swop(value);

    return T100TRUE;
}

T100BOOL T100VHD::setCreateApplication()
{
    T100STRING      app     = "qzf ";

    memcpy(m_file_head.FOOTER.CREATE_APPLICATION, app.data(), 4);

    return T100TRUE;
}

T100BOOL T100VHD::setCreateVersion()
{
    T100INT16       major       = 5;
    T100INT16       minor       = 0;

    m_file_head.FOOTER.CREATE_VERSION_MAJOR = T100ByteTools::swop(major);
    m_file_head.FOOTER.CREATE_VERSION_MINOR = minor;

    return T100TRUE;
}

T100BOOL T100VHD::setCreateHostOS()
{
    T100STRING      host        = "Wi2k";

    memcpy(m_file_head.FOOTER.CREATE_HOST_OS, host.data(), 4);

    return T100TRUE;
}

T100BOOL T100VHD::setOriginalSize()
{
    m_file_head.FOOTER.ORIGINAL_SIZE    = T100ByteTools::swop(m_length);
    return T100TRUE;
}

T100BOOL T100VHD::setCurrentSize()
{
    m_file_head.FOOTER.CURRENT_SIZE     = T100ByteTools::swop(m_length);
    return T100TRUE;
}

T100BOOL T100VHD::setDiskGeometry()
{
    T100INT16       cylinder;

    m_file_head.FOOTER.DISK_GEOMETRY_HEADS      = 16;
    m_file_head.FOOTER.DISK_GEOMETRY_SECTORS    = 63;

    cylinder    = m_length / (16 * 63 * 512);

    m_file_head.FOOTER.DISK_GEOMETRY_CYLINDER   = T100ByteTools::swop(cylinder);

    return T100TRUE;
}

T100BOOL T100VHD::setDiskType()
{
    T100INT32       type        = 2;

    m_file_head.FOOTER.DISK_TYPE    = T100ByteTools::swop(type);

    return T100TRUE;
}

T100BOOL T100VHD::setUniqueID()
{
    GUID        guid;
    GUID        value;

    HRESULT     result  = CoCreateGuid(&guid);

    if(S_OK == result){
        T100GUID_MIX        source;
        T100GUID_MIX        target;

        source.VALUE    = guid;

        T100ByteTools::swop(source.DATA, target.DATA, 16);

        m_file_head.FOOTER.UNIQUE_ID    = target.VALUE;

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VHD::setSavedState()
{
    m_file_head.FOOTER.SAVED_STATE  = 0;
    return T100TRUE;
}

T100BOOL T100VHD::setCheckSum()
{
    T100BYTE*       index       = T100NULL;
    T100INT32       total       = 0;

    index   = m_file_head.FOOTER.COOKIE;

    for(int i=0;i<512;i++){
        total   += index[i];
    }

    m_file_head.FOOTER.CHECKSUM = T100ByteTools::swop(~total);

    return T100TRUE;
}

T100BOOL T100VHD::create(T100VHD_STORAGE_TYPE type)
{
    T100BOOL        result;

    m_disk  = T100NEW T100File(m_filename);

    result  = m_disk->create();

    if(result){
        result  = m_disk->state_seek(m_length, (T100FILE_CALLBACK)((T100VHDCallback*)m_callback)->getCreateCallback(), m_value);

        if(result){
            switch(type){
            case T100VHD_STORAGE_TYPE_FIXED:
                {
                    result  = fixed();
                }
                break;
            case T100VHD_STORAGE_TYPE_DYNAMIC:
                {
                    result  = dynamic();
                }
                break;
            default:
                result  = T100FALSE;
            }

            if(result){
                result  = m_disk->write(m_file_head.DATA, 512);
            }
        }

        if(result){
            result  = m_disk->close();
            if(result){
                m_callback->create_finished(m_value, 0);
            }
        }else{
            result  = m_disk->remove();
        }
    }

    return result;
}

T100VOID T100VHD::cancel()
{
    m_disk->state_cancel();
}

T100BOOL T100VHD::fixed()
{
    T100BOOL        result;

    memset(m_file_head.DATA, 0, 512);

    result  = setCookie();
    if(!result){
        return T100FALSE;
    };

    result  = setFeatures();
    if(!result){
        return T100FALSE;
    };

    result  = setFileFormatVersion();
    if(!result){
        return T100FALSE;
    };

    result  = setDataOffset();
    if(!result){
        return T100FALSE;
    };

    result  = setTimeStamp();
    if(!result){
        return T100FALSE;
    };

    result  = setCreateApplication();
    if(!result){
        return T100FALSE;
    };

    result  = setCreateVersion();
    if(!result){
        return T100FALSE;
    };

    result  = setCreateHostOS();
    if(!result){
        return T100FALSE;
    };

    result  = setOriginalSize();
    if(!result){
        return T100FALSE;
    };

    result  = setCurrentSize();
    if(!result){
        return T100FALSE;
    };

    result  = setDiskGeometry();
    if(!result){
        return T100FALSE;
    };

    result  = setDiskType();
    if(!result){
        return T100FALSE;
    };

    result  = setUniqueID();
    if(!result){
        return T100FALSE;
    };

    result  = setSavedState();
    if(!result){
        return T100FALSE;
    };

    result  = setCheckSum();
    if(!result){
        return T100FALSE;
    };

    return T100TRUE;
}

T100BOOL T100VHD::create1(T100VHD_STORAGE_TYPE type)
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


T100BOOL T100VHD::fixed1()
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

T100BOOL T100VHD::dynamic()
{
    return T100FALSE;
}
