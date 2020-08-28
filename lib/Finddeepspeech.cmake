add_library(deepspeech INTERFACE IMPORTED)
if(WIN32)
	target_link_libraries(deepspeech PUBLIC INTERFACE "${CMAKE_CURRENT_LIST_DIR}/deepspeech/amd64.cpu.win/libdeepspeech.so.if.lib")
	set(DEEPSPEECH_SHARED_LIBRARY_DIR "amd64.cpu.win")
elseif(APPLE)
	set(DEEPSPEECH_SHARED_LIBRARY_DIR "amd64.cpu.osx")
elseif(UNIX)
	set(DEEPSPEECH_SHARED_LIBRARY_DIR "amd64.cpu.linux")
else()
	message(FATAL_ERROR "No deepspeech library configured for this platform")
endif()
configure_file(
	"${CMAKE_CURRENT_LIST_DIR}/deepspeech/${DEEPSPEECH_SHARED_LIBRARY_DIR}/libdeepspeech.so"
	"${CMAKE_CURRENT_BINARY_DIR}/libdeepspeech.so"
	COPYONLY
)
target_include_directories(deepspeech PUBLIC INTERFACE "${CMAKE_CURRENT_LIST_DIR}/deepspeech/")