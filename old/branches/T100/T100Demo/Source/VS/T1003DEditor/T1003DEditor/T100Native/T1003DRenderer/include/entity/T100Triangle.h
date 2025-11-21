#ifndef T100TRIANGLE_H
#define T100TRIANGLE_H

#include "link/T100Entity.h"

class T100Triangle : public T100Entity
{
    public:
        T100Triangle();
        virtual ~T100Triangle();

        static T100WSTRING          Name;
        static T100UINT             Type;

        virtual T100VOID            Load();

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3f&);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100TRIANGLE_H
