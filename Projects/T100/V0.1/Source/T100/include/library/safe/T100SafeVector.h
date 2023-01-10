#ifndef T100SAFEVECTOR_H
#define T100SAFEVECTOR_H

#include <mutex>
#include <vector>


namespace T100Library{

template <typename Type>

class T100SafeVector
{
    public:
        T100SafeVector() {}
        virtual ~T100SafeVector() {}

        void append(const Type value)
        {
            std::lock_guard<std::mutex>     lock(m_mutex);
            m_vector.push_back(value);
        }

        bool remove(const Type value)
        {
            std::lock_guard<std::mutex>     lock(m_mutex);

            typename std::vector<Type>::iterator    it;

            for(it = m_vector.begin(); it != m_vector.end(); it++)
            {
                if(value == (*it)){
                    m_vector.erase(it);
                    return true;
                }
            }

            return false;
        }

        typename std::vector<Type>::iterator begin()
        {
            std::lock_guard<std::mutex>     lock(m_mutex);
            return m_vector.begin();
        }

        typename std::vector<Type>::iterator end()
        {
            std::lock_guard<std::mutex>     lock(m_mutex);
            return m_vector.end();
        }

        void clear()
        {
            std::lock_guard<std::mutex>     lock(m_mutex);

            for(Type item : m_vector){
                if(item){
                    delete item;
                }
            }
            m_vector.clear();
        }

    protected:
        std::vector<Type>       m_vector;

    private:
        std::mutex              m_mutex;

};

}

#endif // T100SAFEVECTOR_H
