#ifndef T100BUFFER_H
#define T100BUFFER_H

#include "T100Common.h"

template<typename ElementType>

class T100Buffer
{
    public:
        T100Buffer() { create(); }
        virtual ~T100Buffer() { destroy(); }

        T100INTEGER     next(ElementType& element){
                            if(0 > m_index){
                                return -1;
                            }else if(m_index >= m_length){
                                m_index = -1;
                                return -1;
                            }
                            element = m_buffer.at(m_index++);
                            return 0;
                        }

        T100INTEGER     batch(ElementType* element, T100WORD& length){
                            if(0 > m_index){
                                return -1;
                            }else if(m_index >= m_length){
                                m_index = -1;
                                return -1;
                            }
                            T100INTEGER result;
                            result = m_index + length;

                            if(result >= m_length){
                                length = result - m_length;
                            }
                            memcopy(element, &m_buffer.at(m_index), sizeof(ElementType) * length);
                            m_index = -1;

                            return 1;
                        }

        ElementType*    data(){
                            return m_buffer.data();
                        }

        T100WORD        size(){
                            return m_length;
                        }

        T100VOID        load(T100WORD length = 0){
                            m_index = 0;
                            if(0 != length){
                                m_length = length;
                            }
                        }

    protected:
        T100VOID        create(){
                            m_buffer.resize(m_length);
                        }

        T100VOID        destroy(){
                        }

    private:
        std::vector<ElementType>        m_buffer;
        T100WORD                        m_length            = 64;
        T100INTEGER                     m_index             = -1;

};

#endif // T100BUFFER_H
