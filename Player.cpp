//
//  Player.cpp
//  Basketball
//


#include "Player.hpp"
#include <cmath>
//names and surnames need to be updated.
std::string names[]={"LeBron","Michael","Stephen","Kevin","Edison","Kobe","Derrick","Wilt","Kareem","Oscar","Tim","Paul","Kevin","Carmelo","Reggie","Vince","Robert","Tony","Rudy","Nicolas","Boris","Evan","Franck","Joakim","Mickael","Timothé","Joffrey","Rodrigue","Mickael","Ian","Kevin","Alexis","Guerschon","Tariq","Moustapha","Andrew","Charles","Axel","Thomas","Fabien","Mathias","Edwin","Jérome","Damien","Hakeem","Kyrie","Magic","Shaquille","James","Bill","Russell","Charles","Dikembe","Dirk","Julius","David","Larry","James","Allen","Marc","Steve","Pau","Jason","Karl","Gary","Yao","Dwight","Damian","Scottie","Georgy","Cyril","Olivier","Pape-Philippe","Roger","Pape","Philippe","Christian","André","Louis","Eric","Jim","Matthieu","David","Sacha","Yves","Jacques","Bill","Vincent","Jean","Bruno","Roger","Charles","Jean-Louis","Skeeter","Jean-Marie","Benkali","Tariq","Alain","Jacky","Willem","Edmond","Michel","Abdoulaye","Maurice","Bernard","Gérard","Eric","Jacques","Frédéric","Gérard","Eric","Raymond","Firmin","Stéphane","Crawford","Marc-Antoine","Johan","Laurent","Fernand","Yvan","Marc","Régis","Michel","Rémi","Lucien","Henri","Stéphane","Thierry","Jean-Pierre","Yohan","Francis","Jean-Michel","Ronnie","André","Jean-Pierre","Philip","Mel","Alex","Walt","Hersey","Kirk","Andre","Joe","Dean","Liu","Charles","Xu","Savas","Miguel","Luke","Sun","Jean-Marc","Karim", "Zainoul","Akay","Ondrej","Eulis","Salah","Aymen","Omar","Nizar","Atef","Ghaith","Michael","Amine","Khalid","Mohamed","Majid","Nabil","Abdelhakim","Jean","Mustapha","Ghaleb","Elie","Joseph","Rony","Omar","Brian","Ali","Norvel","Ali","Hussein","Ater","Jackson"};
std::string surnames[]={"James","Jordan","Curry","Durant","Reshketa","Bryant","Rose","Chamberlain","Abdul-Jabbar","Robertson","Duncan","Pierce","Garnett","Anthony","Miller","Carter","Parish","Parker","Gobert","Batum","Diaw","Fournier","Ntilikina","Noah","Gelabale","Luwawu-Cabarrot","Lauvergne","Beaubois","Piétrus","Mahinmi","Séraphin","Ajinça","Yabusele","Abdul-Wahad","Fall","Albicy","Kahudi","Toupane","Heurtel","Causeur","Lessort","Jackson","Moiso","Inglis","Olajuwon","Irving","Johnson","ONeal","Harden","Russell","Westbrook","Barkley","Mutombo","Nowitzki","Erving","Robinson","Bird","Worthy","Iverson","Gasol","Nash","Gasol","Kidd","Malone","Payton","Ming","Howard","Lillard","Pippen","Adams","Akpomedah","Allinéi","Amagou","Antoine","Badiane","Baillet","Baltzer","Barrais","Bertorelle","Beugnot","Bilba","Bisséni","Gautier","Giffa","Gominon","Caballé","Cain","Collet","Couturier","Hamm","Haudegand","Hemmerlin","Hersin","Jackson","Jouaret","Kaba","Kirksay","Koffi","Lamothe","Laure","Leclère","Longueville","MBaye","Marcelot","Mayeur","Maza","Micoud","Monclar","Monetti","Moroze","Occansey","Offner","Onissah","Ostrowski","Palmer","Pellin","Petro","Pluvy","Prudhomme","Quenin","Quiblier","Racine","Rat","Rippert","Rebuffic","Rey","Risacher","Rupert","Salignon","Sangaré","Schneider","Sénégal","Smith","Souvré","Staelens","Szanyiel","Counts","Groza","Hazzard","Hawkins","Hinrich","Iguodala","Johnson","Kelley","Wei","Jenkins","Xiaoliang","Oguz","Serrano","Fischer","Yue","Kraidy","Ouattara","Bah","Mert","Balvin","Balez","Mejri","Bouzid","Abada","Knioua","Maoua","Nakka","Roll","Rzig","Boukichou","Kherrazi","Naji","Souari","Zouita","Abdelnour","Hoff","Rida","Stephan","Vogel","Fahed","El Turk","Beshara","Mahmoud","Pelle","Kanaan","Tawbe","Majok","Vroman"};
std::string positions[]={"PG","SG","F","PF","C"};


//constructor when player position is not given
Player::Player()
{
    //initialize the division attribute
    
    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];
    
    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames));
    surname=names[randomsurname];
    
    //position initialization
    position=positions[rand()%5];
    
    //generate a random number in [18,30] for the age of the player;
    age=rand()%13 + 18;
    
    //generate a random  number for the height in an interval which depends on the player position
    if (position=="PG")
        height=rand()%11 + 180;
    else if (position=="SG")
        height=rand()%11 + 185;
    else if (position=="F")
        height=rand()%11 + 190;
    else if (position=="PG")
        height=rand()%11 + 195;
    else
        height=rand()%11+203;
    
    //generate a random number for the weight in an interval(0.9*height , 1.1*height)
    weight=rand()%(int(floor((height-100)*0.2))) + ((height-100)*0.9);
    
    //the next attributes have to depend on the league level when creating new players
    //for beginning we let the interval be [40,60]. It will be changed after.
    //we should work on these to make them more biased according to the player position.
    sprint=rand()%21 + 40;
    rebound=rand()%21 + 40;
    passing=rand()%21 + 40;
    handling=rand()%21 + 40;
    shooting=rand()%21 + 40;
    stealing=rand()%21 + 40;
    block=rand()%21 + 40;
    jump=rand()%21 + 40;
    strength=rand()%21 + 40;
}


//constructor when the player position is given
Player::Player(std::string pos)
{
    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];
    
    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames));
    surname=names[randomsurname];
    
    //position initialization
    position=pos;
    
    //generate a random number in [18,30] for the age of the player;
    age=rand()%13 + 18;
    
    //generate a random  number for the height in an interval which depends on the player position
    if (position=="PG")
        height=rand()%11 + 180;
    else if (position=="SG")
        height=rand()%11 + 185;
    else if (position=="F")
        height=rand()%11 + 190;
    else if (position=="PG")
        height=rand()%11 + 195;
    else
        height=rand()%11+203;
    
    //generate a random number for the weight in an interval(0.9*height , 1.1*height)
    weight=rand()%(int(floor((height-100)*0.2))) + ((height-100)*0.9);
    
    //the next attributes have to depend on the league level when creating new players
    //for beginning we let the interval be [20,65]. It will be changed after.
    //we should work on these to make them more biased according to the player position.
    sprint=rand()%46 + 20;
    rebound=rand()%46 + 20;
    passing=rand()%46 + 20;
    handling=rand()%46 + 20;
    shooting=rand()%46 + 20;
    stealing=rand()%46 + 20;
    block=rand()%46 + 20;
    jump=rand()%46 + 20;
    strength=rand()%46 + 20;
    energy=100;
    attack=(sprint+height+passing+handling+shooting+jump+strength)/7;
    defence=(height+sprint+rebound+stealing+block+jump+strength)/7;
    update_overall();
    if (overallgeneral < 40) {
        marketvalue = 50000;
    }
    else {
        marketvalue = (0.6*pow(attack,2) + 0.4*pow(defence,2)) * 100 * 1/3;
    }
};

void Player::update_overall(){
    overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15; 
}
