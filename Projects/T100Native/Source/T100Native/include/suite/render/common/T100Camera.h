#ifndef T100CAMERA_H
#define T100CAMERA_H

#include <vector>
#include "T100Common.h"

#define     T100CAMERA_VECTOR           std::vector<T100Camera*>

class T100Camera
{
    public:
        T100Camera();
        virtual ~T100Camera();

        T100VOID            Location(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID            Direction(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:

    private:
};

#endif // T100CAMERA_H
