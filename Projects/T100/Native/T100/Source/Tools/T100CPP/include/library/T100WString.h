#ifndef T100WSTRING_H
#define T100WSTRING_H

#include <iostream>
#include <string>
#include <vector>

class T100WString
{
    public:
        T100WString();
        virtual ~T100WString();

        wchar_t*        data();

        T100WString&    operator=(T100WString&);
        T100WString&    operator=(wchar_t[]);

        std::iostream operator<<(T100WString&);

    protected:

    private:
        std::vector<wchar_t>        m_wstring;
};

#endif // T100WSTRING_H
