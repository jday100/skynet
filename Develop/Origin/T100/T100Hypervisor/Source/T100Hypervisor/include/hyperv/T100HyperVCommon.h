#ifndef T100HYPERVCOMMON_H
#define T100HYPERVCOMMON_H

#include <iostream>

#define     ENSURE(x)       do { if(!(x)) { std::cerr << L"Error: " #x " is false!" << std::endl; std::exit(1); } } while(0)

#endif // T100HYPERVCOMMON_H
