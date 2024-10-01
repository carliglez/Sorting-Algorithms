/**
 * @brief Implementación de métodos de ordenación. La función del siguiente programa es la implementación
 * de diversos métodos de ordenación mediante plantillas de función. Versión de prueba.
 *
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "../include/sort_method.h"
#include "../include/sort_selection.h"
#include "../include/sort_insertion.h"
#include "../include/sort_merge.h"
#include "../include/sort_quicksort.h"
#include "../include/sort_shellsort.h"
#include "../include/sort_radixsort.h"
#include "../include/sort_heapsort.h"
#include "../include/sort_strategy.h"

// pruebas de eficiencia de los métodos de ordenación
int main(int argc, char * argv[]) {
    unsigned size = 4;
    std::vector<long> sequence(size);
    srand(time(NULL));  // pseudo-aleatorio
    for (int i = 0; i < size; ++i) {
      long random_value = 1000+rand()%(10000-1000);
      sequence[i] = random_value;
    }

    // se instancian los distintos métodos de ordenación
    SortMethod<long>* insertion_sort = new InsertionSort<long>(size, sequence);
    SortMethod<long>* merge_sort = new MergeSort<long>(size, sequence);
    SortMethod<long>* selection_sort = new SelectionSort<long>(size, sequence);
    SortMethod<long>* quick_sort = new QuickSort<long>(size, sequence);
    SortMethod<long>* shell_sort = new ShellSort<long>(size, sequence);
    SortMethod<long>* heap_sort = new HeapSort<long>(size, sequence);
    SortMethod<long>* radix_sort = new RadixSort<long>(size, sequence);

    // InsertionSort por defecto
    SortStrategy<long> sort(insertion_sort);
    sort.Process(sequence, size);

    sort.SetStrategy(selection_sort);
    sort.Process(sequence, size);

    return 0;
}