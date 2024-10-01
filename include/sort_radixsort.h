/**
 * @brief Declaración de la clase RadixSort.
 * 
 */

#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

#include "sort_method.h"

/**
 * @class RadixSort
 * @brief Clase derivada para la ordenación por radixsort.
 * 
 */
template<class Key>
class RadixSort : public SortMethod<Key> {
  public:
    RadixSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      radix_sort(this->getSequence(), this->getSize());
    }
};

#endif  // RADIX_SORT_H_