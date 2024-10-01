/**
 * @brief Declaración de la clase ShellSort.
 * 
 */

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include "sort_method.h"

/**
 * @class ShellSort
 * @brief Clase derivada para la ordenación por ShellSort.
 * 
 */
template<class Key>
class ShellSort : public SortMethod<Key> {
  public:
    ShellSort(unsigned int sz, const std::vector<Key>& seq) : SortMethod<Key>(sz, seq) {}
    void Sort() override {
      shell_sort(this->getSequence(), this->getSize());
    }
};

#endif  // SHELL_SORT_H_