#include "T100CmdLine.h"

#include <iostream>


T100CmdLine::T100CmdLine(int argc, char** argv)
    :m_argc(argc),m_argv(argv),m_status(0)
{
    //ctor
}

T100CmdLine::~T100CmdLine()
{
    //dtor
}

int T100CmdLine::run() {
    int result;

    for(int i=1;i<m_argc;i++){
        char* str = m_argv[i];

        if(nullptr == str){

        }else{
            std::cout << str;

            char letter = str[0];

            switch(letter){
            case '-':
                result = parse(str);
                break;
            default:
                result = parse_string(str);
                break;
            }
        }
    }
    return result;
}

int T100CmdLine::parse(char* str) {
    int     i = 1;
    char    letter;
    int     result;

    do{
        letter = str[i];
        result = parse_value(letter);
        i++;
    }while(0 != letter);

    return result;
}

int T100CmdLine::parse_value(char letter) {
    int result  = 0;

    switch(letter){
    case 'o':
    case 'O':
        m_status        = 1;
        break;
    }

    return result;
}

int T100CmdLine::parse_string(char* str) {
    int result  = 0;

    switch(m_status){
    case 0:
        m_file          = str;
        break;
    case 1:
        m_out           = str;
        m_status        = 0;
        break;
    }

    return result;
}
