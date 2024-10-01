/**
 * @brief Implementación de las plantillas de función para los distintos algoritmos implementados.
 * 
 */

#include <iostream>
#include <vector>

/**
 * @brief Plantilla de función con el método de la ordenación por inserción
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void insertion_sort(std::vector<Key>& sequence, unsigned int size) {
  for (unsigned int i = 1; i < size; ++i) {
    Key key = sequence[i];
    int j = i - 1;
    while (j >= 0 && sequence[j] > key) {
      sequence[j + 1] = sequence[j];
      --j;
      std::cout << " >> Secuencia tras la iteración [j = " << j+2 << "]: ";
      for (unsigned int k = 0; k < size; ++k) {
        std::cout << sequence[k] << " ";
      }
      std::cout << std::endl;
    }
    sequence[j + 1] = key;
  }
}

/**
 * @brief Plantilla de función para hacer el merge del ordenación por mezcla
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param left Tamaño del lado izquierdo de la secuencia
 * @param mid Tamaño de la mitad de la secuencia
 * @param right Tamaño del lado derecho de la secuencia
 */
template <typename Key>
void merge(std::vector<Key>& sequence, unsigned int left, unsigned int mid, unsigned int right) {
  unsigned int n1 = mid - left + 1;
  unsigned int n2 = right - mid;

  std::vector<Key> L(n1);
  std::vector<Key> R(n2);

  for (unsigned int i = 0; i < n1; ++i) {
    L[i] = sequence[left + i];
  }
  for (unsigned int j = 0; j < n2; ++j) {
    R[j] = sequence[mid + 1 + j];
  }

  unsigned int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      sequence[k++] = L[i++];
    } else {
      sequence[k++] = R[j++];
    }
  }

  while (i < n1) {
    sequence[k++] = L[i++];
  }
  while (j < n2) {
    sequence[k++] = R[j++];
  }

  std::cout << " >> Secuencia después del merge: ";
  for (unsigned int k = 0; k < sequence.size(); ++k) {
    std::cout << sequence[k] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Plantilla de la sobrecarga de la función merge_sort para realizar el paso de divide y vencerás
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param left Tamaño subsecuencia izquierda
 * @param right Tamaño subsecuencia derecha
 */
template <typename Key>
void merge_sort(std::vector<Key>& sequence, unsigned int left, unsigned int right) {
  if (left >= right) {
    return;
  }

  unsigned int mid = left + (right - left) / 2;
  merge_sort(sequence, left, mid);
  merge_sort(sequence, mid + 1, right);
  merge(sequence, left, mid, right);
}

/**
 * @brief Plantilla de función con el método de la ordenación por mezcla
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void merge_sort(std::vector<Key>& sequence, unsigned int size) {
  merge_sort(sequence, 0, size - 1);
}

/**
 * @brief Plantilla de función con el método de la ordenación por selección
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void selection_sort(std::vector<Key>& sequence, unsigned int size) {
  Key x;
  for (unsigned int i = 0; i < size - 1; ++i) {
    std::cout << " >> Secuencia tras la iteración [" << i + 1 << "]: " << std::endl;
    unsigned int min = i;
    for (unsigned int j = i + 1; j < size; ++j) {
      if (sequence[j] < sequence[min]) {
        min = j;  
      }
    }
    x = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = x;

    // estado actual de la secuencia después del swap
    for (unsigned int k = 0; k < size; ++k) {
      std::cout << sequence[k] << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Plantilla de función auxiliar para hacer el método quicksort
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param ini Inicio de secuencia
 * @param fin Final de secuencia
 */
template <typename Key>
void aux_quick_sort(std::vector<Key>& sequence, int ini, int fin) {
  int i = ini;
  int f = fin;
  Key p = sequence[(i + f)/2];
  while (i <= f) {
    while (sequence[i] < p) {
      ++i;
    }
    while (sequence[f] > p) {
      --f;
    }
    if (i <= f) {
      Key aux = sequence[i];
      sequence[i] = sequence[f];
      sequence[f] = aux; 
      ++i;
      --f;
      for (int j = 0; j < fin; ++j) {
        std::cout << sequence[j] << " ";
      }
      std::cout << std::endl;
    }
  }

  if (ini < f) {
    aux_quick_sort(sequence, ini, f);  
  }
  if (i < fin) {
    aux_quick_sort(sequence, i, fin);
  }
}

/**
 * @brief Plantilla de función con el método de la ordenación por quicksort
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void quick_sort(std::vector<Key>& sequence, unsigned int size) {
  int ini = 0;
  int fin = size - 1;
  aux_quick_sort(sequence, ini, fin);   
}

/**
 * @brief Plantilla de función auxiliar para hacer el método shellsort
 * 
 * @tparam Key 
 * @param delta Valor delta
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void aux_shell_sort(int delta, std::vector<Key>& sequence, int size) {
  for (int i = delta; i < size; ++i) {
    Key x = sequence[i];
    int j = i;
    while ((j >= delta) && (x < sequence[j - delta])) {
      sequence[j] = sequence[j - delta];
      j = j - delta;
    }
    sequence[j] = x;  

    // puede ir fuera del bucle para resumir las iteraciones
    std::cout << " >>>> Secuencia tras iterar: ";
    for (int k = 0; k < size; ++k) {
      std::cout << sequence[k] << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Plantilla de función con el método de la ordenación por shellsort
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void shell_sort(std::vector<Key>& sequence, unsigned int size) {
  int delta = size;
  double alfa = 0.0;
  std::cout << "Que valor de alfa quieres(valor entre 0 y 1): ";
  std::cin >> alfa;
  while (alfa < 0.0 || alfa > 1.0) {
    if (alfa < 0.0 || alfa > 1.0) {
      std::cout << "Valor no posible, utilice otro valor: ";
      std::cin >> alfa; 
    } 
  }  
  while (delta > 1) {
    delta = delta * alfa;
    aux_shell_sort(delta, sequence, size);

    std::cout << " >> Secuencia tras delta = " << delta << ": ";
    for (int i = 0; i < size; ++i) {
      std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
  }
  
  //delta = 1;
  //aux_shell_sort(delta, sequence, size);  // itera sobre la secuencia ya ordenada
}

/**
 * @brief Plantilla función para el método down del heapsort
 * 
 * @tparam Key 
 * @param i 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void down(int i, std::vector<Key>& sequence, unsigned int size) {
  int h = i;
  int h1 = 2 * i + 1;
  int h2 = h1 + 1;

  if (h1 < size && sequence[h1] > sequence[h]) {
    h = h1;
  } 
  if (h2 < size && sequence[h2] > sequence[h]) {
    h = h2;
  }
  
  if (h != i) {
    Key aux = sequence[i];
    sequence[i] = sequence[h];
    sequence[h] = aux;
    down(h, sequence, size);
  }

  std::cout << " >>>> Secuencia tras la iteración de down[" << i << "]: ";
  for (int j = 0; j < size; j++) {
    std::cout << sequence[j] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Plantilla de función con el método de la ordenación por heapsort
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void heap_sort(std::vector<Key>& sequence, unsigned int size) {
  for (int i = size/2 - 1; i >= 0; --i) {
    down(i, sequence, size);

    std::cout << " >> Secuencia tras down(" << i << "): ";
    for (int j = 0; j < size; j++) {
      std::cout << sequence[j] << " ";
    }
    std::cout << std::endl;
  }
  
  for (int i = size - 1; i > 0; --i) {
    Key aux = sequence[0];
    sequence[0] = sequence[i];
    sequence[i] = aux;
    down(0, sequence, i);

    std::cout << " >> Secuencia tras el swap y down(" << i << "): ";
    for (int j = 0; j < size; j++) {
      std::cout << sequence[j] << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Devuelve el valor máximo de la secuencia para saber el número de dígitos
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 * @return Key 
 */
template <typename Key>
Key getMax(std::vector<Key>& sequence, unsigned int size) {
  Key max = sequence[0];
  for (int i = 1; i < size; ++i) {
    if (sequence[i] > max) {
      max = sequence[i];
    }
  }
  return max;
}

/**
 * @brief Plantilla de función auxiliar RadixSort para obtener el n-ésimo dígito
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de valores
 * @param exp 
 */
template <typename Key>
void countSort(std::vector<Key>& sequence, unsigned int size, int exp) {
  std::vector<Key> output(size);
  int i, count[10] = {0};

  for (i = 0; i < size; ++i) {
    count[(sequence[i] / exp) % 10]++;
  }
  
  for (i = 1; i < 10; ++i) {
   count[i] += count[i - 1];  
  }

  for (i = size - 1; i >= 0; --i) {
    output[count[(sequence[i] / exp) % 10] - 1] = sequence[i];
    count[(sequence[i] / exp) % 10]--;
  }

  for (i = 0; i < size; ++i) {
    sequence[i] = output[i];
  }

  std::cout << " >>>> Secuencia tras iterar con exp = " << exp << ": ";
  for (i = 0; i < size; ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout << "\n";
}

/**
 * @brief Plantilla de función con el método de la ordenación por radixsort
 * 
 * @tparam Key 
 * @param sequence Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void radix_sort(std::vector<Key>& sequence, unsigned int size) {
  Key max = getMax(sequence, size);
  int j = 0;
  for (int exp = 1; max/exp > 0; exp *= 10) {
    std::cout << " >> Secuencia antes de la iteración [" << j << "]: ";
    for (int i = 0; i < size; ++i) {
      std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

    countSort(sequence, size, exp);

    std::cout << " >> Secuencia tras la iteración [" << j << "]: ";
    for (int i = 0; i < size; ++i) {
      std::cout << sequence[i] << " ";
    }
    std::cout << "\n";
    ++j;
  } 
}