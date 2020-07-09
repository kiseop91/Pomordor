#pragma once


#ifdef _WINDOWS
	#ifdef _DEBUG
		#define POM_ASSERT(expression) if(!expression) { std::cout << #expression << " is failed" << std::endl; __debugbreak(); }
	#else
		#define POM_ASSERT(expression)
	#endif
#endif