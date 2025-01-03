#ifndef T100INPUT_H
#define T100INPUT_H

#include <vector>

#define     T100NEUROID_INPUT_VECTOR            std::vector<T100Input*>


class T100Input
{
    friend class T100Neuron;
    public:
        T100Input();
        virtual ~T100Input();

        void            value(float);

    protected:

    private:
        float           m_value;
};

#endif // T100INPUT_H
