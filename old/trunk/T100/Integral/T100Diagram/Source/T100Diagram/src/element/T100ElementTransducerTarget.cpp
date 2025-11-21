#include "T100ElementTransducerTarget.h"

T100ElementTransducerTarget::T100ElementTransducerTarget(T100BufferedFileReader* reader) :
    T100DiagramTransducerTarget(reader)
{
    //ctor
}

T100ElementTransducerTarget::T100ElementTransducerTarget(T100BufferedFileWriter* writer) :
    T100DiagramTransducerTarget(writer)
{
    //ctor
}

T100ElementTransducerTarget::~T100ElementTransducerTarget()
{
    //dtor
}
