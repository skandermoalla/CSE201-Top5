#include "Player.cpp"
#include "Player.hpp"
#include <string>

int main (){
    std::string pos;
    pos = "PG";
    Player player1 = Player::Player (pos);
    cout << "Name: " << player1.name;
    cout << "Surname: " << player1.surname;
    cout << "Age: " << player1.age;
    if (17 < player1.age && player1.age < 31){
        cout << "Age is fine";
    }
    cout << "Height: " << player1.height;
    if (179 < player1.height && player1.height < 192){
        cout << "Height is fine";
    }
    cout << "Weight: " << player1.weight;
    if (0,9*player1.height < player1.weight && player1.weight < 1,1*player1.weight){
        cout << "Weight is fine";
    }
    cout << "Attack: " << player1.attack;
    cout << "Defence: " << player1.defence;
    cout << "Market Value: " << player1.marketvalue;
    player1 = player1.update_overall();
    cout << "Market Value: " << player1.marketvalue;
    
    return 0;
}

