#include "T100File.h"

#include <stdio.h>

T100File::T100File()
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

void T100File::Read(T100FILE_VECTOR& value)
{
    char* filename = (char*)"text.txt";

    FILE*   file  = fopen(filename, "r");

    if(!file){
        return;
    }

    fread(buffer, size, size, file);
}
