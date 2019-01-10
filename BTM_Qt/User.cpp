#include "User.h"

User::User()
{ name="Random";
  teamname="Random";
  team=Team();
  nationality="Random";
}

User::User(std::string username , std::string team_name , std::string nation)
{   name=username;
    teamname=team_name;
    team = Team(team_name);
    nationality=nation;
    budget=100000;
}

