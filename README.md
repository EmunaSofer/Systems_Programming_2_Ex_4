# MyContainer Project

**Overview**
This project implements a C++ template class called **MyContainer** that represents a dynamic container for comparable objects. The container supports various operations including dynamic addition and removal of elements, and provides six different iterator types for traversing elements in different orders. The class includes iterators for ascending order, descending order, side-cross order, reverse order, insertion order, and middle-out order traversal.

**Requirements**
Before running the project, ensure that your system has the following tools:
* C++11 or later
* g++ (C++ compiler)
* Valgrind (for memory leak detection)

**File Structure**
The project is divided into several files:
* **MyContainer.hpp** – Header file containing the template declaration of the `MyContainer` class and all its iterator implementations.
* **test.cpp** – Unit test file using the doctest framework to test all container operations and iterators.
* **main.cpp** – A demonstration file that showcases how to use the `MyContainer` class and its various iterators.
* **doctest.h** – Testing framework header file for unit testing.
* **Makefile** – A Makefile for compiling the project, running tests, and memory leak detection.

**Running the Project**
After downloading all the files, run the following commands in your terminal:
1. **Build and run demonstration**: `make Main`
2. **Run unit tests**: `make test`
3. **Check for memory leaks**: `make valgrind`
4. **Clean up**: `make clean`

**Explanation of Functions**

**Container Operations:**
* **MyContainer()** - Creates an empty container (default constructor).
* **void addElement(const T& element)** - Adds an element to the container.
* **void remove(const T& element)** - Removes all instances of an element from the container (throws exception if element not found).
* **size_t size()** - Returns the number of elements in the container.
* **operator<<** - Stream output operator for printing the container in format {element1, element2, ...}.

**Iterator Types:**
* **AscendingOrder** - Traverses elements in ascending order (smallest to largest).
* **DescendingOrder** - Traverses elements in descending order (largest to smallest).
* **SideCrossOrder** - Alternates between smallest and largest remaining elements from sorted order.
* **ReverseOrder** - Traverses elements in reverse insertion order.
* **Order** - Traverses elements in original insertion order.
* **MiddleOutOrder** - Starts from middle element, then alternates left-right from sorted order.

**Iterator Access Methods:**
* **begin_ascending_order() / end_ascending_order()** - Returns begin/end iterators for ascending traversal.
* **begin_descending_order() / end_descending_order()** - Returns begin/end iterators for descending traversal.
* **begin_side_cross_order() / end_side_cross_order()** - Returns begin/end iterators for side-cross traversal.
* **begin_reverse_order() / end_reverse_order()** - Returns begin/end iterators for reverse traversal.
* **begin_order() / end_order()** - Returns begin/end iterators for insertion order traversal.
* **begin_middle_out_order() / end_middle_out_order()** - Returns begin/end iterators for middle-out traversal.

**Iterator Behavior Examples**
For container `[7, 15, 6, 1, 2]`:
* **AscendingOrder**: 1, 2, 6, 7, 15
* **DescendingOrder**: 15, 7, 6, 2, 1
* **SideCrossOrder**: 1, 15, 2, 7, 6
* **ReverseOrder**: 2, 1, 6, 15, 7
* **Order**: 7, 15, 6, 1, 2
* **MiddleOutOrder**: 6, 15, 1, 7, 2

**Contact**
* Email: [emuna002@gmail.com]
