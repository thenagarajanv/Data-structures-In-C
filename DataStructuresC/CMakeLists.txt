cmake_minimum_required(VERSION 3.21)
project(DataStructuresC C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructuresC main.c cmake-build-debug/Trees.c BinarySearchTree.c LinkedList.c Stacks.cpp Stacks.c Queues.c StackUsingQueue.c CircularQueues.c HashingC.c Sorting.c Searching.c)
