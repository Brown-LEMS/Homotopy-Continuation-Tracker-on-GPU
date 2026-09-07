# -----------------------------------------------------------------------------
# magmaHC-main executable
# -----------------------------------------------------------------------------

add_executable(magmaHC-main magmaHC-main.cpp)

target_link_libraries(magmaHC-main
  PRIVATE
    magmaHC
    Threads::Threads
)

set_target_properties(magmaHC-main PROPERTIES
  CUDA_SEPARABLE_COMPILATION ON
)
