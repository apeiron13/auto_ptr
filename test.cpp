#ifdef RUN_TEST
#include "string_ptr.hpp"
#include <iostream>

void main()
{
	std::string aa = "aaaa";
	std::string* a = new std::string("aaa");
	std::string* b = new std::string("bbb");
	string_ptr example1(b);
	string_ptr example2(a);
	string_ptr example3(example1);
	//std::string* manual_pointer1 = example1.release();
	std::cout << *example3<<std::endl;
	std::cout << *example2.get()<<std::endl;
	std::string * manual_pointer2 = example2.release();
	std::cout << *manual_pointer2<<std::endl;
	string_ptr example4 = example3;
	std::cout << *example4<<std::endl;

	std::string* c = new std::string("cccc");
	string_ptr example5(c);
	example5->swap(*example4);
	std::cout << *example5 << " " << *example4 << std::endl;

	std::string* d = new std::string("dddd");
	string_ptr example6(d);
	std::cout << example6.release() << std::endl;
	//std::cout << *example6 << std::endl;
	 
	std::string* e = new std::string("eeee");
	string_ptr example7(d);
	string_ptr example8;
	example8 = example7;
	std::cout << *example8.get() << std::endl;

}
#endif

