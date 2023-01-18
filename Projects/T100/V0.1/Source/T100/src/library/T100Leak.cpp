#include "T100Leak.h"



#include <stdio.h>
#include <string.h>
#include <iostream>
#include "T100Log.h"


void global_out(const char* msg)
{
#ifdef __LOG__
    T100Log::info(msg);
#else
    std::cout << "INFO: " << msg << std::endl;
#endif // __LOG__
}

void global_fatal(const char* msg)
{
#ifdef __LOG__
    T100Log::fatal(msg);
#else
    std::cout << "FATAL: " << msg << std::endl;
#endif // __LOG__
}

void global_error(const char* msg)
{
#ifdef __LOG__
    T100Log::error(msg);
#else
    std::cout << "ERROR: " << msg << std::endl;
#endif // __LOG__
}

void global_warn(const char* msg)
{
#ifdef __LOG__
    T100Log::warn(msg);
#else
    std::cout << "WARNING: " << msg << std::endl;
#endif // __LOG__
}


void* operator new(size_t size, const char* file, int line)
{

    void* result = 0;
    //puts("new");

    global_out("new...");
    global_out(file);

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

    //puts(std::to_string((T100DWORD)result).c_str());
    global_out(std::to_string((T100DWORD)result).c_str());

    return result;
}

void* operator new[](size_t size, const char* file, int line)
{

    void* result = 0;
    //puts("new");

    global_out("new[]...");

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

    //std::cout << file << ":" << line << std::endl;
    //puts("delete");

    global_out("delete...");

    T100DWORD               index;
    T100LEAK_ITEM*          item        = T100NULL;
    T100LEAK_HASH::iterator it;

    index = (T100DWORD)pointer;
    it = g_leak_hash.find(index);
    if(g_leak_hash.end() == it){
        //std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
        std::string msg;
        msg = msg + "DELETE ERROR!" + " " + "\t" + "ADDRESS: " + std::to_string(index);
        msg = msg + " " + file + " " + std::to_string(line);
        global_error(msg.c_str());
        g_leak_total++;
        return;
    }else{
        item = it->second;
        if(!item){
            //std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
            std::string msg;
            msg = msg + "DELETE ERROR!" + " " + "\t" + "ADDRESS: " + std::to_string(index);
            msg = msg + " " + file + " " + std::to_string(line);
            global_error(msg.c_str());
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

    //std::cout << file << ":" << line << std::endl;
    //puts("delete");

    global_out("delete[]...");

    T100DWORD               index;
    T100LEAK_ITEM*          item        = T100NULL;
    T100LEAK_HASH::iterator it;

    index = (T100DWORD)pointer;
    it = g_leak_hash.find(index);
    if(g_leak_hash.end() == it){
        //std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
        std::string msg;
        msg = msg + "DELETE ERROR!" + " " + "\t" + "ADDRESS: " + std::to_string(index);
        msg = msg + " " + file + " " + std::to_string(line);
        global_error(msg.c_str());
        g_leak_total++;
        return;
    }else{
        item = it->second;
        if(!item){
            //std::cout << "DELETE ERROR!!!" << "\t" << index << std::endl;
            std::string msg;
            msg = msg + "DELETE ERROR!" + " " + "\t" + "ADDRESS: " + std::to_string(index);
            msg = msg + " " + file + " " + std::to_string(line);
            global_error(msg.c_str());
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
        //std::cout << "MEMORY ERROR!!!" << "\t" << g_leak_total << std::endl;
        std::string msg;
        msg = msg + "MEMORY ERROR!!!" + " " + "\t" + "Total: " + std::to_string(g_leak_total);
        global_error(msg.c_str());
    }

    if(0 != g_leak_hash.size()){
        //std::cout << "MEMORY ERROR!!!" << "\t" << g_leak_hash.size() << std::endl;
        std::string msg;
        msg = msg + "MEMORY ERROR!!!" + " " + "\t" + "Total: " + std::to_string(g_leak_hash.size());
        global_error(msg.c_str());
        for(auto item : g_leak_hash){
            //std::cout << item.second->FILE << "\t" << item.second->LINE << std::endl;
            std::string msg;
            msg = msg + "\tERROR!!!" + "\t" + "File: " + item.second->FILE + "\t" + "Line: " + std::to_string(item.second->LINE);
            global_error(msg.c_str());
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
