#include "market.h"
#include "ui_market.h"

Market::Market(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
}
Market::Market(User& theuser, League& theleague , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
    myuser=&theuser;
    myleague=&theleague;
    // Player 1
    if (theuser.team.players.size()>=1){
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->label_13->setText(QString::fromStdString(theuser.team.players[0].position));
    this->ui->pushButton->setText(QString::number(theuser.team.players[0].marketvalue)+"$");
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber->display("-");
        this->ui->label_13->setText(QString::fromStdString("-"));
    }

    // Player 2
if (theuser.team.players.size()>=2){
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_14->setText(QString::fromStdString(theuser.team.players[1].position));
    this->ui->pushButton_2->setText(QString::number(theuser.team.players[1].marketvalue)+"$");
}
else{
    this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_2->display("-");
    this->ui->label_14->setText(QString::fromStdString("-"));
}


    // Player 3
if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_15->setText(QString::fromStdString(theuser.team.players[2].position));
    this->ui->pushButton_3->setText(QString::number(theuser.team.players[2].marketvalue)+"$");
}
else{
    this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_3->display("-");
    this->ui->label_15->setText(QString::fromStdString("-"));
}

    // Player 4
if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_16->setText(QString::fromStdString(theuser.team.players[3].position));
    this->ui->pushButton_4->setText(QString::number(theuser.team.players[3].marketvalue)+"$");
}
else{
    this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_4->display("-");
    this->ui->label_16->setText(QString::fromStdString("-"));
}

    // Player 5
if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_17->setText(QString::fromStdString(theuser.team.players[4].position));
    this->ui->pushButton_5->setText(QString::number(theuser.team.players[4].marketvalue)+"$");
}
else{
    this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_5->display("-");
    this->ui->label_17->setText(QString::fromStdString("-"));
}

    // Player 6
if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_18->setText(QString::fromStdString(theuser.team.players[5].position));
    this->ui->pushButton_6->setText(QString::number(theuser.team.players[5].marketvalue)+"$");
}
else{
    this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_6->display("-");
    this->ui->label_18->setText(QString::fromStdString("-"));
}

    // Player 7
if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_19->setText(QString::fromStdString(theuser.team.players[6].position));
    this->ui->pushButton_7->setText(QString::number(theuser.team.players[6].marketvalue)+"$");
}
else{
    this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_7->display("-");
    this->ui->label_19->setText(QString::fromStdString("-"));
}

    // Player 8
if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_20->setText(QString::fromStdString(theuser.team.players[7].position));
    this->ui->pushButton_8->setText(QString::number(theuser.team.players[7].marketvalue)+"$");
}
else{
    this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_8->display("-");
    this->ui->label_20->setText(QString::fromStdString("-"));
}

    // Player 9
if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_21->setText(QString::fromStdString(theuser.team.players[8].position));
    this->ui->pushButton_9->setText(QString::number(theuser.team.players[8].marketvalue)+"$");
}
else{
    this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_9->display("-");
    this->ui->label_21->setText(QString::fromStdString("-"));
}

    // Player 10
if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_22->setText(QString::fromStdString(theuser.team.players[9].position));
    this->ui->pushButton_10->setText(QString::number(theuser.team.players[9].marketvalue)+"$");
}
else{
    this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_10->display("-");
    this->ui->label_22->setText(QString::fromStdString("-"));
}

    // Player 11
if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_23->setText(QString::fromStdString(theuser.team.players[10].position));
    this->ui->pushButton_11->setText(QString::number(theuser.team.players[10].marketvalue)+"$");
}
else{
    this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_11->display("-");
    this->ui->label_23->setText(QString::fromStdString("-"));
}

    // Player 12
if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_24->setText(QString::fromStdString(theuser.team.players[11].position));
    this->ui->pushButton_12->setText(QString::number(theuser.team.players[11].marketvalue)+"$");
}
else{
    this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_12->display("-");
    this->ui->label_24->setText(QString::fromStdString("-"));
}

}


Market::~Market()
{
    delete ui;
}

//Back Button
void Market::on_pushButton_13_clicked()
{
    this -> hide();
    emit backButtonClicked(*(this->myuser));
    //emit backButtonClicked();
}

//Sell player 1
void Market::on_pushButton_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[0].marketvalue;
    myuser->team.PlayerSell(0);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 2
void Market::on_pushButton_2_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[1].marketvalue;
    myuser->team.PlayerSell(1);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 3
void Market::on_pushButton_3_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[2].marketvalue;
    myuser->team.PlayerSell(2);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 4
void Market::on_pushButton_4_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[3].marketvalue;
    myuser->team.PlayerSell(3);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 5
void Market::on_pushButton_5_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[4].marketvalue;
    myuser->team.PlayerSell(4);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 6
void Market::on_pushButton_6_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[5].marketvalue;
    myuser->team.PlayerSell(5);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 7
void Market::on_pushButton_7_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[6].marketvalue;
    myuser->team.PlayerSell(6);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 8
void Market::on_pushButton_8_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[7].marketvalue;
    myuser->team.PlayerSell(7);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 9
void Market::on_pushButton_9_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[8].marketvalue;
    myuser->team.PlayerSell(8);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

//Sell player 10
void Market::on_pushButton_10_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[9].marketvalue;
    myuser->team.PlayerSell(9);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}
//Sell player 11
void Market::on_pushButton_11_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[10].marketvalue;
    myuser->team.PlayerSell(10);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}
//Sell player 12
void Market::on_pushButton_12_clicked()
{
    this -> hide();
    myuser->budget+=myuser->team.players[11].marketvalue;
    myuser->team.PlayerSell(11);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
}

