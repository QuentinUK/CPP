// 3 Simple C++17 Features That Will Make Your Code Simpler 
// Jonathan Boccara's blog

#include <iostream>
#include <tuple>
#include <utility>
#include <map>
/*#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

template<typename T>
T pow_m(int n, int pow){
	T p { n };
	while(--pow) p*=n;
	return p;
}

void power_test(){
	cpp_int z, y, g = 0; 
    const int rows = 20; 
	for(int i=0; i<rows; i++) { 
		y = 4 + g; 
        z = y * y; 
        g = g + 3*pow_m<cpp_int>(10, i+1);
        
		for(int m=rows;m>=i;m--) { 
			std::cout << ' '; 
		} 
		std::cout << y << "’" << '=' << z << std::endl; 
	} 
}
*/
std::tuple<char, int, bool> mytuple()
{
    char a = 'a';
    int i = 123;
    bool b = true;
    return std::tuple(a, i, b); // make_tuple not needed anymore
}

int main() {
    // power_test();
    // structured binding
    auto [a, i, b] = mytuple();
    std::cout << a << ' ' << i << ' ' << b << '\n';
    
    // returning compound objects
    auto mymap{std::map<char, int>()};
    auto [itelem, success] = mymap.insert(std::pair('a', 100));
    if (!success) {
        std::cout << "not inserted\n"; // Insert failure
    }
    // selection initialsation
    if (auto [itelem, success] = mymap.insert(std::pair('b', 100)); success) {
        std::cout << "well inserted\n"; // Insert success
    }
    for(const auto& [key, value] : mymap) {
        std::cout << key << ' ' << value << '\n';
     }
	// direct initialisation
    auto [a1, i1, b1] = std::tuple('a', 123, true);
	return 0;
}
