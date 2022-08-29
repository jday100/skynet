#ifndef T100CALLBACK_H
#define T100CALLBACK_H

#include "T100Common.h"


typedef     T100BOOL (*T100CALLBACK_HANDLE)(void*, void*, void*, void*);

typedef struct{
    void*                   VIEW;
    void*                   SERVE;
    void*                   DATA;
    T100CALLBACK_HANDLE     HANDLE;
}T100CALLBACK_ITEM;

#define     T100CALLBACK_VECTOR         std::vector<T100CALLBACK_ITEM*>


class T100Callback
{
    public:
        T100Callback();
        virtual ~T100Callback();

        T100BOOL                    add(T100CALLBACK_HANDLE, void*, void*, void*);
        T100BOOL                    remove(T100CALLBACK_HANDLE);
        T100BOOL                    clear();

        virtual T100BOOL            run(void*);

    protected:

    private:
        T100CALLBACK_VECTOR         m_callbacks;
};

#endif // T100CALLBACK_H
