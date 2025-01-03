#ifndef T100NEURON_H
#define T100NEURON_H

#include <iostream>
#include "T100Input.h"
#include "T100Output.h"

class T100Neuron
{
    public:
        T100Neuron();
        virtual ~T100Neuron();

        void operator<(const float in);
        void operator>(float& out);

        void            input(T100Input&);
        void            output(T100Output&);
        void            run();

        void            training();

    protected:
        T100NEUROID_INPUT_VECTOR            m_input;
        T100NEUROID_OUTPUT_VECTOR           m_output;

    private:
        float           m_in;
        float           m_out;

        float           m_a;
        float           m_b;
};

#endif // T100NEURON_H
