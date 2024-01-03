#ifndef T100FILEREADER_H
#define T100FILEREADER_H

#include <fstream>


class T100FileReader
{
    public:
        T100FileReader(char*);
        virtual ~T100FileReader();

        int     open();
        int     close();

        int     read(int, char*);


    protected:

    private:
        char*               m_file          = nullptr;
        std::ifstream*      m_ifs           = nullptr;
};

#endif // T100FILEREADER_H
