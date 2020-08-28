set(ASIOSDK_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/ASIOSDK2")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/portaudio/src" "${CMAKE_CURRENT_LIST_DIR}/portaudio/bin" EXCLUDE_FROM_ALL)
configure_file("${CMAKE_CURRENT_LIST_DIR}/portaudio/bin/portaudio_x64.dll" "${CMAKE_CURRENT_BINARY_DIR}/portaudio_x64.dll" COPYONLY)
