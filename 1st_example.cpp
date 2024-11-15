#include <iostream>
#include <vector>
#include <string>

bool ifStartsWith(const std::string& str , char ch)
{
    return (str.at(0) == ch);
}

bool ifEndsWith(const std::string& str, char ch)
{
    return (str.at(str.length()-1) == ch);
}

bool filtersting(std::vector<std::string>& ip_vct ,
std::vector<std::string>& ot_vct, bool (*func)(const std::string& ,char), char check_char)
{
    bool ret = false;
    for(auto elem: ip_vct)
    {
        if(func(elem , check_char))
        {
            ot_vct.push_back(elem);
            ret = true;
        }
    }
    return ret;
}

int main() {
    // Write C++ code here
std::vector<std::string> names, filtered_names; 
names.push_back("Bosch") ;
names.push_back("Boot") ;
names.push_back("Robert");
names.push_back("HUB");
if(filtersting(names , filtered_names ,ifStartsWith , 'B' ))
{
    for(auto name :filtered_names )
    {
        std::cout << name << ",";
    }
}
else
    std::cout << "no names found";

    return 0;
}