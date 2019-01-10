#ifndef USER_H
#define USER_H

#include <string>
#include "Team.h"
#pragma once
class User
{
public:
    User();
    User(std::string username, std::string team_name, std::string nation);
    std::string name;
    std::string teamname;
    std::string nationality;
    Team team;
    int budget;
};

#endif // USER_H
