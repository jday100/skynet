#ifndef T1003DOBJECT_H
#define T1003DOBJECT_H

#include <vector>
#include "T100Common.h"
#include "vector/T100Vector3f.h"

class T100Instance;

#define     T1003DOBJECT_VECTOR             std::vector<T1003DObject*>

class T1003DObject
{
    public:
        T1003DObject();
        virtual ~T1003DObject();

        T100WSTRING             Name;
        T100UINT                Type;

        virtual T100VOID        SetPosition(T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100VOID        SetPosition(T100Vector3f&) = 0;
        T100Vector3f&           GetPosition();

        virtual T100VOID        SetRotation(T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100VOID        SetRotation(T100Vector3f&) = 0;
        T100Vector3f&           GetRotation();

        T100VOID                SetInstancePtr(T100Instance*);
        T100Instance*           GetInstancePtr();

    protected:
        T100Vector3f            m_position;
        T100Vector3f            m_rotation;

        T100Instance*           m_instancePtr           = T100NULL;

    private:
};

#endif // T1003DOBJECT_H
