#ifndef T100TESTSTRING_H
#define T100TESTSTRING_H

#include "T100Test.h"


class T100TestString : public T100Test
{
    public:
        T100TestString();
        virtual ~T100TestString();

        virtual T100BOOL            test_all();

    protected:
        T100VOID                    load();

        //字符串赋值
        T100BOOL                    test_assign();

        //字符串连接
        T100BOOL                    test_connect();

        //字符遍列
        T100BOOL                    test_traversal();

        //字符串转换
        T100BOOL                    test_transform();

        //字符数据
        T100BOOL                    test_data();

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100TESTSTRING_H
