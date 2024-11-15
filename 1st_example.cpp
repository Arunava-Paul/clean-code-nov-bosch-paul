#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using size_t = std::string::size_type;

function<bool(const string& str)> checkCharPredicateGenerator(char ch, size_t pos)
{
    auto foo = [ch, pos](const string& str)->bool
    {
        return (str.at(pos) == ch);
    };
    return foo;
}

function<bool(const string& str)> isPresentPredicateGenerator(string&& chkstr)
{
    auto foo = [chkstr](const string& str)->bool {
        return (str == chkstr);
    };
    return foo;
}

bool filterstring(std::vector<std::string>& ip_vct, std::vector<std::string>& ot_vct, const function<bool(const string&)>& func)
{
    bool ret = false;
    for (const auto& elem : ip_vct)
    {
        if (func(elem))
        {
            ot_vct.push_back(elem);
            ret = true;
        }
    }
    return ret;
}

int main() {
    // Write C++ code here
    size_t pos = 0;
    char letter = 'B';
    function<bool(const std::string&)> startLetterCondition = checkCharPredicateGenerator(letter, pos);
    
    function<bool(const std::string&)> findStringCondition = isPresentPredicateGenerator("Boot");

    std::vector<std::string> names, filtered_names; 
    names.push_back("Bosch");
    names.push_back("Boot");
    names.push_back("Robert");
    names.push_back("HUB");

    if (filterstring(names, filtered_names, startLetterCondition))
    {
        for (auto name : filtered_names)
        {
            std::cout << name << ",";
        }
    }
    else
        std::cout << "no names found";
    std::cout << endl; 
    std::cout << "=============================="<<endl; 
    filtered_names.resize(0);
    if (filterstring(names, filtered_names, findStringCondition))
    {
        for (auto name : filtered_names)
        {
            std::cout << name << ",";
        }
    }
    else
        std::cout << "no names found";

    return 0;
}






