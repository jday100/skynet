#ifndef T1003DFILE3DF_H
#define T1003DFILE3DF_H

#include "json/json.hpp"

using JSON = nlohmann::json;

class T1003DFile3DF
{
    public:
        T1003DFile3DF();
        virtual ~T1003DFile3DF();

        JSON&           GetJSON();

    protected:
        JSON            m_json;

    private:
};

#endif // T1003DFILE3DF_H
