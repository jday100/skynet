#include "T100Produce.h"

#include "T100BuildInfo.h"
#include "T100ProduceParser.h"
#include "T100ProduceBuilder.h"

#include "T100RealBuilder.h"
#include "T100VirtualBuilder.h"


T100Produce::T100Produce()
{
    //ctor
}

T100Produce::~T100Produce()
{
    //dtor
}

T100ProduceBuilder* T100Produce::create_builder(T100ProduceInfo& info)
{
    T100ProduceBuilder*         result          = T100NULL;

    switch(info.getMode()){
    case T100MODE_REAL:
        {
            result = T100NEW T100RealBuilder();
        }
        break;
    case T100MODE_VIRTUAL:
        {
            result = T100NEW T100VirtualBuilder();
        }
        break;
    default:
        break;
    }

    return result;
}

T100BOOL T100Produce::run(T100STRING& source, T100STRING& target)
{
    T100BOOL                    result          = T100TRUE;
    T100ProduceInfo             info;
    T100ProduceParser           parser;
    T100ProduceBuilder*         builder         = T100NULL;

    result = parser.run(source, info);
    if(!result){
        return T100FALSE;
    }

    builder = create_builder(info);
    if(!builder){
        return T100FALSE;
    }

    result = builder->run(target, info);

    return result;
}



