#include "T100JSONTest.h"

#include <fstream>
#include "T100Common.h"
#include "json/json.hpp"

using JSON = nlohmann::json;

T100JSONTest::T100JSONTest()
{
    //ctor
}

T100JSONTest::~T100JSONTest()
{
    //dtor
}

int T100JSONTest::test()
{
    T100STRING      file    = "./build/json_test.json";
    std::ifstream   ifs(file);
    std::ofstream   ofs(file);

    JSON    json;
    JSON    result;

    json["name"]    = "json";

    json = {{"name","json1"}};

    ofs << json;

    ofs.flush();

    ifs >> result;

    if(json["name"] == result["name"]){
        return 0;
    }

    return -1;
}
