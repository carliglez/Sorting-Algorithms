/**
 * @brief Declaración de la clase HeapSort.
 * 
 */

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include "sort_method.h"

/**
 * @class HeapSort
 * @brief Clase derivada para la ordenación por HeapSort.
 * 
 */
template<class Key>
class HeapSort : public SortMethod<Key> {
  public:
    HeapSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      heap_sort(this->getSequence(), this->getSize());
    }
};

#endif  // HEAP_SORT_H_