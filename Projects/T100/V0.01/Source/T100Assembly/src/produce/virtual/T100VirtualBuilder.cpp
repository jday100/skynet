#include "T100VirtualBuilder.h"

#include "T100PartDrawer.h"
#include "T100VirtualMerger.h"
#include "T100VirtualFile.h"
#include "T100VirtualFileWriter.h"


T100VirtualBuilder::T100VirtualBuilder()
{
    //ctor
}

T100VirtualBuilder::~T100VirtualBuilder()
{
    //dtor
}

T100BOOL T100VirtualBuilder::run(T100STRING& file, T100ProduceInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;
    T100VirtualInfo     vinfo;

    value = build(info);
    if(!value){
        return T100FALSE;
    }

    value = merge(info, vinfo);
    if(!value){
        return T100FALSE;
    }

    value = save(file, vinfo);
    result = value;

    return result;
}

T100BOOL T100VirtualBuilder::build(T100ProduceInfo& info)
{
    T100BOOL            result          = T100TRUE;

    for(T100PartInfo* item : info.getPartDrawer().getPartInfos()){
        if(item){
            m_part = item;
            item->getBuildInfo().m_code_master = item->getParseInfo().getToken()->master;
            item->getBuildInfo().m_data_master = item->getParseInfo().getToken()->master;
            result = build(item->getParseInfo().getToken());
            if(result){
                result = save(item);
                if(!result){
                    return T100FALSE;
                }
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VirtualBuilder::build(T100PartToken* token)
{
    T100BOOL            result          = T100TRUE;

    for(T100SegmentToken* item : token->segments){
        if(item){
            result = build(item);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    if(result){
        //result = m_produce->getPartDrawer().save(name, info);
    }

    return result;
}

T100BOOL T100VirtualBuilder::build(T100SegmentToken* token)
{
    T100BOOL            result          = T100TRUE;

    for(T100SentenceToken* item : token->sentences){
        if(item){
            result = build(item);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VirtualBuilder::build(T100SentenceToken* token)
{
    T100BOOL            result          = T100FALSE;

    if(token->value){
        result = token->value->build(&(m_part->getBuildInfo()));
    }

    if(result){
        result = T100TRUE;
    }else{
        result = T100FALSE;

        result = token->value->build(&(m_part->getBuildInfo()));

        T100WORD type = token->type;

        if(token->value){
            T100String name = token->value->value;
            return result;
        }
    }

    return result;
}

T100BOOL T100VirtualBuilder::merge(T100ProduceInfo& source, T100VirtualInfo& target)
{
    T100BOOL                result          = T100TRUE;
    T100VirtualMerger       merger;

    result = merger.run(source, target);

    return result;
}

T100BOOL T100VirtualBuilder::save(T100STRING& file, T100VirtualInfo& info)
{
    T100BOOL                    result          = T100TRUE;
    T100VirtualFileWriter*      writer          = T100NULL;
    T100VirtualFile             vfile(file);

    writer = vfile.getWriter();

    if(writer){
        result = writer->save(info);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VirtualBuilder::save(T100PartInfo* part)
{
    T100BOOL            result          = T100TRUE;

    result = T100ProduceInfo::getPartDrawer().save(part->getName(), part);

    return result;
}
