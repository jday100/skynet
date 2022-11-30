#ifndef T100ORDERTYPES_H
#define T100ORDERTYPES_H

#include "T100String.h"

namespace T100Component{

typedef enum{
    T100REGISTER_NONE           = 0,
    //
    T100COR,
    T100CBR,
    T100CCR,
    //
    T100SSR,
    T100SPR,
    //
    T100AAR,
    T100ABR,
    T100ACR,
    T100ADR,
    //
    T100ACF,
    T100AMF,
    T100AOF,
    //
    T100GDR,
    //
    T100REGISTER_MAX
}T100REGISTER_TYPE;

typedef enum{
    T100ORDER_NONE          = 0,
    //
    T100ORDER_ADD,
    T100ORDER_SUB,
    T100ORDER_MUL,
    T100ORDER_DIV,
    //
    T100ORDER_AND,
    T100ORDER_OR,
    T100ORDER_NOT,
    T100ORDER_XOR,
    //
    T100ORDER_LOCK,
    T100ORDER_UNLOCK,
    T100ORDER_HALT,
    //
    T100ORDER_NOP,
    T100ORDER_CMT,
    T100ORDER_DBG,
    //
    T100ORDER_CALL,
    T100ORDER_RETURN,
    T100ORDER_INT,
    T100ORDER_IRET,
    //
    T100ORDER_JUMP,
    T100ORDER_JZ,
    T100ORDER_JNZ,
    T100ORDER_LOOP,
    //
    T100ORDER_PUSH,
    T100ORDER_POP,
    //
    T100ORDER_LGD,
    T100ORDER_ENTER,
    T100ORDER_QUIT,
    //
    T100ORDER_IN,
    T100ORDER_OUT,
    T100ORDER_MOVE,
    //
    T100ORDER_MAX
}T100ORDER_TYPE;

typedef enum{
    T100DATA_NONE           = 0,
    T100DATA_INTEGER,
    T100DATA_FLOAT,
    T100DATA_STRING,
    T100DATA_ALL,
    T100DATA_COR,
    T100DATA_CBR,
    T100DATA_CCR,
    T100DATA_SSR,
    T100DATA_SPR,
    T100DATA_AAR,
    T100DATA_ABR,
    T100DATA_ACR,
    T100DATA_ADR,
    T100DATA_ACF,
    T100DATA_AMF,
    T100DATA_AOF,
    T100DATA_LDG,
    T100DATA_LABEL,
    T100DATA_PROCEDURE,
    T100DATA_VARIABLE,
    T100DATA_MAX
}T100DATA_TYPE;

typedef enum{
    T_NONE          = 1,
    //IMM
    T_IMM,
    //
    T_ALL,
    //
    T_COR,
    T_CBR,
    T_CCR,
    //
    T_SSR,
    T_SPR,
    //
    T_AAR,
    T_ABR,
    T_ACR,
    T_ADR,
    //
    T_ACF,
    T_AMF,
    T_AOF,
    //
    T_LGD,
    //
    //MEM
    T_MEM,
    //
    T_ARR,
    //
    I_COR,
    I_CBR,
    I_CCR,
    //
    I_AAR,
    I_ABR,
    I_ACR,
    I_ADR,
    //
    //IND
    I_MEM,
    //
    I_ARR,
    //
    ST_IMM,
    ST_MEM,
    ST_ARR,
    //
    SI_MEM,
    SI_ARR,
    //
    T_MAX
}T100OPERATE_TYPE;

/*
0       0       @0      #0
a       a       @a      #a
A       A       @A      #A
COR     COR     @COR    #COR
{0}     {0}     @{0}    #{0}
{0:0}   {0:0}   @{0:0}  #{0:0}
{0:0}   {0:0}   {0:@0}  {0:#0}
{0:0}   {0:0}   {@0:0}  {#0:0}
*/
/*
0       IMM     ADD     IND
a       VAl     ADD     IND
A       VAL     ADD     IND
COR     VAl     ADD     IND
{0}     VAl     ADD     IND
{0:0}   VAl     ADD     IND
{0:0}   VAL     VAL     VAL
{0:0}   VAL     VAL     VAL
*/

typedef enum{
    S_NONE          = 0,
    S_ADD,                  //ADDRESS
    S_VAL,                  //VALUE
    S_MAX
}T100SYMBOL_TYPE;

typedef enum{
    A_NONE          = 0,
    A_IMM,                  //IMMEDIATE
    A_MEM,                  //MEMORY
    A_IND,                  //INDIRECT
    A_MAX
}T100ADDRESSING_TYPE;

typedef enum{
    T100OPERATOR_NONE           = 1,
    T100OPERATOR_ONE,
    T100OPERATOR_ONE_ONE,
    T100OPERATOR_ONE_THREE,
    T100OPERATOR_THREE_ONE,
    T100OPERATOR_THREE_THREE,
    T100OPERATOR_MAX
}T100OPERATOR_TYPE;

typedef struct{
    T100BOOL                    ISARRAY         = T100FALSE;
    T100BOOL                    ISSHARE         = T100FALSE;
    T100WORD                    VALUE;
    T100STRING                  NAME;
    T100WORD                    LENGTH;
    T100DATA_TYPE               DATA_TYPE;
    T100SYMBOL_TYPE             ADDR_TYPE       = S_NONE;
    T100BOOL                    USED            = T100FALSE;
}T100OPERATOR;

typedef struct{
    T100OPERATOR                BASE;
    T100OPERATOR                OFFSET;
    T100BOOL                    USED            = T100FALSE;
    T100SYMBOL_TYPE             SYMBOL_TYPE;
    T100OPERATOR_TYPE           TYPE;
}T100OPERATOR_COMPLEXUS;

typedef struct{
    T100OPERATOR_COMPLEXUS      TARGET;
    T100OPERATOR_COMPLEXUS      SOURCE;
    T100OPERATOR_TYPE           TYPE;
}T100OPERATOR_BINOCULAR;

//

typedef struct{
    T100BYTE                    OFFSET              = 0;
    T100BYTE                    TYPE;
    T100BOOL                    BASE_USED           = T100FALSE;
    T100BYTE                    BASE_TYPE;
    T100WORD                    BASE_VALUE;
    T100BOOL                    BASE_FLAG           = T100FALSE;
    T100BYTE                    BASE_OFFSET         = 0;
    T100BOOL                    BASE_ARRAY          = T100FALSE;
    T100WORD                    BASE_INDEX;
    T100BYTE                    OPERATOR_TYPE;
    T100WORD                    OPERATOR_VALUE;
    T100BOOL                    OPERATOR_FLAG       = T100FALSE;
    T100BYTE                    OPERATOR_OFFSET     = 0;
    T100BOOL                    OPERATOR_ARRAY      = T100FALSE;
    T100WORD                    OPERATOR_INDEX;
}T100OPERATOR_BUILD;

typedef struct{
    T100BOOL                    USED;
    T100BYTE                    TYPE;
    T100ADDRESSING_TYPE         ADDR_TYPE;
    T100WORD                    INTERIM_OFFSET      = 0;
    T100WORD                    OFFSET              = 0;
    T100WORD                    VALUE               = 0;
    T100BOOL                    FLAG                = T100FALSE;
    T100BOOL                    ARRAY               = T100FALSE;
    T100WORD                    INDEX;
}T100OPERATOR_SINGLE;

typedef struct{
    T100BOOL                    USED                = T100FALSE;
    T100OPERATOR_SINGLE         BASE;
    T100OPERATOR_SINGLE         OPERATOR;
    T100WORD                    TYPE;
    T100WORD                    VALUE;
}T100OPERATOR_DOUBLE;

typedef struct{
    T100OPERATOR_BUILD          TARGET;
    T100OPERATOR_BUILD          SOURCE;
    T100OPERATOR_TYPE           TYPE;
}T100OPERATOR_INFO;

}

#endif // T100ORDERTYPES_H
