#include "T100FAT.h"

#include "T100Boot.h"


T100FAT::T100FAT()
{
    //ctor
}

T100FAT::~T100FAT()
{
    //dtor
}

int T100FAT::build(T100ImgFile& file){
    T100Boot        boot;

    boot.build(file);
}
