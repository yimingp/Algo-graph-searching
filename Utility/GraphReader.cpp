//
// Created by Yiming  Pan on 5/6/20.
//

#include "GraphReader.h"

void GraphReader::print(){
    for (Vertex<std::string> &v : graph)
    {
        std::cout << "----------------\n";
        std::cout << "vertex key: " << v.getObj() << "\n";
        std::cout << "vertex id: " << v.getId() << "\n";
        std::cout << "vertex edges: \n";
        for (auto i = v.second.begin(); i != v.second.end(); ++i)
        {
            std::cout << "\t " << v.getId() << " -> " << i->first << " weight: " << i->second << "\n";
        }
    }
    std::cout << std::endl;
}

void GraphReader::addNewVertex(std::string key)
{
    graph.emplace_back();
    graph.back().setObj(key);
    graph.back().setId(graph.size() - 1);
}

int GraphReader::findId(std::string key)
{
    for (Vertex<std::string> &v : graph)
    {
        if (v.getObj() == key)
        {
            return v.getId();
        }
    }
    throw "Not such vertex in network";
}

void GraphReader::addNewEdge(std::string first, std::string second, int weight)
{
    std::string temp;
    bool firstVertexCheck = false;
    bool secondVertexCheck = false;

    for (Vertex<std::string> &v : graph)
    {
        if (firstVertexCheck && secondVertexCheck)
            break;

        temp = v.getObj();

        if (temp == first)
        {
            v.second.emplace_back(findId(second),weight);
            v.resetIterator();
            firstVertexCheck = true;
            continue;
        }

        if (temp == second)
        {
            v.second.emplace_back(findId(first),weight);
            v.resetIterator();
            secondVertexCheck = true;
            continue;
        }
    }
}

std::list<Vertex<std::string>> &GraphReader::readFile(std::string filePath)
{

    std::ifstream srcIn;

    int numOfNodes;
    std::string buffer;

    srcIn.open(filePath);

    if (!srcIn.good())
        throw "Can not open source file";

    srcIn >> buffer;

    numOfNodes = std::stoi(buffer);

    for (int i = 0; i < numOfNodes; ++i)
    {
        srcIn >> buffer;
        addNewVertex(buffer);
    }

    srcIn >> buffer; // discard [undirected]
    srcIn.ignore();

    while (true)
    {
        getline(srcIn, buffer);
        if(buffer != ""){
            addNewEdge(buffer.substr(0, buffer.find_first_of('-') - 1), buffer.substr(buffer.find_first_of('-') + 2, (buffer.find_last_of(' ')-buffer.find_first_of('-')-2)),
                       std::stoi(buffer.substr(buffer.find_last_of(' ') + 1)));
        }
        if (srcIn.eof())
            break;
    }

    srcIn.close();

    return graph;
}