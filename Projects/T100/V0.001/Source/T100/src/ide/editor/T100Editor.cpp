#include "T100Editor.h"

#include "T100BuilderNew.h"


T100Editor::T100Editor()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100BOOL T100Editor::load(T100STDSTRING file)
{
    T100BOOL        result;
    T100Builder     builder;

    result = builder.parse(file);


    return T100FALSE;
}

T100BOOL T100Editor::save()
{
    return T100FALSE;
}
