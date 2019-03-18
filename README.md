# Nemostatic library c++

Code is originally written by Prof. Wooyoung Kim.

## Getting Started

Compare to Java, C++ is close to system level; however the performance of C++ is slower than Java nemolibrary. The algorithm that both C++, and Java invoke is the same. We provided C++ code with some optimization; however the performance of C++ code still need to be improved.

### Prerequisites

- G++ 5.4 or greater.
- GNU/Linux environemtn
- cmake 3.5.1 or greater



### Compilie and run

```
cmake CMakeLists.txt
make -j4
./nemolib test_samples/mytest.txt 3 1000 0
```

example output
```
Analyzing target graph...
238 => 0.259794
78 => 0.740206
Analyzing random graphs...
Analyzing random graph 100...
Analyzing random graph 200...
Analyzing random graph 300...
Analyzing random graph 400...
Analyzing random graph 500...
Analyzing random graph 600...
Analyzing random graph 700...
Analyzing random graph 800...
Analyzing random graph 900...
Analyzing random graph 1000...
Comparing target graph to random graphs
Label   RelFreq         Mean            StDev           Z-Score         P-Value
238     25.979%         1.313%          0.002           112.578         0.000
78      74.021%         98.687%         0.002           -112.578                1.000

Time = 8176.177ms
```

## test script
In order to test the program, you can simple run the test script. It will save the result into result.txt
```
sh ./run_test.sh
```

## Acknowledgments
* Prof. Wooyoung Kim



# Change Log (included in git log, or better way to include?)
## graph.hpp -> graph.h
- unsigned long long -> uint_fast64_t (gaurantee the fastest int)

## Subgraph.h and Subgraph.cpp
- remove Subgraph copy(); because default copy constructor, and assignment operator will handle it.
- Invoke member initializer to increase the performance
- invoke const refernce, and references to increase the performance.
- removed the virtual destructor which does nothing.
- improved contains from n^2 to n
- ostream overloading from n^2 to n (by invoking iterator)
- subgraph get function return type from int to vertex

## NautyLink.h NautyLink.cpp
- Now the constructor invoke the member initializer
- int get_G_M() just implemented (merely returning G_M)
- nautylabel invoke the iterator so that it is from (n*n*(2n)) -> (n*n), or simply from O(n^3) to O(n^2)

## Graph.h Graph.cpp (Upgrade)
- Noticed that the graph does not invoke the hash properly. (could have been better)
- Design goal, make the best performance from the code.
- Unnecessary Edge class deletec
- in addVertex, change the if logic where there is wrong -1.
- in addVertex, some if statement to ternary statement
- Invoking file read buffer to read file even faster (buffer size = 1MB)

## RandESU.h RandESU.cpp
- post order increment to preorder increment
- Make use of refernce more.