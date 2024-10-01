/**
 * @brief Declaración de la clase InsertionSort.
 * 
 */

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "sort_method.h"

/**
 * @class InsertionSort
 * @brief Clase derivada para la ordenación por inserción.
 * 
 */
template<class Key>
class InsertionSort : public SortMethod<Key> {
  public:
    InsertionSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      insertion_sort(this->getSequence(), this->getSize());
    }
};

#endif  // INSERTION_SORT_H_