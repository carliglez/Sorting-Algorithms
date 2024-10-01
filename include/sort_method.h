/**
 * @brief Declaración de la clase SortMethod.
 * 
 */

#ifndef SORT_METHOD_H_
#define SORT_METHOD_H_

#include <vector>

#include "sort_library.h"

/**
 * @class SortMethod
 * @brief Clase abstracta para la ordenación de una secuencia.
 * 
 */
template<class Key>
class SortMethod {
  private:
    unsigned int size;
    std::vector<Key> sequence;
  public:
    SortMethod(unsigned int sz, const std::vector<Key>& seq) : size(sz), sequence(seq){}

    // getters de los atributos privados de la clase base SortMethod
    unsigned int getSize() { return size; }
    std::vector<Key>& getSequence() { return sequence; }

    // método virtual Sort() que implementan las clases derivadas
    virtual void Sort() = 0;
};

#endif  // SORT_METHOD_H_