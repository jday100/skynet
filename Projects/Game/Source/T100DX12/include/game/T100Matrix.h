#ifndef T100MATRIX_H
#define T100MATRIX_H

namespace DirectX{
    constexpr float XM_PI = 3.141592654f;
    constexpr float XM_2PI = 6.283185307f;
    constexpr float XM_1DIVPI = 0.318309886f;
    constexpr float XM_1DIV2PI = 0.159154943f;
    constexpr float XM_PIDIV2 = 1.570796327f;
    constexpr float XM_PIDIV4 = 0.785398163f;

    class XMMATRIX;
    class XMVECTOR;
}

class T100Matrix
{
    public:
        T100Matrix();
        virtual ~T100Matrix();

    protected:

    private:
};

#endif // T100MATRIX_H
