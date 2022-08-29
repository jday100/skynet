#include "T100TestString.h"

#include "T100String.h"

T100STDSTRING       T100TestString::m_unit          = "string";


T100TestString::T100TestString()
    :T100Test(m_unit)
{
    //ctor
}

T100TestString::~T100TestString()
{
    //dtor
}

T100VOID T100TestString::load()
{

}

T100BOOL T100TestString::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_assign()){
        result = T100FALSE;
    }

    if(!test_connect()){
        result = T100FALSE;
    }

    if(!test_traversal()){
        result = T100FALSE;
    }

    if(!test_transform()){
        result = T100FALSE;
    }

    if(!test_data()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestString::test_assign()
{
    T100String  source(U"你好");
    T100CHAR    ni  =   0x4F60;
    T100CHAR    hao =   0x597D;

    if(2 != source.getLength()){
        return T100FALSE;
    }

    if(ni != source[0]){
        return T100FALSE;
    }

    if(hao != source[1]){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100TestString::test_connect()
{
    T100String result;
    T100String nihao(U"你好");
    T100String world(U"世界");
    T100String target(U"你好世界");

    result = nihao + world;

    if(4 != result.getLength()){
        return T100FALSE;
    }

    if(target == result){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100TestString::test_traversal()
{
    T100String  source(U"你好");
    T100CHAR    ni  =   0x4F60;
    T100CHAR    hao =   0x597D;

    if(2 != source.getLength()){
        return T100FALSE;
    }

    if(ni != source[0]){
        return T100FALSE;
    }

    if(hao != source[1]){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100TestString::test_transform()
{
    T100String      source(U"你好");
    T100STDSTRING   stdstring       = u8"你好";
    T100STDSTRING32 stdstring32     = U"你好";
    T100CHAR        ni              =   0x4F60;
    T100CHAR        hao             =   0x597D;

    if(2 != source.getLength()){
        return T100FALSE;
    }

    if(ni != source[0]){
        return T100FALSE;
    }

    if(hao != source[1]){
        return T100FALSE;
    }

    if(source.to_std_string() != stdstring){
        return T100FALSE;
    }

    if(source.to_std_string32() != stdstring32){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100TestString::test_data()
{
    T100String      source(U"你好");
    T100CHAR        ni      =   0x4F60;
    T100CHAR        hao     =   0x597D;

    if(2 != source.getLength()){
        return T100FALSE;
    }

    if(ni != source[0]){
        return T100FALSE;
    }

    if(hao != source[1]){
        return T100FALSE;
    }

    T100WORD* data;

    data = source.getRawData();

    if(T100NULL == data){
        return T100FALSE;
    }

    if(2 != data[0]){
        return T100FALSE;
    }

    if(ni != data[1]){
        return T100FALSE;
    }

    if(hao != data[2]){
        return T100FALSE;
    }

    if(0 != data[3]){
        return T100FALSE;
    }

    if(4 != source.getRawLength()){
        return T100FALSE;
    }

    return T100TRUE;
}
