#ifndef T100JSON_H
#define T100JSON_H

#include <fstream>
#include <initializer_list>
#include "T100Common.h"
#include "json/json.hpp"

using JSON = nlohmann::json;

class T100JSON
{
    friend class T100FileTest;
    friend class T100File3DF;
    public:
        T100JSON();
        T100JSON(T100WCHAR*);
        T100JSON(T100WSTRING);
        T100JSON(std::initializer_list<std::pair<std::string, std::string>>);
        virtual ~T100JSON();

        T100BOOL                    IsObject();

        JSON::iterator              Find(T100STRING);
        JSON::iterator              End();

        JSON&                       GetJSON();
        JSON&                       At(T100STRING);

        /*
        friend std::istream* operator>>(std::istream*, const T100JSON&);
        friend std::ostream* operator<<(std::ostream*, const T100JSON&);
        */

        T100WSTRING operator[](T100CHAR*);

        friend std::ifstream& operator>>(std::ifstream&, T100JSON&);
        friend std::ofstream& operator<<(std::ofstream&, const T100JSON&);

    protected:
        T100WSTRING                     m_filename          = L"filename.json";
        JSON                            m_json;

    private:
};

#endif // T100JSON_H
