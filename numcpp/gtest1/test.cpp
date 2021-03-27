#include "pch.h"

#include "../test1/gm.cpp"

TEST(function_test, t_add) {
  //EXPECT_EQ(1, 1);
  //EXPECT_TRUE(true);
	int n_start = 0;
	int n_stop = 100000;
	for (int i = n_start; i < n_stop; i++) {
		for (int j = n_start; j < n_stop; j++) {
			EXPECT_EQ(t_add(i, j), i + j);
		}
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}