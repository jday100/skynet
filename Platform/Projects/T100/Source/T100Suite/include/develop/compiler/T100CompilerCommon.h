#ifndef T100COMPILERCOMMON_H
#define T100COMPILERCOMMON_H

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
    //T100ERROR_NONE        = 0,
    //
    T100ERROR_BYTE          = 1,
    T100ERROR_CHAR,
    T100ERROR_STRING,
    T100ERROR_KEYWORD,
    T100ERROR_SENTENCE,
    T100ERROR_SEGMENT,
    T100ERROR_PART,
    //
    T100ERROR_MAX
}T100ASSEMBLY_ERROR_TYPE;

#endif // T100COMPILERCOMMON_H
