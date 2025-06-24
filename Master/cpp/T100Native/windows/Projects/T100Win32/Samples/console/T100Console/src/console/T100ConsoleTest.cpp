#include "T100ConsoleTest.h"

#include "console/T100Console.h"

using namespace T100LIBRARY;

T100ConsoleTest::T100ConsoleTest()
{
    //ctor
}

T100ConsoleTest::~T100ConsoleTest()
{
    //dtor
}

void T100ConsoleTest::test()
{
    T100Console         console;

    console.OutLine(L"hello world!");
    console.OutLine(L"hello world!");
    console.OutLine(L"hello world!");
    console.OutLine(L"hello world!");
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_BLACK);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_WHITE);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_RED);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_GREEN);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_BLUE);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_YELLOW);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_PURPLE);
    console.OutLine(L"hello world!");

    //console.SetForegroundColour(T100COLOUR_CYAN);
    console.OutLine(L"hello world!");

    T100WSTRING     result;
    console.GetLine(result);
    console.OutLine(result);
}
