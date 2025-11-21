#include "T100BufferToken.h"

namespace T100LIBRARY{

T100BufferToken::T100BufferToken() :
    T100LeafToken()
{
    //ctor
    Type        = T100TOKEN_BUFFER;
}

T100BufferToken::~T100BufferToken()
{
    //dtor
}

}
