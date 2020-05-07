//
// Created by Yiming  Pan on 5/6/20.
//

#include "GraphSearcher_trivial.h"

void GraphSearcher_trivial::printResult() {
    int weight;
    for(auto &big_p : pathList){
        weight = 0;
        for(auto small_p : big_p.first){
            weight += small_p.second;
        }
        big_p.second = weight;
    }

    size_t size = pathList[0].first.size();
    weight = pathList[0].second;
    std::vector<std::pair<std::vector<std::pair<std::string,int>>,int>> shortestPathes;
    std::vector<std::pair<std::vector<std::pair<std::string,int>>,int>> smallestWeightPathes;
    for (auto &sub_v : pathList)
    {
        if(sub_v.first.size() < size)
            size = sub_v.first.size();
        if(sub_v.second < weight)
            weight = sub_v.second;
    }
    for (auto &sub_v : pathList){
        if(sub_v.first.size() == size){
            shortestPathes.push_back(sub_v);
        }
        if(sub_v.second == weight){
            smallestWeightPathes.push_back(sub_v);
        }
    }
//    for(auto shortestPath : shortestPathes){
//        std::cout << "shortest level path : {";
//        for (size_t i = 0; i < shortestPath.first.size() - 1; ++i)
//        {
//            std::cout << "(" << shortestPath.first[i].first << " - " << shortestPath.first[i+1].first;
//            if (i + 1 == shortestPath.first.size() - 1)
//                std::cout << ")";
//            else
//                std::cout << "), ";
//        }
//        std::cout << "} total weight: " << shortestPath.second << std::endl;
//    }
    std::cout << std::endl;
    for(auto shortestPath : smallestWeightPathes){
        std::cout << "trivial solution : {";
        for (size_t i = 0; i < shortestPath.first.size() - 1; ++i)
        {
            std::cout << "(" << shortestPath.first[i].first << " - " << shortestPath.first[i+1].first;
            if (i + 1 == shortestPath.first.size() - 1)
                std::cout << ")";
            else
                std::cout << "), ";
        }
        std::cout << "} total weight: " << shortestPath.second << std::endl;
    }
}

int GraphSearcher_trivial::getWeight(std::vector<std::pair<int,int>> & v, int second) {
    for(std::pair<int,int> p : v){
        if(p.first == second){
            return p.second;
        }
    }
    throw "not found";
}

void GraphSearcher_trivial::addNewPath(std::stack<Vertex<std::string> *> & s) {

    pathList.emplace_back();
    pathList.back().second = 0;

    auto stack = s;

    std::vector<std::pair<int,int>> temp;

    while (!stack.empty())
    {
        if(pathList.back().first.size() > 0){
            pathList.back().first.front().second = getWeight(temp,stack.top()->getId());
        }
        pathList.back().first.emplace(pathList.back().first.begin(), stack.top()->getObj() ,0);
        temp.clear();
        for(auto pair : stack.top()->second){
            temp.push_back(pair);
        }
        stack.pop();
    }
}

void GraphSearcher_trivial::search(std::string root, std::string target, std::list<Vertex<std::string>> &graph)
{
    bool exhausted = true;
    int tempInt;
    int levelCounter = 0;
    int shortestLevelReached = graph.size();
    int firstVertexId = findId(root, graph);
    int secondVertexId = findId(target, graph);
    Vertex<std::string> *temp;
    Vertex<std::string> *temp2;

    std::stack<Vertex<std::string> *> stack;

    stack.push(jumpTo(firstVertexId, graph));
    stack.top()->first = true;

    while (!stack.empty())
    {
        temp = stack.top();

        while (temp->hasNext())
        {
            tempInt = temp->getNext().first;
            temp2 = jumpTo(tempInt, graph);

            if (tempInt == secondVertexId)
            {
                shortestLevelReached = levelCounter;
                stack.push(temp2);
                addNewPath(stack);
                stack.pop();
                continue;
            }

            if (!temp2->first && levelCounter < shortestLevelReached)
            {
                exhausted = false;
                temp2->first = true;
                stack.push(temp2);
                ++levelCounter;
                break;
            }
        }

        if (exhausted)
        {
            --levelCounter;
            temp->first = false;
            temp->resetIterator();
            stack.pop();
        }
        else
            exhausted = true;
    }

    printResult();
}