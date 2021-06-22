#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
	cout << i << endl;
}

int main()
{
	int a = 1;
	for (uint8_t i = 0; i < 4; i++)
	{
		thread t(output, i);
		t.detach();
	}


		

    // cout << "======================" << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     thread t([i]{
    //         cout << i << endl;
    //     });
    //     t.detach();
    // }

    getchar();
	return 0;
}

//----------------------------------------------------------------
// g++ test_mt.cpp -lpthread -o test_mt   (must -lpthread)