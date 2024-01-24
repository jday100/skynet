#ifndef T100CMDLINE_H
#define T100CMDLINE_H


class T100CmdLine
{
    public:
        T100CmdLine();
        virtual ~T100CmdLine();

        int         run(int, char**);

    protected:
        int         parse(int, char**);

        int         parse_in(char*);
        int         parse_out(char*);

        int         parse_create(int, char**);
        int         parse_format(int, char**);

    private:
        char*       m_in_file       = nullptr;
        char*       m_out_file      = nullptr;
        int         create_file(char*);
        int         format_file(char*);
};

#endif // T100CMDLINE_H
