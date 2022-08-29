#include "T100FileTools.h"

#include "T100File.h"


T100FileTools::T100FileTools()
{
    //ctor
}

T100FileTools::~T100FileTools()
{
    //dtor
}

T100BOOL T100FileTools::compare(T100String source_name, T100String target_name)
{
    T100File    source(source_name);
    T100File    target(target_name);
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(source.length() == target.length()){
        T100WORD    sdata[1024];
        T100WORD    tdata[1024];
        T100WORD    slength     = 0;
        T100WORD    sindex      = 0;
        T100WORD    tlength     = 0;
        T100WORD    tindex      = 0;
        T100WORD    schar;
        T100WORD    tchar;

        value = source.open(T100FILE_READ);
        if(!value){
            return T100FALSE;
        }
        value = target.open(T100FILE_READ);
        if(!value){
            source.close();
            return T100FALSE;
        }

        do{
            if(sindex >= slength){
                slength = 1024;
                value = source.read(sdata, slength);
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
                value = target.read(tdata, tlength);
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
    }else{
        result = T100FALSE;
    }

    if(!source.close()){
        result = T100FALSE;
    }

    if(!target.close()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100FileTools::load(T100String file, T100WORD_VECTOR& data, T100WORD offset)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100WORD    total;
    T100WORD    index       = 0;
    T100WORD    length;
    T100File    source(file);

    length = source.length();

    total = offset + length;

    if(total > data.size()){
        data.resize(total);
    }

    value = source.open(T100FILE_READ);
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
            value = source.read(buffer, l);
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

    value = source.close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

/*
T100BOOL T100FileTools::load(T100String file, T100WORD_VECTOR& data, T100WORD offset)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100WORD    total;
    T100WORD    index       = 0;
    T100WORD    length;
    T100File    source(file);

    length  = source.length();
    total   = offset + length;

    if(total > data.size()){
        data.resize(total);
    }

    value = source.open(T100FILE_READ);
    if(!value){
        return T100FALSE;
    }

    T100WORD    buffer[1024];
    T100WORD    os;
    T100WORD    l;

    l   = 0;
    os  = offset;

    do{
        if(index >= l){
            l = 1024;
            value = source.read(buffer, l);
            if(value){
                if(0 == l){
                    break;
                }else{
                    index = 0;

                    for(int i = 0;i < l;i++){
                        data.at(os++) = buffer[index++];
                        //index++;
                    }
                }
            }else{
                result = T100FALSE;
                break;
            }
        }
        //else{
        //    data.at(os++) = buffer[index++];
        //}
    }while(T100TRUE);

    value = source.close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}
*/
