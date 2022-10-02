## Parallelization with OpenMP

Parallel programming is the concept of breaking up the work of a problem into smaller tasks and using a set of compute resources to work on it simultaneously, to solve the problem in a lesser amount of time than a single resource working on the same problem. The C programming language is a commonly used language along with the [OpenMP](https://www.openmp.org/resources/) API to achieve this in programs.

This concept is specially useful in complex problems (such as image convolution) that require complex solutions. In this example, the problem will be to solve a summation equation for a very large positive integer _N_, in order to caluclate a value for [pi](https://en.wikipedia.org/wiki/Pi). The equation used is given below.

<img src="https://user-images.githubusercontent.com/62464945/193469582-bb77fcb4-b6bc-49cf-a74e-4a76b1c09e52.png" width="800" />

The solution uses parallel programming to divide and the summation workload, which is done by a programming loop. This loop is parallelized by the line
```c
#pragma omp parallel for reduction(+:value)
```

This line does 3 things:
- omp parallel for - Is a combination of [omp parallel](https://www.ibm.com/docs/en/xl-c-aix/13.1.2?topic=processing-pragma-omp-parallel) and [omp for](https://www.ibm.com/docs/en/xcfbg/121.141?topic=processing-pragma-omp). 
  - `omp parallel` instructs compiler to parallelize the following code block (the loop) and creates a team of threads.
  - `omp for` distributes the work of the loop among the team of threads created with `omp parallel`.
- reduction(+:value) - Each thread has their own value for the `value` variable of the loop (the answer for each iteration of the summation) and the addition operator (+) is finally added to all these values to give the answer for the summation (the final value of pi).
