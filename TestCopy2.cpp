#include <iostream>
#include <vector>

#include <chrono>

using milli = std::chrono::milliseconds;
const int g_n = 500;
float TestData[g_n][g_n][g_n];

void foo() {
	//operation
}

void column_ordered() {
	for (int k = 0; k < g_n; k++)
		for (int j = 0; j < g_n; j++)
			for (int i = 0; i < g_n; i++)
				TestData[i][j][k] = 0.0f;
}

void row_ordered() {
	for (int i = 0; i < g_n; i++)
		for (int j = 0; j < g_n; j++)
			for (int k = 0; k < g_n; k++)
				TestData[i][j][k] = 0.0f;
}



int main()
{
	std::chrono::high_resolution_clock::time_point start;
	start = std::chrono::high_resolution_clock::now();
	column_ordered();
	std::chrono::high_resolution_clock::time_point end;
	end = std::chrono::high_resolution_clock::now();

	std::cout << "column ordered running duration : " << std::chrono::duration_cast<milli>(end - start).count() << " millisecs" << std::endl;

	std::chrono::high_resolution_clock::time_point start2;
	start2 = std::chrono::high_resolution_clock::now();
	row_ordered();
	std::chrono::high_resolution_clock::time_point end2;
	end2 = std::chrono::high_resolution_clock::now();

	std::cout << "row ordered running duration : " << std::chrono::duration_cast<milli>(end2 - start2).count() << " millisecs" << std::endl;

	getchar();
}