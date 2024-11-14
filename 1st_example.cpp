#include <iostream>

int main() {
    // Write C++ code here
std::string names[5] = {"Bosch" , "Robert"  , "Lenovo" , "Blr" , "Rubic"};
for(auto name: names)
{	
	char ch = name[0];
	if(ch == 'B')
		std::cout << name << std::endl;
}
    return 0;
}