#include<iostream>
#include <chrono>
#include<locale>
#define MEMBER 1024*1024

#define USE_SIZE 1000
void Test()
{
	int* ptr = new int[100 * MEMBER];
	int ptr2 = ptr[0];
	bool is_start = true;

	clock_t start1 = clock();

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < USE_SIZE; i++)
	{
		ptr[i] = -i;
	}
	for (int i = 0; i < 100000; i++)
	{
		for (int i2 = 0; i2 < USE_SIZE - 1; i2++)
		{
			if (ptr[i2] < ptr[i2+1])
			{
				int tmp = ptr[i2];
				ptr[i2] = ptr[i2+1];
				ptr[i2 + 1] = tmp;
			}
		}
	}

	auto end = std::chrono::steady_clock::now();
	auto answer = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	std::cout <<"Spead: " << answer.count()<<" "<< "Nanosec" << std::endl;
	
	delete ptr;
	
}

void Menu() {

	std::cout << "Menu" << std::endl;
	std::cout << "1)Program CACHEON " << std::endl;
	std::cout << "2)Program CACHEOFF" << std::endl;
	std::cout << "3)Exit" << std::endl;
}



int main(void)
{
	setlocale(LC_ALL, "ru");

	char pick = '0';
	
	while (pick != '3')
	{
		Menu();
		std::cin >> pick;

		switch (pick)
		{


		case '1':
			system("SC stop CACHEOFF");
			system("SC start CACHEON");
			Test();
			std::cout << "CACHEON" << std::endl;
			break;


		case'2':
			system("SC start CACHEOFF");
			system("SC stop CACHEON");
			Test();
			std::cout << "CACHEOFF" << std::endl;
			break;


		default:
			std::cout << "ALERT!" << std::endl;
			break;


		}
	}
		return 0;
}