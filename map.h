#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

template<class K, class V>
class Map
{
private:
    struct Pair
    {
        K key;
        V value;
        int index;
    };


    Pair *data;
    int size = 0;
    int capacity = 1;

    void resize()
    {
        capacity *= 2;
        Pair *newData = new Pair[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    int findIndex(const K &key)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (key == data[i].key)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    void Sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (data[i].key > data[j].key)
                {
                    swap(data[i], data[j]);
                }
            }
        }
    }

public:
    Map()
    {
        this->data = new Pair[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = {};
        }
    };

    Map(const Map &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new Pair[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
    }

    Map(const Map &&other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new Pair[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
        other.size = 0;
        other.capacity = 1;
        delete[] other.data;
    }

    ~Map()
    {
        delete[] data;
        size = 0;
        capacity = 1;
    }

    Map &operator=(const Map &other)
    {
        if (this == &other) { return *this; }
        delete [] this->data;
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new Pair[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    Map &operator=(Map &&other)
    {
        if (this == &other) { return *this; }
        delete [] this->data;
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new Pair[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
        other.size = 0;
        other.capacity = 1;
        delete[] other.data;

        return *this;
    }

    void Set(const K key, const V value)
    {
        int index = findIndex(key);

        if (index == -1)
        {
            // Nu exista >>> Il adaugam
            if (size >= capacity)
            {
                resize();
            }
            data[size].key = key;
            data[size].value = value;
            data[size].index = size;
            size++;
            Sort();
        } else
        {
            // Exista
            data[index].value = value;
        }
    }

    bool Get(const K &key, V &value)
    {
        int index = findIndex(key);
        if (index == -1)
        {
            return false;
        }
        value = data[index].value;
        return true;
    }

    int Count()
    {
        return size;
    }

    void Clear()
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = {};
        }
        size = 0;
    }

    bool Delete(const K &key)
    {
        int index = findIndex(key);
        if (index == -1)
        {
            return false;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
            data[i].index = i;
        }
        size--;
        return true;
    }

    V &operator[](const K key)
    {
        int index = findIndex(key);
        if (index != -1)
        {
            // Exista
            return data[index].value;
        }
        // Nu exista
        if (size >= capacity)
        {
            resize();
        }
        data[size].key = key;
        data[size].value = {};
        data[size].index = size;
        size++;
        Sort();
        return data[size - 1].value;
    }

    class Iterator
    {
    public:
        Pair *data;

        Iterator &operator++()
        {
            data++;
            return *this;
        }

        bool operator !=(Iterator &other)
        {
            return data != other.data;
        }

        Pair operator*()
        {
            return *data;
        }
    };

    Iterator begin() const
    {
        Iterator it;
        it.data = &data[0];
        return it;
    }

    Iterator end() const
    {
        Iterator it;
        it.data = &data[size];
        return it;
    }

    bool Includes(const Map<K, V> &map)
    {
        bool result = true;
        for (auto [key, value, index]: map)
        {
            if (findIndex(key) == -1)
            {
                result = false;
                break;
            }
        }
        return result;
    }
};


#endif //MAP_H
