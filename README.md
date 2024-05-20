# Max Pooling Project

This project performs max pooling operations on a 2D matrix using different methods. The methods include a naive approach and global max pooling. The project demonstrates how to apply these methods and measure their performance.

## Files

- `src/main.cpp`: The main file containing the implementation and performance measurement.
- `src/naive.h` and `src/naive.cpp`: Header and source files containing the declaration and definition of the naive max pooling function.
- `src/optimized_1.h` and `src/optimized_1.cpp`: Header and source files for the first optimized max pooling function.
- `src/optimized_2.h` and `src/optimized_2.cpp`: Header and source files for the second optimized max pooling function.
- `src/naive2.h` and `src/naive2.cpp`: Header and source files for the second naive max pooling function.

## Requirements

- C++ compiler (e.g., g++)
- C++ Standard Library

## Instructions

### Compilation

To compile the project, navigate to the `src` folder and use the following command:

```bash
cd src
g++ main.cpp naive.cpp naive2.cpp optimized_1.cpp optimized_2.cpp -o maxpooling
