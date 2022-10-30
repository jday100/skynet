#include "T100Token.h"

namespace T100Component{

T100Token::T100Token()
    :T100Library::T100Class()
{
    //ctor
}

T100Token::~T100Token()
{
    //dtor
}

T100VOID T100Token::clear()
{
    type    = T100TOKEN_NONE;
    eof     = T100FALSE;
    err     = T100ERROR_NONE;
    row     = 0;
}

}
