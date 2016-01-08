#include "gtest\gtest.h"

using namespace testing;

int main(int argc, char* argv[])
{
	InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	system("pause");
	return result;
}