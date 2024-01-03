#ifndef T100CMDLINE_H
#define T100CMDLINE_H


class T100CmdLine
{
    public:
        T100CmdLine(int argc, char** argv);
        virtual ~T100CmdLine();

        char*           m_file          = nullptr;
        char*           m_out           = nullptr;

        int run();

    protected:
        int parse(char*);
        int parse_value(char);
        int parse_string(char*);

    private:
        int         m_status;
        int         m_argc;
        char**      m_argv;
};

#endif // T100CMDLINE_H
