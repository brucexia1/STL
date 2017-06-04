//test 在class template 中拥有 static data members
// test __STL_STATIC_TEMPLATE_TEMPLATE_MEMBER_BUG, defined in <stl_config.h>


#include <iostream>
using namespace std;

template <typename T>
class testClass
{
public:
	static int _data;
	 testClass();
	~ testClass();
	
};

// 为static data member 进行定义，并设初值
template<> int testClass<int>::_data = 1;
template<> int testClass<char>::_data = 2;

int main()
{
	cout << testClass<int>::_data <<endl;
	cout << testClass<char>::_data <<endl;

	template<> int testClass<int> obj1,obj2;
	template<> int testClass<char> objc1,objc2;
	cout << obj1._data <<endl;
	cout << obj2._data <<endl;
	cout << objc1._data <<endl;
	cout << objc2._data <<endl;
}