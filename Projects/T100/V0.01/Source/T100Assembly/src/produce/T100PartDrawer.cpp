#include "T100PartDrawer.h"
#include "T100PartFile.h"


T100PART_INFO_VECTOR    T100PartDrawer::m_part_vector;
T100PART_INFO_HASH      T100PartDrawer::m_part_hash;


T100PartDrawer::T100PartDrawer()
{
    //ctor
}

T100PartDrawer::~T100PartDrawer()
{
    //dtor
}

T100BOOL T100PartDrawer::exists(T100String name)
{
    T100BOOL                            result          = T100FALSE;
    T100PART_INFO_HASH::iterator        it;

    it = m_part_hash.find(name);

    if(it == m_part_hash.end()){
        result = T100FALSE;
    }else{
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100PartDrawer::append(T100String& name, T100PartInfo* info)
{
    m_part_hash[name] = info;
    m_part_vector.push_back(info);
    return T100TRUE;
}

T100PART_INFO_VECTOR& T100PartDrawer::getPartInfos()
{
    return m_part_vector;
}

T100BOOL T100PartDrawer::load(T100String name, T100PartInfo* info)
{
    T100BOOL                result          = T100TRUE;
    T100String              file;

    T100PartFileReader*     reader          = T100NULL;

    file = getName(name);
    T100PartFile            part(file);

    reader = part.getReader();
    if(!reader){
        return T100FALSE;
    }

    result = reader->load(*info);

    return result;
}

T100BOOL T100PartDrawer::save(T100String name, T100PartInfo* info)
{
    T100BOOL                result          = T100TRUE;
    T100String              file;

    T100PartFileWriter*     writer          = T100NULL;

    file = getName(name);
    T100PartFile            part(file);

    writer = part.getWriter();
    if(!writer){
        return T100FALSE;
    }

    result = writer->save(info);

    return result;
}

T100String T100PartDrawer::getName(T100String name)
{
    return name;
}
