/**
 * @brief Declaración de la clase SortSelection.
 * 
 */

#ifndef SORT_SELECTION_H_
#define SORT_SELECTION_H_

#include "sort_method.h"

/**
 * @class SortSelection
 * @brief Clase derivada para la ordenación por selección.
 * 
 */
template<class Key>
class SelectionSort : public SortMethod<Key> {
  public:
    SelectionSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      selection_sort(this->getSequence(), this->getSize());
    }
};

#endif  // SORT_SELECTION_H_