#ifndef T100NEUROIDTEST_H
#define T100NEUROIDTEST_H

#include "T100Neuroid.h"

class T100NeuroidTest : public T100Neuroid
{
    public:
        T100NeuroidTest();
        virtual ~T100NeuroidTest();

        void            test();

        T100Input       input1;
        T100Input       input2;
        T100Output      output;

        void            training(float, float, float);
        void            run();

    protected:
        void            create();
        void            destroy();

    private:
        T100Layer       layer0;
        T100Layer       layer1;

        T100Neuron      i1;
        T100Neuron      i2;
        T100Neuron      o1;

        T100Output      output1;
        T100Output      output2;
        T100Input       input;

};

#endif // T100NEUROIDTEST_H
