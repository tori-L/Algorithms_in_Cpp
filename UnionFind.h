//
// Created by Tori Lim on 11/30/23.
//

#include <vector>
#include <iostream>

#ifndef ALGORITHMS_IN_CPP_UNION_FIND_H
#define ALGORITHMS_IN_CPP_UNION_FIND_H

class WeightedUnionFind {
private:
    std::vector<int> ids;
    std::vector<int> weights;

    inline int root(int val) {
        // Search the hierarchy until we find the root, which is the value whose id is equal to itself
        while (ids[val] != val) {
            ids[val] = ids[ids[val]];   // Path compression
            val = ids[val];
        }
        return val;
    }
public:
    WeightedUnionFind(int n) {
        weights.assign(n, 1);
        ids = std::vector<int>(n);
        for(int i = 0; i < n; i++)
            ids[i] = i;
    }

    void createUnion(int a, int b) {
        int rootA = this->root(a);
        int rootB = this->root(b);
        if (rootA != rootB) {
            if (weights[rootA] >= weights[rootB]) {
                ids[rootB] = rootA;
                weights[rootA] += weights[rootB];
            }
            else {
                ids[rootA] = rootB;
                weights[rootB] += weights[rootA];
            }
        }
    }

    bool connected(int a, int b) { return this->root(a) == this->root(b); }

    void viewIds() {
        std::cout << "Values: ";
        for (int i = 0; i < ids.size(); i++) {
            std::cout << i << " ";
        }
        std::cout << "\nIds:    ";
        for (int i = 0; i < ids.size(); i++) {
            std::cout << ids[i] << " ";
        }
        std::cout << std::endl << "-----------------" << std::endl;
    }
};

#endif //ALGORITHMS_IN_CPP_UNION_FIND_H
