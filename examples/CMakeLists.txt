cmake_minimum_required(VERSION 3.10)

project(fsm_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SRC_DIR ../src)
set(FSM_SRC
        ${SRC_DIR}/fsm_event.cpp
        ${SRC_DIR}/fsm_transition.cpp
        ${SRC_DIR}/fsm_state.cpp
        ${SRC_DIR}/fsm.cpp
   )

add_executable(fsm_example
        ${FSM_SRC}
        fsm_example.cpp
        )

target_include_directories(fsm_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
