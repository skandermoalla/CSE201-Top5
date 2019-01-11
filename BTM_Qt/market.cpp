#include "market.h"
#include "ui_market.h"
#include <iostream>
#include <QMessageBox>

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

    // Selling Players

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

//Buy Players


// Player 1
if (theleague.playermarket.size()>=1){
this->ui->label_25->setText(QString::fromStdString(theleague.playermarket[0].surname));
this->ui->lcdNumber_13->display(theleague.playermarket[0].overallgeneral);
this->ui->label_26->setText(QString::fromStdString(theleague.playermarket[0].position));
this->ui->pushButton_14->setText(QString::number(theleague.playermarket[0].marketvalue)+"$");
}
else{
    this->ui->label_25->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_13->display("-");
    this->ui->label_26->setText(QString::fromStdString("-"));
}

// Player 2
if (theleague.playermarket.size()>=2){
this->ui->label_27->setText(QString::fromStdString(theleague.playermarket[1].surname));
this->ui->lcdNumber_14->display(theleague.playermarket[1].overallgeneral);
this->ui->label_28->setText(QString::fromStdString(theleague.playermarket[1].position));
this->ui->pushButton_15->setText(QString::number(theleague.playermarket[1].marketvalue)+"$");
}
else{
this->ui->label_27->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_14->display("-");
this->ui->label_28->setText(QString::fromStdString("-"));
}


// Player 3
if (theleague.playermarket.size()>=3){
this->ui->label_29->setText(QString::fromStdString(theleague.playermarket[2].surname));
this->ui->lcdNumber_15->display(theleague.playermarket[2].overallgeneral);
this->ui->label_30->setText(QString::fromStdString(theleague.playermarket[2].position));
this->ui->pushButton_16->setText(QString::number(theleague.playermarket[2].marketvalue)+"$");
}
else{
this->ui->label_29->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_15->display("-");
this->ui->label_30->setText(QString::fromStdString("-"));
}

// Player 4
if (theleague.playermarket.size()>=4){
this->ui->label_31->setText(QString::fromStdString(theleague.playermarket[3].surname));
this->ui->lcdNumber_16->display(theleague.playermarket[3].overallgeneral);
this->ui->label_32->setText(QString::fromStdString(theleague.playermarket[3].position));
this->ui->pushButton_17->setText(QString::number(theleague.playermarket[3].marketvalue)+"$");
}
else{
this->ui->label_31->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_16->display("-");
this->ui->label_32->setText(QString::fromStdString("-"));
}

// Player 5
if (theleague.playermarket.size()>=5){
this->ui->label_33->setText(QString::fromStdString(theleague.playermarket[4].surname));
this->ui->lcdNumber_17->display(theleague.playermarket[4].overallgeneral);
this->ui->label_34->setText(QString::fromStdString(theleague.playermarket[4].position));
this->ui->pushButton_18->setText(QString::number(theleague.playermarket[4].marketvalue)+"$");
}
else{
this->ui->label_33->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_17->display("-");
this->ui->label_34->setText(QString::fromStdString("-"));
}

// Player 6
if (theleague.playermarket.size()>=6){
this->ui->label_35->setText(QString::fromStdString(theleague.playermarket[5].surname));
this->ui->lcdNumber_18->display(theleague.playermarket[5].overallgeneral);
this->ui->label_36->setText(QString::fromStdString(theleague.playermarket[5].position));
this->ui->pushButton_19->setText(QString::number(theleague.playermarket[5].marketvalue)+"$");
}
else{
this->ui->label_35->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_18->display("-");
this->ui->label_36->setText(QString::fromStdString("-"));
}

// Player 7
if (theleague.playermarket.size()>=7){
this->ui->label_37->setText(QString::fromStdString(theleague.playermarket[6].surname));
this->ui->lcdNumber_19->display(theleague.playermarket[6].overallgeneral);
this->ui->label_38->setText(QString::fromStdString(theleague.playermarket[6].position));
this->ui->pushButton_20->setText(QString::number(theleague.playermarket[6].marketvalue)+"$");
}
else{
this->ui->label_37->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_19->display("-");
this->ui->label_38->setText(QString::fromStdString("-"));
}

// Player 8
if (theleague.playermarket.size()>=8){
this->ui->label_39->setText(QString::fromStdString(theleague.playermarket[7].surname));
this->ui->lcdNumber_20->display(theleague.playermarket[7].overallgeneral);
this->ui->label_40->setText(QString::fromStdString(theleague.playermarket[7].position));
this->ui->pushButton_21->setText(QString::number(theleague.playermarket[7].marketvalue)+"$");
}
else{
this->ui->label_39->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_20->display("-");
this->ui->label_40->setText(QString::fromStdString("-"));
}

// Player 9
if (theleague.playermarket.size()>=9){
this->ui->label_41->setText(QString::fromStdString(theleague.playermarket[8].surname));
this->ui->lcdNumber_21->display(theleague.playermarket[8].overallgeneral);
this->ui->label_42->setText(QString::fromStdString(theleague.playermarket[8].position));
this->ui->pushButton_22->setText(QString::number(theleague.playermarket[8].marketvalue)+"$");
}
else{
this->ui->label_41->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_21->display("-");
this->ui->label_42->setText(QString::fromStdString("-"));
}

// Player 10
if (theleague.playermarket.size()>=10){
this->ui->label_43->setText(QString::fromStdString(theleague.playermarket[9].surname));
this->ui->lcdNumber_22->display(theleague.playermarket[9].overallgeneral);
this->ui->label_44->setText(QString::fromStdString(theleague.playermarket[9].position));
this->ui->pushButton_23->setText(QString::number(theleague.playermarket[9].marketvalue)+"$");
}
else{
this->ui->label_43->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_22->display("-");
this->ui->label_44->setText(QString::fromStdString("-"));
}

// Player 11
if (theleague.playermarket.size()>=11){
this->ui->label_45->setText(QString::fromStdString(theleague.playermarket[10].surname));
this->ui->lcdNumber_23->display(theleague.playermarket[10].overallgeneral);
this->ui->label_46->setText(QString::fromStdString(theleague.playermarket[10].position));
this->ui->pushButton_24->setText(QString::number(theleague.playermarket[10].marketvalue)+"$");
}
else{
this->ui->label_45->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_23->display("-");
this->ui->label_46->setText(QString::fromStdString("-"));
}

// Player 12
if (theleague.playermarket.size()>=12){
this->ui->label_47->setText(QString::fromStdString(theleague.playermarket[11].surname));
this->ui->lcdNumber_24->display(theleague.playermarket[11].overallgeneral);
this->ui->label_48->setText(QString::fromStdString(theleague.playermarket[11].position));
this->ui->pushButton_25->setText(QString::number(theleague.playermarket[11].marketvalue)+"$");
}
else{
this->ui->label_47->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_24->display("-");
this->ui->label_48->setText(QString::fromStdString("-"));
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
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[0].marketvalue;
    myuser->team.PlayerSell(0);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 2
void Market::on_pushButton_2_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[1].marketvalue;
    myuser->team.PlayerSell(1);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 3
void Market::on_pushButton_3_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[2].marketvalue;
    myuser->team.PlayerSell(2);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 4
void Market::on_pushButton_4_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[3].marketvalue;
    myuser->team.PlayerSell(3);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 5
void Market::on_pushButton_5_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[4].marketvalue;
    myuser->team.PlayerSell(4);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 6
void Market::on_pushButton_6_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[5].marketvalue;
    myuser->team.PlayerSell(5);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 7
void Market::on_pushButton_7_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[6].marketvalue;
    myuser->team.PlayerSell(6);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 8
void Market::on_pushButton_8_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[7].marketvalue;
    myuser->team.PlayerSell(7);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 9
void Market::on_pushButton_9_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[8].marketvalue;
    myuser->team.PlayerSell(8);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 10
void Market::on_pushButton_10_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[9].marketvalue;
    myuser->team.PlayerSell(9);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 11
void Market::on_pushButton_11_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[10].marketvalue;
    myuser->team.PlayerSell(10);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Sell player 12
void Market::on_pushButton_12_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want sell this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget+=myuser->team.players[11].marketvalue;
    myuser->team.PlayerSell(11);
    //myuser->team.players.erase(myuser->team.players.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 1
void Market::on_pushButton_14_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[0].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[0]);
    myleague->playermarket.erase(myleague->playermarket.begin()+0);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 2
void Market::on_pushButton_15_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[1].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[1]);
    myleague->playermarket.erase(myleague->playermarket.begin()+1);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 3
void Market::on_pushButton_16_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[2].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[2]);
    myleague->playermarket.erase(myleague->playermarket.begin()+2);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 4
void Market::on_pushButton_17_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[3].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[3]);
    myleague->playermarket.erase(myleague->playermarket.begin()+3);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 5
void Market::on_pushButton_18_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[4].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[4]);
    myleague->playermarket.erase(myleague->playermarket.begin()+4);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 6
void Market::on_pushButton_19_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[5].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[5]);
    myleague->playermarket.erase(myleague->playermarket.begin()+5);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 7
void Market::on_pushButton_20_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[6].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[6]);
    myleague->playermarket.erase(myleague->playermarket.begin()+6);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 8
void Market::on_pushButton_21_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[7].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[7]);
    myleague->playermarket.erase(myleague->playermarket.begin()+7);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 9
void Market::on_pushButton_22_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[8].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[8]);
    myleague->playermarket.erase(myleague->playermarket.begin()+8);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 10
void Market::on_pushButton_23_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[9].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[9]);
    myleague->playermarket.erase(myleague->playermarket.begin()+9);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 11
void Market::on_pushButton_24_clicked()
{QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[10].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[10]);
    myleague->playermarket.erase(myleague->playermarket.begin()+10);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//Buy Player 12
void Market::on_pushButton_25_clicked()
{ QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want buy this player?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
    this -> hide();
    myuser->budget-=myleague->playermarket[11].marketvalue;
    myuser->team.PlayerBuy(myleague->playermarket[11]);
    myleague->playermarket.erase(myleague->playermarket.begin()+11);
    emit backButtonClicked(*(this->myuser));
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}
