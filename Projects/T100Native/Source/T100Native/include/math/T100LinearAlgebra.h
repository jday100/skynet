#ifndef T100LINEARALGEBRA_H
#define T100LINEARALGEBRA_H

class T100Matrix3;
class T100Matrix4;
class T100VectorV3;
class T100VectorV4;
class T100VectorH4;

T100VectorV3&       operator *  (const T100VectorV3&, const T100Matrix3&);
T100VectorV4&       operator *  (const T100VectorV4&, const T100Matrix4&);

T100VectorH4&       operator *  (const T100VectorH4&, const T100Matrix4&);

class T100LinearAlgebra
{
    public:
        T100LinearAlgebra();
        virtual ~T100LinearAlgebra();

    protected:

    private:
};

#endif // T100LINEARALGEBRA_H
