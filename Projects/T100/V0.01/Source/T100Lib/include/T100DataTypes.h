#ifndef T100DATATYPES_H
#define T100DATATYPES_H

//常量
#define     T100NULL            nullptr
#define     T100TRUE            true
#define     T100FALSE           false

//数据类型定义
typedef     void                    T100VOID;

typedef     bool                    T100BOOL;

//无符号
typedef     unsigned char           T100BYTE;
typedef     unsigned short          T100HWORD;
typedef     unsigned int            T100WORD;
typedef     unsigned long long      T100DWORD;

//有符号
typedef     int                     T100INT;
typedef     long long               T100LONG;


typedef     float                   T100FLOAT;


//位操作结构体
typedef union{
    T100BYTE        BYTE;
    struct{
        T100BOOL    BIT0 : 1;
        T100BOOL    BIT1 : 1;
        T100BOOL    BIT2 : 1;
        T100BOOL    BIT3 : 1;
        T100BOOL    BIT4 : 1;
        T100BOOL    BIT5 : 1;
        T100BOOL    BIT6 : 1;
        T100BOOL    BIT7 : 1;
    };
}T100BYTE_BITS;


typedef union{
    T100HWORD               HWORD;
    struct{
        T100BYTE_BITS       BYTE_LOW;
        T100BYTE_BITS       BYTE_HIGH;
    };
}T100HWORD_BITS;


typedef union{
    T100WORD                WORD;
    struct{
        T100HWORD_BITS      HWORD_LOW;
        T100HWORD_BITS      HWORD_HIGH;
    };
    struct{
        T100BYTE_BITS       BYTE0;
        T100BYTE_BITS       BYTE1;
        T100BYTE_BITS       BYTE2;
        T100BYTE_BITS       BYTE3;
    };
}T100WORD_BITS;


typedef union{
    T100DWORD               DWORD;
    struct{
        T100WORD_BITS       WORD_LOW;
        T100WORD_BITS       WORD_HIGH;
    };
}T100DWORD_BITS;


#endif // T100DATATYPES_H
