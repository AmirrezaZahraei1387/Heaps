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
    PrioH[ROOT_INDEX] = std::move(PrioH[currentSize--]);
    percolateDown(ROOT_INDEX);

    reduce();
}

template<typename Comparable>
void PriorityHeap<Comparable>::deleteMin(Comparable &element) {
    if(isEmpty()){
        throw std::underflow_error("request for deleteMin while table is empty");
    }

    element = std::move(PrioH[ROOT_INDEX]);
    PrioH[ROOT_INDEX] = std::move(PrioH[currentSize--]);
    percolateDown(1);

    reduce();
}
#endif //PRIORITYHEAP_PRIORITYHEAPINTER_INL
