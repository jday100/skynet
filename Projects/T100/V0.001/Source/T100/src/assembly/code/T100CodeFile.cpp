#include "T100CodeFile.h"

T100CodeFile::T100CodeFile()
{
    //ctor
}

T100CodeFile::~T100CodeFile()
{
    //dtor
}

T100BOOL T100CodeFile::count(T100SEGMENTDATA_VECTOR& seg, T100WORD& total, T100WORD& length)
{
    T100BOOL    result      = T100TRUE;

    for(auto item : seg){
        if(item){
            total++;
            length += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100CodeFile::count(T100SEGMENTDATA_VECTOR& seg, T100WORD& table, T100WORD& total, T100WORD& length)
{
    T100BOOL    result      = T100TRUE;

    for(auto item : seg){
        if(item){
            table   += item->getName().getRawLength();
            total++;
            length  += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}
