//
// Created by KAVOSH on 1/7/2024.
//

#ifndef PRIORITYHEAP_PRIORITYHEAPINTER_INL
#define PRIORITYHEAP_PRIORITYHEAPINTER_INL
#include "PriorityHeap.hpp"
#include <stdexcept>

template<typename Comparable>
bool PriorityHeap<Comparable>::isEmpty() {
    return currentSize == 0;
}

template<typename Comparable>
void PriorityHeap<Comparable>::deleteMin() {
    if(isEmpty()){
        throw std::underflow_error("request for deleteMin while table is empty");
    }
    PrioH[1] = std::move(PrioH[currentSize--]);
    percolateDown(1);
}

template<typename Comparable>
void PriorityHeap<Comparable>::deleteMin(Comparable &element) {
    if(isEmpty()){
        throw std::underflow_error("request for deleteMin while table is empty");
    }

    element = std::move(PrioH[1]);
    PrioH[1] = std::move(PrioH[currentSize--]);
    percolateDown(1);
}

template<typename Comparable>
void PriorityHeap<Comparable>::remove(const Comparable &element) {

}
#endif //PRIORITYHEAP_PRIORITYHEAPINTER_INL
