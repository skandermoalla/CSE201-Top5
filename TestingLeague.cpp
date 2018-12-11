#include "League.cpp"
#include "League.hpp"
#include <iostream>

int main{
		League L1 = League::League(1,'2018/2019');
		League L2 = League::League(2, '2019/2020');
		League L3 = League::League(3, '2020/2021');
		std::cout << L1.get_division(), L2.get_division(), L3.get_division() << std::endl;
		std::cout << L1.get_season(), L2.get_season(), L3.get_season() << std::endl;

		L1.set_division(3);
		L2.set_division(1);
		L3.set_division(2);
		
		std::cout << L1.get_division(), L2.get_division(), L3.get_division() << std::endl;

		L1.set_season("2020/2021");
		L2.set_season("2019/2020");
		L3.set_season("2018/2019");

		std::cout << L1.get_season(), L2.get_season(), L3.get_season() << std::endl;

}

