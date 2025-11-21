#ifndef T100STRINGTOOLS_H
#define T100STRINGTOOLS_H

#include <string>

class T100StringTools
{
    public:
        T100StringTools();
        virtual ~T100StringTools();

        static std::string          ToLower(const std::string& str);
        static std::wstring         ToLower(const std::wstring& str);

    protected:

    private:
};

#endif // T100STRINGTOOLS_H
