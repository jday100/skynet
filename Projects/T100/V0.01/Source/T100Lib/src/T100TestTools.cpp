#include "T100TestTools.h"

T100TestTools::T100TestTools()
{
    //ctor
}

T100TestTools::~T100TestTools()
{
    //dtor
}

T100BOOL T100TestTools::CleanAndCreate(T100File& file)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = file.exists();
    if(value){
        value = file.remove();
        if(value){
            value = file.exists();
            if(value){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    value = file.create();
    result = value;

    return result;
}
