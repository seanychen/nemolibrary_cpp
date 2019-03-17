# Project Title

Nemostatic library, and the code is originally written by Prof. Wooyoung Kim.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc



# Change Log
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