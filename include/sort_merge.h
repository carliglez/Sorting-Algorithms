/**
 * @brief Declaración de la clase MergeSort.
 * 
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "sort_method.h"

/**
 * @class MergeSort
 * @brief Clase derivada para la ordenación por mezcla.
 * 
 */
template<class Key>
class MergeSort : public SortMethod<Key> {
  public:
    MergeSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      merge_sort(this->getSequence(), this->getSize());
    }
};

#endif  // MERGE_SORT_H_