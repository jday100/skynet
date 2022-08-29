#include "T100Leak.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "T100Log.h"

void* operator new(size_t size, const char* file, int line)
{

    void* result = 0;
    puts("new");

    T100DWORD   index;

    result = malloc(size);
    if(!result){
        g_leak_total++;
    }

    index = (T100DWORD)result;

    T100LEAK_ITEM*          item    = T100NULL;
    T100LEAK_HASH::iterator it;

    it = g_leak_hash.find(index);

    if(g_leak_hash.end() == it){
        item = new T100LEAK_ITEM;
        if(!item){
            g_leak_total++;
            return 0;
        }
        item->FILE          = file;
        item->LINE          = line;
        item->ADDRESS       = index;
        item->COUNT         = 1;
        g_leak_hash[index]  = item;
    }else{
        item = it->second;
        if(!item){
            g_leak_total++;
            return 0;
        }
        item->COUNT++;

        g_leak_total++;
    }

    puts(std::to_string((T100DWORD)result).c_str());
    return result;
}

void* operator new[](size_t size, const char* file, int line)
{

    void* result = 0;
    puts("new");

    T100DWORD   index;

    result = malloc(size);
    if(!result){
        g_leak_total++;
    }

    index = (T100DWORD)result;

    T100LEAK_ITEM*          item    = T100NULL;
    T100LEAK_HASH::iterator it;

    it = g_leak_hash.find(index);

    if(g_leak_hash.end() == it){
        item = new T100LEAK_ITEM;
        if(!item){
            g_leak_total++;
            return 0;
        }
        item->FILE          = file;
        item->LINE          = line;
        item->ADDRESS       = index;
        item->COUNT         = 1;
        g_leak_hash[index]  = item;
    }else{
        item = it->second;
        if(!item){
            g_leak_total++;
            return 0;
        }
        item->COUNT++;

        g_leak_total++;
    }

    return result;
}

void global_delete(void* pointer, const char* file, int line)
{

    std::cout << file << ":" << line << std::endl;
    puts("delete");

    T100DWORD               index;
    T100LEAK_ITEM*          item        = T100NULL;
    T100LEAK_HASH::iterator it;

    index = (T100DWORD)pointer;
    it = g_leak_hash.find(index);
    if(g_leak_hash.end() == it){
        std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
        g_leak_total++;
        return;
    }else{
        item = it->second;
        if(!item){
            std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
            g_leak_total++;
            return;
        }
        if(1 == item->COUNT){
            g_leak_hash.erase(it);
            delete item;
        }else{
            item->COUNT--;
            g_leak_total++;
        }
    }

    free(pointer);
}

void global_deletes(void* pointer, const char* file, int line)
{

    std::cout << file << ":" << line << std::endl;
    puts("delete");

    T100DWORD               index;
    T100LEAK_ITEM*          item        = T100NULL;
    T100LEAK_HASH::iterator it;

    index = (T100DWORD)pointer;
    it = g_leak_hash.find(index);
    if(g_leak_hash.end() == it){
        std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
        g_leak_total++;
        return;
    }else{
        item = it->second;
        if(!item){
            std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
            g_leak_total++;
            return;
        }
        if(1 == item->COUNT){
            g_leak_hash.erase(it);
            delete item;
        }else{
            item->COUNT--;
            g_leak_total++;
        }
    }

    free(pointer);
}

void global_leak_report()
{
    if(0 == g_leak_total){

    }else{
        std::cout << "MEMORY ERROR!!!" << "\t" << g_leak_total << std::endl;
    }

    if(0 != g_leak_hash.size()){
        std::cout << "MEMORY ERROR!!!" << "\t" << g_leak_hash.size() << std::endl;
        for(auto item : g_leak_hash){
            std::cout << item.second->FILE << "\t" << item.second->LINE << std::endl;
        }
    }
}

T100Leak::T100Leak()
{
    //ctor
}

T100Leak::~T100Leak()
{
    //dtor
}
