#ifndef T100SHELL_H
#define T100SHELL_H

#include <string>

class T100Shell
{
    public:
        T100Shell();
        virtual ~T100Shell();

        void        Run(const std::string&);

    protected:

    private:
};

#endif // T100SHELL_H
