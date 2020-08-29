cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(Models)
configure_file("${CMAKE_CURRENT_LIST_DIR}/model.h.in" "${CMAKE_CURRENT_LIST_DIR}/model.h")

include(Audio)
configure_file("${CMAKE_CURRENT_LIST_DIR}/audio.h.in" "${CMAKE_CURRENT_LIST_DIR}/audio.h")

add_executable (speech "speech.cpp" "model.h" "deepsmartptrs.h" "audio.h")

find_package(deepspeech REQUIRED)
target_link_libraries(speech deepspeech)

find_package(audiofile REQUIRED)
target_link_libraries(speech audiofile)

