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
    explicit PriorityHeap(std::initializer_list<Comparable> list);

    void insert(const Comparable& element);
    void insert(Comparable&& element);

    void deleteMin();
    void deleteMin(Comparable& element);

    void remove(const Comparable& element);

    void makeEmpty();

    int size();

    void increaseKey(const Comparable& element);
    void decreaseKey(const Comparable& element);

private:
    int currentSize{0};
    std::vector<Comparable> PrioH;

    void buildHeap();
    void percolateDown(int whichHole);
    void percolateUp(int whichHole);
    int findPos(const Comparable& element);
};


#endif //PRIORITYHEAP_PRIORITYHEAP_HPP
