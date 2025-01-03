#include "T100Output.h"

#include "T100Math.h"

T100Output::T100Output()
{
    //ctor
}

T100Output::~T100Output()
{
    //dtor
}

void T100Output::output(float out)
{
    value   = T100Math::level(out);
}

void T100Output::connect(T100Input& input)
{

}
