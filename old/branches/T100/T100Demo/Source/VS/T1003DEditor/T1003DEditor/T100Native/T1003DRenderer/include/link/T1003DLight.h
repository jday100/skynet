#ifndef T1003DLIGHT_H
#define T1003DLIGHT_H

#include <vector>
#include "T100Common.h"
#include "T1003DObject.h"

#define     T1003DLIGHT_VECTOR              std::vector<T1003DLight*>

class T1003DLight : public T1003DObject
{
    public:
        T1003DLight();
        virtual ~T1003DLight();

        T100WSTRING         Name;

        T100VOID            SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID            SetPosition(T100Vector3f&);

        T100VOID            SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID            SetRotation(T100Vector3f&);

    protected:

    private:
};

#endif // T1003DLIGHT_H
