#include "T100String.h"

int crt_str_len(const char* value)
{
    int result  = 0;

    do{
        if(value[result++] == '\0'){
            break;
        }
    }while(true);
    return result;
}
