# Compilar el código fuente y generar un ejecutable: make
# Limpiar ficheros .o y ejecutable: make clean
# Ejemplo de ejecución: ./main

# Variables
CC = g++
CFLAGS = -D DEBUG -std=c++17

# Objetivo por defecto (se ejecuta al correr solo "make")
make:	include/sort_method.h include/sort_selection.h include/sort_insertion.h \
			include/sort_merge.h include/sort_quicksort.h include/sort_shellsort.h \
			include/sort_radixsort.h include/sort_heapsort.h include/sort_strategy.h \
			src/main.cc
	$(CC) $(CFLAGS) -o main src/main.cc

# Objetivo alternativo (se ejecuta al correr "make test")
test:	include/sort_method.h include/sort_selection.h include/sort_insertion.h \
			include/sort_merge.h include/sort_quicksort.h include/sort_shellsort.h \
			include/sort_radixsort.h include/sort_heapsort.h include/sort_strategy.h \
			src/test_main.cc
	$(CC) $(CFLAGS) -o test_main src/test_main.cc

# Limpiar los archivos binarios
clean:
	rm -f *.o main test_main