#ifndef T100ASM64COMMON_H
#define T100ASM64COMMON_H

#include "T100Common.h"


typedef enum{
    T100ASCII_NONE                  = -1,
    T100ASCII_NULL                  = 0,
    T100ASCII_TAB                   = 9,
    T100ASCII_LF                    = 10,
    T100ASCII_CR                    = 13,
    T100ASCII_SPACE                 = 32,
    T100ASCII_EXCLAMATION           = 33,
    T100ASCII_DOUBLE_QUOTES         = 34,
    T100ASCII_POUND                 = 35,
    T100ASCII_DOLLAR                = 36,
    T100ASCII_PERCENT               = 37,
    T100ASCII_AND                   = 38,
    T100ASCII_APOSTROPHE            = 39,
    T100ASCII_OPEN_PARENS           = 40,
    T100ASCII_CLOSED_PARENS         = 41,
    T100ASCII_ASTERISK              = 42,
    T100ASCII_PLUS                  = 43,
    T100ASCII_COMMA                 = 44,
    T100ASCII_MINUS                 = 45,
    T100ASCII_DOT                   = 46,
    T100ASCII_SLASH                 = 47,
    T100ASCII_ZERO                  = 48,
    T100ASCII_NINE                  = 57,
    T100ASCII_COLON                 = 58,
    T100ASCII_SEMICOLON             = 59,
    T100ASCII_LESSTHAN              = 60,
    T100ASCII_EQUAL                 = 61,
    T100ASCII_GREATERTHAN           = 62,
    T100ASCII_QUESTION              = 63,
    T100ASCII_EMAIL                 = 64,
    T100ASCII_UPPER_A               = 65,
    T100ASCII_UPPER_Z               = 90,
    T100ASCII_OPEN_BRACKETS         = 91,
    T100ASCII_CLOSED_BRACKETS       = 93,
    T100ASCII_BACKSLASH             = 92,
    T100ASCII_CARET                 = 94,
    T100ASCII_UNDERLINE             = 95,
    T100ASCII_GRAVE                 = 96,
    T100ASCII_LOWER_A               = 97,
    T100ASCII_LOWER_Z               = 122,
    T100ASCII_OPEN_BRACE            = 123,
    T100ASCII_CLOSED_BRACE          = 125,
    T100ASCII_VERTICALBAR           = 124,
    T100ASCII_TILDE                 = 126,
    T100ASCII_MAX
}T100ASCII_TYPE;


typedef enum{
    T100TOKEN_NONE                  = 0,
    T100TOKEN_EOF,
    T100TOKEN_ERROR,
    T100TOKEN_SPACE,
    T100TOKEN_BR,
    //
    T100CHAR_EXCLAMATION,           //!
    T100CHAR_DOUBLE_QUOTES,         //"
    T100CHAR_POUND,                 //#
    T100CHAR_DOLLAR,                //$
    T100CHAR_PERCENT,               //%
    T100CHAR_AND,                   //&
    T100CHAR_APOSTROPHE,            //'
    T100CHAR_OPEN_PARENS,           //(
    T100CHAR_CLOSED_PARENS,         //)
    T100CHAR_ASTERISK,              //*
    T100CHAR_PLUS,                  //+
    T100CHAR_COMMA,                 //,
    T100CHAR_MINUS,                 //-
    T100CHAR_DOT,                   //.
    T100CHAR_SLASH,                 //"/"
    T100CHAR_DIGIT,                 //0~9
    T100CHAR_COLON,                 //:
    T100CHAR_SEMICOLON,             //;
    T100CHAR_LESSTHAN,              //<
    T100CHAR_EQUAL,                 //=
    T100CHAR_GREATERTHAN,           //>
    T100CHAR_QUESTION,              //?
    T100CHAR_EMAIL,                 //@
    T100CHAR_UPPER,                 //A~Z
    T100CHAR_OPEN_BRACKETS,         //[
    T100CHAR_CLOSED_BRACKETS,       //]
    T100CHAR_BACKSLASH,             //"\"
    T100CHAR_CARET,                 //^
    T100CHAR_UNDERLINE,             //_
    T100CHAR_GRAVE,                 //'
    T100CHAR_LOWER,                 //a~z
    T100CHAR_OPEN_BRACE,            //{
    T100CHAR_CLOSED_BRACE,          //}
    T100CHAR_VERTICALBAR,           //|
    T100CHAR_TILDE,                 //~
    T100CHAR_UNICODE
    //
    T100TOKEN_MAX
}T100ASM64_TOKEN_TYPE;



#endif // T100ASM64COMMON_H
