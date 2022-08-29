#include "T100AssemblyHint.h"

#include "T100ByteToken.h"
#include "T100CharToken.h"
#include "T100StringToken.h"
#include "T100KeywordToken.h"
#include "T100SentenceToken.h"
#include "T100SegmentToken.h"
#include "T100Sentence.h"
#include "T100Segment.h"


char*   T100TokenTypeNames[T100TOKEN_MAX+1] = {
    "T100TOKEN_NONE",
    //
    "T100TOKEN_EOF",
    "T100TOKEN_ERROR",
    "T100TOKEN_SPACE",
    "T100TOKEN_BR",
    //
    "T100BYTE_ASCII",
    "T100BYTE_ONE",
    "T100BYTE_TWO",
    "T100BYTE_THREE",
    "T100BYTE_FOUR",
    "T100BYTE_FIVE",
    "T100BYTE_SIX",
    "T100BYTE_SEVEN",
    //
    "T100CHAR_EXCLAMATION",                  //!
    "T100CHAR_DOUBLE_QUOTES",                //"
    "T100CHAR_POUND",                        //#
    "T100CHAR_DOLLAR",                       //$
    "T100CHAR_PERCENT",                      //%
    "T100CHAR_AND",                          //&
    "T100CHAR_CLOSED_SINGLE_QUOTES",         //'
    "T100CHAR_OPEN_PARENS",                  //(
    "T100CHAR_CLOSED_PARENS",                //)
    "T100CHAR_ASTERISK",                     //*
    "T100CHAR_PLUS",                         //+
    "T100CHAR_COMMA",                        //,
    "T100CHAR_MINUS",                        //-
    "T100CHAR_DOT",                          //.
    "T100CHAR_SLASH",                        //"/"
    "T100CHAR_DIGIT",                        //0~9
    "T100CHAR_COLON",                        //:
    "T100CHAR_SEMICOLON",                    //;
    "T100CHAR_LESSTHAN",                     //<
    "T100CHAR_EQUAL",                        //=
    "T100CHAR_GREATERTHAN",                  //>
    "T100CHAR_QUESTION",                     //?
    "T100CHAR_EMAIL",                        //@
    "T100CHAR_UPPER",                        //A~Z
    "T100CHAR_OPEN_BRACKETS",                //[
    "T100CHAR_CLOSED_BRACKETS",              //]
    "T100CHAR_BACKSLASH",                    //"\"
    "T100CHAR_CARET",                        //^
    "T100CHAR_UNDERLINE",                    //_
    "T100CHAR_OPEN_SINGLE_QUOTES",           //'
    "T100CHAR_LOWER",                        //a~z
    "T100CHAR_OPEN_BRACE",                   //{
    "T100CHAR_CLOSED_BRACE",                 //}
    "T100CHAR_VERTICALBAR",                  //|
    "T100CHAR_TILDE",                        //~
    "T100CHAR_UNICODE",
    //
    "T100KEYWORD_INTEGER",
    "T100KEYWORD_FLOAT",
    "T100KEYWORD_STRING",
    //
    "T100KEYWORD_MODE",
    "T100KEYWORD_REAL",
    "T100KEYWORD_NORMAL",
    "T100KEYWORD_TINY",
    "T100KEYWORD_SMALL",
    "T100KEYWORD_BIG",
    "T100KEYWORD_DEFAULT",
    "T100KEYWORD_VIRTUAL",
    "T100KEYWORD_SHARE",
    "T100KEYWORD_LOCATION",
    "T100KEYWORD_LENGTH",
    //
    "T100KEYWORD_IMPORT",
    "T100KEYWORD_CODE",
    "T100KEYWORD_DATA",
    "T100KEYWORD_END",
    "T100KEYWORD_PROCEDURE",
    //
    "T100KEYWORD_COR",
    "T100KEYWORD_CBR",
    "T100KEYWORD_CCR",
    //
    "T100KEYWORD_AAR",
    "T100KEYWORD_ABR",
    "T100KEYWORD_ACR",
    "T100KEYWORD_ADR",
    //
    "T100KEYWORD_ACF",
    "T100KEYWORD_AMF",
    "T100KEYWORD_AOF",
    //
    "T100KEYWORD_LABEL",
    "T100KEYWORD_VARIABLE",
    "T100KEYWORD_COMMENT",
    "T100CONSTANT_INTEGER",
    "T100CONSTANT_FLOAT",
    "T100CONSTANT_STRING",
    //
    "T100KEYWORD_ADD",
    "T100KEYWORD_DIV",
    "T100KEYWORD_MUL",
    "T100KEYWORD_SUB",
    //
    "T100KEYWORD_AND",
    "T100KEYWORD_OR",
    "T100KEYWORD_NOT",
    "T100KEYWORD_XOR",
    //
    "T100KEYWORD_NOP",
    "T100KEYWORD_CMT",
    "T100KEYWORD_DEBUG",
    "T100KEYWORD_LOCK",
    "T100KEYWORD_UNLOCK",
    "T100KEYWORD_HALT",
    //
    "T100KEYWORD_CALL",
    "T100KEYWORD_INT",
    "T100KEYWORD_IRET",
    "T100KEYWORD_JUMP",
    "T100KEYWORD_JNZ",
    "T100KEYWORD_JZ",
    "T100KEYWORD_LOOP",
    "T100KEYWORD_RET",
    //
    "T100KEYWORD_MOV",
    "T100KEYWORD_IN",
    "T100KEYWORD_OUT",
    //
    "T100SENTENCE_MODE",
    "T100SENTENCE_VARIABLE",
    "T100SENTENCE_LABEL",
    "T100SENTENCE_PROCEDURE",
    "T100SENTENCE_IMPORT",
    //
    "T100SENTENCE_CODE",
    "T100SENTENCE_DATA",
    "T100SENTENCE_END",
    //
    "T100SENTENCE_ADD",
    "T100SENTENCE_DIV",
    "T100SENTENCE_MUL",
    "T100SENTENCE_SUB",
    //
    "T100SENTENCE_AND",
    "T100SENTENCE_OR",
    "T100SENTENCE_NOT",
    "T100SENTENCE_XOR",
    //
    "T100SENTENCE_NOP",
    "T100SENTENCE_CMT",
    "T100SENTENCE_DEBUG",
    "T100SENTENCE_LOCK",
    "T100SENTENCE_UNLOCK",
    "T100SENTENCE_HALT",
    //
    "T100SENTENCE_CALL",
    "T100SENTENCE_RET",
    "T100SENTENCE_INT",
    "T100SENTENCE_IRET",
    "T100SENTENCE_JUMP",
    "T100SENTENCE_JNZ",
    "T100SENTENCE_JZ",
    "T100SENTENCE_LOOP",
    //
    "T100SENTENCE_IN",
    "T100SENTENCE_MOVE",
    "T100SENTENCE_OUT",
    //
    "T100SEGMENT_NONE",
    "T100SEGMENT_CODE",
    "T100SEGMENT_DATA",
    "T100SEGMENT_PROCEDURE",
    "T100SEGMENT_IMPORT",
    "T100SEGMENT_MODE",
    //
    "T100FILE_IMPORT",
    "T100FILE_SOURCE",
    //
    "T100TOKEN_MAX"
};


T100BOOL        T100AssemblyHint::m_detail      = T100TRUE;


T100AssemblyHint::T100AssemblyHint()
{
    //ctor
}

T100AssemblyHint::~T100AssemblyHint()
{
    //dtor
}

T100STDSTRING T100AssemblyHint::file_hint(T100STDSTRING file, T100STDSTRING msg)
{
    T100STDSTRING result;

    result = "File: ";
    result += file;
    result += " >> ";

    result += msg;

    return result;
}

T100STDSTRING T100AssemblyHint::byte_hint(T100ByteToken* token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        case T100TOKEN_BR:
            {
                value   = "BR";
                name    = "T100TOKEN_BR";
                break;
            }
        default:
            value   = byte_to_string(token->data);
            name    = token_type_name(token->type);
    };



    result = "Byte: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    return result;
}


T100STDSTRING T100AssemblyHint::byte_to_string(T100BYTE byte)
{
    T100STDSTRING   result;

    switch(byte){
    case 0:
        {
            result = "NUL";
            break;
        }
    case 10:
        {
            result = "LF";
            break;
        }
    case 13:
        {
            result = "CR";
            break;
        }
    case 32:
        {
            result = "SP";
            break;
        }
    default:
        result = byte;
    };

    return result;
}

T100STDSTRING T100AssemblyHint::token_type_name(T100WORD type)
{
    T100STDSTRING   result;

    result = T100TokenTypeNames[type];

    return result;
}

T100STDSTRING T100AssemblyHint::char_hint(T100CharToken* token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        case T100TOKEN_BR:
            {
                value   = "BR";
                name    = "T100TOKEN_BR";
                break;
            }
        default:
            value   = byte_to_string(token->data);
            name    = token_type_name(token->type);
    };



    result = "Char: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    return result;
}

T100STDSTRING T100AssemblyHint::string_hint(T100StringToken* token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->data.to_std_string();
            name    = token_type_name(token->type);
    };

    size = token->data.getLength();


    result = "String: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Size: ";
    result += std::to_string(size);
    result += " ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    return result;
}

T100STDSTRING T100AssemblyHint::keyword_hint(T100KeywordToken* token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->data.to_std_string();
            name    = token_type_name(token->type);
    };

    size = token->data.getLength();


    result = "Keyword: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Size: ";
    result += std::to_string(size);
    result += " ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    return result;
}


T100STDSTRING T100AssemblyHint::build_hint(T100WORD type, T100String data, T100STDSTRING msg)
{
    T100STDSTRING   result;

    if(m_detail){

        result = "Build: ";
        result += token_type_name(type);
        result += " String: ";
        result += data.to_std_string();
        result += " >> ";
        result += msg;
    }

    return result;
}

T100STDSTRING T100AssemblyHint::sentence_hint(T100SentenceToken *token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->data->data.to_std_string();
            name    = token_type_name(token->type);
    };

    if(token->data){
        size = token->data->data.getLength();
    }

    result = "<Sentence>: ";
    result += "[";
    result += value;
    result += "] ";
    //result += "Size: ";
    //result += std::to_string(size);
    //result += " ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += token->tostring();
    }

    return result;
}

T100STDSTRING T100AssemblyHint::sentence_hint(T100Sentence* data, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    result = "<Sentence>: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        //result += token->tostring();
    }

    return result;
}

T100STDSTRING T100AssemblyHint::segment_hint(T100Segment* data, T100STDSTRING msg)
{
    T100STDSTRING   result;

    if(m_detail){

        result = "Build: ";
        result += "File: ";
        result += data->file.to_std_string();
        //result += " Segment: ";
        //result += data->file.getStdString();
        result += " >> ";
        result += msg;
    }

    return result;
}

T100STDSTRING T100AssemblyHint::segment_hint(T100SegmentToken *token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->name.to_std_string();
            name    = token_type_name(token->type);
    };

    size = token->sentences.size();


    result = "<Segment>: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Size: ";
    result += std::to_string(size);
    result += " ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += token->tostring();
    }

    return result;
}

T100STDSTRING T100AssemblyHint::file_hint(T100FileToken* token, T100STDSTRING msg)
{
    T100STDSTRING   result;
    T100STDSTRING   value;
    T100STDSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = "EOF";
                name    = "T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = "ERROR";
                name    = "T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->file.to_std_string();
            name    = token_type_name(token->type);
    };

    size = token->segments.size();


    result = "<File>: ";
    result += "[";
    result += value;
    result += "] ";
    result += "Size: ";
    result += std::to_string(size);
    result += " ";
    result += "Type: ";
    result += name;
    result += " >> ";

    result += msg;

    if(m_detail){
        result += "\n";
        result += token->tostring();
    }

    return result;
}

T100STDSTRING T100AssemblyHint::info_hint(T100STDSTRING msg)
{
    T100STDSTRING   result;

    result =    "=== Build finished: ";
    result +=   "warnings("+std::to_string(1)+"), ";
    result +=   "errors("+std::to_string(1)+") ";
    result +=   "time: ";
    result +=   " ===";

    return result;
}

T100STDSTRING T100AssemblyHint::help_hint(T100STDSTRING msg)
{
    return msg;
}

T100STDSTRING T100AssemblyHint::variable_hint(T100STDSTRING name, T100STDSTRING msg)
{
    T100STDSTRING   result;

    result =    "Variable: ";
    result +=   name;
    result +=   " >> ";
    result +=   msg;

    return result;
}

T100STDSTRING T100AssemblyHint::label_hint(T100STDSTRING name, T100STDSTRING msg)
{
    T100STDSTRING   result;

    result =    "Label: ";
    result +=   name;
    result +=   " >> ";
    result +=   msg;

    return result;
}

T100STDSTRING T100AssemblyHint::procedure_hint(T100STDSTRING name, T100STDSTRING msg)
{
    T100STDSTRING   result;

    result =    "Procedure: ";
    result +=   name;
    result +=   " >> ";
    result +=   msg;

    return result;
}
