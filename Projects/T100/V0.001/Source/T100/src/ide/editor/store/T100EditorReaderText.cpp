#include "T100EditorReaderText.h"

#include "T100File.h"


T100EditorReaderText::T100EditorReaderText()
{
    //ctor
}

T100EditorReaderText::~T100EditorReaderText()
{
    //dtor
}

T100BOOL T100EditorReaderText::load(T100STDSTRING file, T100WORD_VECTOR& data)
{
    T100File    reader(file);
    T100BOOL    result;
    T100WORD    length;

    if(!reader.exists()){
        return T100FALSE;
    }

    length = reader.length();

    data.resize(length);

    if(reader.open(T100FILE_READ)){
        result = reader.read(data.data(), length);
        reader.close();
    }else{
        result = T100FALSE;
    }

    if(result){
        return T100TRUE;
    }

    return T100FALSE;
}
