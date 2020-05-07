//
// Created by Yiming  Pan on 5/6/20.
//

#include "GraphSearcher_interface.h"

#ifndef INC_20S_3353_PA04_GRAPHSEARCHER_OPTIMAL_H
#define INC_20S_3353_PA04_GRAPHSEARCHER_OPTIMAL_H


class GraphSearcher_optimal : public GraphSearcher_interface{
private:
    bool checkEmpty(std::list<Vertex<std::string>>&);
public:
    void search(std::string, std::string, std::list<Vertex<std::string>>&);
};


#endif //INC_20S_3353_PA04_GRAPHSEARCHER_OPTIMAL_H
