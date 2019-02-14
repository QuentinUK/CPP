// 3 Simple C++17 Features That Will Make Your Code Simpler 
// Jonathan Boccara's blog

#include <iostream>
#include <tuple>
#include <utility>
#include <map>

std::tuple<char, int, bool> mytuple()
{
    char a = 'a';
    int i = 123;
    bool b = true;
    return std::make_tuple(a, i, b);
}

int main() {
    // structured binding
    auto [a, i, b] = mytuple();
    std::cout << a << ' ' << i << ' ' << b << '\n';
    
    // returning compound objects
    auto mymap{std::map<int, int>()};
    auto [itelem, success] = mymap.insert(std::pair('a', 100));
    if (!success) {
        std::cout << "not inserted\n"; // Insert failure
    }
	// your code goes here
	return 0;
}
