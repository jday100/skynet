#include "T100ExecutableNormalSmallMerger.h"

#include <assert.h>
#include "T100FileData.h"


T100ExecutableNormalSmallMerger::T100ExecutableNormalSmallMerger(T100Code* code)
    :m_code(code)
{
    //ctor
}

T100ExecutableNormalSmallMerger::~T100ExecutableNormalSmallMerger()
{
    //dtor
}

T100FileData* T100ExecutableNormalSmallMerger::run(T100CODEDATA_VECTOR& files)
{
    T100BOOL        result      = T100FALSE;
    T100FileData*   file        = T100NULL;

    file = T100NEW T100FileData(m_code);

    file->m_code    = T100Code::m_code;
    file->m_data    = T100Code::m_data;

    if(T100FALSE == T100Code::m_data_default_flag){
        file->m_data = T100NEW T100SegmentData();
    }

    if(T100NULL == file->m_share_code){
        file->m_share_code = T100NEW T100SegmentCode();
        file->m_share_code->isShare = T100TRUE;
    }

    if(T100NULL == file->m_share_data){
        file->m_share_data = T100NEW T100SegmentData();
        file->m_share_data->isShare = T100TRUE;
    }

    assert(T100Code::m_code != T100NULL);
    assert(file->m_code != T100NULL);
    assert(file->m_data != T100NULL);

    assert(file->m_share_code != T100NULL);
    assert(file->m_share_data != T100NULL);

    for(auto item : files){
        if(!item){
            T100DELETE(file);
            T100AssemblyError::error(T100BUILD_MARGER_FAILURE);
            return T100NULL;
        }

        result = merge(file, item);

        if(!result){
            T100DELETE(file);
            T100AssemblyError::error(T100AssemblyHint::file_hint(item->file.to_std_string(), T100BUILD_MARGER_FAILURE));
            return T100NULL;
        }
    }

    assert(file->m_code != T100NULL);
    assert(file->m_data != T100NULL);

    assert(file->m_share_code != T100NULL);
    assert(file->m_share_data != T100NULL);

    file->m_codes.push_back(file->m_code);
    if(0 != file->m_data->getMem().size())
    file->m_datas.push_back(file->m_data);
    if(1 != file->m_share_code->getMem().size())
    file->m_share_codes.push_back(file->m_share_code);
    if(0 != file->m_share_data->getMem().size())
    file->m_share_datas.push_back(file->m_share_data);

    T100Log::info(T100BUILD_MARGER_SUCCESS);

    return file;
}

T100BOOL T100ExecutableNormalSmallMerger::merge(T100FileData* target, T100FileData* source)
{
    T100BOOL    result      = T100FALSE;

    for(auto item : source->m_codes){
        if(!item){
            return T100FALSE;
        }

        if(decideCode((T100SegmentCode*)target->m_code, (T100SegmentCode*)item)){
            result = mergeCode((T100SegmentCode*)target->m_code, (T100SegmentCode*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    //target->m_codes.push_back(target->m_code);

    for(auto item : source->m_datas){
        if(!item){
            return T100FALSE;
        }

        if(decideData((T100SegmentData*)target->m_data, (T100SegmentData*)item)){
            result = mergeData((T100SegmentData*)target->m_data, (T100SegmentData*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    //target->m_datas.push_back(target->m_data);

    for(auto item : source->m_share_codes){
        if(!item){
            return T100FALSE;
        }

        if(decideCode((T100SegmentCode*)target->m_share_code, (T100SegmentCode*)item)){
            result = mergeCode((T100SegmentCode*)target->m_share_code, (T100SegmentCode*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    //target->m_share_codes.push_back(target->m_share_code);

    for(auto item : source->m_share_datas){
        if(!item){
            return T100FALSE;
        }

        if(decideData((T100SegmentData*)target->m_share_data, (T100SegmentData*)item)){
            result = mergeData((T100SegmentData*)target->m_share_data, (T100SegmentData*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    //target->m_share_datas.push_back(target->m_share_data);

    return T100TRUE;
}

T100BOOL T100ExecutableNormalSmallMerger::decideCode(T100SegmentCode* target, T100SegmentCode* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    if(target->isShare != source->isShare)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100ExecutableNormalSmallMerger::decideData(T100SegmentData* target, T100SegmentData* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    //if(source->m_location != 0)return T100FALSE;

    if(target->isShare != source->isShare)return T100FALSE;

    return T100TRUE;
}

