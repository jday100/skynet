#ifndef T100VESSEL_H
#define T100VESSEL_H

#include <vector>
#include <unordered_map>
#include "T100Common.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"

namespace T100Library{

template <typename Key, typename Value>

class T100Vessel
{
    public:
        T100Vessel() {}
        virtual ~T100Vessel() {}

        T100WORD    size() { m_vector.size(); };
        T100BOOL    push_back(Key key, Value value)
        {
            typename std::vector<Value>::iterator it;

            for(it = m_vector.begin();it != m_vector.end(); it++)
            {
                if(*it == value){
                    return T100FALSE;
                }
            }

            m_vector.push_back(value);
            m_hash[key] = value;

            return T100TRUE;
        };

        Value       at(T100WORD index)
        {
            return m_vector.at(index);
        };

        Value       operator[](const Key key)
        {
            return m_hash[key];
        };

    protected:
        std::vector<Value>                  m_vector;
        std::unordered_map<Key, Value>      m_hash;

    private:
};

/////////
template <typename Value>

class T100Vessel<T100String, Value>
{
    public:
        T100Vessel() {};
        virtual ~T100Vessel() {};

        T100WORD        size() { m_vector.size(); };
        T100BOOL        push_back(T100String key, Value value)
        {
            typename std::vector<Value>::iterator it;

            for(it = m_vector.begin(); it != m_vector.end(); it++)
            {
                if(*it == value){
                    return T100FALSE;
                }
            }

            m_vector.push_back(value);
            m_hash[key] = value;

            return T100TRUE;
        };

        Value           at(T100WORD index)
        {
            return m_vector.at(index);
        };

        Value           operator[](const T100String key)
        {
            return m_hash[key];
        };

    protected:
        std::vector<Value>      m_vector;
        std::unordered_map<T100String, Value, T100StringHash, T100StringEqual>      m_hash;

    private:

};

}

#endif // T100VESSEL_H
