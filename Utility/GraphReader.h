//
// Created by Yiming  Pan on 5/6/20.
//

#include <string>
#include <fstream>
#include <iostream>
#include "Vertex.h"

#ifndef INC_20S_3353_PA04_GRAPHREADER_H
#define INC_20S_3353_PA04_GRAPHREADER_H


class GraphReader {
private:
    int findId(std::string);
    void addNewVertex(std::string);
    void addNewEdge(std::string,std::string,int);
    std::list<Vertex<std::string>> graph;
public:
    void print();
    std::list<Vertex<std::string>>& readFile(std::string);
};


#endif //INC_20S_3353_PA04_GRAPHREADER_H
