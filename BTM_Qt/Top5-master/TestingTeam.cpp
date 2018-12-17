#include "Team.cpp"
#include "Team.hpp"
#include <string>

int main(){
    Team team1 = Team::Team (std::string 'Tigers');
    cout << "Division: " << team1.division();
    team1.division() = 3;
    cout << "Division: " << team1.division();

    for (int i = 0, i < 12, i++) {
        double Age;
        double Motivation;
        Age += team1.players()[age];
        Age = Age/12;
        Motivation += team1.players()[motivation];
        Motivation = Motivation/12;
    }
    cout << "Age(theoretical): " << Age;
    cout << "Age: " << team1.age();
    cout << "Motivation(theoretical): " << Motivation;
    cout << "Motivation: " << team1.motivation();
    return 0;
}

