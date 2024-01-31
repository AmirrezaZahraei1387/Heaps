//
// Created by KAVOSH on 1/7/2024.
//
#ifndef PRIORITYHEAP_PRIORITYHEAP_HPP
#define PRIORITYHEAP_PRIORITYHEAP_HPP
#include <vector>
#include <initializer_list>

enum PrintType{
    AS_ARRAY,
    AS_TREE,
};

template<typename Comparable>
class PriorityHeap{
public:
    using INDEXS = std::vector<int>;

    explicit PriorityHeap();
    PriorityHeap(std::initializer_list<Comparable> list);

    void insert(const Comparable& element);
    void insert(Comparable&& element);

    void printHeap(PrintType printType, std::ostream& out);

    void deleteMin();
    void deleteMin(Comparable& element);

    bool isEmpty();
    void makeEmpty();

    int size();

private:
    static const int ROOT_INDEX{1};
    static constexpr int DEFAULT_SIZE{13};
    int currentSize{0};
    std::vector<Comparable> PrioH;

    void buildHeap();

    void percolateDown(int hole);
    void percolateUp(int hole);

    void printHeapAsArray(int hole, std::ostream& out);
    void printHeapAsTree(int hole, std::ostream& out);

    void expand();
    void reduce();
};

#include "PriorityHeapCore.inl"
#include "PriorityHeapInter.inl"

#endif //PRIORITYHEAP_PRIORITYHEAP_HPP
