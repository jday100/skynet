#ifndef T100CALLBACK_H
#define T100CALLBACK_H

#include "T100Common.h"
#include "T100Class.h"
#include "T100DataStructure.h"

#define         T100CALLBACK_VECTOR         std::vector<T100CALLBACK_ENTRY*>

namespace T100Library{

typedef         T100BOOL (*T100CALLBACK)(void*);

typedef         T100BOOL (*T100CALLBACK_HANDLE)(void*, void*, void*, void*, void*);

typedef struct{
    void*                   OBJECT;
    void*                   VALUE;
    T100CALLBACK_HANDLE     HANDLE;
}T100CALLBACK_ENTRY;

class T100Callback : public T100Class
{
    public:
        T100Callback();
        virtual ~T100Callback();

        T100BOOL                append(T100CALLBACK_HANDLE, void*);
        T100BOOL                remove(T100CALLBACK_HANDLE);

        T100BOOL                clear();

        virtual T100BOOL        run(void*);

    protected:
        T100CALLBACK_VECTOR     m_callbacks;

    private:
};

}

#endif // T100CALLBACK_H
