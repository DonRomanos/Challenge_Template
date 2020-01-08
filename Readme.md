# Onions
Just like Onions are the basics for any great dish, this is the basic for some of my projects. It is meant to be forked and provides a starting point with my most used tools and technologies, which are:

* CMake
* Conan
* GTest
* Google Microbenchmark

I use it mostly as reference and for creating some programming Challenges. This is also the reason for the folder structure.

## How to use
Requirements:
* CMake
* Conan
* Python (for Conan)

Setting up a Conan profile for your environment
```
conan profile new WhateverCompilerSettingsYouWant --detect
```
For more Infos see: https://docs.conan.io/en/latest/reference/profiles.html

Installing the Libraries using Conan
```
// Good news google benchmark is now on conan-center :)
mkdir build && cd build
conan install .. --build missing
conan build ..
```

Now you should see the library successfully compiling and running the tests.

#### Note
If you don't have the dependencies or dont want to build with them for some reason you can disable them with these CMake Options, simply set them to 'OFF'.

```
BUILD_REFERENCE
BUILD_TESTS
BUILD_BENCHMARK
```

### Alternative without Conan
Requirements:
* CMake

You can build the library without Conan if you manually install the gtest and google benchmark libraries.

Just tell Cmake where to find them by setting following CMake Variables

```
gtest_DIR
benchmark_ROOT_DIR
```

You can do so via command line
```
cmake -Dgtest_DIR=usr/local/... -Dbenchmark_ROOT_DIR=usr/...
```
or via the gui by adding a path entry with the name.

## Folder Structure
As this is mainly meant for creating coding challenges (My way of learning, if you can explain something well, you understand it well) the folder structure is setup in a way to suit that purpose. 

Challenges usually consist of different Levels each handling a different topic. This is represented within each of the folders.

```
Onions
│   Readme.md
│   CMakeLists.txt
|   Conanfile.py    
│
└───src
    │   Level_0.hpp  // here is the user implementation a new file for each Level
    │   ...
    │
    └───benchmark
    │   │   main.cpp
    │   │   Level_0_benchmark.hpp // Different Benchmarks for different Levels
    │   │   ...
    │
    └───tests
    │   |   main.cpp
    │   |   Level_0_tests.hpp // For each Level a set of tests verifying the Result
    │   |   ...
    |
    └───reference
        |   Level_0_reference.hpp // My implementation which you can check your solution against
        |   ...
```

This should be pretty self explaining. Each Level is a separate Header File.

## Issues discovered during Developement
While setting up this repository I came across several problems which I want to note down here.

### Conan Generators dealing with Targets
Currently I'm using the 'cmake_find_package' generator which will create a 'findXXX.Cmake' file. This way I don't have to modify anything in the CMakeLists.txt compared to an approach without Conan. However since this file is automatically created it does not take into account all targets but creates only one for gtest for example.

Therefore I could not link against gtest::main but had to provide the main for myself. As the Gtest package comes with a Config.cmake I wonder if its possible to have the 'cmake_find_package' generator use that instead. But this is a separate story that should be adressed within Conan.

### Ctest swallowing output
At first I wanted to show the benchmark output as part of the tests. However ctest by default swallows all the output and can only be brought to bring it up for failing tests, as far as I could see. I could not work my way around it and decided to make a target and not a test executing the benchmark.

Another separate Story would be adding an option to add_test in cmake to show the standard output. 