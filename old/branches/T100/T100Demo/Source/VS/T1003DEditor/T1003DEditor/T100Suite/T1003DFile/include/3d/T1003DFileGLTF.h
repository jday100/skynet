#ifndef T1003DFILEGLTF_H
#define T1003DFILEGLTF_H

#include "json/json.hpp"

using JSON = nlohmann::json;

class T1003DFileGLTF
{
    public:
        T1003DFileGLTF();
        virtual ~T1003DFileGLTF();

        JSON&           GetJSON();

    protected:
        JSON            m_json;

    private:
};

#endif // T1003DFILEGLTF_H
