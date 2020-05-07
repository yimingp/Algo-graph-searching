//
// Created by Yiming  Pan on 5/6/20.
//

#include "../Utility/GraphReader.h"

#ifndef INC_20S_3353_PA04_GRAPHSEARCHER_H
#define INC_20S_3353_PA04_GRAPHSEARCHER_H

class GraphSearcher_interface {
public:
    virtual void search(std::string, std::string, std::list<Vertex<std::string>>&) = 0;

    int findId(std::string key,std::list<Vertex<std::string>>& graph){
        for (Vertex<std::string> &v : graph)
        {
            if (v.getObj() == key)
            {
                return v.getId();
            }
        }
        throw "Not such vertex in network";
    }

    Vertex<std::string>* jumpTo(int id, std::list<Vertex<std::string>>& graph){
        for (Vertex<std::string> &v : graph)
        {
            if (v.getId() == id)
            {
                return &v;
            }
        }
        throw "destination vertex is missing";
    }
};


#endif //INC_20S_3353_PA04_GRAPHSEARCHER_H
