//
// Created by KAVOSH on 1/7/2024.
//
#ifndef PRIORITYHEAP_PRIORITYHEAPCORE_INL
#define PRIORITYHEAP_PRIORITYHEAPCORE_INL
#include "PriorityHeap.hpp"
#include <memory>
#include <iostream>

template<typename Comparable>
PriorityHeap<Comparable>::PriorityHeap(std::initializer_list<Comparable> list)
: PrioH(list.size()+DEFAULT_SIZE),
currentSize(list.size())
{
    for(int i{0}; i<list.size(); ++i)
        PrioH[i+1] = list.begin()[i];
    buildHeap();
}

template<typename Comparable>
PriorityHeap<Comparable>::PriorityHeap()
: PrioH(DEFAULT_SIZE)
{}

/**
 * Percolating an element added to a hole at the end
 * of the heap up until it is in its correct spot.
 */
template<typename Comparable>
void PriorityHeap<Comparable>::percolateUp(int hole) {
    // keep the element in the hole in index 0 to
    // avoid unnecessary swaps.
    PrioH[0] = std::move(PrioH[hole]);

    while(true){
        if(PrioH[0] < PrioH[hole/2]) {
            PrioH[hole] = std::move(PrioH[hole / 2]);
        }else{
            PrioH[hole] = std::move(PrioH[0]);
            break;
        }
        hole /=2;
    }
}

/**
 * Percolating an item down to find out its correct position
 * Hole is the index to start percolating
*/
template<typename Comparable>
void PriorityHeap<Comparable>::percolateDown(int hole) {
    // keep the element in the hole in index 0 to
    // avoid unnecessary swaps.
    PrioH[0] = std::move(PrioH[hole]);

    int child;

    while(true) {
        child = 2*hole;
        if(child > currentSize){
            break;
        }
        if(child != currentSize && PrioH[child + 1] < PrioH[child])
            ++child;
        if(PrioH[child] < PrioH[0])
            PrioH[hole] = std::move(PrioH[child]);
        else
            break;
        hole = child;
    }

    PrioH[hole] = std::move(PrioH[0]);
}


/**
 * Routines to insert an element into the heap
 * and allowing duplicate elements to occur
 */
template<typename Comparable>
void PriorityHeap<Comparable>::insert(const Comparable &element) {
    expand();
    PrioH[currentSize+1] = element;
    percolateUp(++currentSize);
}

template<typename Comparable>
void PriorityHeap<Comparable>::insert(Comparable &&element) {
    expand();
    PrioH[currentSize+1] = element;
    percolateUp(++currentSize);
}

template<typename Comparable>
void PriorityHeap<Comparable>::expand() {
    if(PrioH.size() == currentSize - 1){
        PrioH.resize(currentSize*2);
    }
}

template<typename Comparable>
void PriorityHeap<Comparable>::reduce() {
    if(currentSize <= PrioH.size()/2){
        PrioH.resize(PrioH.size()/2+1);
    }
}

template<typename Comparable>
void PriorityHeap<Comparable>::buildHeap() {
    for(int i{currentSize/2}; i > 0; --i){
        percolateDown(i);
    }
}

template<typename Comparable>
void PriorityHeap<Comparable>::printHeap() {
    for(int i{1}; i<= currentSize; ++i){
        std::cout<<i<<"+--+"<<PrioH[i]<<std::endl;
    }
}

#endif //PRIORITYHEAP_PRIORITYHEAPCORE_INL
