#ifndef T100FILEREADER_H
#define T100FILEREADER_H


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
};

#endif // T100FILEREADER_H
