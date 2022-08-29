#include "T100AssemblyHint.h"

#include "T100ByteToken.h"
#include "T100CharToken.h"
#include "T100StringToken.h"
#include "T100KeywordToken.h"
#include "T100SentenceToken.h"
#include "T100SegmentToken.h"
#include "T100PartToken.h"
#include "T100Sentence.h"
#include "T100Segment.h"


wchar_t*   T100TokenTypeNames[T100TOKEN_MAX+1] = {
    L"T100TOKEN_NONE",
    //
    L"T100TOKEN_EOF",
    L"T100TOKEN_ERROR",
    L"T100TOKEN_SPACE",
    L"T100TOKEN_BR",
    //
    L"T100BYTE_ASCII",
    L"T100BYTE_ONE",
    L"T100BYTE_TWO",
    L"T100BYTE_THREE",
    L"T100BYTE_FOUR",
    L"T100BYTE_FIVE",
    L"T100BYTE_SIX",
    L"T100BYTE_SEVEN",
    //
    L"T100CHAR_EXCLAMATION",                  //!
    L"T100CHAR_DOUBLE_QUOTES",                //"
    L"T100CHAR_POUND",                        //#
    L"T100CHAR_DOLLAR",                       //$
    L"T100CHAR_PERCENT",                      //%
    L"T100CHAR_AND",                          //&
    L"T100CHAR_CLOSED_SINGLE_QUOTES",         //'
    L"T100CHAR_OPEN_PARENS",                  //(
    L"T100CHAR_CLOSED_PARENS",                //)
    L"T100CHAR_ASTERISK",                     //*
    L"T100CHAR_PLUS",                         //+
    L"T100CHAR_COMMA",                        //,
    L"T100CHAR_MINUS",                        //-
    L"T100CHAR_DOT",                          //.
    L"T100CHAR_SLASH",                        //"/"
    L"T100CHAR_DIGIT",                        //0~9
    L"T100CHAR_COLON",                        //:
    L"T100CHAR_SEMICOLON",                    //;
    L"T100CHAR_LESSTHAN",                     //<
    L"T100CHAR_EQUAL",                        //=
    L"T100CHAR_GREATERTHAN",                  //>
    L"T100CHAR_QUESTION",                     //?
    L"T100CHAR_EMAIL",                        //@
    L"T100CHAR_UPPER",                        //A~Z
    L"T100CHAR_OPEN_BRACKETS",                //[
    L"T100CHAR_CLOSED_BRACKETS",              //]
    L"T100CHAR_BACKSLASH",                    //"\"
    L"T100CHAR_CARET",                        //^
    L"T100CHAR_UNDERLINE",                    //_
    L"T100CHAR_OPEN_SINGLE_QUOTES",           //'
    L"T100CHAR_LOWER",                        //a~z
    L"T100CHAR_OPEN_BRACE",                   //{
    L"T100CHAR_CLOSED_BRACE",                 //}
    L"T100CHAR_VERTICALBAR",                  //|
    L"T100CHAR_TILDE",                        //~
    L"T100CHAR_UNICODE",
    //
    L"T100KEYWORD_INTEGER",
    L"T100KEYWORD_FLOAT",
    L"T100KEYWORD_STRING",
    //
    L"T100KEYWORD_MODE",
    L"T100KEYWORD_REAL",
    L"T100KEYWORD_TINY",
    L"T100KEYWORD_VIRTUAL",
    L"T100KEYWORD_LOCATION",
    L"T100KEYWORD_LENGTH",
    L"T100KEYWORD_DEFAULT",
    //
    L"T100KEYWORD_IMPORT",
    L"T100KEYWORD_CODE",
    L"T100KEYWORD_DATA",
    L"T100KEYWORD_END",
    L"T100KEYWORD_PROCEDURE",
    //
    L"T100KEYWORD_COR",
    L"T100KEYWORD_CBR",
    L"T100KEYWORD_CCR",
    //
    L"T100KEYWORD_AAR",
    L"T100KEYWORD_ABR",
    L"T100KEYWORD_ACR",
    L"T100KEYWORD_ADR",
    //
    L"T100KEYWORD_ACF",
    L"T100KEYWORD_AMF",
    L"T100KEYWORD_AOF",
    //
    L"T100KEYWORD_LABEL",
    L"T100KEYWORD_VARIABLE",
    L"T100KEYWORD_COMMENT",
    L"T100CONSTANT_INTEGER",
    L"T100CONSTANT_FLOAT",
    L"T100CONSTANT_STRING",
    //
    L"T100KEYWORD_ADD",
    L"T100KEYWORD_DIV",
    L"T100KEYWORD_MUL",
    L"T100KEYWORD_SUB",
    //
    L"T100KEYWORD_AND",
    L"T100KEYWORD_OR",
    L"T100KEYWORD_NOT",
    L"T100KEYWORD_XOR",
    //
    L"T100KEYWORD_NOP",
    L"T100KEYWORD_CMT",
    L"T100KEYWORD_DEBUG",
    L"T100KEYWORD_LOCK",
    L"T100KEYWORD_UNLOCK",
    L"T100KEYWORD_HALT",
    //
    L"T100KEYWORD_CALL",
    L"T100KEYWORD_INT",
    L"T100KEYWORD_IRET",
    L"T100KEYWORD_JUMP",
    L"T100KEYWORD_JNZ",
    L"T100KEYWORD_JZ",
    L"T100KEYWORD_LOOP",
    L"T100KEYWORD_RET",
    //
    L"T100KEYWORD_MOV",
    L"T100KEYWORD_IN",
    L"T100KEYWORD_OUT",
    //
    L"T100SENTENCE_MODE",
    L"T100SENTENCE_VARIABLE",
    L"T100SENTENCE_LABEL",
    L"T100SENTENCE_PROCEDURE",
    L"T100SENTENCE_IMPORT",
    //
    L"T100SENTENCE_CODE",
    L"T100SENTENCE_DATA",
    L"T100SENTENCE_END",
    //
    L"T100SENTENCE_ADD",
    L"T100SENTENCE_DIV",
    L"T100SENTENCE_MUL",
    L"T100SENTENCE_SUB",
    //
    L"T100SENTENCE_AND",
    L"T100SENTENCE_OR",
    L"T100SENTENCE_NOT",
    L"T100SENTENCE_XOR",
    //
    L"T100SENTENCE_NOP",
    L"T100SENTENCE_CMT",
    L"T100SENTENCE_DEBUG",
    L"T100SENTENCE_LOCK",
    L"T100SENTENCE_UNLOCK",
    L"T100SENTENCE_HALT",
    //
    L"T100SENTENCE_CALL",
    L"T100SENTENCE_RET",
    L"T100SENTENCE_INT",
    L"T100SENTENCE_IRET",
    L"T100SENTENCE_JUMP",
    L"T100SENTENCE_JNZ",
    L"T100SENTENCE_JZ",
    L"T100SENTENCE_LOOP",
    //
    L"T100SENTENCE_IN",
    L"T100SENTENCE_MOVE",
    L"T100SENTENCE_OUT",
    //
    L"T100SEGMENT_NONE",
    L"T100SEGMENT_CODE",
    L"T100SEGMENT_DATA",
    L"T100SEGMENT_PROCEDURE",
    L"T100SEGMENT_IMPORT",
    L"T100SEGMENT_MODE",
    //
    L"T100FILE_IMPORT",
    L"T100FILE_SOURCE",
    //
    L"T100TOKEN_MAX"
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

T100WSTRING T100AssemblyHint::file_hint(T100WSTRING file, T100WSTRING msg)
{
    T100WSTRING result;

    result = L"File: ";
    result += file;
    result += L" >> ";

    result += msg;

    return result;
}

T100WSTRING T100AssemblyHint::byte_hint(T100ByteToken* token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        case T100TOKEN_BR:
            {
                value   = L"BR";
                name    = L"T100TOKEN_BR";
                break;
            }
        default:
            value   = byte_to_string(token->value);
            name    = token_type_name(token->type);
    };



    result = L"Byte: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    return result;
}


T100WSTRING T100AssemblyHint::byte_to_string(T100BYTE byte)
{
    T100WSTRING   result;

    switch(byte){
    case 0:
        {
            result = L"NUL";
            break;
        }
    case 10:
        {
            result = L"LF";
            break;
        }
    case 13:
        {
            result = L"CR";
            break;
        }
    case 32:
        {
            result = L"SP";
            break;
        }
    default:
        result = byte;
    };

    return result;
}

T100WSTRING T100AssemblyHint::token_type_name(T100WORD type)
{
    T100WSTRING   result;

    result = T100TokenTypeNames[type];

    return result;
}

T100WSTRING T100AssemblyHint::char_hint(T100CharToken* token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        case T100TOKEN_BR:
            {
                value   = L"BR";
                name    = L"T100TOKEN_BR";
                break;
            }
        default:
            value   = byte_to_string(token->value);
            name    = token_type_name(token->type);
    };



    result = L"Char: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    return result;
}

T100WSTRING T100AssemblyHint::string_hint(T100StringToken* token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->value.to_wstring();
            name    = token_type_name(token->type);
    };

    size = token->value.length();


    result = L"String: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Size: ";
    result += std::to_wstring(size);
    result += L" ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    return result;
}

T100WSTRING T100AssemblyHint::keyword_hint(T100KeywordToken* token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->value.to_wstring();
            name    = token_type_name(token->type);
    };

    size = token->value.length();


    result = L"Keyword: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Size: ";
    result += std::to_wstring(size);
    result += L" ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    return result;
}


T100WSTRING T100AssemblyHint::build_hint(T100WORD type, T100String data, T100WSTRING msg)
{
    T100WSTRING   result;

    if(m_detail){

        result = L"Build: ";
        result += token_type_name(type);
        result += L" String: ";
        result += data.to_wstring();
        result += L" >> ";
        result += msg;
    }

    return result;
}

T100WSTRING T100AssemblyHint::sentence_hint(T100SentenceToken *token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->value->value.to_wstring();
            name    = token_type_name(token->type);
    };

    if(token->value){
        size = token->value->value.length();
    }

    result = L"<Sentence>: ";
    result += L"[";
    result += value;
    result += L"] ";
    //result += "Size: ";
    //result += std::to_string(size);
    //result += " ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    if(m_detail){
        result += L"\n";
        //result += token->tostring();
    }

    return result;
}

T100WSTRING T100AssemblyHint::sentence_hint(T100Sentence* data, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    result = L"<Sentence>: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    if(m_detail){
        result += L"\n";
        //result += token->tostring();
    }

    return result;
}

T100WSTRING T100AssemblyHint::segment_hint(T100Segment* data, T100WSTRING msg)
{
    T100WSTRING   result;

    if(m_detail){

        result = L"Build: ";
        result += L"File: ";
        //result += data->file.to_wstring();
        //result += " Segment: ";
        //result += data->file.getStdString();
        result += L" >> ";
        result += msg;
    }

    return result;
}

T100WSTRING T100AssemblyHint::segment_hint(T100SegmentToken *token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->name.to_wstring();
            name    = token_type_name(token->type);
    };

    size = token->sentences.size();


    result = L"<Segment>: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Size: ";
    result += std::to_wstring(size);
    result += L" ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    if(m_detail){
        result += L"\n";
        //result += token->tostring();
    }

    return result;
}

T100WSTRING T100AssemblyHint::file_hint(T100PartToken* token, T100WSTRING msg)
{
    T100WSTRING   result;
    T100WSTRING   value;
    T100WSTRING   name;
    T100WORD        size;

    switch(token->type){
        case T100TOKEN_EOF:
            {
                value   = L"EOF";
                name    = L"T100TOKEN_EOF";
                break;
            }
        case T100TOKEN_ERROR:
            {
                value   = L"ERROR";
                name    = L"T100TOKEN_ERROR";
                break;
            }
        default:
            value   = token->file.to_wstring();
            name    = token_type_name(token->type);
    };

    size = token->segments.size();


    result = L"<File>: ";
    result += L"[";
    result += value;
    result += L"] ";
    result += L"Size: ";
    result += std::to_wstring(size);
    result += L" ";
    result += L"Type: ";
    result += name;
    result += L" >> ";

    result += msg;

    if(m_detail){
        result += L"\n";
        //result += token->tostring();
    }

    return result;
}

T100WSTRING T100AssemblyHint::info_hint(T100WSTRING msg)
{
    T100WSTRING   result;

    result =    L"=== Build finished: ";
    result +=   L"warnings("+std::to_wstring(1)+L"), ";
    result +=   L"errors("+std::to_wstring(1)+L") ";
    result +=   L"time: ";
    result +=   L" ===";

    return result;
}

T100WSTRING T100AssemblyHint::help_hint(T100WSTRING msg)
{
    return msg;
}

T100WSTRING T100AssemblyHint::variable_hint(T100WSTRING name, T100WSTRING msg)
{
    T100WSTRING   result;

    result =    L"Variable: ";
    result +=   name;
    result +=   L" >> ";
    result +=   msg;

    return result;
}

T100WSTRING T100AssemblyHint::label_hint(T100WSTRING name, T100WSTRING msg)
{
    T100WSTRING   result;

    result =    L"Label: ";
    result +=   name;
    result +=   L" >> ";
    result +=   msg;

    return result;
}

T100WSTRING T100AssemblyHint::procedure_hint(T100WSTRING name, T100WSTRING msg)
{
    T100WSTRING   result;

    result =    L"Procedure: ";
    result +=   name;
    result +=   L" >> ";
    result +=   msg;

    return result;
}
