#include "T100ImgFile.h"

#include <cstring>


T100ImgFile::T100ImgFile()
{
    //ctor
}

T100ImgFile::~T100ImgFile()
{
    //dtor
}

int T100ImgFile::create(char* file){
    std::ofstream       ofs;

    char                buffer[512];

    memset(&buffer, 50, 512);

    ofs.open(file, std::ios::out | std::ios::binary);

    if(ofs.is_open()){
        for(int i=0;i<2;i++){
            for(int m=0;m<80;m++){
                for(int n=0;n<18;n++){
                    ofs.write(buffer, 512);
                }
            }
        }
    }

    ofs.close();
}

int T100ImgFile::open(char* file){
    m_fs = new std::fstream(file, std::ios::in | std::ios::out | std::ios::binary);

    if(m_fs && m_fs->is_open()){
        return 0;
    }
    return -1;
}

int T100ImgFile::close(){
    m_fs->close();
    return 0;
}


int T100ImgFile::read(){

}

int T100ImgFile::write(char* data, size_t size){
    bool result = m_fs->write(data, size).fail();

    if(result){
        return -1;
    }
    return 0;
}

