#ifndef T100CMDLINE_H
#define T100CMDLINE_H


class T100CmdLine
{
    public:
        T100CmdLine();
        virtual ~T100CmdLine();

        int             Run(int, char**);

    protected:

    private:
};

#endif // T100CMDLINE_H
