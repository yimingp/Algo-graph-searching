//
// Created by Yiming  Pan on 4/15/20.
//

#include "GraphGenerator.h"

void GraphGenerator::run(){
    for(size_t i = 0; i < numOfGraphs; ++i) {
        int weight;
        size_t temp = 0;
        size_t temp2 = 0;
        std::srand(time(0));
        std::ofstream out;
        out.open(outputPath + static_cast<char>(i+48) + ".txt");
        std::vector<std::string> nodeNames;
        std::vector<
        std::pair<
        std::vector<
        std::pair<std::string,bool>>,bool>> edges;
        for(size_t i = 0; i < numOfNodes; ++i){
            nodeNames.push_back(nodeNameGenerator(i));
        }
        for(size_t i = 0; i < numOfNodes; ++i){
            edges.emplace_back();
            edges.back().second = false;
            for(size_t j = 0; j < numOfNodes; ++j){
                if(j != i){
                    edges.back().first.emplace_back(nodeNames[i] + " - " + nodeNames[j],false);
                }
            }
        }
        out << numOfNodes << std::endl;
        for(std::string& name : nodeNames){
            out << name << std::endl;
        }
        out << "[undirected]" << std::endl;

        if(numOfEdges > (numOfNodes*(numOfNodes-1)/2)){
            numOfEdges = numOfNodes*(numOfNodes-1)/2;
            std::cout << "Exceed maxium edges possible, reseting number of edges to maxium" << std::endl;
        }else if(numOfEdges < numOfNodes-1){
            numOfEdges = numOfNodes - 1;
            std::cout << "Number of edges not enough to connect all nodes, reseting number of edges to minimum" << std::endl;
        }

        for(size_t i = 0; i < numOfNodes-1; ++i) {
            temp = rand() % numOfNodes;
            temp2 = rand() % (numOfNodes-1);
            while(edges[temp].second)
                temp = rand() % numOfNodes;
            edges[temp].second = true;
            while((edges[temp].first)[temp2].second)
                temp2 = rand() % (numOfNodes-1);
            (edges[temp].first)[temp2].second = true;
            if(temp2 < temp)
                (edges[temp2].first)[temp-1].second = true;
            else
                (edges[temp2+1].first)[temp].second = true;
            weight = rand() % (3 * numOfNodes) + 1;
            out << (edges[temp].first)[temp2].first << " " << weight << std::endl;
        }

        for(size_t i = numOfEdges - numOfNodes + 1; i > 0; --i){
            temp = rand() % numOfNodes;
            while((edges[temp].first)[temp2].second)
                temp2 = rand() % (numOfNodes-1);
            (edges[temp].first)[temp2].second = true;
            if(temp2 < temp)
                (edges[temp2].first)[temp-1].second = true;
            else
                (edges[temp2+1].first)[temp].second = true;
            weight = rand() % (3 * numOfNodes) + 1;
            out << (edges[temp].first)[temp2].first << " " << weight << std::endl;
        }
        out.close();
    }
}

std::string GraphGenerator::nodeNameGenerator(int num){
    int count = 0;
    std::string temp = "";
    while(num >= 25){
        num -= 25;
        ++count;
    }
    for(int i = 0; i < count; ++i){
        temp += 'Z';
    }
    temp += static_cast<char>(num+65);
    return temp;
}
