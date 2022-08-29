#ifndef T100MOUSE_H
#define T100MOUSE_H

#include "T100Device.h"

typedef struct{
    T100BOOL        LEFT;
    T100BOOL        MIDDLE;
    T100BOOL        RIGHT;
    int             WHELL;
    int             X;
    int             Y;
    int             DX;
    int             DY;
}T100MOUSE_DATA;


#define     T100MOUSE_QUEUE     std::queue<T100MOUSE_DATA*>


enum T100MOUSE_MODE{
    T100MOUSEMODE_NONE          = T100DEVICEMODE_MAX,
    T100MOUSEMODE_TYPE,
    T100MOUSEMODE_SET,
    T100MOUSEMODE_GET,
    T100MOUSEMODE_READ,
    T100MOUSEMODE_MAX
};

/*
0:1 获得设备类型
1:4 返回设备类型
//
0:2 设置
//
0:3 读取设备
1:  按键
2:  坐标
3:  偏移量
*/

typedef union{
    struct{
        bool        LEFT:1;
        bool        MIDDLE:1;
        bool        RIGHT:1;
        T100INT     WHELL:16;
    };
    T100WORD        WORD;
}T100MOUSE_BUTTON;

typedef union{
    struct{
        T100INT     X:16;
        T100INT     Y:16;
    };
    T100WORD        WORD;
}T100MOUSE_LOCATION;

typedef union{
    struct{
        T100INT     DX:16;
        T100INT     DY:16;
    };
    T100WORD        WORD;
}T100MOUSE_OFFSET;


class T100Mouse : public T100Device
{
    public:
        T100Mouse(T100QU32*);
        virtual ~T100Mouse();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:

    private:
};

#endif // T100MOUSE_H
