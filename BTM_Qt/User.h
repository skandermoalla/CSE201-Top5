#ifndef USER_H
#define USER_H

#include <string>
#include "Team.h"
#pragma once
class User
{
public:
    User();
    User(const std::string username,const  std::string team_name, const std::string nation);
    std::string name;
    std::string teamname;
    std::string nationality;
    Team team;
    int budget;
};

#endif // USER_H
