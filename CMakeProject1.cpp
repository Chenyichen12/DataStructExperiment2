// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include "sort.cpp"
using namespace std;

int main()
{
	//洗牌算法
	int *array = new int[10];
	for (int i = 0; i < 10; i++) {
		array[i] = i;
	}
	for (int i = 9; i >= 0; i++) {
		std::swap(array[rand() % (i + 1)], array[i]);
	}
	sort1::sortTheArray(array, 10);
	system("pause");
}
