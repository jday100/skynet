#include "T100Console.h"

#include <string.h>
#include <iostream>


T100Console::T100Console()
{
    //ctor
}

T100Console::~T100Console()
{
    //dtor
}

T100VOID T100Console::setCmdParser(T100CmdParser* cmd)
{
    m_parser = cmd;
}

T100INTEGER T100Console::run(T100INTEGER argc, T100STDCHAR** argv)
{
    T100INTEGER             result      = 0;
    T100COMMAND_VECTOR      cmds;

    load(argc, argv, cmds);
    result = m_parser->parse(cmds);

    shell();
}

T100INTEGER T100Console::run()
{
    return shell();
}

T100INTEGER T100Console::run(T100STDSTRING line)
{
    T100INTEGER             result      = 0;
    T100COMMAND_VECTOR      cmds;

    split(line, cmds);
    result = m_parser->parse(cmds);
    if(!result){
        return result;
    }

    return shell();
}

T100BOOL T100Console::prompt()
{
    T100BOOL    result      = T100FALSE;

    std::cout << T100CONSOLE_PROMPT_DEFAULT;
    result = T100TRUE;

    return result;
}

T100BOOL T100Console::getline(T100STDSTRING& line)
{
    T100STDCHAR     buffer[1024];
    T100STDCHAR*    ptr;

    ptr = buffer;
    gets(ptr);

    line = ptr;

    return T100TRUE;
}

T100BOOL T100Console::split(T100STDSTRING& line, T100COMMAND_VECTOR& cmds)
{
    T100STDCHAR*        source      = T100NULL;
    T100STDCHAR*        item        = T100NULL;
    T100STDSTRING       str;

    source = (T100STDCHAR*)(line.c_str());

    item = ::strtok(source, T100CONSOLE_SEPARATOR_DEFAULT);

    while(T100NULL != item){
        str = item;
        cmds.push_back(str);

        item = ::strtok(T100NULL, T100CONSOLE_SEPARATOR_DEFAULT);
    }

    return T100TRUE;
}

T100BOOL T100Console::load(T100INTEGER argc, T100STDCHAR** argv, T100COMMAND_VECTOR& cmds)
{
    T100STDSTRING       str;

    for(int i=0;i<argc;i++){
        str = argv[i];
        cmds.push_back(str);
    }

    return T100TRUE;
}

T100INTEGER T100Console::shell()
{
    T100INTEGER             result      = 0;
    T100STDSTRING           line;
    T100COMMAND_VECTOR      cmds;

    do{
        result      = 0;
        line.clear();
        cmds.clear();

        prompt();
        getline(line);

        if("quit" == line){
            m_parser->quit();
            break;
        }

        split(line, cmds);
        result = m_parser->parse(cmds);
    }while(T100TRUE);

    return result;
}
