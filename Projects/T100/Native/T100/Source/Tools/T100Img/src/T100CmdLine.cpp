#include "T100CmdLine.h"
#include "T100Img.h"


T100CmdLine::T100CmdLine()
{
    //ctor
}

T100CmdLine::~T100CmdLine()
{
    //dtor
}

int T100CmdLine::run(int argc, char** argv) {
    if(1 < argc){
        return parse(argc, argv);
    }else{
        return 0;
    }
}

int T100CmdLine::parse(int argc, char** argv) {
    char*   cmd     = nullptr;
    char    letter;

    cmd         = argv[1];
    letter      = cmd[0];

    if('-' == letter){
        letter = cmd[1];
        switch(letter){
        case 'c':
            return parse_create(argc, argv);
            break;
        case 'f':
            return parse_format(argc, argv);
            break;
        case 'o':
            return parse_out(argv[2]);
            break;
        }
    }else{
        return -1;
    }
}

int T100CmdLine::parse_in(char* name) {
    m_in_file  = name;
    return 0;
}

int T100CmdLine::parse_out(char* name) {
    m_out_file  = name;
    return 0;
}

int T100CmdLine::parse_create(int argc, char** argv) {
    char*   cmd     = nullptr;
    char    letter;
    int     result  = -1;

    cmd         = argv[2];
    letter      = cmd[0];

    if('-' == letter){
        letter = cmd[1];
        switch(letter){
        case 'o':
            result = parse_out(argv[3]);
            break;
        }

        if(0 == result){
            return create_file(m_out_file);
        }
    }else{
        return -1;
    }
}

int T100CmdLine::parse_format(int argc, char** argv) {
    char*   cmd     = nullptr;
    char    letter;
    int     result  = -1;

    cmd         = argv[2];
    letter      = cmd[0];

    if('-' == letter){
        letter = cmd[1];
        switch(letter){
        case 'i':
            result = parse_in(argv[3]);
            break;
        }

        if(0 == result){
            return format_file(m_in_file);
        }
    }else{
        return -1;
    }
}

int T100CmdLine::create_file(char* file) {
    T100Img         img;

    return img.create(file);
}


int T100CmdLine::format_file(char* file) {
    T100Img         img;

    return img.format(file);
}
