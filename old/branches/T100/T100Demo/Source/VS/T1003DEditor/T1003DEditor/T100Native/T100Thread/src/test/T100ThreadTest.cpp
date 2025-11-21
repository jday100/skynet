#include "test/T100ThreadTest.h"

#include <iostream>
#include "T100SimpleThread.h"

T100ThreadTest::T100ThreadTest()
{
    //ctor
}

T100ThreadTest::~T100ThreadTest()
{
    //dtor
}

void T100ThreadTest::test()
{
    new T100SimpleThread(&T100ThreadTest::run, this);
}

void T100ThreadTest::run()
{
    std::cout << "running...";
}
