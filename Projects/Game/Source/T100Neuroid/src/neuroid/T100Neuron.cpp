#include "T100Neuron.h"

T100Neuron::T100Neuron()
{
    //ctor

    m_a     = 0.49;
    m_b     = 0;
}

T100Neuron::~T100Neuron()
{
    //dtor
}

void T100Neuron::operator<(const float in)
{
    m_in    = in;

    m_out   = m_in;
}

void T100Neuron::operator>(float& out)
{
    out     = m_out;
}

void T100Neuron::input(T100Input& in)
{
    m_input.push_back(&in);
}

void T100Neuron::output(T100Output& out)
{
    m_output.push_back(&out);
}

void T100Neuron::run()
{
    float           total           = 0;
    float           value;

    for(T100Input* in : m_input){
        total   += in->m_value;
    }

    value   = total;

    value   = m_a * total + m_b;

    for(T100Output* out : m_output){
        out->output(value);
    }
}

void T100Neuron::training()
{

}
