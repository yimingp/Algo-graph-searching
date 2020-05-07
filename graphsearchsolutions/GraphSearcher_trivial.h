//
// Created by Yiming  Pan on 5/6/20.
//

#include <stack>

#include "GraphSearcher_interface.h"

#ifndef INC_20S_3353_PA04_GRAPHSEARCHER_TRIVIAL_H
#define INC_20S_3353_PA04_GRAPHSEARCHER_TRIVIAL_H


class GraphSearcher_trivial : public GraphSearcher_interface{
private:
    std::vector<std::pair<std::vector<std::pair<std::string,int>>,int>> pathList;
    void printResult();
    int getWeight(std::vector<std::pair<int,int>>&,int);
    void addNewPath(std::stack<Vertex<std::string> *> &);
public:
    void search(std::string, std::string, std::list<Vertex<std::string>>&);
};


#endif //INC_20S_3353_PA04_GRAPHSEARCHER_TRIVIAL_H
