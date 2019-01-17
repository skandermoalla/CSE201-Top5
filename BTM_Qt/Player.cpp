#include "Player.h"

#include <cmath>

const std::string names[]={"LeBron","Stephen","Kevin","Edison","Kobe","Derrick","Wilt","Kareem","Oscar","Tim","Paul","Kevin","Carmelo","Reggie","Vince","Robert","Tony","Rudy","Nicolas","Boris","Evan","Franck","Joakim","Mickael","Timothé","Joffrey","Rodrigue","Mickael","Ian","Kevin","Alexis","Guerschon","Tariq","Moustapha","Andrew","Charles","Axel","Thomas","Fabien","Mathias","Edwin","Jérome","Damien","Hakeem","Kyrie","Magic","Shaquille","James","Bill","Russell","Charles","Dikembe","Dirk","Julius","David","Larry","James","Allen","Marc","Steve","Pau","Jason","Karl","Gary","Yao","Dwight","Damian","Scottie","Georgy","Cyril","Olivier","Pape-Philippe","Roger","Pape","Philippe","Christian","André","Louis","Eric","Jim","Matthieu","David","Sacha","Yves","Jacques","Bill","Vincent","Jean","Bruno","Roger","Charles","Jean-Louis","Skeeter","Jean-Marie","Benkali","Tariq","Alain","Jacky","Willem","Edmond","Michel","Abdoulaye","Maurice","Bernard","Gérard","Eric","Jacques","Frédéric","Gérard","Eric","Raymond","Firmin","Stéphane","Crawford","Marc-Antoine","Johan","Laurent","Fernand","Yvan","Marc","Régis","Michel","Rémi","Lucien","Henri","Stéphane","Thierry","Jean-Pierre","Yohan","Francis","Jean-Michel","Ronnie","André","Jean-Pierre","Philip","Mel","Alex","Walt","Hersey","Kirk","Andre","Joe","Dean"};
const std::string surnames[]={"James","Curry","Durant","Reshketa","Bryant","Rose","Chamberlain","Abdul-Jabbar","Robertson","Duncan","Pierce","Garnett","Anthony","Miller","Carter","Parish","Parker","Gobert","Batum","Diaw","Fournier","Ntilikina","Noah","Gelabale","Luwawu-Cabarrot","Lauvergne","Beaubois","Piétrus","Mahinmi","Séraphin","Ajinça","Yabusele","Abdul-Wahad","Fall","Albicy","Kahudi","Toupane","Heurtel","Causeur","Lessort","Jackson","Moiso","Inglis","Olajuwon","Irving","Johnson","ONeal","Harden","Russell","Westbrook","Barkley","Mutombo","Nowitzki","Erving","Robinson","Bird","Worthy","Iverson","Gasol","Nash","Gasol","Kidd","Malone","Payton","Ming","Howard","Lillard","Pippen","Adams","Akpomedah","Allinéi","Amagou","Antoine","Badiane","Baillet","Baltzer","Barrais","Bertorelle","Beugnot","Bilba","Bisséni","Gautier","Giffa","Gominon","Caballé","Cain","Collet","Couturier","Hamm","Haudegand","Hemmerlin","Hersin","Jackson","Jouaret","Kaba","Kirksay","Koffi","Lamothe","Laure","Leclère","Longueville","MBaye","Marcelot","Mayeur","Maza","Micoud","Monclar","Monetti","Moroze","Occansey","Offner","Onissah","Ostrowski","Palmer","Pellin","Petro","Pluvy","Prudhomme","Quenin","Quiblier","Racine","Rat","Rippert","Rebuffic","Rey","Risacher","Rupert","Salignon","Sangaré","Schneider","Sénégal","Smith","Souvré","Staelens","Szanyiel","Counts","Groza","Hazzard","Hawkins","Hinrich","Iguodala","Johnson","Kelley"};
const std::string positions[]={"PG","SG","F","PF","C"};
const QString photolocation[]={":/images/images/james.png",":/images/images/curry.png",":/images/images/Kevin Durant.png",":/images/images/image_2.jpg", ":/images/images/Kobe Bryant.png", ":/images/images/Derrick Rose.png", ":/images/images/Wilt Chamberlain.png", ":/images/images/Kareem Abdul-Jabbar.png", ":/images/images/Oscar Robertson.png", ":/images/images/Tim Duncan.png", ":/images/images/Paul Pierce.png", ":/images/images/Kevin Garnett.png", ":/images/images/Carmelo Anthony.png", ":/images/images/Reggie Miller.png", ":/images/images/Vince Carter.png", ":/images/images/Robert Parish.png", ":/images/images/Tony Parker.png", ":/images/images/Rudy Gobert.png", ":/images/images/Nicolas Batum.png", ":/images/images/Boris Diaw.png", ":/images/images/Evan Fournier.png", ":/images/images/Franck Ntilikina.png", ":/images/images/Joakim Noah.png", ":/images/images/Mickael Gelabale.png", ":/images/images/Timothé Luwawu-Cabarrot.png", ":/images/images/Joffrey Lauvergne.png", ":/images/images/Rodrigue Beaubois.png", ":/images/images/Mickael Piétrus.png", ":/images/images/Ian Mahinmi.png", ":/images/images/Kevin Séraphin.png", ":/images/images/Alexis Ajinça.png", ":/images/images/Guerschon Yabusele.png", ":/images/images/Tariq Abdul-Wahad.png", ":/images/images/Moustapha Fall.png", ":/images/images/Andrew Albicy.png", ":/images/images/Charles Kahudi.png", ":/images/images/Axel Toupane.png", ":/images/images/Thomas Heurtel.png", ":/images/images/Fabien Causeur.png", ":/images/images/Mathias Lessort.png", ":/images/images/Edwin Jackson.png", ":/images/images/Jérome Moiso.png", ":/images/images/Damien Inglis.png", ":/images/images/Hakeem Olajuwon.png", ":/images/images/Kyrie Irving.png", ":/images/images/Magic Johnson.png", ":/images/images/Shaquille ONeal.png", ":/images/images/James Harden.png", ":/images/images/Bill Russell.png", ":/images/images/Russell Westbrook.png", ":/images/images/Charles Barkley.png", ":/images/images/Dikembe Mutombo.png", ":/images/images/Dirk Nowitzki.png", ":/images/images/Julius Erving.png", ":/images/images/David Robinson.png", ":/images/images/Larry Bird.png", ":/images/images/James Worthy.png", ":/images/images/Allen Iverson.png", ":/images/images/Marc Gasol.png", ":/images/images/Steve Nash.png", ":/images/images/Pau Gasol.png", ":/images/images/Jason Kidd.png", ":/images/images/Karl Malone.png", ":/images/images/Gary Payton.png", ":/images/images/Yao Ming.png", ":/images/images/Dwight Howard.png", ":/images/images/Damian Lillard.png", ":/images/images/Scottie Pippen.png", ":/images/images/Georgy Adams.png", ":/images/images/Cyril Akpomedah.png", ":/images/images/Olivier Allinéi.png", ":/images/images/Pape-Philippe Amagou.png", ":/images/images/Roger Antoine.png", ":/images/images/Pape Badiane.png", ":/images/images/Philippe Baillet.png", ":/images/images/Christian Baltzer.png", ":/images/images/André Barrais.png", ":/images/images/Louis Bertorelle.png", ":/images/images/Eric Beugnot.png", ":/images/images/Jim Bilba.png", ":/images/images/Matthieu Bisséni.png", ":/images/images/David Gautier.png", ":/images/images/Sacha Giffa.png", ":/images/images/Yves Gominon.png", ":/images/images/Jacques Caballé.png", ":/images/images/Bill Cain.png", ":/images/images/Vincent Collet.png", ":/images/images/Jean Couturier.png", ":/images/images/Bruno Hamm.png", ":/images/images/Roger Haudegand.png", ":/images/images/Charles Hemmerlin.png", ":/images/images/Jean-Louis Hersin.png", ":/images/images/Skeeter Jackson.png", ":/images/images/Jean-Marie Jouaret.png", ":/images/images/Benkali Kaba.png", ":/images/images/Tariq Kirksay.png", ":/images/images/Alain Koffi.png", ":/images/images/Jacky Lamothe.png", ":/images/images/Willem Laure.png", ":/images/images/Edmond Leclère.png", ":/images/images/Michel Longueville.png", ":/images/images/Abdoulaye MBaye.png", ":/images/images/Maurice Marcelot.png", ":/images/images/Bernard Mayeur.png", ":/images/images/Gérard Maza.png", ":/images/images/Eric Micoud.png", ":/images/images/Jacques Monclar.png", ":/images/images/Frédéric Monetti.png", ":/images/images/Gérard Moroze.png", ":/images/images/Eric Occansey.png", ":/images/images/Raymond Offner.png", ":/images/images/Firmin Onissah.png", ":/images/images/Stéphane Ostrowski.png", ":/images/images/Crawford Palmer.png", ":/images/images/Marc-Antoine Pellin.png", ":/images/images/Johan Petro.png", ":/images/images/Laurent Pluvy.png", ":/images/images/Fernand Prudhomme.png", ":/images/images/Yvan Quenin.png", ":/images/images/Marc Quiblier.png", ":/images/images/Régis Racine.png", ":/images/images/Michel Rat.png", ":/images/images/Rémi Rippert.png", ":/images/images/Lucien Rebuffic.png", ":/images/images/Henri Rey.png", ":/images/images/Stéphane Risacher.png", ":/images/images/Thierry Rupert.png", ":/images/images/Jean-Pierre Salignon.png", ":/images/images/Yohan Sangaré.png", ":/images/images/Francis Schneider.png", ":/images/images/Jean-Michel Sénégal.png", ":/images/images/Ronnie Smith.png", ":/images/images/André Souvré.png", ":/images/images/Jean-Pierre Staelens.png", ":/images/images/Philip Szanyiel.png", ":/images/images/Mel Counts.png", ":/images/images/Alex Groza.png", ":/images/images/Walt Hazzard.png", ":/images/images/Hersey Hawkins.png", ":/images/images/Kirk Hinrich.png", ":/images/images/Andre Iguodala.png", ":/images/images/Joe Johnson.png"};


//constructor when player position is not given
Player::Player()
{
    //initialize the division attribute

    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];

    //choose a random number to select a picture
    int randomphoto=rand()%(sizeof(photolocation)/sizeof(photolocation[0]));
    photoadress=photolocation[randomphoto];

    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames[0]));
    surname=surnames[randomsurname];

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
    energy=100;
    motivation=70;
    attack=(sprint+passing+handling+shooting+jump+strength)/6;
    defence=(sprint+rebound+stealing+block+jump+strength)/6;
    //overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15;
    overallgeneral= attack*0.6 + defence*0.4;
    if (overallgeneral < 40) {
        marketvalue = 50000;
    }
    else {
        marketvalue = floor((0.6*pow(attack,2) + 0.4*pow(defence,2)) * 100 * 1/3);
    }
}


//constructor when the player position is given
Player::Player(std::string pos)
{
    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];

    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames[0]));
    surname=surnames[randomsurname];

    photoadress=":/images/images/IMG_5930.jpg";

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
    motivation=70;
    attack=(sprint+passing+handling+shooting+jump+strength)/6;
    defence=(sprint+rebound+stealing+block+jump+strength)/6;
    update_overall();
    if (overallgeneral < 40) {
        marketvalue = 50000;
    }
    else {
        marketvalue = floor((0.6*pow(attack,2) + 0.4*pow(defence,2)) * 100 * 1/3);
    }
    //overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15;
    overallgeneral= attack*0.6 + defence*0.4;
};

void Player::update_overall(){
    attack = (sprint+passing+handling+shooting+jump+strength)/6;
    defence = (sprint+rebound+stealing+block+jump+strength)/6;
    //overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15;
    overallgeneral= attack*0.6 + defence*0.4;
    if (overallgeneral < 40) {
        marketvalue = 50000;
    }
    else {
        marketvalue = floor((0.6*pow(attack,2) + 0.4*pow(defence,2)) * 100 * 1/3);
    }
}

void Player::afterMatchUpdate(const int change, const int motivationChange){
    sprint += change;
    rebound += change;
    passing += change;
    handling += change;
    shooting += change;
    stealing += change;
    block += change;
    jump += change;
    strength += change;
    energy -= 10;
    motivation += motivationChange;
}
