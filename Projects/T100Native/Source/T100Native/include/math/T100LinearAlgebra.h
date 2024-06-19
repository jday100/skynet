#ifndef T100LINEARALGEBRA_H
#define T100LINEARALGEBRA_H

class T100Matrix3;
class T100VectorV3;

T100VectorV3&       operator *  (const T100VectorV3&, const T100Matrix3&);

class T100LinearAlgebra
{
    public:
        T100LinearAlgebra();
        virtual ~T100LinearAlgebra();

    protected:

    private:
};

#endif // T100LINEARALGEBRA_H
