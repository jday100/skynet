#include "T100ConsoleTest.h"

T100ConsoleTest::T100ConsoleTest() :
    T100TestNode(L"Console", this)
{
    //ctor
}

T100ConsoleTest::~T100ConsoleTest()
{
    //dtor
}

T100RESULT T100ConsoleTest::DoTest()
{
    return test_console();
}

T100RESULT T100ConsoleTest::test_console()
{
    T100Console         console;

    T100COLOUR_TYPE     colour;

    colour  = console.GetForegroundColour();

    console.SetForegroundColour(T100COLOUR_TYPE_BLACK);
    console.SetBackgroundColour(T100COLOUR_TYPE_WHITE);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);
    console.SetBackgroundColour(T100COLOUR_TYPE_BLACK);

    console.SetForegroundColour(T100COLOUR_TYPE_WHITE);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_RED);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_GREEN);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_BLUE);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_YELLOW);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_PURPLE);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    console.SetForegroundColour(T100COLOUR_TYPE_CYAN);
    console.OutLine(L"Console Test");
    console.SetForegroundColour(colour);

    return T100RESULT_SUCCESS;
}
