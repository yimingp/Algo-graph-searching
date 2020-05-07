//
// Created by Yiming  Pan on 4/15/20.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <utility>

#ifndef INC_20S_3353_PA03_GRAPHGENERATOR_H
#define INC_20S_3353_PA03_GRAPHGENERATOR_H

// This generator generates weighted graph

class GraphGenerator {
private:
    size_t numOfNodes;
    size_t numOfEdges;
    std::string outputPath;
    size_t numOfGraphs;

    std::string nodeNameGenerator(int);

public:
    GraphGenerator(size_t numOfNodes=10, size_t numOfEdges=15,std::string outputPath="generatedGraph", size_t numOfGraphs=1) : numOfNodes(numOfNodes), numOfEdges(numOfEdges), outputPath(outputPath),  numOfGraphs(numOfGraphs) {}

    void run();
};


#endif //INC_20S_3353_PA03_GRAPHGENERATOR_H
