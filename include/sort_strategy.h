/**
 * @brief Declaración de la clase SortStrategy para facilitar el cambio de ordenación del programa.
 * 
 */

#ifndef SORT_STRATEGY_H_
#define SORT_STRATEGY_H_

#include <iostream>
#include <vector>
#include <memory>  // std::unique_ptr permite que la memoria se gestione automáticamente, evitando la necesidad de usar delete

#include "sort_method.h"

/**
 * @brief Clase strategy.
 * 
 * @tparam Key
 * 
 */
template<class Key>
class SortStrategy {
  public:
    SortStrategy(std::unique_ptr<SortMethod<Key>> function = nullptr);
    ~SortStrategy() = default;  // no necesitamos destructor

    void SetStrategy(std::unique_ptr<SortMethod<Key>> function);
    void Process(const std::vector<Key>& sequence, unsigned size);

  private:
    std::unique_ptr<SortMethod<Key>> function_;
};

/**
 * @brief Constructor que recibe un puntero a una función de ordenación
 * 
 * @tparam Key
 * @param function
 */
template<class Key>
SortStrategy<Key>::SortStrategy(std::unique_ptr<SortMethod<Key>> function)
  : function_(std::move(function)) {}  // std::move() transferire la propiedad del puntero a la clase SortStrategy, evitando la copia de punteros

/**
 * @brief Método setter para la strategy seleccionada
 * 
 * @tparam Key 
 * @param function 
 */
template<class Key>
void SortStrategy<Key>::SetStrategy(std::unique_ptr<SortMethod<Key>> function) {
  // si el puntero recibido es nulo, salimos sin hacer nada
  if (!function) {
    return;
  }

  // si ya hay una estrategia y es la misma, no hacemos nada
  if (function_ && typeid(*function_) == typeid(*function)) {
    std::cout << "\nLa función de ordenación seleccionada ya está asignada." << std::endl;
    return;
}

  // asignamos la nueva estrategia
  function_ = std::move(function);
  std::cout << "\nLa función de ordenación ha sido asignada correctamente." << std::endl;
}

/**
 * @brief Método para procesar la ordenación seleccionada
 * 
 * @tparam Key
 * @param sequence
 * @param size
 */
template<class Key>
void SortStrategy<Key>::Process(const std::vector<Key>& sequence, unsigned size) {
  if (!function_) {
    std::cerr << "Error: No hay función de ordenación asignada." << std::endl;
    return;
  }

  std::cout << "\n- Secuencia original: ";
  for (int i = 0; i < size; ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl << std::endl;
  
  function_->Sort();

  std::cout << "\n- Secuencia ordenada: ";
  for (int i = 0; i < size; ++i) {
    std::cout << function_->getSequence()[i] << " ";
  }
  std::cout << std::endl; 
}

#endif  // SORT_STRATEGY_H_