#include "T100ProduceParser.h"

#include "T100File.h"
#include "T100PathTools.h"
#include "T100AssemblyError.h"
#include "T100PartToken.h"
#include "T100PartScanner.h"
#include "T100PartScannerTools.h"
#include "T100ProduceInfo.h"

#include "T100ParseInfo.h"
#include "T100PartDrawer.h"

#include "T100ClassPathDrawer.h"

namespace T100Assembly{

T100ProduceParser::T100ProduceParser()
{
    //ctor
}

T100ProduceParser::~T100ProduceParser()
{
    //dtor
}

T100VOID T100ProduceParser::setClassPathDrawer(T100ClassPathDrawer* drawer)
{
    m_path_drawer = drawer;
}

T100ClassPathDrawer* T100ProduceParser::getClassPathDrawer()
{
    return m_path_drawer;
}

T100BOOL T100ProduceParser::run(T100STRING& file, T100ProduceInfo& info)
{
    T100BOOL        result;

    m_path_drawer->setRoot(T100PathTools::getCwd());

    result = load(file, T100TRUE);

    return result;
}

T100BOOL T100ProduceParser::load(T100STRING& file, T100BOOL flag)
{
    T100BOOL            result;
    T100WSTRING         cwd;
    T100STRING          full;

    result = search(file, full);
    if(!result){
        return T100FALSE;
    }

    T100WSTRING         current;
    T100WSTRING         path;
    T100WSTRING         name;

    cwd     = T100PathTools::getCwd();
    current = full.to_wstring();

    T100PathTools::format(current, path, name);
    T100PathTools::cddir(path);

    result = scan(name, flag);

    T100PathTools::chdir(cwd);

    return result;
}

T100BOOL T100ProduceParser::scan(T100WSTRING& file, T100BOOL flag)
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

        if(T100FILE_SOURCE == token.type){
            if(flag){
                token.master = T100TRUE;
            }
            token.file = file;
        }

        if(append(token)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!tools.close()){
        result = T100FALSE;
    }

    if(T100AssemblyError::err){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ProduceParser::append(T100PartToken& token)
{
    T100BOOL            result          = T100FALSE;
    T100WSTRING         path;
    T100WSTRING         name;
    T100WSTRING         full;

    name = token.file.to_wstring();

    T100PathTools::full(name, full);

    if(m_produce->getPartDrawer().exists(T100STRING(full))){
        return T100TRUE;
    }else{
        if(T100FILE_IMPORT == token.type){
            T100STRING      part(name);
            result = load(part, T100FALSE);
        }else{
            result = add(full, token);
        }
    }
    return result;
}

T100BOOL T100ProduceParser::add(T100WSTRING& full, T100PartToken& token)
{
    T100BOOL            result          = T100TRUE;
    T100STRING          name(full);
    T100PartInfo*       info            = T100NULL;
    T100PartToken*      item            = T100NULL;

    item = token.copy();

    if(item){
        info = T100ProduceInfo::getPartDrawer().getPartInfo(name);
        if(info){

        }else{
            info = T100NEW T100PartInfo();
        }
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

T100BOOL T100ProduceParser::search(T100STRING file, T100STRING& full)
{
    T100BOOL        result;
    T100File        item(file.to_wstring());

    if(item.exists()){
        full = file;
        return T100TRUE;
    }

    result = m_path_drawer->find(file, full);

    return result;
}

}
