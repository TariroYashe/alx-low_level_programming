#!/bin/bash

# Compile all .c files into object files.
gcc -c -fPIC *.c

# Create the dynamic library (liball.so) from the object files.
gcc -shared -o liball.so *.o

# Clean up the object files.
rm -f *.o
