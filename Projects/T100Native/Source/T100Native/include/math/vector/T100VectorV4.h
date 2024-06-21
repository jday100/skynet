#ifndef T100VECTORV4_H
#define T100VECTORV4_H

#include "T100Common.h"

class T100VectorV4
{
    public:
        T100VectorV4();
        virtual ~T100VectorV4();

        T100FLOAT           m_x         = 0.0;
        T100FLOAT           m_y         = 0.0;
        T100FLOAT           m_z         = 0.0;
        T100FLOAT           m_w         = 0.0;

    public:
        T100BOOL            operator == (const T100VectorV4&);
        T100BOOL            operator != (const T100VectorV4&);

        T100VectorV4&       operator =  (const T100VectorV4&);

        T100VectorV4&       operator +  (const T100VectorV4&);
        T100VectorV4&       operator -  (const T100VectorV4&);

        T100VectorV4&       operator *  (const T100VectorV4&);
        T100VectorV4&       operator /  (const T100VectorV4&);

    protected:

    private:
};

#endif // T100VECTORV4_H
