//
// Created by Yiming  Pan on 5/6/20.
//

#include "GraphSearcher_optimal.h"

bool GraphSearcher_optimal::checkEmpty(std::list<Vertex<std::string>>& graph){
    for(auto& v : graph){
        if(!v.first){
            return false;
        }
    }
    return true;
}

void GraphSearcher_optimal::search(std::string root, std::string target, std::list<Vertex<std::string>>& graph) {

    int smallestDist;
    int weight;
    Vertex<std::string>* currVertex;
    Vertex<std::string>* temp;

    int firstVertexId = findId(root, graph);
    int secondVertexId = findId(target, graph);

    std::vector<std::string> pathList;

    jumpTo(firstVertexId,graph)->currDist = 0;


    while(!checkEmpty(graph)){

        smallestDist = 999999;

        for(auto& v : graph){
            if(!v.first && v.currDist < smallestDist){
                smallestDist = v.currDist;
                currVertex = &v;
            }
        }

        currVertex->first = true;

        for(auto& u : currVertex->second){

            temp = jumpTo(u.first,graph);

            if(u.first == secondVertexId){
                weight = currVertex->currDist + u.second;
                temp->predecessor = currVertex->getId();
                goto finished;
            }

            if(temp->currDist > currVertex->currDist + u.second){
                temp->currDist = currVertex->currDist + u.second;
                temp->predecessor = currVertex->getId();
            }
        }
    }
finished:

    while(temp->predecessor != -1){
        pathList.emplace(pathList.begin(),temp->getObj());
        temp = jumpTo(temp->predecessor,graph);
    }
    pathList.emplace(pathList.begin(),root);

    std::cout << "optimal solution: {";
    for (size_t i = 0; i < pathList.size() - 1; ++i)
    {
        std::cout << "(" << pathList[i] << " - " << pathList[i+1];
        if (i + 1 == pathList.size() - 1)
            std::cout << ")";
        else
            std::cout << "), ";
    }
    std::cout << "} total weight: " << weight << std::endl;
}