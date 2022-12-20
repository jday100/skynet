#include "T100ThisAppHelp.h"

#include "T100Console.h"

T100ThisAppHelp::T100ThisAppHelp()
    :T100Library::T100Help()
{
    //ctor
}

T100ThisAppHelp::~T100ThisAppHelp()
{
    //dtor
}


T100VOID T100ThisAppHelp::show()
{
    T100Library::T100Console    console;

    T100WSTRING     msg;

    msg     = L"T100 Help:";

    console.outline(msg);

    msg     = L" \
        -?      usage       run usage\n \
        -T      test        run test\n \
        -H      help        run help\n \
        -V      vpc         run vpc\n \
        -D      vdisk       run vdisk console\n \
        -M      vdm         run vdisk manager\n \
        -F      font        run font file builder\n \
        -I      ide         run ide\n \
        -A      assembly    run assembly compiler\n \
        -E      editor      run editor\n \
        -L      log         setup log\n \
        -R      error       setup error\n \
        \n \
        -q      quit        quit app\n \
        -l      list        list test units\n \
        -i      input       input file\n \
        -o      output      output file\n \
        -u      unit        run test unit\n \
        -p      classpath   setup import path\n \
    ";

    console.outline(msg);
}
