#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementTransducerTarget::T100ElementTransducerTarget(T100Library::T100BufferedFileWriter* writer)
    :T100DiagramTransducerTarget(writer)
{
    //ctor
}

T100ElementTransducerTarget::~T100ElementTransducerTarget()
{
    //dtor
}

}
