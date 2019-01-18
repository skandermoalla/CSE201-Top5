#include "Player.h"
#include <iostream>
#include <cmath>
#include <ctime>

const std::string names[]={"LeBron","Michael","Stephen","Kevin","Edison","Kobe","Derrick","Wilt","Kareem","Oscar","Tim","Paul","Kevin","Carmelo","Reggie","Vince","Robert","Tony","Rudy","Nicolas","Boris","Evan","Franck","Joakim","Mickael","Timothe","Joffrey","Rodrigue","Mickael","Ian","Kevin","Alexis","Guerschon","Tariq","Moustapha","Andrew","Charles","Axel","Thomas","Fabien","Mathias","Edwin","Anthony","Damien","Hakeem","Kyrie","Magic","Shaquille","James","Bill","Russell","Charles","Dikembe","Dirk","Felipe","David","Alex","Pierre","Allen","Marc","Steve","Pau","Jason","Nikola","Gary","Yao","Dwight","Damian","Scottie","Alen","Cyril","Robin","Pape-Philippe","Rudy","Luigi","Gabriel","Christian","Amedeo","Demir","Toney","Toddrick","Filip","Danilo","Mouphtaou","Walter","Ante","Trey","Jan","Sasha","Luca","Nelson","Aaron","Thomas","Derrick","Erikas","Egor","Tariq","Alain","Andrey","Ian","Leo","Scottie","Abdoulaye","Nigel","Nate","Santi","Timofey","Andrey","Fedor","Yovel","Vyacheslav","Xavier","Chima","Kendrick","Evangelos","Marc-Antoine","Johan","Laurent","Eric","Shevon","Sertac","Filip","Jeff","Devin","Markel","James","Stephane","Thierry","Dee","Yohan","Francis","Yuta","Danilo","Lonzo","Taj","Lauri","J.J.","George","Walt","Serge","Kirk","Andre","Joe","Goran","Liu","Charles","Xu","Savas","Miguel","Luke","Sun","Jean-Marc","Karim", "Zainoul","Akay","Ondrej","Eulis","Salah","Aymen","Omar","Nizar","Atef","Ghaith","Michael","Amine","Khalid","Mohamed","Majid","Nabil","Abdelhakim","Jean","Mustapha","Ghaleb","Elie","Joseph","Rony","Omar","Brian","Ali","Norvel","Ali","Hussein","Ater","Jackson"};
const std::string surnames[]={"James","Jordan","Curry","Durant","Reshketa","Bryant","Rose","Chamberlain","Abdul-Jabbar","Robertson","Duncan","Pierce","Garnett","Anthony","Miller","Carter","Parish","Parker","Gobert","Batum","Diaw","Fournier","Ntilikina","Noah","Gelabale","Luwawu-Cabarrot","Lauvergne","Beaubois","Piétrus","Mahinmi","Séraphin","Ajinca","Yabusele","Abdul-Wahad","Fall","Albicy","Kahudi","Toupane","Heurtel","Causeur","Lessort","Jackson","Randolph","Inglis","Olajuwon","Irving","Johnson","ONeal","Harden","Russell","Westbrook","Barkley","Mutombo","Nowitzki","Reyes","Robinson","King","Oriola","Iverson","Gasol","Nash","Gasol","Kidd","Kalinic","Payton","Ming","Howard","Lillard","Pippen","Omic","Akpomedah","Amaize","Amagou","Fernandez","Datome","Deck","Baltzer","Della Valle","Berk","Douglas","Gotcher","Barovic","Barthel","Yarou","Tavares","Tomic","Thompkins","Vesely","Vujacic","Vildoza","Weidemann","White","Walkup","Williams","Venskus","Vialtsev","Kirksay","Koffi","Vorontsevich","Vougioukas","Westermann","Wilbekin","MBaye","William-Goss","Wolters","Yusta","Yakufin","Zubkov","Zugic","Zoosman","Zaytsev","Rabaseda","Moneke","Ray","Sakellariou","Pellin","Petro","Pluvy","Moreland","Shields","Sanli","Barovic","Brooks","Brooks","Brown","Bell","Risacher","Rupert","Bost","Sangaré","Schneider","Watanabe","Gallinari","Ball","Gibson","Markkanen","Redick","Hill","Hazzard","Ibakan","Hinrich","Iguodala","Johnson","Dragic","Wei","Jenkins","Xiaoliang","Oguz","Serrano","Fischer","Yue","Kraidy","Ouattara","Bah","Mert","Balvin","Balez","Mejri","Bouzid","Abada","Knioua","Maoua","Nakka","Roll","Rzig","Boukichou","Kherrazi","Naji","Souari","Zouita","Abdelnour","Hoff","Rida","Stephan","Vogel","Fahed","ElTurk","Beshara","Mahmoud","Pelle","Kanaan","Tawbe","Majok","Vroman"};
const std::string positions[]={"PG","SG","F","PF","C"};
const QString photolocation[]={":/images/images/James LeBron.png", ":/images/images/Michael Jordan.png", ":/images/images/Step Curry.png",":/images/images/Kevin Durant.png",":/images/images/Edison Reshketa.jpg", ":/images/images/Kobe Bryant.png", ":/images/images/Derrick Rose.png", ":/images/images/Wilt Chamberlain.png", ":/images/images/Kareem AbdulJabbar.png", ":/images/images/Oscar Robertson.png", ":/images/images/Tim Duncan.png", ":/images/images/Paul Pierce.png", ":/images/images/Kevin Garnett.png", ":/images/images/Carmelo Anthony.png", ":/images/images/Reggie Miller.png", ":/images/images/Vince Carter.png", ":/images/images/Robert Parish.png", ":/images/images/Tony Parker.png", ":/images/images/Rudy Gobert.png", ":/images/images/Nicolas Batum.png", ":/images/images/Boris Diaw.png", ":/images/images/Evan Fournier.png", ":/images/images/Franck Ntilikina.png", ":/images/images/Joakim Noah.png", ":/images/images/Mickael Gelabale.png", ":/images/images/Timothe Luwawu-Cabarrot.png", ":/images/images/Joffrey Lauvergne.png", ":/images/images/Rodrigue Beaubois.png", ":/images/images/Mickael Pietrus.png", ":/images/images/Ian Mahinmi.png", ":/images/images/Kevin Seraphin.png", ":/images/images/Alexis Ajinca.png", ":/images/images/Guerschon Yabusele.png", ":/images/images/Tariq Abdul-Wahad.png", ":/images/images/Moustapha Fall.png", ":/images/images/Andrew Albicy.png", ":/images/images/Charles Kahudi.png", ":/images/images/Axel Toupane.png", ":/images/images/Thomas Heurtel.png", ":/images/images/Fabien Causeur.png", ":/images/images/Mathias Lessort.png", ":/images/images/Edwin Jackson.png", ":/images/images/Anthony Randolph.png", ":/images/images/Damien Inglis.png", ":/images/images/Hakeem Olajuwon.png", ":/images/images/Kyrie Irving.png", ":/images/images/Magic Johnson.png", ":/images/images/Shaquille Oneal.png", ":/images/images/James Harden.png", ":/images/images/Bill Russell.png", ":/images/images/Russell Westbrook.png", ":/images/images/Charles Barkley.png", ":/images/images/Dikembe Mutombo.png", ":/images/images/Dirk Nowitzki.png", ":/images/images/Felipe Reyes.png", ":/images/images/David Robinson.png", ":/images/images/Alex King.png", ":/images/images/Pierre Oriola.png", ":/images/images/Allen Iverson.jpg", ":/images/images/Marc Gasol.png", ":/images/images/Steve Nash.png", ":/images/images/Pau Gasol.png", ":/images/images/Jason Kidd.png", ":/images/images/Nikola Kalinic.png", ":/images/images/Gary Payton.png", ":/images/images/Yao Ming.png", ":/images/images/Dwight Howard.png", ":/images/images/Damian Lillard.png", ":/images/images/Scottie Pippen.png", ":/images/images/Alen Omic.png", ":/images/images/Cyril Akpomedah.png", ":/images/images/Robin Amaize.png", ":/images/images/Pape PhilippeAmagou.png", ":/images/images/Rudy Fernandez.png", ":/images/images/Luigi Datome.png", ":/images/images/Gabriel Deck.png", ":/images/images/Christian Baltzer.png", ":/images/images/Amedeo DellaValle.png", ":/images/images/Demir Berk.png", ":/images/images/Toney Douglas.png", ":/images/images/Toddrick Gotcher.png", ":/images/images/Filip Barovic.png", ":/images/images/Danilo Barthel.png", ":/images/images/Mouphtaou Yarou.png", ":/images/images/Walter Tavares.png", ":/images/images/Ante Tomic.png", ":/images/images/Trey Thompkins.png", ":/images/images/Jan Vesely.png", ":/images/images/Sasha Vujacic.png", ":/images/images/Luca Vildoza.png", ":/images/images/Nelson Weidemann.png", ":/images/images/Aaron White.png", ":/images/images/Thomas Walkup.png", ":/images/images/Derrick Williams.png", ":/images/images/Erikas Venskus.png", ":/images/images/Egor Vialtsev.png", ":/images/images/Tariq Kirksay.png", ":/images/images/Alain Koffi.png", ":/images/images/Andrey Vorontsevich.png", ":/images/images/Ian Vougioukas.png", ":/images/images/Leo Westermann.png", ":/images/images/Scottie Wilbekin.png", ":/images/images/Abdoulaye Mbaye.png", ":/images/images/Nigel William Goss.png", ":/images/images/Nate Wolters.png", ":/images/images/Santi Yusta.png", ":/images/images/Timofey Yakufin.png", ":/images/images/Andrey Zubkov.png", ":/images/images/Fedor Zugic.png", ":/images/images/Yovel Zoosman.png", ":/images/images/Vyacheslav Zaytsev.png", ":/images/images/Xavier Rabaseda.png", ":/images/images/Chima Moneke.png", ":/images/images/Kendrick Ray.png", ":/images/images/Evangelos Sakellariou.png", ":/images/images/Marc AntoinePellin.png", ":/images/images/Johan Petro.png", ":/images/images/Laurent Pluvy.png", ":/images/images/Eric Moreland.png", ":/images/images/Shavon Shields.png", ":/images/images/Sertac Sanli.png", ":/images/images/Filip Barovic.png", ":/images/images/Jeff Brooks.png", ":/images/images/Devin Brooks.png", ":/images/images/Markel Brown.png", ":/images/images/James Bell.png", ":/images/images/Stephane Risacher.png", ":/images/images/Thierry Rupert.png", ":/images/images/Dee Bost.png", ":/images/images/Yohan Sangare.png", ":/images/images/Francis Schneider.png", ":/images/images/Yuta Watanabe.png", ":/images/images/Danilo Gallinari.png", ":/images/images/Lonzo Ball.png", ":/images/images/Taj Gibson.png", ":/images/images/Lauri Markkanen.png", ":/images/images/J.J. Redick.png", ":/images/images/George Hill.png", ":/images/images/Walt Hazzard.png", ":/images/images/Serge Ibaka.png", ":/images/images/Kirk Hinrich.png", ":/images/images/Andre Iguodala.png", ":/images/images/Joe Johnson.png", ":/images/images/Goran Dragic.png", ":/images/images/Liu Wei.png", ":/images/images/Charles Jenkins.png", ":/images/images/Xu Xiaoliang.png", ":/images/images/Savas Oguz.png", ":/images/images/Miguel Serrano.png", ":/images/images/Luke Fischer.png", ":/images/images/Sun Yue.png", ":/images/images/Jean MarcKraidy.png", ":/images/images/Karim Ouattara.png", ":/images/images/Zainoul Bah.png", ":/images/images/Akay Mert.png", ":/images/images/Ondrej Balvin.png", ":/images/images/Eulis Baez.png", ":/images/images/Salah Mejri.png", ":/images/images/Aymen Bouzid.png", ":/images/images/Omar Abada.png", ":/images/images/Nizar Knioua.png", ":/images/images/Atef Maoua.png", ":/images/images/Gaith Nakka.png", ":/images/images/Michael Roll.png", ":/images/images/Amine Rzig.png", ":/images/images/Khalid Bouchikou.png", ":/images/images/Mohamed Kherrazi.png", ":/images/images/Majid Naji.png", ":/images/images/Nabil Souari.png", ":/images/images/Abdelhakim Zouita.png", ":/images/images/Jean AbdelNour.png", ":/images/images/Mustapha Huff.png", ":/images/images/Ghaleb Rida.png", ":/images/images/Elie Stephan.png", ":/images/images/Joseph Vogel.png", ":/images/images/Rony Fahed.jpg", ":/images/images/Omar ElTurk.png", ":/images/images/Brian Beshara.png", ":/images/images/Ali Mahmoud.png", ":/images/images/Norvel Pelle.png", ":/images/images/Ali Kanaan.png", ":/images/images/Hussein Tawbe.png", ":/images/images/Ater Majok.png"};
const std::string photoloc[]={":/images/images/James LeBron.png", ":/images/images/Michael Jordan.png", ":/images/images/Step Curry.png",":/images/images/Kevin Durant.png",":/images/images/Edison Reshketa.jpg", ":/images/images/Kobe Bryant.png", ":/images/images/Derrick Rose.png", ":/images/images/Wilt Chamberlain.png", ":/images/images/Kareem AbdulJabbar.png", ":/images/images/Oscar Robertson.png", ":/images/images/Tim Duncan.png", ":/images/images/Paul Pierce.png", ":/images/images/Kevin Garnett.png", ":/images/images/Carmelo Anthony.png", ":/images/images/Reggie Miller.png", ":/images/images/Vince Carter.png", ":/images/images/Robert Parish.png", ":/images/images/Tony Parker.png", ":/images/images/Rudy Gobert.png", ":/images/images/Nicolas Batum.png", ":/images/images/Boris Diaw.png", ":/images/images/Evan Fournier.png", ":/images/images/Franck Ntilikina.png", ":/images/images/Joakim Noah.png", ":/images/images/Mickael Gelabale.png", ":/images/images/Timothe Luwawu-Cabarrot.png", ":/images/images/Joffrey Lauvergne.png", ":/images/images/Rodrigue Beaubois.png", ":/images/images/Mickael Pietrus.png", ":/images/images/Ian Mahinmi.png", ":/images/images/Kevin Seraphin.png", ":/images/images/Alexis Ajinca.png", ":/images/images/Guerschon Yabusele.png", ":/images/images/Tariq Abdul-Wahad.png", ":/images/images/Moustapha Fall.png", ":/images/images/Andrew Albicy.png", ":/images/images/Charles Kahudi.png", ":/images/images/Axel Toupane.png", ":/images/images/Thomas Heurtel.png", ":/images/images/Fabien Causeur.png", ":/images/images/Mathias Lessort.png", ":/images/images/Edwin Jackson.png", ":/images/images/Anthony Randolph.png", ":/images/images/Damien Inglis.png", ":/images/images/Hakeem Olajuwon.png", ":/images/images/Kyrie Irving.png", ":/images/images/Magic Johnson.png", ":/images/images/Shaquille Oneal.png", ":/images/images/James Harden.png", ":/images/images/Bill Russell.png", ":/images/images/Russell Westbrook.png", ":/images/images/Charles Barkley.png", ":/images/images/Dikembe Mutombo.png", ":/images/images/Dirk Nowitzki.png", ":/images/images/Felipe Reyes.png", ":/images/images/David Robinson.png", ":/images/images/Alex King.png", ":/images/images/Pierre Oriola.png", ":/images/images/Allen Iverson.jpg", ":/images/images/Marc Gasol.png", ":/images/images/Steve Nash.png", ":/images/images/Pau Gasol.png", ":/images/images/Jason Kidd.png", ":/images/images/Nikola Kalinic.png", ":/images/images/Gary Payton.png", ":/images/images/Yao Ming.png", ":/images/images/Dwight Howard.png", ":/images/images/Damian Lillard.png", ":/images/images/Scottie Pippen.png", ":/images/images/Alen Omic.png", ":/images/images/Cyril Akpomedah.png", ":/images/images/Robin Amaize.png", ":/images/images/Pape PhilippeAmagou.png", ":/images/images/Rudy Fernandez.png", ":/images/images/Luigi Datome.png", ":/images/images/Gabriel Deck.png", ":/images/images/Christian Baltzer.png", ":/images/images/Amedeo DellaValle.png", ":/images/images/Demir Berk.png", ":/images/images/Toney Douglas.png", ":/images/images/Toddrick Gotcher.png", ":/images/images/Filip Barovic.png", ":/images/images/Danilo Barthel.png", ":/images/images/Mouphtaou Yarou.png", ":/images/images/Walter Tavares.png", ":/images/images/Ante Tomic.png", ":/images/images/Trey Thompkins.png", ":/images/images/Jan Vesely.png", ":/images/images/Sasha Vujacic.png", ":/images/images/Luca Vildoza.png", ":/images/images/Nelson Weidemann.png", ":/images/images/Aaron White.png", ":/images/images/Thomas Walkup.png", ":/images/images/Derrick Williams.png", ":/images/images/Erikas Venskus.png", ":/images/images/Egor Vialtsev.png", ":/images/images/Tariq Kirksay.png", ":/images/images/Alain Koffi.png", ":/images/images/Andrey Vorontsevich.png", ":/images/images/Ian Vougioukas.png", ":/images/images/Leo Westermann.png", ":/images/images/Scottie Wilbekin.png", ":/images/images/Abdoulaye Mbaye.png", ":/images/images/Nigel William Goss.png", ":/images/images/Nate Wolters.png", ":/images/images/Santi Yusta.png", ":/images/images/Timofey Yakufin.png", ":/images/images/Andrey Zubkov.png", ":/images/images/Fedor Zugic.png", ":/images/images/Yovel Zoosman.png", ":/images/images/Vyacheslav Zaytsev.png", ":/images/images/Xavier Rabaseda.png", ":/images/images/Chima Moneke.png", ":/images/images/Kendrick Ray.png", ":/images/images/Evangelos Sakellariou.png", ":/images/images/Marc AntoinePellin.png", ":/images/images/Johan Petro.png", ":/images/images/Laurent Pluvy.png", ":/images/images/Eric Moreland.png", ":/images/images/Shavon Shields.png", ":/images/images/Sertac Sanli.png", ":/images/images/Filip Barovic.png", ":/images/images/Jeff Brooks.png", ":/images/images/Devin Brooks.png", ":/images/images/Markel Brown.png", ":/images/images/James Bell.png", ":/images/images/Stephane Risacher.png", ":/images/images/Thierry Rupert.png", ":/images/images/Dee Bost.png", ":/images/images/Yohan Sangare.png", ":/images/images/Francis Schneider.png", ":/images/images/Yuta Watanabe.png", ":/images/images/Danilo Gallinari.png", ":/images/images/Lonzo Ball.png", ":/images/images/Taj Gibson.png", ":/images/images/Lauri Markkanen.png", ":/images/images/J.J. Redick.png", ":/images/images/George Hill.png", ":/images/images/Walt Hazzard.png", ":/images/images/Serge Ibaka.png", ":/images/images/Kirk Hinrich.png", ":/images/images/Andre Iguodala.png", ":/images/images/Joe Johnson.png", ":/images/images/Goran Dragic.png", ":/images/images/Liu Wei.png", ":/images/images/Charles Jenkins.png", ":/images/images/Xu Xiaoliang.png", ":/images/images/Savas Oguz.png", ":/images/images/Miguel Serrano.png", ":/images/images/Luke Fischer.png", ":/images/images/Sun Yue.png", ":/images/images/Jean MarcKraidy.png", ":/images/images/Karim Ouattara.png", ":/images/images/Zainoul Bah.png", ":/images/images/Akay Mert.png", ":/images/images/Ondrej Balvin.png", ":/images/images/Eulis Baez.png", ":/images/images/Salah Mejri.png", ":/images/images/Aymen Bouzid.png", ":/images/images/Omar Abada.png", ":/images/images/Nizar Knioua.png", ":/images/images/Atef Maoua.png", ":/images/images/Gaith Nakka.png", ":/images/images/Michael Roll.png", ":/images/images/Amine Rzig.png", ":/images/images/Khalid Bouchikou.png", ":/images/images/Mohamed Kherrazi.png", ":/images/images/Majid Naji.png", ":/images/images/Nabil Souari.png", ":/images/images/Abdelhakim Zouita.png", ":/images/images/Jean AbdelNour.png", ":/images/images/Mustapha Huff.png", ":/images/images/Ghaleb Rida.png", ":/images/images/Elie Stephan.png", ":/images/images/Joseph Vogel.png", ":/images/images/Rony Fahed.jpg", ":/images/images/Omar ElTurk.png", ":/images/images/Brian Beshara.png", ":/images/images/Ali Mahmoud.png", ":/images/images/Norvel Pelle.png", ":/images/images/Ali Kanaan.png", ":/images/images/Hussein Tawbe.png", ":/images/images/Ater Majok.png"};


//constructor when player position is not given
Player::Player()
{
    //initialize the division attribute
    std::cout<<(sizeof(names)/sizeof(names[0]))<<" ";
    std::cout<<(sizeof(photolocation)/sizeof(photolocation[0]));
    std::cout<<std::endl;
    //choose a random numbers to select a name,surname and the photoloc
    int randomname=rand()%(sizeof(photolocation)/sizeof(photolocation[0]));
    name=names[randomname];
    //int randomphoto=rand()%(sizeof(photolocation)/sizeof(photolocation[0]));
    photoadress=photolocation[randomname];
    photoadd=photoloc[randomname];
    //int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames[0]));
    surname=surnames[randomname];

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
