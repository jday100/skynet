#include "T100CapacityTools.h"

#include <string>


T100CapacityTools::T100CapacityTools()
{
    //ctor
}

T100CapacityTools::~T100CapacityTools()
{
    //dtor
}

T100INT64 T100CapacityTools::parse(T100STRING value)
{
    T100BYTE        byte;
    T100INT32       length;
    T100INT64       result;

    length  = value.length();
    byte    = value[length - 1];

    switch(byte){
    case 'B':
        {
            value.pop_back();
            return stod(value);
        }
        break;
    case 'K':
        {
            value.pop_back();
            T100INT64   item;

            item    = stod(value);
            result  = 1024LL * item;
            return result;
        }
        break;
    case 'M':
        {
            value.pop_back();
            T100INT64   item;

            item    = stod(value);
            result  = 1024LL * 1024 * item;
            return result;
        }
        break;
    case 'G':
        {
            value.pop_back();
            T100INT64   item;

            item    = stod(value);
            result  = 1024LL * 1024 * 1024 * item;
            return result;
        }
        break;
    case 'T':
        {
            value.pop_back();
            T100INT64   item;

            item    = stod(value);
            result  = 1024LL * 1024 * 1024 * 1024 * item;
            return result;
        }
        break;
    default:
        {
            return stod(value);
        }
        break;
    };
}
