#include "T100Math.h"

T100Math::T100Math()
{
    //ctor
}

T100Math::~T100Math()
{
    //dtor
}

float T100Math::level(float in)
{
    float       result;

    if(in >= 0.5){
        result  = 1;
    }else{
        result  = 0;
    }

    return result;
}
