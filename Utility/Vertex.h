//
// Created by Yiming  Pan on 2/27/20.
//

#include <list>
#include <vector>
#include <utility>

#ifndef INC_20S_3353_PA02_VERTEX_H
#define INC_20S_3353_PA02_VERTEX_H

template <typename T>
class Vertex
{
private:
    T obj;
    int id;

public:
    Vertex();

    bool first;
    std::vector<std::pair<int,int>> second;
    size_t index;
    int currDist;
    int predecessor;

    bool hasNext();
    const std::pair<int,int> getNext();

    const T& getObj();
    const int& getId();

    void setObj(const T&);
    void setId(const int&);

    void reset(){
        index = 0;
        first = false;
    }
    void resetIterator();
};

template <typename T>
Vertex<T>::Vertex()
{
    first = false;
    currDist = 999999;
    predecessor = -1;
}

template <typename T>
bool Vertex<T>::hasNext()
{
    return index < second.size();
}

template <typename T>
const std::pair<int,int> Vertex<T>::getNext()
{
    return second[index++];
}

template <typename T>
const T& Vertex<T>::getObj(){
    return obj;
}

template <typename T>
const int& Vertex<T>::getId(){
    return id;
}

template <typename T>
void Vertex<T>::setObj(const T& newObj){
    obj = newObj;
}

template <typename T>
void Vertex<T>::setId(const int& newId){
    id = newId;
}

template<typename T>
void Vertex<T>::resetIterator() {
    index = 0;
}

#endif //INC_20S_3353_PA02_VERTEX_H