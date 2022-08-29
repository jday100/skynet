#include "T100ExecutableNormalBigBuilder.h"

#include "T100ExecutableNormalBigFile.h"
#include "T100ExecutableNormalBigMerger.h"


T100ExecutableNormalBigBuilder::T100ExecutableNormalBigBuilder()
{
    //ctor
}

T100ExecutableNormalBigBuilder::~T100ExecutableNormalBigBuilder()
{
    //dtor
}

T100BOOL T100ExecutableNormalBigBuilder::save(T100STDSTRING file, T100Code* code)
{
    T100BOOL            result;
    T100FileData*       data        = T100NULL;

    T100ExecutableNormalBigFile         binary;
    T100ExecutableNormalBigMerger       merger(code);

    data = merger.run(code->m_files);
    if(!data){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_SUCCESS));

    result = binary.setData(data);
    if(!result){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_SAVE_FAILURE));
        return T100FALSE;
    }

    result = binary.save(file);

    return result;
}
