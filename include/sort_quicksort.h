/**
 * @brief Declaración de la clase QuickSort.
 * 
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include "sort_method.h"

/**
 * @class QuickSort
 * @brief Clase derivada para la ordenación rápida.
 * 
 */
template<class Key>
class QuickSort : public SortMethod<Key> {
  public:
    QuickSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      quick_sort(this->getSequence(), this->getSize());
    }
};

#endif  // QUICK_SORT_H_