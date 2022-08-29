#include "T100HintQU32.h"

T100HintQU32::T100HintQU32()
{
    //ctor
}

T100HintQU32::~T100HintQU32()
{
    //dtor
}

T100STDSTRING T100HintQU32::vpc_hint(T100STDSTRING msg)
{
    return msg;
}

T100STDSTRING T100HintQU32::order_hint(T100WORD value, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "Order: ";
    result += std::to_string(value);
    result += " >> ";

    result += msg;

    return result;
}

T100STDSTRING T100HintQU32::order_hint(T100WORD base, T100WORD offset, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "Order: ";
    result += "[";
    result += hex(base);
    result += " : ";
    result += hex(offset);
    result += "]";
    result += " >> ";

    result += msg;

    return result;
}

T100STDSTRING T100HintQU32::order_hint(T100WORD base, T100WORD offset, T100OPERATOR_DOUBLE &target, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "Order: ";
    result += "[";
    result += hex(base);
    result += " : ";
    result += hex(offset);
    result += "]";
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += "  [BASE: " + hex(base);
        result += " : ";
        result += "OFFSET: " + hex(offset) + "]";
        result += " \n\tTARGET: ";
        result += "[BASE: " + hex(target.BASE.VALUE);
        result += " : ";
        result += "OFFSET: " + hex(target.OPERATOR.VALUE) + "]";
        //result += " \nDATA: ";
        //result += dec(source.OPERATOR_VALUE);
        //result += "(" + hex(source.OPERATOR_VALUE) + ")";
    }

    return result;
}

T100STDSTRING T100HintQU32::order_hint(T100WORD base, T100WORD offset, T100OPERATOR_DOUBLE &target, T100OPERATOR_DOUBLE &source, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "Order: ";
    result += "[";
    result += hex(base);
    result += " : ";
    result += hex(offset);
    result += "]";
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += "  [BASE: " + hex(base);
        result += " : ";
        result += "OFFSET: " + hex(offset) + "]";
        result += " \n\tTARGET: ";
        result += "[BASE: " + hex(target.BASE.VALUE);
        result += " : ";
        result += "OFFSET: " + hex(target.OPERATOR.VALUE) + "]";
        result += " \n\tSOURCE: ";
        result += "[BASE: " + hex(source.BASE.VALUE);
        result += " : ";
        result += "OFFSET: " + hex(source.OPERATOR.OFFSET) + "]";
        result += " \n\tDATA: ";
        result += dec(source.OPERATOR.VALUE);
        result += "(" + hex(source.OPERATOR.VALUE) + ")";
    }

    return result;
}

T100STDSTRING T100HintQU32::cmt_hint(T100WORD base, T100WORD offset, T100WORD id, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "Order: ";
    result += "[";
    result += hex(base);
    result += " : ";
    result += hex(offset);
    result += "]";
    result += " CMT";
    result += std::to_string(id);
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += "  [BASE: " + hex(base);
        result += " : ";
        result += "OFFSET: " + hex(offset) + "]";
        result += " \n\tDATA: ";
        result += dec(id);
        result += "(" + hex(id) + ")";
    }

    return result;
}
