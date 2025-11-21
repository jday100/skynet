#include "T100Shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

T100Shell::T100Shell()
{
    //ctor
}

T100Shell::~T100Shell()
{
    //dtor
}

T100INT T100Shell::Run()
{
    std::cout << "$";

    do{
        std::string     value;

        getline(std::cin, value);

        std::cout << value;

        Execute(value);

    }while(1);
}

T100VOID T100Shell::Execute(std::string value)
{
    std::string     command;

    command     = CWD() + "/usr/bin/" + value;

    system(command.c_str());
}

std::string T100Shell::CWD()
{
    char path[_MAX_PATH];

    getcwd(path, sizeof(path));

    std::string     result;

    result  = path;

    return result;
}
