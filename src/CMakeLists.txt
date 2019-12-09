cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
								
set(CMAKE_CXX_FLAGS "-O3")

project(RV_sim)			# Название проекта

set(FSIM_EXE fsim.cpp)
set(TSIM_EXE tsim.cpp)
set(COSIM_EXE cosim.cpp)

set(F_LIB simulator.cpp proc_state.cpp instruction.cpp)
set(T_LIB tsimulator.cpp tproc_state.cpp tinstruction.cpp)
set(COMMON_LIB vmemory.cpp decoder.cpp memory.cpp)
set(CO_LIB cosimulator.cpp)

#executables
add_executable(fsim ${FSIM_EXE} ${F_LIB} ${COMMON_LIB})
add_executable(tsim ${TSIM_EXE} ${T_LIB} ${COMMON_LIB})
add_executable(cosim ${COSIM_EXE} ${T_LIB} ${F_LIB} ${COMMON_LIB} ${CO_LIB})
