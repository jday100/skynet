#include "T100Img.h"

#include "T100ImgFile.h"
#include "T100FAT.h"


T100Img::T100Img()
{
    //ctor
}

T100Img::~T100Img()
{
    //dtor
}


int T100Img::create(char* file) {
    T100ImgFile         img;

    return img.create(file);
}

int T100Img::format(char* file) {
    T100ImgFile         img;
    T100FAT             fat;

    if(!img.open(file)){

        fat.build(img);
        img.close();
    }
}
