#include "T100Test.h"

#include <iostream>
#include "T100Neuron.h"
#include "T100Neuroid.h"

T100Test::T100Test()
{
    //ctor
}

T100Test::~T100Test()
{
    //dtor
}

void T100Test::test()
{
    float               result;
    T100Neuron          neuron;

    neuron < 1.0f;
    neuron > result;

    std::cout << result;
}

void T100Test::test_neuroid()
{
    T100Neuroid         neuroid;

    neuroid.run();
}

void T100Test::test_neuron()
{
    T100Neuron          neuron;

    T100Input           input1;
    T100Input           input2;
    T100Output          output;
    float               result;

    neuron.input(input1);
    neuron.input(input2);
    neuron.output(output);

    input1.value(0);
    input2.value(0);

    neuron.run();

    result  = output.value;

    std::cout << result;
}

void T100Test::test_traning()
{
    T100Neuron          neuron;

    T100Input           input1;
    T100Input           input2;
    T100Output          output;
    float               result;

    neuron.input(input1);
    neuron.input(input2);
    neuron.output(output);

    input1.value(0);
    input2.value(0);
    output.output(0);

    neuron.training();
}
