/**
 * @brief Implementación de métodos de ordenación. La función del siguiente programa es la implementación
 * de diversos métodos de ordenación mediante plantillas de función.
 *  
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <memory>

#include "../include/sort_method.h"
#include "../include/sort_selection.h"
#include "../include/sort_insertion.h"
#include "../include/sort_merge.h"
#include "../include/sort_quicksort.h"
#include "../include/sort_shellsort.h"
#include "../include/sort_radixsort.h"
#include "../include/sort_heapsort.h"
#include "../include/sort_strategy.h"

/**
 * @brief Método main del programa principal
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char * argv[]) {
  int option = 0;
  
  // tamaño de la secuencia
  unsigned size = 0;
  std::cout << "Introduzca el tamaño de la secuencia: ";
  std::cin >> size;
  std::vector<long> sequence(size);
  
  // introducir los valores de forma aleatoria o manualmente
  std::cout << std::endl;
  std::cout << "¿Cómo desea introducir los valores a la secuencia?" << std::endl;
  std::cout << "1. Introducirlos manualmente" << std::endl; 
  std::cout << "2. Introducirlos aleatoriamente" << std::endl;
  std::cout << "→ ";
  std::cin >> option;
  while(true) {
    if (option == 1 || option == 2) {
      break;
    }
    std::cout << "No se ha elegido una opción correcta" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
  }
  if (option == 1) {
    long value = 0;
    for (int i = 0; i < size; ++i) {
      std::cout << "Introduzca el valor " << i << " de la secuencia: ";
      std::cin >> value;
      sequence[i] = value;
    }
  } else if (option == 2) {
    int value = 0;
    srand(time(NULL));  // pseudo-aleatorio
    for (int i = 0; i < size; ++i) {
      long random_value = 1000+rand()%(10000-1000);  // entre 1000 y 9999
      sequence[i] = random_value;
    }
  }

  // no se asigna ninguna strategy por defecto
  SortStrategy<long> strategy;

  // menú
  bool quit = false;
  option = 0;
  quit = false;  
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Seleccione una acción a realizar: " << std::endl;
    std::cout << "1. Elegir la función de ordenación" << std::endl;
    std::cout << "2. Ordenar la secuencia de valores" << std::endl;
    std::cout << "3. Salir del programa" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
    int option_function;
    switch (option) {
      case 1:
        std::cout << std::endl;
        std::cout << "1. Ordenación por Inserción" << std::endl; 
        std::cout << "2. Ordenación por MergeSort" << std::endl; 
        std::cout << "3. Ordenación por Selección" << std::endl; 
        std::cout << "4. Ordenación por QuickSort" << std::endl; 
        std::cout << "5. Ordenación por Incrementos Decrecientes (ShellSort)" << std::endl; 
        std::cout << "6. Ordenación por HeapSort" << std::endl; 
        std::cout << "7. Ordenación por RadixSort" << std::endl;
        std::cout << "→ ";
        std::cin >> option_function;
        switch(option_function) {
          case 1: {
            std::cout << "\n*Ordenación por InsertionSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> insertion_sort = std::make_unique<InsertionSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(insertion_sort));  // ordenación por insertionsort
            break;
          }
          case 2: {
            std::cout << "\n*Ordenación por MergeSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> merge_sort = std::make_unique<MergeSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(merge_sort));  // ordenación por mergesort
            break;
          }
          case 3: {
            std::cout << "\n*Ordenación por SelectionSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> selection_sort = std::make_unique<SelectionSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(selection_sort));  // ordenación por selectionsort
            break;
          }
          case 4: {
            std::cout << "\n*Ordenación por QuickSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> quick_sort = std::make_unique<QuickSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(quick_sort));  // ordenación por quicksort
            break;
          }
          case 5: {
            std::cout << "\n*Ordenación por Incrementos Decrecientes (ShellSort) seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> shell_sort = std::make_unique<ShellSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(shell_sort));  // ordenación por shellsort
            break;
          }
          case 6: {
            std::cout << "\n*Ordenación por HeapSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> heap_sort = std::make_unique<HeapSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(heap_sort));  // ordenación por heapsort
            break;
          }
          case 7: {
            std::cout << "\n*Ordenación por RadixSort seleccionada*" << std::endl;
            std::unique_ptr<SortMethod<long>> radix_sort = std::make_unique<RadixSort<long>>(size, sequence);
            strategy.SetStrategy(std::move(radix_sort));  // ordenación por radixsort
            break;
          }
          default:
            break;
        }
        break;  // vuelve al menú anterior (acciones a realizar)
      case 2:
          strategy.Process(sequence, size);
        break;
      case 3:
        quit = true;
        break;
      default:
        break;        
    }
  }  

  std::cout << std::endl;
  std::cout << "Saliendo del programa..." << std::endl;
  return 0;
}