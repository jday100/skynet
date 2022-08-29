#include "T100TestApp.h"


int main(int argc, char** argv)
{
    int                 wargc;
    wchar_t**           wargv;
    T100TestApp         app;


    app.getCmdLine(wargc, wargv);
    app.run(wargc, wargv);

    return 0;
}
