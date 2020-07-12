#include <gtest/gtest.h>
#include "../PomordorEngine/Pome.h"

TEST(ExampleTests, DemonstrateGTestMacros) {
    EXPECT_TRUE(true);
} 

TEST(PythonScriptTest, FileName)
{
	PythonScript sc;
	sc.CreateToastScript("title", "msg", 5.f, "");
	EXPECT_TRUE(sc.GetScriptName() == "title");
}

TEST(TestToastMessage, floatToast)
{
	PythonScript script;
	script.CreateToastScript("test.py", "Test", 5.0f, "");
	FileManager::Save(script, "test.py");
	Pome::Toast::ToastMessage("test.py");

	EXPECT_TRUE(true);
}

 