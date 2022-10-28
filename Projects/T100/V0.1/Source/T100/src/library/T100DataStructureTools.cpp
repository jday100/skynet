#include "T100DataStructureTools.h"

#include <string.h>

namespace T100Library{

T100DataStructureTools::T100DataStructureTools()
    :T100Class()
{
    //ctor
}

T100DataStructureTools::~T100DataStructureTools()
{
    //dtor
}

T100BOOL T100DataStructureTools::to_vector(T100WORD* source, T100WORD length, T100WORD_VECTOR& target)
{
    target.resize(length);

    memcpy(target.data(), source, length * sizeof(T100WORD));

    return T100TRUE;
}

}
