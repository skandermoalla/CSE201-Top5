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
    /* Label 1-12 are the names of the users players
     * label 13-24 are the positions of the users players
     * lcdNumber 1-12 are the overalls of the users players
     * image 1-12 are the images of the users players
     * pushbutton 1-12 are the selling buttons of the users players */

    // Player 1
    if (theuser.team.players.size()>=1){
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->label_13->setText(QString::fromStdString(theuser.team.players[0].position));
    this->ui->pushButton->setText(QString::number(theuser.team.players[0].marketvalue)+"$");
        QPixmap im1(theuser.team.players[0].photoadress);
        this->ui->image_1->setPixmap(im1);
        this->ui->image_1->setScaledContents(true);
        this->ui->image_1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber->display("-");
        this->ui->label_13->setText(QString::fromStdString("-"));
        this->ui->image_1->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 2
if (theuser.team.players.size()>=2){
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_14->setText(QString::fromStdString(theuser.team.players[1].position));
    this->ui->pushButton_2->setText(QString::number(theuser.team.players[1].marketvalue)+"$");
    QPixmap im1(theuser.team.players[1].photoadress);
    this->ui->image_2->setPixmap(im1);
    this->ui->image_2->setScaledContents(true);
    this->ui->image_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}
else{
    this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_2->display("-");
    this->ui->label_14->setText(QString::fromStdString("-"));
    this->ui->image_2->setText(QString::fromStdString("        NO PICTURE "));
}


    // Player 3
if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_15->setText(QString::fromStdString(theuser.team.players[2].position));
    this->ui->pushButton_3->setText(QString::number(theuser.team.players[2].marketvalue)+"$");
    QPixmap im1(theuser.team.players[2].photoadress);
    this->ui->image_3->setPixmap(im1);
    this->ui->image_3->setScaledContents(true);
    this->ui->image_3->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_3->display("-");
    this->ui->label_15->setText(QString::fromStdString("-"));
    this->ui->image_3->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 4
if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_16->setText(QString::fromStdString(theuser.team.players[3].position));
    this->ui->pushButton_4->setText(QString::number(theuser.team.players[3].marketvalue)+"$");
    QPixmap im1(theuser.team.players[3].photoadress);
    this->ui->image_4->setPixmap(im1);
    this->ui->image_4->setScaledContents(true);
    this->ui->image_4->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_4->display("-");
    this->ui->label_16->setText(QString::fromStdString("-"));
    this->ui->image_4->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 5
if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_17->setText(QString::fromStdString(theuser.team.players[4].position));
    this->ui->pushButton_5->setText(QString::number(theuser.team.players[4].marketvalue)+"$");
    QPixmap im1(theuser.team.players[4].photoadress);
    this->ui->image_5->setPixmap(im1);
    this->ui->image_5->setScaledContents(true);
    this->ui->image_5->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_5->display("-");
    this->ui->label_17->setText(QString::fromStdString("-"));
    this->ui->image_5->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 6
if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_18->setText(QString::fromStdString(theuser.team.players[5].position));
    this->ui->pushButton_6->setText(QString::number(theuser.team.players[5].marketvalue)+"$");
    QPixmap im1(theuser.team.players[5].photoadress);
    this->ui->image_6->setPixmap(im1);
    this->ui->image_6->setScaledContents(true);
    this->ui->image_6->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_6->display("-");
    this->ui->label_18->setText(QString::fromStdString("-"));
    this->ui->image_6->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 7
if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_19->setText(QString::fromStdString(theuser.team.players[6].position));
    this->ui->pushButton_7->setText(QString::number(theuser.team.players[6].marketvalue)+"$");
    QPixmap im1(theuser.team.players[6].photoadress);
    this->ui->image_7->setPixmap(im1);
    this->ui->image_7->setScaledContents(true);
    this->ui->image_7->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}
else{
    this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_7->display("-");
    this->ui->label_19->setText(QString::fromStdString("-"));
    this->ui->image_7->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 8
if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_20->setText(QString::fromStdString(theuser.team.players[7].position));
    this->ui->pushButton_8->setText(QString::number(theuser.team.players[7].marketvalue)+"$");
    QPixmap im1(theuser.team.players[7].photoadress);
    this->ui->image_8->setPixmap(im1);
    this->ui->image_8->setScaledContents(true);
    this->ui->image_8->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_8->display("-");
    this->ui->label_20->setText(QString::fromStdString("-"));
    this->ui->image_8->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 9
if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_21->setText(QString::fromStdString(theuser.team.players[8].position));
    this->ui->pushButton_9->setText(QString::number(theuser.team.players[8].marketvalue)+"$");
    QPixmap im1(theuser.team.players[8].photoadress);
    this->ui->image_9->setPixmap(im1);
    this->ui->image_9->setScaledContents(true);
    this->ui->image_9->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_9->display("-");
    this->ui->label_21->setText(QString::fromStdString("-"));
    this->ui->image_9->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 10
if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_22->setText(QString::fromStdString(theuser.team.players[9].position));
    this->ui->pushButton_10->setText(QString::number(theuser.team.players[9].marketvalue)+"$");
    QPixmap im1(theuser.team.players[9].photoadress);
    this->ui->image_10->setPixmap(im1);
    this->ui->image_10->setScaledContents(true);
    this->ui->image_10->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_10->display("-");
    this->ui->label_22->setText(QString::fromStdString("-"));
    this->ui->image_10->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 11
if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_23->setText(QString::fromStdString(theuser.team.players[10].position));
    this->ui->pushButton_11->setText(QString::number(theuser.team.players[10].marketvalue)+"$");
    QPixmap im1(theuser.team.players[10].photoadress);
    this->ui->image_11->setPixmap(im1);
    this->ui->image_11->setScaledContents(true);
    this->ui->image_11->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_11->display("-");
    this->ui->label_23->setText(QString::fromStdString("-"));
    this->ui->image_11->setText(QString::fromStdString("        NO PICTURE "));
}

    // Player 12
if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_24->setText(QString::fromStdString(theuser.team.players[11].position));
    this->ui->pushButton_12->setText(QString::number(theuser.team.players[11].marketvalue)+"$");
    QPixmap im1(theuser.team.players[11].photoadress);
    this->ui->image_12->setPixmap(im1);
    this->ui->image_12->setScaledContents(true);
    this->ui->image_12->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_12->display("-");
    this->ui->label_24->setText(QString::fromStdString("-"));
    this->ui->image_12->setText(QString::fromStdString("        NO PICTURE "));
}

//Buy Players
/* Label 25,27,29,....47 are the names of the market players
 * label 26,28,30,....48 are the positions of the market players
 * lcdNumber 13-24 are the overalls of the market players
 * image 21-32 are the images of the market players
 * pushbutton 14-25 are the buying buttons of the market players */

// Player 1
if (theleague.playermarket.size()>=1){
this->ui->label_25->setText(QString::fromStdString(theleague.playermarket[0].surname));
this->ui->lcdNumber_13->display(theleague.playermarket[0].overallgeneral);
this->ui->label_26->setText(QString::fromStdString(theleague.playermarket[0].position));
this->ui->pushButton_14->setText(QString::number(theleague.playermarket[0].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[0].photoadress);
    this->ui->image_21->setPixmap(im1);
    this->ui->image_21->setScaledContents(true);
    this->ui->image_21->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
    this->ui->label_25->setText(QString::fromStdString("NO PLAYER"));
    this->ui->lcdNumber_13->display("-");
    this->ui->label_26->setText(QString::fromStdString("-"));
    this->ui->image_21->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 2
if (theleague.playermarket.size()>=2){
this->ui->label_27->setText(QString::fromStdString(theleague.playermarket[1].surname));
this->ui->lcdNumber_14->display(theleague.playermarket[1].overallgeneral);
this->ui->label_28->setText(QString::fromStdString(theleague.playermarket[1].position));
this->ui->pushButton_15->setText(QString::number(theleague.playermarket[1].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[1].photoadress);
    this->ui->image_22->setPixmap(im1);
    this->ui->image_22->setScaledContents(true);
    this->ui->image_22->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_27->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_14->display("-");
this->ui->label_28->setText(QString::fromStdString("-"));
    this->ui->image_22->setText(QString::fromStdString("        NO PICTURE "));
}


// Player 3
if (theleague.playermarket.size()>=3){
this->ui->label_29->setText(QString::fromStdString(theleague.playermarket[2].surname));
this->ui->lcdNumber_15->display(theleague.playermarket[2].overallgeneral);
this->ui->label_30->setText(QString::fromStdString(theleague.playermarket[2].position));
this->ui->pushButton_16->setText(QString::number(theleague.playermarket[2].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[2].photoadress);
    this->ui->image_23->setPixmap(im1);
    this->ui->image_23->setScaledContents(true);
    this->ui->image_23->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_29->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_15->display("-");
this->ui->label_30->setText(QString::fromStdString("-"));
    this->ui->image_23->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 4
if (theleague.playermarket.size()>=4){
this->ui->label_31->setText(QString::fromStdString(theleague.playermarket[3].surname));
this->ui->lcdNumber_16->display(theleague.playermarket[3].overallgeneral);
this->ui->label_32->setText(QString::fromStdString(theleague.playermarket[3].position));
this->ui->pushButton_17->setText(QString::number(theleague.playermarket[3].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[3].photoadress);
    this->ui->image_24->setPixmap(im1);
    this->ui->image_24->setScaledContents(true);
    this->ui->image_24->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_31->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_16->display("-");
this->ui->label_32->setText(QString::fromStdString("-"));
    this->ui->image_24->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 5
if (theleague.playermarket.size()>=5){
this->ui->label_33->setText(QString::fromStdString(theleague.playermarket[4].surname));
this->ui->lcdNumber_17->display(theleague.playermarket[4].overallgeneral);
this->ui->label_34->setText(QString::fromStdString(theleague.playermarket[4].position));
this->ui->pushButton_18->setText(QString::number(theleague.playermarket[4].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[4].photoadress);
    this->ui->image_25->setPixmap(im1);
    this->ui->image_25->setScaledContents(true);
    this->ui->image_25->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_33->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_17->display("-");
this->ui->label_34->setText(QString::fromStdString("-"));
    this->ui->image_25->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 6
if (theleague.playermarket.size()>=6){
this->ui->label_35->setText(QString::fromStdString(theleague.playermarket[5].surname));
this->ui->lcdNumber_18->display(theleague.playermarket[5].overallgeneral);
this->ui->label_36->setText(QString::fromStdString(theleague.playermarket[5].position));
this->ui->pushButton_19->setText(QString::number(theleague.playermarket[5].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[5].photoadress);
    this->ui->image_26->setPixmap(im1);
    this->ui->image_26->setScaledContents(true);
    this->ui->image_26->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_35->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_18->display("-");
this->ui->label_36->setText(QString::fromStdString("-"));
    this->ui->image_26->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 7
if (theleague.playermarket.size()>=7){
this->ui->label_37->setText(QString::fromStdString(theleague.playermarket[6].surname));
this->ui->lcdNumber_19->display(theleague.playermarket[6].overallgeneral);
this->ui->label_38->setText(QString::fromStdString(theleague.playermarket[6].position));
this->ui->pushButton_20->setText(QString::number(theleague.playermarket[6].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[6].photoadress);
    this->ui->image_27->setPixmap(im1);
    this->ui->image_27->setScaledContents(true);
    this->ui->image_27->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_37->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_19->display("-");
this->ui->label_38->setText(QString::fromStdString("-"));
    this->ui->image_27->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 8
if (theleague.playermarket.size()>=8){
this->ui->label_39->setText(QString::fromStdString(theleague.playermarket[7].surname));
this->ui->lcdNumber_20->display(theleague.playermarket[7].overallgeneral);
this->ui->label_40->setText(QString::fromStdString(theleague.playermarket[7].position));
this->ui->pushButton_21->setText(QString::number(theleague.playermarket[7].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[7].photoadress);
    this->ui->image_28->setPixmap(im1);
    this->ui->image_28->setScaledContents(true);
    this->ui->image_28->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_39->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_20->display("-");
this->ui->label_40->setText(QString::fromStdString("-"));
    this->ui->image_28->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 9
if (theleague.playermarket.size()>=9){
this->ui->label_41->setText(QString::fromStdString(theleague.playermarket[8].surname));
this->ui->lcdNumber_21->display(theleague.playermarket[8].overallgeneral);
this->ui->label_42->setText(QString::fromStdString(theleague.playermarket[8].position));
this->ui->pushButton_22->setText(QString::number(theleague.playermarket[8].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[8].photoadress);
    this->ui->image_29->setPixmap(im1);
    this->ui->image_29->setScaledContents(true);
    this->ui->image_29->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}
else{
this->ui->label_41->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_21->display("-");
this->ui->label_42->setText(QString::fromStdString("-"));
    this->ui->image_29->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 10
if (theleague.playermarket.size()>=10){
this->ui->label_43->setText(QString::fromStdString(theleague.playermarket[9].surname));
this->ui->lcdNumber_22->display(theleague.playermarket[9].overallgeneral);
this->ui->label_44->setText(QString::fromStdString(theleague.playermarket[9].position));
this->ui->pushButton_23->setText(QString::number(theleague.playermarket[9].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[9].photoadress);
    this->ui->image_30->setPixmap(im1);
    this->ui->image_30->setScaledContents(true);
    this->ui->image_30->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}
else{
this->ui->label_43->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_22->display("-");
this->ui->label_44->setText(QString::fromStdString("-"));
    this->ui->image_30->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 11
if (theleague.playermarket.size()>=11){
this->ui->label_45->setText(QString::fromStdString(theleague.playermarket[10].surname));
this->ui->lcdNumber_23->display(theleague.playermarket[10].overallgeneral);
this->ui->label_46->setText(QString::fromStdString(theleague.playermarket[10].position));
this->ui->pushButton_24->setText(QString::number(theleague.playermarket[10].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[10].photoadress);
    this->ui->image_31->setPixmap(im1);
    this->ui->image_31->setScaledContents(true);
    this->ui->image_31->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_45->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_23->display("-");
this->ui->label_46->setText(QString::fromStdString("-"));
    this->ui->image_31->setText(QString::fromStdString("        NO PICTURE "));
}

// Player 12
if (theleague.playermarket.size()>=12){
this->ui->label_47->setText(QString::fromStdString(theleague.playermarket[11].surname));
this->ui->lcdNumber_24->display(theleague.playermarket[11].overallgeneral);
this->ui->label_48->setText(QString::fromStdString(theleague.playermarket[11].position));
this->ui->pushButton_25->setText(QString::number(theleague.playermarket[11].marketvalue)+"$");
    QPixmap im1(theleague.playermarket[11].photoadress);
    this->ui->image_32->setPixmap(im1);
    this->ui->image_32->setScaledContents(true);
    this->ui->image_32->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
else{
this->ui->label_47->setText(QString::fromStdString("NO PLAYER"));
this->ui->lcdNumber_24->display("-");
this->ui->label_48->setText(QString::fromStdString("-"));
    this->ui->image_32->setText(QString::fromStdString("        NO PICTURE "));
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
    if (myuser->team.players.size()==7){
            QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
       }
       else{QMessageBox::StandardButton reply;

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
}

//Sell player 2
void Market::on_pushButton_2_clicked()
{if (myuser->team.players.size()==7){
        QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
}

//Sell player 3
void Market::on_pushButton_3_clicked()
{if (myuser->team.players.size()==7){
        QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 4
void Market::on_pushButton_4_clicked()
{if (myuser->team.players.size()==7){
        QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 5
void Market::on_pushButton_5_clicked()
{
    if (myuser->team.players.size()==7){
            QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
       }
       else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 6
void Market::on_pushButton_6_clicked()
{if (myuser->team.players.size()==7){
        QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 7
void Market::on_pushButton_7_clicked()
{
    if (myuser->team.players.size()==7){
            QMessageBox::about(this, "Impossible transaction", "Minimum number of players reached");
       }
       else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 8
void Market::on_pushButton_8_clicked()
{
    if (myuser->team.players.size()<8) {
    }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 9
void Market::on_pushButton_9_clicked()
{
    if (myuser->team.players.size()<9) {
    }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 10
void Market::on_pushButton_10_clicked()
{
    if (myuser->team.players.size()<10) {
    }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 11
void Market::on_pushButton_11_clicked()
{
    if (myuser->team.players.size()<11) {
    }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Sell player 12
void Market::on_pushButton_12_clicked()
{
    if (myuser->team.players.size()<12) {
    }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 1
void Market::on_pushButton_14_clicked()
{
    if (myuser->team.players.size()==12){
             QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
        }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 2
void Market::on_pushButton_15_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 3
void Market::on_pushButton_16_clicked()
{
    if (myuser->team.players.size()==12){
             QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
        }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 4
void Market::on_pushButton_17_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 5
void Market::on_pushButton_18_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 6
void Market::on_pushButton_19_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 7
void Market::on_pushButton_20_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 8
void Market::on_pushButton_21_clicked()
{
    if (myuser->team.players.size()==12){
             QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
        }
        else{
        QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 9
void Market::on_pushButton_22_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
    QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 10
void Market::on_pushButton_23_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
    QMessageBox::StandardButton reply;
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
        }}
}

//Buy Player 11
void Market::on_pushButton_24_clicked()
{if (myuser->team.players.size()==12){
        QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
   }
   else{
    QMessageBox::StandardButton reply;

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
        }}
}

//Buy Player 12
void Market::on_pushButton_25_clicked()
{   if (myuser->team.players.size()==12){
         QMessageBox::about(this, "Impossible transaction", "Maximum number of players reached");
    }
    else{
    QMessageBox::StandardButton reply;
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
}
