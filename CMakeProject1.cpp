// CMakeProject1.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include <chrono>
#include "sort.cpp"
using namespace std;
using namespace std::chrono;
void wash(int *array,int n){
    for (int i = n; i >= 0; --i) {
        std::swap(array[rand() % (i + 1)], array[i]);
    }
}

int main()
{
	//洗牌算法
    const int n = 100000;
	int array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = i;
    }
    wash(array,n);
    auto begin = high_resolution_clock::now();
	sort1::sortTheArray(array,n);
    auto end = high_resolution_clock::now();
    cout<<to_string(duration_cast<microseconds>(end - begin).count())<<"ms"<<endl;

    wash(array,n);
    begin = high_resolution_clock::now();
    sort2::sortTheArray(array,n);
    end = high_resolution_clock::now();
    cout<<to_string(duration_cast<microseconds>(end - begin).count())<<"ms"<<endl;

    wash(array,n);
    begin = high_resolution_clock::now();
    sort3::sortTheArray(array,n);
    end = high_resolution_clock::now();
    cout<<to_string(duration_cast<microseconds>(end - begin).count())<<"ms"<<endl;

    wash(array,n);
    begin = high_resolution_clock::now();
    sort4::sortTheArray(array,n);
    end = high_resolution_clock::now();
    cout<<to_string(duration_cast<microseconds>(end - begin).count())<<"ms"<<endl;

    wash(array,n);
    begin = high_resolution_clock::now();
    sort5::sortTheArray(array,n);
    end = high_resolution_clock::now();
    cout<<to_string(duration_cast<microseconds>(end - begin).count())<<"ms"<<endl;
}
