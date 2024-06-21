#ifndef T100VECTORH4_H
#define T100VECTORH4_H

#include "T100Common.h"

class T100VectorH4
{
    public:
        T100VectorH4();
        virtual ~T100VectorH4();

        T100FLOAT           m_x         = 0.0;
        T100FLOAT           m_y         = 0.0;
        T100FLOAT           m_z         = 0.0;
        T100FLOAT           m_w         = 0.0;

    public:
        T100BOOL            operator == (const T100VectorH4&);
        T100BOOL            operator != (const T100VectorH4&);

        T100VectorH4&       operator =  (const T100VectorH4&);

        T100VectorH4&       operator +  (const T100VectorH4&);
        T100VectorH4&       operator -  (const T100VectorH4&);

        T100VectorH4&       operator *  (const T100VectorH4&);
        T100VectorH4&       operator /  (const T100VectorH4&);

    protected:

    private:
};

#endif // T100VECTORH4_H
