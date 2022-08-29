#include "T100ProduceParser.h"

#include "T100PathTools.h"
#include "T100PartToken.h"
#include "T100PartScanner.h"
#include "T100PartScannerTools.h"
#include "T100ProduceInfo.h"

#include "T100ParseInfo.h"
#include "T100PartDrawer.h"


T100ProduceParser::T100ProduceParser()
{
    //ctor
}

T100ProduceParser::~T100ProduceParser()
{
    //dtor
}

T100BOOL T100ProduceParser::run(T100STRING& file, T100ProduceInfo& info)
{
    T100BOOL            result;

    m_root = T100PathTools::getCwd();

    result = load(file, T100TRUE);

    return result;
}

T100BOOL T100ProduceParser::load(T100STRING& file, T100BOOL flag)
{
    T100BOOL            result;
    T100WSTRING         cwd;

    T100WSTRING         current;
    T100WSTRING         path;
    T100WSTRING         name;

    cwd     = T100PathTools::getCwd();
    current = file.to_wstring();

    T100PathTools::format(current, path, name);
    T100PathTools::chdir(path);

    result = scan(name);

    T100PathTools::chdir(cwd);

    return result;
}

T100BOOL T100ProduceParser::scan(T100WSTRING& file)
{
    T100BOOL                    result          = T100TRUE;
    T100PartScannerTools        tools;
    T100PartToken               token;
    T100PartScanner*            scanner         = T100NULL;

    scanner = tools.create(file);
    if(!scanner){
        return T100FALSE;
    }

    while(scanner->next(token)){
        if(token.eof)break;

        if(append(token, T100FALSE)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!tools.close()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ProduceParser::append(T100PartToken& token, T100BOOL flag)
{
    T100BOOL            result          = T100FALSE;
    T100WSTRING         path;
    T100WSTRING         name;
    T100WSTRING         full;

    name = token.file.to_wstring();

    T100PathTools::full(name, full);

    if(m_produce->getPartDrawer().exists(T100String(full))){
        return T100TRUE;
    }else{
        if(T100FILE_IMPORT == token.type){
            T100String  part(name);
            result = load(part, flag);
        }else{
            result = add(full, token);
        }
    }

    return result;
}

T100BOOL T100ProduceParser::add(T100WSTRING& full, T100PartToken& token)
{
    T100BOOL            result          = T100TRUE;
    T100String          name(full);
    T100PartInfo*       info            = T100NULL;
    T100PartToken*      item            = T100NULL;

    item = token.copy();

    if(item){
        info = T100NEW T100PartInfo();
        info->getParseInfo().setToken(item);
    }else{
        return T100FALSE;
    }

    if(m_produce->getPartDrawer().append(name, info)){

    }else{
        T100SAFE_DELETE(item);
        T100SAFE_DELETE(info);
        result = T100FALSE;
    }

    return result;
}





