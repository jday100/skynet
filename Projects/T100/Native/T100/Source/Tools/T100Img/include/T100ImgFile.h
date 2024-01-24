#ifndef T100IMGFILE_H
#define T100IMGFILE_H

#include <fstream>


class T100ImgFile
{
    public:
        T100ImgFile();
        virtual ~T100ImgFile();

        int             create(char*);

        int             open(char*);
        int             close();

        int             read();
        int             write(char*, size_t);

    protected:

    private:
        std::fstream*   m_fs            = nullptr;
};

#endif // T100IMGFILE_H
