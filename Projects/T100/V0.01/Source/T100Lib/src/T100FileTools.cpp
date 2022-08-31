#include "T100FileTools.h"

#include "T100File.h"
#include "T100FileReader.h"


T100FileTools::T100FileTools()
{
    //ctor
}

T100FileTools::~T100FileTools()
{
    //dtor
}

T100BOOL T100FileTools::load(T100WSTRING name, T100WORD_VECTOR& data, T100WORD offset)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100WORD            total;
    T100WORD            index           = 0;
    T100WORD            length;
    T100File            file(name);
    T100FileReader*     source          = T100NULL;

    source = file.getReader();
    if(!source){
        return T100FALSE;
    }

    length = file.length();

    total = offset + length;

    if(total > data.size()){
        data.resize(total);
    }

    value = source->open();
    if(!value){
        return T100FALSE;
    }

    T100WORD    buffer[1024];
    T100WORD    os;
    T100WORD    l;

    l = 0;
    os = offset;
    do{
        if(index >= l){
            l = 1024;
            value = source->read(buffer, l);
            if(value){
                if(0 == l){
                    break;
                }else{
                    index = 0;
                }
            }else{
                result = T100FALSE;
                break;
            }
        }

        data.at(os++) = buffer[index++];

    }while(T100TRUE);

    value = source->close();
    if(!value){
        result = T100FALSE;
    }

    T100SAFE_DELETE(source);

    return result;
}

T100BOOL T100FileTools::compare(T100WSTRING source_name, T100WSTRING target_name)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100File            sfile(source_name);
    T100File            tfile(target_name);

    T100FileReader*     source          = T100NULL;
    T100FileReader*     target          = T100NULL;

    if(sfile.length() != tfile.length()){
        return T100FALSE;
    }

    T100WORD        sdata[1024];
    T100WORD        tdata[1024];
    T100WORD        slength         = 0;
    T100WORD        tlength         = 0;
    T100WORD        sindex          = 0;
    T100WORD        tindex          = 0;
    T100WORD        schar;
    T100WORD        tchar;

    source = sfile.getReader();
    if(!source){
        return T100FALSE;
    }

    target = tfile.getReader();
    if(!target){
        T100SAFE_DELETE(source);
        return T100FALSE;
    }

    value = source->open();
    if(!value){
        T100SAFE_DELETE(source);
        T100SAFE_DELETE(target);
        return T100FALSE;
    }

    value = target->open();
    if(!value){
        source->close();

        T100SAFE_DELETE(source);
        T100SAFE_DELETE(target);
        return T100FALSE;
    }

    do{
        if(sindex >= slength){
            slength = 1024;
            value = source->read(sdata, slength);
            if(value){
                if(0 == slength){
                    break;
                }else{
                    sindex = 0;
                }
            }else{
                result = T100FALSE;
                break;
            }
        }
        schar = sdata[sindex++];

        if(tindex >= tlength){
            tlength = 1024;
            value = target->read(tdata, tlength);
            if(value){
                if(0 == tlength){
                    break;
                }else{
                    tindex = 0;
                }
            }else{
                result = T100FALSE;
                break;
            }
        }
        tchar = tdata[tindex++];

        if(schar == tchar){

        }else{
            result = T100FALSE;
            break;
        }
    }while(T100TRUE);

    if(!source->close()){
        result = T100FALSE;
    }

    if(!target->close()){
        result = T100FALSE;
    }

    return result;
}
