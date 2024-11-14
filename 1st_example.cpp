#include <iostream>
#include <vector>
#include <string>
static void CompareAndPrint(std::vector<std::string>& vct , char ch_)
{
    for(auto name: vct)
{	
	char ch = name[0];
	if(ch == ch_)
		std::cout << name << std::endl;
}
}
int main() {
    // Write C++ code here
std::vector<std::string> names; 
names.push_back("Bosch") ;
names.push_back("Robert");
CompareAndPrint(names , 'B');

    return 0;
}