//
// Created by Tori Lim on 11/30/23.
//

#include "UnionFind.h"
#include <iostream>

int main() {
    WeightedUnionFind wf(5);
    wf.viewIds();
    wf.createUnion(1, 2);
    wf.createUnion(3, 4);
    wf.createUnion(1, 4);
    wf.viewIds();
    std::cout << wf.connected(1, 4) << std::endl;
    return 0;
}
