#include "T100HintLib.h"

#include "T100StringTools.h"
#include "T100File.h"


T100HintLib::T100HintLib()
{
    //ctor
}

T100HintLib::~T100HintLib()
{
    //dtor
}

T100STDSTRING T100HintLib::file_hint(T100File* file, T100WORD* data, T100WORD length, T100STDSTRING msg)
{
    T100STDSTRING   result;

    result  =   "T100File::";
    result  +=  msg + "\n";

    result  +=  "\t";
    result  +=  "File name : ";
    result  +=  file->m_file.to_std_string();
    result  +=  "\n";

    result  +=  "\t";
    result  +=  "Seek : ";
    result  +=  T100StringTools::to_string(file->m_seek);
    result  +=  "\n";

    if(m_detail){


    }else{
        T100WORD size;

        size = length > 64 ? 64 : length;

        result  +=  "\t";
        result  +=  "Data : [";

        for(T100WORD i = 0;i < size;i++){
            result  +=  hex(data[i]);
        }

        result  +=  "]";
        result  +=  "\n";
    }

    return result;
}

T100STDSTRING T100HintLib::file_hint(T100File* file, T100STDSTRING msg)
{
    T100STDSTRING   result;

    result  =   msg;
    result  +=  file->m_file.to_std_string();
    result  +=  "\n";

    return result;
}
