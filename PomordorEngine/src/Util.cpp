#include "pegpch.h"
#include "Util.h"

namespace Pome{

    void printHello()
    {
        std::cout << "hello world" << std::endl;
        return;
    }
	void printJson()
	{
		Json::Value root;
		root["hello"] = "jsoncpp";
		
		std::ofstream out("hello.json", std::ios::out);
		out << root;
		out.close();
	}
}