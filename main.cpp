#include <iostream>
#include <vector>

std::vector<int> a;
int vaild = 0;
int invaid = 0;
int passes = 0;
int gigabytes = 0;
int num_of_ints = 0;

int main() {
	std::cout << "How many passes should it do?" << std::endl;
	std::cin >> passes;
	std::cout << "How many GBs of memory should it allocate eatch time?" << std::endl;
	std::cin >> gigabytes;
	num_of_ints = ((256*1024)*1024)*gigabytes;

	for (int i = 0; i < passes; i++) {
		for(int i = 0; i < num_of_ints; i++) {
			a.push_back(i);
			//std::cout << "Allocated new int in vector " << i << std::endl;
		}

		for(int i = 0; i < a.size(); i++) {
			if(a[i] != i) {
				//std::cout << "Error in memory." << std::endl;
				invaid++;
			} else {
				//std::cout << "Memory is vaild." << std::endl;
				vaild++;
			}
		}

		std::cout << "pass: " << i + 1 << " vaild: " << vaild << " invaild: " << invaid << std::endl;
		a.clear();
		a.shrink_to_fit();
		vaild = 0;
		invaid = 0;
	}
}
