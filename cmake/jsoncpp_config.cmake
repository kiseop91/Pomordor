
option(JSONCPP_WITH_TESTS "Compile and (for jsoncpp_check) run JsonCpp test executables" OFF)
option(JSONCPP_WITH_POST_BUILD_UNITTEST "Automatically run unit-tests as a post build step" OFF)
option(JSONCPP_WITH_WARNING_AS_ERROR "Force compilation to fail if a warning occurs" OFF)
option(JSONCPP_WITH_STRICT_ISO "Issue all the warnings demanded by strict ISO C and ISO C++" OFF)
option(JSONCPP_WITH_PKGCONFIG_SUPPORT "Generate and install .pc files" OFF)
option(JSONCPP_WITH_CMAKE_PACKAGE "Generate and install cmake package files" OFF)
option(JSONCPP_WITH_EXAMPLE "Compile JsonCpp example" OFF)
option(BUILD_OBJECT_LIBS "Build jsoncpp_lib as a object library." OFF)

#choose jsonlibrary type
option(BUILD_SHARED_LIBS "Build jsoncpp_lib as a shared library." OFF)
option(BUILD_STATIC_LIBS "Build jsoncpp_lib as a static library." ON)

if(BUILD_SHARED_LIBS)
	set(Jsoncpp jsoncpp_lib)
elseif(BUILD_STATIC_LIBS)
	set(Jsoncpp jsoncpp_static)
endif()

