cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(GPU-HC
  VERSION 1.0
  LANGUAGES CXX CUDA
)

# -----------------------------------------------------------------------------
# Build options
# -----------------------------------------------------------------------------
option(GPUHC_ICL_BUILD
  "Use ICL machine dependency paths and multi-arch CUDA flags" OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/config/cmake/InitializeBuildType.cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -----------------------------------------------------------------------------
# Dependency roots (override on the cmake command line if needed)
# -----------------------------------------------------------------------------
if(GPUHC_ICL_BUILD)
  set(_magma_root_default    "/home/ahmad/magma-openblas")
  set(_magma_source_default  "/home/ahmad/magma-openblas")
  set(_yaml_root_default     "/home/ahmad/yaml-cpp")
  set(_openblas_hint_default "/home/ahmad/openblas")
else()
  # Oscar / Brown defaults:
  #   MAGMA install (lib + public headers): magma-2.10.0/bin
  #   MAGMA source  (internal headers):     magma-2.10.0
  set(_magma_root_default    "/gpfs/data/bkimia/cchien3/magma-2.10.0/bin")
  set(_magma_source_default  "/gpfs/data/bkimia/cchien3/magma-2.10.0")
  set(_yaml_root_default     "/gpfs/data/bkimia/cchien3/yaml-cpp/bin")
  set(_openblas_hint_default "")
endif()

set(MAGMA_ROOT "${_magma_root_default}" CACHE PATH
  "MAGMA install prefix (contains include/ and lib/)")
set(MAGMA_SOURCE_ROOT "${_magma_source_default}" CACHE PATH
  "MAGMA source tree (for magma_internal.h / magma_templates.h)")
set(YAML_CPP_ROOT "${_yaml_root_default}" CACHE PATH
  "yaml-cpp install prefix")
set(OPENBLAS_ROOT "${_openblas_hint_default}" CACHE PATH
  "Optional OpenBLAS install hint; leave empty to use modules / CMAKE_PREFIX_PATH")

# -----------------------------------------------------------------------------
# Compiler flags
# -----------------------------------------------------------------------------
if(GPUHC_ICL_BUILD)
  # MAGMA on ICL expects the Fortran name-mangling macro -DADD_
  add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:-O3>
    $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CXX>:-DADD_>
    $<$<COMPILE_LANGUAGE:CXX>:-march=native>
    $<$<COMPILE_LANGUAGE:CUDA>:-DADD_>
    $<$<COMPILE_LANGUAGE:CUDA>:-Xptxas=-v>
  )
  # Multi-arch fat binary for ICL GPUs
  set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} \
    -gencode arch=compute_70,code=sm_70 \
    -gencode arch=compute_80,code=sm_80 \
    -gencode arch=compute_90,code=sm_90")
else()
  add_compile_options(
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Release>>:-O3>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Release>>:-DNDEBUG>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Release>>:-march=native>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Release>>:-ffast-math>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Debug>>:-g>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CONFIG:Debug>>:-Wall>
  )
  # Volta / Turing / Ampere (V100, RTX, A100, A40, 3090, A6000)
  set(CMAKE_CUDA_ARCHITECTURES 70 75 80 86)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
  message(WARNING "GCC >= 5.0 is recommended for performance")
endif()

# -----------------------------------------------------------------------------
# Third-party packages
# -----------------------------------------------------------------------------
find_package(CUDAToolkit REQUIRED)
find_package(OpenMP REQUIRED)
find_package(Threads REQUIRED)

# MAGMA 2.10.0 at MAGMA_ROOT is built against CUDA 12 (libcublas.so.12 / libcudart.so.12).
# Configure with: module load cuda/12.9.0-cinr openblas/0.3.29-c43s
if(CUDAToolkit_VERSION VERSION_LESS 12)
  message(WARNING
    "CUDA ${CUDAToolkit_VERSION} detected, but Magma at ${MAGMA_ROOT} "
    "expects CUDA 12. Load cuda/12.9.0-cinr before configuring.")
endif()

list(APPEND CMAKE_PREFIX_PATH "${YAML_CPP_ROOT}")
find_package(yaml-cpp REQUIRED CONFIG)

if(OPENBLAS_ROOT)
  list(APPEND CMAKE_PREFIX_PATH "${OPENBLAS_ROOT}")
  set(_openblas_hints HINTS "${OPENBLAS_ROOT}" "${OPENBLAS_ROOT}/lib")
endif()
find_library(OPENBLAS_LIBRARY
  NAMES openblas
  ${_openblas_hints}
  REQUIRED
)

# -----------------------------------------------------------------------------
# Imported MAGMA target
# -----------------------------------------------------------------------------
if(NOT EXISTS "${MAGMA_ROOT}/lib/libmagma.so")
  message(FATAL_ERROR "libmagma.so not found under ${MAGMA_ROOT}/lib")
endif()
if(NOT EXISTS "${MAGMA_ROOT}/include/magma_v2.h")
  message(FATAL_ERROR "magma_v2.h not found under ${MAGMA_ROOT}/include")
endif()

add_library(MAGMA::magma SHARED IMPORTED GLOBAL)
set_target_properties(MAGMA::magma PROPERTIES
  IMPORTED_LOCATION "${MAGMA_ROOT}/lib/libmagma.so"
  INTERFACE_INCLUDE_DIRECTORIES
    "${MAGMA_ROOT}/include;${MAGMA_SOURCE_ROOT}/control;${MAGMA_SOURCE_ROOT}/magmablas;${MAGMA_SOURCE_ROOT}/testing"
)
list(APPEND CMAKE_BUILD_RPATH "${MAGMA_ROOT}/lib")

add_library(OpenBLAS::OpenBLAS UNKNOWN IMPORTED GLOBAL)
set_target_properties(OpenBLAS::OpenBLAS PROPERTIES
  IMPORTED_LOCATION "${OPENBLAS_LIBRARY}"
)

message(STATUS "MAGMA_ROOT        = ${MAGMA_ROOT}")
message(STATUS "MAGMA_SOURCE_ROOT = ${MAGMA_SOURCE_ROOT}")
message(STATUS "YAML_CPP_ROOT     = ${YAML_CPP_ROOT}")
message(STATUS "OPENBLAS_LIBRARY  = ${OPENBLAS_LIBRARY}")
message(STATUS "CUDAToolkit       = ${CUDAToolkit_VERSION}")

# -----------------------------------------------------------------------------
# Project targets
# -----------------------------------------------------------------------------
add_subdirectory(magmaHC)
add_subdirectory(cmd)
