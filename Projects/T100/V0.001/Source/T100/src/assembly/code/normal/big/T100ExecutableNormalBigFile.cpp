#include "T100ExecutableNormalBigFile.h"

#include <iostream>
#include <assert.h>


T100ExecutableNormalBigFile::T100ExecutableNormalBigFile()
{
    //ctor
}

T100ExecutableNormalBigFile::~T100ExecutableNormalBigFile()
{
    //dtor
}

T100BOOL T100ExecutableNormalBigFile::load(T100FileData* data)
{
    assert(data != T100NULL);
    assert(data->getCode() != T100NULL);
    assert(data->getData() != T100NULL);

    //m_file      = data;
    //m_code      = data->getCode();
    //m_data      = data->getData();

    return T100TRUE;
}

/*
T100BOOL T100ExecutableNormalBigFile::save(T100STDSTRING file)
{
    T100BOOL    result      = T100FALSE;

    m_ofs = T100NEW std::ofstream(file, std::ios::out | std::ios::binary);

    if(!(m_ofs->is_open())){
        T100DELETE(m_ofs);
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_SUCCESS));

    result = write_head();

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_HEAD_SUCCESS));
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_HEAD_FAILURE));
    }

    if(result)result = write_data();

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_DATA_SUCCESS));
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_DATA_FAILURE));
    }

    if(result)result = write_code();

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_CODE_SUCCESS));
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_CODE_FAILURE));
    }

    m_ofs->close();
    T100DELETE(m_ofs);

    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_CLOSE_SUCCESS));

    return result;
}

T100BOOL T100ExecutableNormalBigFile::write_head()
{
    T100STDCHAR*    data        = T100NULL;
    T100WORD        length      = 0;

    T100EXECUTABLE_FILE_HEAD    head;

    head.COMMON.SIGN    = T100FILE_EXECUTABLE;
    head.CODE_OFFSET    = sizeof(T100EXECUTABLE_FILE_HEAD) / 4;
    head.CODE_LENGTH    = m_code->getMem().size();
    head.DATA_OFFSET    = head.CODE_OFFSET + head.CODE_LENGTH;
    head.DATA_LENGTH    = m_data->getMem().size();

    data    = (char*)&head;
    length  = sizeof(T100EXECUTABLE_FILE_HEAD);

    m_ofs->write(data, length);

    return T100TRUE;
}

T100BOOL T100ExecutableNormalBigFile::write_data()
{
    T100WORD    size;

    if(!m_data){
        return T100TRUE;
    }

    size = m_data->getMem().size() * 4;

    m_ofs->write((char*)(m_data->getMem().data()), size);

    return T100TRUE;
}

T100BOOL T100ExecutableNormalBigFile::write_code()
{
    assert(T100NULL != m_code);

    T100WORD_VECTOR     mem(m_code->getMem());

    for(auto item : m_code->m_variable_call){
        if(item){
            T100WORD        offset;

            offset = item->offset;

            T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(item->name);

            if(vd){
                if(vd->isvirtual){
                    mem[offset] = vd->offset;
                    continue;
                }else{
                    mem[offset] = vd->offset + 2;
                }
            }else{
                T100AssemblyError::error(T100AssemblyHint::variable_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_VARIABLE_NOT_FOUND));
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    T100WORD        os;

    if(m_data){
        os = m_data->getMem().size() + 2;
    }else{
        os = 2;
    }

    for(auto item : m_code->m_label_call){
        if(item){
            T100BOOL    result      = T100FALSE;
            T100WORD    offset;
            T100WORD    value;

            offset = item->offset;

            T100LABEL_DEFINE* ld = T100Code::getLabelDefine(item->name);

            if(ld){
                if(ld->isvirtual)continue;

                value = ld->offset;

                mem[offset] = value + os;
            }else{
                T100AssemblyError::error(T100AssemblyHint::label_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_LABEL_NOT_FOUND));
                return T100FALSE;
            }

        }else{
            return T100FALSE;
        }
    }

    for(auto item : m_code->m_procedure_call){
        if(item){
            T100BOOL    result      = T100FALSE;
            T100WORD    offset;
            T100WORD    value;

            offset = item->offset;

            T100PROCEDURE_DEFINE* pd = T100Code::getProcedureDefine(item->name);

            if(pd){
                value = pd->offset;
                mem[offset] = value + os;
            }else{
                T100AssemblyError::error(T100AssemblyHint::procedure_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_PROCEDURE_NOT_FOUND));
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    T100WORD    size;

    size = mem.size() * 4;
    m_ofs->write((char*)(mem.data()), size);

    return T100TRUE;
}
*/
