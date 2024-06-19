#ifndef T100VECTORV3_H
#define T100VECTORV3_H

#include "T100Common.h"
class T100VectorV3;

T100VectorV3&       operator +  (const T100VectorV3&, const T100FLOAT&);

class T100VectorV3
{
    public:
        T100VectorV3();
        virtual ~T100VectorV3();

        T100FLOAT           m_x         = 0.0;
        T100FLOAT           m_y         = 0.0;
        T100FLOAT           m_z         = 0.0;

    public:
        T100BOOL            operator == (const T100VectorV3&);
        T100BOOL            operator != (const T100VectorV3&);

        T100VectorV3&       operator =  (const T100VectorV3&);

        T100VectorV3&       operator +  (const T100VectorV3&);
        T100VectorV3&       operator -  (const T100VectorV3&);

        T100VectorV3&       operator *  (const T100VectorV3&);
        T100VectorV3&       operator /  (const T100VectorV3&);

    protected:

    private:
};

#endif // T100VECTORV3_H
