cmake_minimum_required(VERSION 3.5.1)
project(nemolib_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(nauty)

#IF (CMAKE_COMPILER_IS_GNUCC)
#    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O2")
#    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O2")
#ENDIF (CMAKE_COMPILER_IS_GNUCC)

add_executable(nemolib
        main.cpp
        nauty/gtools.c
        nauty/gtools.h
        nauty/naugraph.c
        nauty/naurng.c
        nauty/naurng.h
        nauty/nausparse.c
        nauty/nausparse.h
        nauty/nautil.c
        nauty/nautinv.c
        nauty/nautinv.h
        nauty/naututil.c
        nauty/naututil.h
        nauty/nauty.c
        nauty/nauty.h
        nauty/schreier.c
        nauty/schreier.h
        nauty/sorttemplates.c
        ESU.cpp
        ESU.h
        Graph.cpp
        Graph.h
        graph64.hpp
        NautyLink.cpp
        NautyLink.h
        RandESU.cpp
        RandESU.h
        RandomGraphAnalysis.cpp
        RandomGraphAnalysis.h
        RandomGraphGenerator.cpp
        RandomGraphGenerator.h
        StatisticalAnalysis.cpp
        StatisticalAnalysis.h
        Subgraph.cpp
        Subgraph.h
        SubgraphCount.cpp
        SubgraphCount.h
        SubgraphEnumerationResult.h
        SubgraphProfile.cpp
        SubgraphProfile.h)
