//
// Created by KAVOSH on 1/7/2024.
//
#ifndef PRIORITYHEAP_PRIORITYHEAP_HPP
#define PRIORITYHEAP_PRIORITYHEAP_HPP
#include <vector>
#include <initializer_list>

template<typename Comparable>
class PriorityHeap{
public:
    explicit PriorityHeap();
    PriorityHeap(std::initializer_list<Comparable> list);

    void insert(const Comparable& element);
    void insert(Comparable&& element);

    void printHeap();

    void deleteMin();
    void deleteMin(Comparable& element);

    void remove(const Comparable& element);

    bool isEmpty();
    void makeEmpty();

    int size();

    void increaseKey(const Comparable& element);
    void decreaseKey(const Comparable& element);

private:
    static constexpr int DEFAULT_SIZE{10};
    int currentSize{0};
    std::vector<Comparable> PrioH;

    void buildHeap();

    void percolateDown(int hole);
    void percolateUp(int hole);

    void expand();
    void reduce();
};

#include "PriorityHeapCore.inl"

#endif //PRIORITYHEAP_PRIORITYHEAP_HPP
