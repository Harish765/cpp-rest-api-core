[![Build Status](https://travis-ci.org/systelab/cpp-rest-api-core.svg?branch=master)](https://travis-ci.org/systelab/cpp-rest-api-core)
[![Build status](https://ci.appveyor.com/api/projects/status/ix9b122obt2f2j9v?svg=true)](https://ci.appveyor.com/project/systelab/cpp-rest-api-core)
[![codecov](https://codecov.io/gh/systelab/cpp-rest-api-core/branch/master/graph/badge.svg)](https://codecov.io/gh/systelab/cpp-rest-api-core)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8e7fca4ee7cb47a1801f51771532b2cb)](https://www.codacy.com/app/systelab/cpp-rest-api-core?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-rest-api-core&amp;utm_campaign=Badge_Grade)
[![Download](https://api.bintray.com/packages/systelab/conan/RESTAPICore:systelab/images/download.svg)](https://bintray.com/systelab/conan/RESTAPICore:systelab/_latestVersion)


# C++ REST API framework

This repository implements a C++ framework to facilitate the creation of REST API.

## Supported features

* Routing mechanism
* Authentication through JWT
* User access validation
* Token expiration validation
* Custom access validation

## Setup

### Build from sources

Prerequisites:
  - [Git](https://git-scm.com/)
  - [Conan](https://conan.io/)
  - [CMake](https://cmake.org/)
  - [Visual Studio](https://visualstudio.microsoft.com/) (only on Windows)
  - [GCC](https://gcc.gnu.org/) (only on Linux)

Build library with the following steps:
  1. Clone this repository in a local drive
  2. Make a build directory (i.e. `build/`)
  3. Install `conan` dependencies in the build directory
  4. Run `cmake` in the build directory to configure build targets
  5. Use `Visual Studio` (on Windows) or `make` (on Linux) to build the library

#### Windows
``` bash
> git clone https://github.com/systelab/cpp-rest-api-core
> md build && cd build
> conan install .. -s arch=x86
> cmake ..
> devenv.exe RESTAPICore.sln
```

#### Linux
``` bash
> git clone https://github.com/systelab/cpp-rest-api-core
> mkdir build && cd build
> conan install ..
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
```

### Download using Conan

  1. Create/update your `conanfile.txt` to add this library as follows:

```
[requires]
RESTAPICore/1.0.0@systelab/stable

[generators]
cmake
```

  2. Integrate Conan into CMake by adding the following code into your `CMakeLists.txt`:

```cmake
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
```

  3. Link against `${CONAN_LIBS}` when configuring your executables in CMake:

```cmake
set(MY_PROJECT MyProject)
add_executable(${MY_PROJECT} main.cpp)
target_link_libraries(${MY_PROJECT} ${CONAN_LIBS})
```

## Usage

### Configure a router

`TBD`

### Add user access validation

`TBD`

### Add token expiration validation

`TBD`

### Custom access validation

`TBD`
