#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include<QListView>
#include <QLabel>
#pragma once

class Player{
public:
    //constuctors
    Player();
    Player(std::string pos);

    //player attributes
    std::string name;
    std::string surname;
    std::string position; // PG=pointguard SG=shootingguard F=forward PF=powerforward C=center
    int division;
    int age;
    int height;
    int weight;
    int sprint;
    int rebound;
    int passing;
    int handling;
    int shooting;
    int stealing;
    int block;
    int jump;
    int strength;
    int motivation;
    int energy;
    double attack;
    double defence;
    double overallgeneral;
    double marketvalue;
    QString photoadress;
    std::string photoadd;

    //player methods
    void update_overall();
    void afterMatchUpdate(const int change, const int motivationChange);

};

#endif // PLAYER_H
