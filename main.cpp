//
// Created by Yiming  Pan on 5/6/20.
//
#include "Utility/GraphReader.h"
#include "graphgenerator/GraphGenerator.h"
#include "graphsearchsolutions/GraphSearcher_trivial.h"
#include "graphsearchsolutions/GraphSearcher_optimal.h"

#include <chrono>

using namespace std::chrono;

void resetGraph(std::list<Vertex<std::string>>& graph){
    for(auto& v : graph){
        v.reset();
    }
}

int main(){


    GraphGenerator gg(20,30);
    gg.run();   // finished with output file "generatedGraph0.txt"

    GraphReader gr;
    std::list<Vertex<std::string>> graph = gr.readFile("generatedGraph0.txt");
    gr.print();

    GraphSearcher_trivial gsT;
    GraphSearcher_optimal gsO;

    auto start = system_clock::now();
    gsT.search(graph.front().getObj(),graph.back().getObj(),graph);
    auto end = system_clock::now();
    duration<double> elapsed_time = end - start;
    std::cout << "time tooked : " << elapsed_time.count() << std::endl;

    resetGraph(graph);

    start = system_clock::now();
    gsO.search(graph.front().getObj(),graph.back().getObj(),graph);
    end = system_clock::now();
    elapsed_time = end - start;
    std::cout << "time tooked : " << elapsed_time.count() << std::endl;

    return 0;
}

