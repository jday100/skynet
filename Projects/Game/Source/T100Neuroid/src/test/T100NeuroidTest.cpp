#include "T100NeuroidTest.h"

#include <iostream>
#include "T100Layer.h"

T100NeuroidTest::T100NeuroidTest()
    :T100Neuroid()
{
    //ctor
    create();
}

T100NeuroidTest::~T100NeuroidTest()
{
    //dtor
    destroy();
}

void T100NeuroidTest::create()
{
    i1.input(input1);
    i2.input(input2);

    i1.output(output1);
    i2.output(output2);

    o1.input(input);
    o1.output(output);

    output1.connect(input);
    output2.connect(input);
}

void T100NeuroidTest::destroy()
{

}

void T100NeuroidTest::training(float a, float b, float c)
{

}

void T100NeuroidTest::run()
{

}

void T100NeuroidTest::test()
{
    float           result;

    input1.value(1);
    input2.value(1);

    run();

    result  = output.value;

    std::cout << result;
}
