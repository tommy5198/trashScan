// gen.cpp
//
// generate node map
//

#include <vector>
#include <chrono>
#include <random>
#include "env.h"

std::vector<Node> GenerateNodeMap()
{
    std::vector<Node> tmp;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randGen(seed);
    for(int i = 0; i < numOfNodes; i++) {
        double x = randGen() % ((int)maxX + 1);
        double y = randGen() % ((int)maxY + 1);
        tmp.push_back((Node){x, y});
    }
    return tmp;
}


