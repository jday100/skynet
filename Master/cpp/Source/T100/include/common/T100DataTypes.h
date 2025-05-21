#ifndef T100DATATYPES_H
#define T100DATATYPES_H

//常量
#define     T100NULL                nullptr
#define     T100TRUE                true
#define     T100FALSE               false

//数据类型定义
typedef     void                    T100VOID;
typedef     bool                    T100BOOL;

//无符号
typedef     unsigned char           T100BYTE;
typedef     unsigned short          T100HWORD;
typedef     unsigned int            T100WORD;
typedef     unsigned long long      T100DWORD;

//有符号
typedef     char                    T100INT8;
typedef     short                   T100INT16;
typedef     int                     T100INT32;
typedef     long long               T100INT64;

typedef     T100INT32               T100INT;
typedef     T100INT64               T100LONG;
typedef     float                   T100FLOAT;
typedef     double                  T100DOUBLE;

#endif // T100DATATYPES_H
