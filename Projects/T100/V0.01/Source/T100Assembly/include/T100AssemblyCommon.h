#ifndef T100ASSEMBLYCOMMON_H
#define T100ASSEMBLYCOMMON_H

#include "T100Common.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100Log.h"
class T100PartInfo;


#define     T100STRING              T100String


enum T100ASCII_TYPE{
    T100ASCII_NONE                      = -1,
    T100ASCII_NULL                      = 0,
    T100ASCII_TAB                       = 9,
    T100ASCII_LF                        = 10,
    T100ASCII_CR                        = 13,
    T100ASCII_SPACE                     = 32,
    T100ASCII_EXCLAMATION               = 33,
    T100ASCII_DOUBLE_QUOTES             = 34,
    T100ASCII_POUND                     = 35,
    T100ASCII_DOLLAR                    = 36,
    T100ASCII_PERCENT                   = 37,
    T100ASCII_AND                       = 38,
    T100ASCII_APOSTROPHE                = 39,
    T100ASCII_OPEN_PARENS               = 40,
    T100ASCII_CLOSED_PARENS             = 41,
    T100ASCII_ASTERISK                  = 42,
    T100ASCII_PLUS                      = 43,
    T100ASCII_COMMA                     = 44,
    T100ASCII_MINUS                     = 45,
    T100ASCII_DOT                       = 46,
    T100ASCII_SLASH                     = 47,
    T100ASCII_ZERO                      = 48,
    T100ASCII_NINE                      = 57,
    T100ASCII_COLON                     = 58,
    T100ASCII_SEMICOLON                 = 59,
    T100ASCII_LESSTHAN                  = 60,
    T100ASCII_EQUAL                     = 61,
    T100ASCII_GREATERTHAN               = 62,
    T100ASCII_QUESTION                  = 63,
    T100ASCII_EMAIL                     = 64,
    T100ASCII_UPPER_A                   = 65,
    T100ASCII_UPPER_Z                   = 90,
    T100ASCII_OPEN_BRACKETS             = 91,
    T100ASCII_CLOSED_BRACKETS           = 93,
    T100ASCII_BACKSLASH                 = 92,
    T100ASCII_CARET                     = 94,
    T100ASCII_UNDERLINE                 = 95,
    T100ASCII_GRAVE                     = 96,
    T100ASCII_LOWER_A                   = 97,
    T100ASCII_LOWER_Z                   = 122,
    T100ASCII_OPEN_BRACE                = 123,
    T100ASCII_CLOSED_BRACE              = 125,
    T100ASCII_VERTICALBAR               = 124,
    T100ASCII_TILDE                     = 126,
    T100ASCII_MAX
};



enum T100ASSEMBLY_TOKEN_TYPE{
    //T100TOKEN_NONE          = 0,
    //
    T100TOKEN_EOF               = 1,
    T100TOKEN_ERROR,
    T100TOKEN_SPACE,
    T100TOKEN_BR,
    //
    T100BYTE_ASCII,
    T100BYTE_ONE,
    T100BYTE_TWO,
    T100BYTE_THREE,
    T100BYTE_FOUR,
    T100BYTE_FIVE,
    T100BYTE_SIX,
    T100BYTE_SEVEN,
    //
    T100CHAR_EXCLAMATION,                  //!
    T100CHAR_DOUBLE_QUOTES,                //"
    T100CHAR_POUND,                        //#
    T100CHAR_DOLLAR,                       //$
    T100CHAR_PERCENT,                      //%
    T100CHAR_AND,                          //&
    T100CHAR_APOSTROPHE,                   //'
    T100CHAR_OPEN_PARENS,                  //(
    T100CHAR_CLOSED_PARENS,                //)
    T100CHAR_ASTERISK,                     //*
    T100CHAR_PLUS,                         //+
    T100CHAR_COMMA,                        //,
    T100CHAR_MINUS,                        //-
    T100CHAR_DOT,                          //.
    T100CHAR_SLASH,                        //"/"
    T100CHAR_DIGIT,                        //0~9
    T100CHAR_COLON,                        //:
    T100CHAR_SEMICOLON,                    //;
    T100CHAR_LESSTHAN,                     //<
    T100CHAR_EQUAL,                        //=
    T100CHAR_GREATERTHAN,                  //>
    T100CHAR_QUESTION,                     //?
    T100CHAR_EMAIL,                        //@
    T100CHAR_UPPER,                        //A~Z
    T100CHAR_OPEN_BRACKETS,                //[
    T100CHAR_CLOSED_BRACKETS,              //]
    T100CHAR_BACKSLASH,                    //"\"
    T100CHAR_CARET,                        //^
    T100CHAR_UNDERLINE,                    //_
    T100CHAR_GRAVE,                        //'
    T100CHAR_LOWER,                        //a~z
    T100CHAR_OPEN_BRACE,                   //{
    T100CHAR_CLOSED_BRACE,                 //}
    T100CHAR_VERTICALBAR,                  //|
    T100CHAR_TILDE,                        //~
    T100CHAR_UNICODE,
    //
    T100KEYWORD_INTEGER,
    T100KEYWORD_FLOAT,
    T100KEYWORD_STRING,
    //
    T100KEYWORD_MODE,
    T100KEYWORD_REAL,
    T100KEYWORD_NORMAL,
    T100KEYWORD_TINY,
    T100KEYWORD_VIRTUAL,
    T100KEYWORD_SHARE,
    T100KEYWORD_LOCATION,
    T100KEYWORD_LENGTH,
    T100KEYWORD_DEFAULT,
    //
    T100KEYWORD_IMPORT,
    T100KEYWORD_CODE,
    T100KEYWORD_DATA,
    T100KEYWORD_END,
    T100KEYWORD_PROCEDURE,
    //
    T100KEYWORD_COR,
    T100KEYWORD_CBR,
    T100KEYWORD_CCR,
    //
    T100KEYWORD_AAR,
    T100KEYWORD_ABR,
    T100KEYWORD_ACR,
    T100KEYWORD_ADR,
    //
    T100KEYWORD_ACF,
    T100KEYWORD_AMF,
    T100KEYWORD_AOF,
    //
    T100KEYWORD_LABEL,
    T100KEYWORD_VARIABLE,
    T100KEYWORD_COMMENT,
    T100CONSTANT_INTEGER,
    T100CONSTANT_FLOAT,
    T100CONSTANT_STRING,
    //
    T100KEYWORD_ADD,
    T100KEYWORD_DIV,
    T100KEYWORD_MUL,
    T100KEYWORD_SUB,
    //
    T100KEYWORD_AND,
    T100KEYWORD_OR,
    T100KEYWORD_NOT,
    T100KEYWORD_XOR,
    //
    T100KEYWORD_NOP,
    T100KEYWORD_CMT,
    T100KEYWORD_DEBUG,
    T100KEYWORD_LOCK,
    T100KEYWORD_UNLOCK,
    T100KEYWORD_HALT,
    //
    T100KEYWORD_CALL,
    T100KEYWORD_INT,
    T100KEYWORD_IRET,
    T100KEYWORD_JUMP,
    T100KEYWORD_JNZ,
    T100KEYWORD_JZ,
    T100KEYWORD_LOOP,
    T100KEYWORD_RETURN,
    //
    T100KEYWORD_MOVE,
    T100KEYWORD_IN,
    T100KEYWORD_OUT,
    //
    T100SENTENCE_MODE,
    T100SENTENCE_VARIABLE,
    T100SENTENCE_LABEL,
    T100SENTENCE_PROCEDURE,
    T100SENTENCE_IMPORT,
    //
    T100SENTENCE_CODE,
    T100SENTENCE_DATA,
    T100SENTENCE_END,
    //
    T100SENTENCE_ADD,
    T100SENTENCE_DIV,
    T100SENTENCE_MUL,
    T100SENTENCE_SUB,
    //
    T100SENTENCE_AND,
    T100SENTENCE_OR,
    T100SENTENCE_NOT,
    T100SENTENCE_XOR,
    //
    T100SENTENCE_NOP,
    T100SENTENCE_CMT,
    T100SENTENCE_DEBUG,
    T100SENTENCE_LOCK,
    T100SENTENCE_UNLOCK,
    T100SENTENCE_HALT,
    //
    T100SENTENCE_CALL,
    T100SENTENCE_RETURN,
    T100SENTENCE_INT,
    T100SENTENCE_IRET,
    T100SENTENCE_JUMP,
    T100SENTENCE_JNZ,
    T100SENTENCE_JZ,
    T100SENTENCE_LOOP,
    //
    T100SENTENCE_IN,
    T100SENTENCE_MOVE,
    T100SENTENCE_OUT,
    //
    T100SEGMENT_NONE,
    T100SEGMENT_CODE,
    T100SEGMENT_DATA,
    T100SEGMENT_PROCEDURE,
    T100SEGMENT_IMPORT,
    T100SEGMENT_MODE,
    //
    T100FILE_IMPORT,
    T100FILE_SOURCE,
    //

    T100TOKEN_MAX
};

enum T100ASSEMBLY_ERROR_TYPE{
    //T100ERROR_NONE          = 0,

    T100ERROR_BYTE          = 1,
    T100ERROR_CHAR,
    T100ERROR_STRING,
    T100ERROR_KEYWORD,
    T100ERROR_SENTENCE,
    T100ERROR_SEGMENT,
    T100ERROR_FILE,

    T100ERROR_MAX
};

#include "T100OrderTypes.h"


typedef struct{
    T100BOOL            isvirtual   = T100FALSE;
    T100BOOL            isshare     = T100FALSE;
    T100String          name;
    T100WORD            value;
    T100WORD            length;
    T100WORD            offset;
    T100DATA_TYPE       type;
    T100BOOL            isarray     = T100FALSE;
}T100VARIABLE_DEFINE;


typedef struct{
    T100BOOL            isvirtual;
    T100BOOL            isshare;
    T100String          name;
    T100WORD            offset;
}T100LABEL_DEFINE;

typedef struct{
    T100String          name;
    T100WORD            offset;
}T100ITEM;


#define     T100SEGMENTDATA_VECTOR      std::vector<T100Segment*>

#define     T100PART_INFO_VECTOR        std::vector<T100PartInfo*>
#define     T100PART_INFO_HASH          std::unordered_map<T100String, T100PartInfo*, T100StringHash, T100StringEqual>

#define     T100VARIABLE_CALL           T100ITEM
#define     T100LABEL_CALL              T100ITEM
#define     T100PROCEDURE_CALL          T100ITEM

#define     T100VARIABLE_HASH           std::unordered_map<T100String, T100VARIABLE_DEFINE*, T100StringHash, T100StringEqual>
#define     T100VARIABLEOFFSET_HASH     std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100VARIABLECALL_VECTOR     std::vector<T100VARIABLE_CALL*>

#define     T100LABEL_HASH              std::unordered_map<T100String, T100LABEL_DEFINE*, T100StringHash, T100StringEqual>
#define     T100LABELOFFSET_HASH        std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100LABElCALL_VECTOR        std::vector<T100LABEL_CALL*>


#define     T100PROCEDURE_DEFINE        T100ITEM
#define     T100PROCEDURE_HASH          std::unordered_map<T100String, T100PROCEDURE_DEFINE*, T100StringHash, T100StringEqual>
#define     T100PROCEDUREOFFSET_HASH    std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100PROCEDURECALL_VECTOR    std::vector<T100PROCEDURE_CALL*>

typedef struct{
    T100String          name;
    T100WORD            location;
}T100SEGMENT_KEY;

/*
typedef enum{
    T100SEGMENT_NONE        = 0,
    T100SEGMENT_CODE,
    T100SEGMENT_DATA,
    T100SEGMENT_MAX
}T100SEGMENT_TYPE;
*/

#endif // T100ASSEMBLYCOMMON_H
