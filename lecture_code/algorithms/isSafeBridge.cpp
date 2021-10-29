#include <iostream>
#include <string>
bool isSafeBridge(std::string s)
{
	s.replace(0, s.size() - 4, s.size() - 4, '#');
	std::cout << s << std::endl;
	auto found = s.find(' ');
	return found == std::string::npos;
}

int main()
{
	// if no matches were found, the function returns string::npos

	std::cout << isSafeBridge("asdfasdfasdfasdfasdfas");
	std::cout << isSafeBridge("123456789");
	//	std::cout << isSafeBridge("## ##");
	//	std::cout << isSafeBridge("#");
	//	std::cout << isSafeBridge("# #");
}
