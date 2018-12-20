#include "League.cpp"
#include "League.hpp"
#include <iostream>

int main{
		League L1 = League::League(1,'2018/2019');
		League L2 = League::League(2, '2019/2020');
		League L3 = League::League(3, '2020/2021');
		std::cout << L1.division, L2.division, L3.division << std::endl;
		std::cout << L1.season, L2.season, L3.season << std::endl;

		
		std::cout << L1.teams, L2.teams, L3.teams << std::endl;
    
        calendar2018 = L1.calendar()
    cout << "First week matches: " << calendar2018[1];
    
}

