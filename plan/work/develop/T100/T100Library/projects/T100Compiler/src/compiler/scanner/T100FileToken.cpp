#include "T100FileToken.h"

namespace T100LIBRARY{

T100FileToken::T100FileToken() :
    T100LeafToken()
{
    //ctor
    Type        = T100TOKEN_FILE;
}

T100FileToken::~T100FileToken()
{
    //dtor
}

}
