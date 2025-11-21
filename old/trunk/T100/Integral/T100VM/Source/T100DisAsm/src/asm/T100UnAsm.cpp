#include "T100UnAsm.h"

#include <io.h>
#include <fstream>
#include <sys/stat.h>
#include "T100InstructActuator.h"

T100UnAsm::T100UnAsm()
{
    //ctor
}

T100UnAsm::~T100UnAsm()
{
    //dtor
}

int T100UnAsm::Execute(T100CmdLineInfo* info)
{
    if(!info){
        return -1;
    }

    struct _stat64      state;

    if(_stat64(info->FILE.c_str(), &state) != 0){
        return -1;
    }

    if(state.st_size < info->OFFSET){
        return -1;
    }

    T100BYTE_VECTOR     data;
    T100UINT            length;
    std::ifstream       ifs(info->FILE, std::ios::in | std::ios::binary);

    length  = state.st_size - info->OFFSET;

    if(!ifs.is_open()){
        return -1;
    }

    ifs.seekg(info->OFFSET);
    data.resize(length);

    int result = ifs.read((char*)data.data(), length).gcount();

    if(result != length){
        ifs.close();
        return -1;
    }
    ifs.close();

    T100InstructActuator        actuator(data);

    actuator.Create();

    return actuator.Parse();
}
