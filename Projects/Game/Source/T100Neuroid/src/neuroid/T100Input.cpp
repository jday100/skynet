#include "T100Input.h"

#include "T100Math.h"

T100Input::T100Input()
{
    //ctor
}

T100Input::~T100Input()
{
    //dtor
}

void T100Input::value(float in)
{
    m_value = T100Math::level(in);
}
