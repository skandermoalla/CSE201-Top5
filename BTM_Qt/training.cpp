#include "training.h"
#include "ui_training.h"
#include <iostream>
#include <QMessageBox>

Training::Training(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);

}

Training::Training(User &theuser , League& league, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    myuser = &theuser;
    myleague = &league;

     // Player 1
    if (theuser.team.players.size()>=1){
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
        this->ui->label->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(theuser.team.players[0].energy);
    // Image Player 1
    QPixmap im1(theuser.team.players[0].photoadress);
    this->ui->image_1->setPixmap(im1);
    this->ui->image_1->setScaledContents(true);
    this->ui->image_1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber->display("-");
        this->ui->labelp->setText(QString::fromStdString("-"));

        ui->progressBar->setRange(0, 100);
        ui->progressBar->setValue(0);
        this->ui->image_1->setText(QString::fromStdString("        NO PICTURE "));

    }

    // Player 2
    if (theuser.team.players.size()>=2){
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
        this->ui->label_2->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));

    ui->progressBar_2->setRange(0, 100);
    ui->progressBar_2->setValue(theuser.team.players[1].energy);
    QPixmap im1(theuser.team.players[1].photoadress);
    this->ui->image_2->setPixmap(im1);
    this->ui->image_2->setScaledContents(true);
    this->ui->image_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_2->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_2->display("-");
        this->ui->label_2p->setText(QString::fromStdString("-"));

        ui->progressBar_2->setRange(0, 100);
        ui->progressBar_2->setValue(0);
        this->ui->image_2->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 3
    if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
        this->ui->label_3->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));

    ui->progressBar_3->setRange(0, 100);
    ui->progressBar_3->setValue(theuser.team.players[2].energy);
        QPixmap im1(theuser.team.players[2].photoadress);
        this->ui->image_3->setPixmap(im1);
        this->ui->image_3->setScaledContents(true);
        this->ui->image_3->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_3->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_3->display("-");
        this->ui->label_3p->setText(QString::fromStdString("-"));

        ui->progressBar_3->setRange(0, 100);
        ui->progressBar_3->setValue(0);
        this->ui->image_3->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 4
    if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
        this->ui->label_4->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));

        ui->progressBar_4->setRange(0, 100);
        ui->progressBar_4->setValue(theuser.team.players[3].energy);
        QPixmap im1(theuser.team.players[3].photoadress);
        this->ui->image_4->setPixmap(im1);
        this->ui->image_4->setScaledContents(true);
        this->ui->image_4->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_4->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_4->display("-");
        this->ui->label_4p->setText(QString::fromStdString("-"));

        ui->progressBar_4->setRange(0, 100);
        ui->progressBar_4->setValue(0);
        this->ui->image_4->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 5
    if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
        this->ui->label_5->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[4].position));

        ui->progressBar_5->setRange(0, 100);
        ui->progressBar_5->setValue(theuser.team.players[4].energy);
        QPixmap im1(theuser.team.players[4].photoadress);
        this->ui->image_5->setPixmap(im1);
        this->ui->image_5->setScaledContents(true);
        this->ui->image_5->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_5->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_5->display("-");
        this->ui->label_5p->setText(QString::fromStdString("-"));

        ui->progressBar_5->setRange(0, 100);
        ui->progressBar_5->setValue(0);
        this->ui->image_5->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 6
    if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
        this->ui->label_6->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));

        ui->progressBar_6->setRange(0, 100);
        ui->progressBar_6->setValue(theuser.team.players[5].energy);
        QPixmap im1(theuser.team.players[5].photoadress);
        this->ui->image_6->setPixmap(im1);
        this->ui->image_6->setScaledContents(true);
        this->ui->image_6->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_6->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_6->display("-");
        this->ui->label_6p->setText(QString::fromStdString("-"));

        ui->progressBar_6->setRange(0, 100);
        ui->progressBar_6->setValue(0);
        this->ui->image_6->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 7
    if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
        this->ui->label_7->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));

        ui->progressBar_7->setRange(0, 100);
        ui->progressBar_7->setValue(theuser.team.players[6].energy);
        QPixmap im1(theuser.team.players[6].photoadress);
        this->ui->image_7->setPixmap(im1);
        this->ui->image_7->setScaledContents(true);
        this->ui->image_7->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    }
    else{
        this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_7->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_7->display("-");
        this->ui->label_7p->setText(QString::fromStdString("-"));

        ui->progressBar_7->setRange(0, 100);
        ui->progressBar_7->setValue(0);
        this->ui->image_7->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 8
    if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
        this->ui->label_8->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));

        ui->progressBar_8->setRange(0, 100);
        ui->progressBar_8->setValue(theuser.team.players[7].energy);
        QPixmap im1(theuser.team.players[7].photoadress);
        this->ui->image_8->setPixmap(im1);
        this->ui->image_8->setScaledContents(true);
        this->ui->image_8->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_8->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_8->display("-");
        this->ui->label_8p->setText(QString::fromStdString("-"));

        ui->progressBar_8->setRange(0, 100);
        ui->progressBar_8->setValue(0);
        this->ui->image_8->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 9
    if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
        this->ui->label_9->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));

        ui->progressBar_9->setRange(0, 100);
        ui->progressBar_9->setValue(theuser.team.players[8].energy);
        QPixmap im1(theuser.team.players[8].photoadress);
        this->ui->image_9->setPixmap(im1);
        this->ui->image_9->setScaledContents(true);
        this->ui->image_9->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_9->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_9->display("-");
        this->ui->label_9p->setText(QString::fromStdString("-"));

        ui->progressBar_9->setRange(0, 100);
        ui->progressBar_9->setValue(0);
        this->ui->image_9->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 10
    if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
        this->ui->label_10->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));

        ui->progressBar_10->setRange(0, 100);
        ui->progressBar_10->setValue(theuser.team.players[9].energy);
        QPixmap im1(theuser.team.players[9].photoadress);
        this->ui->image_10->setPixmap(im1);
        this->ui->image_10->setScaledContents(true);
        this->ui->image_10->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_10->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_10->display("-");
        this->ui->label_10p->setText(QString::fromStdString("-"));

        ui->progressBar_10->setRange(0, 100);
        ui->progressBar_10->setValue(0);
        this->ui->image_10->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 11
    if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
        this->ui->label_11->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));

        ui->progressBar_11->setRange(0, 100);
        ui->progressBar_11->setValue(theuser.team.players[10].energy);
        QPixmap im1(theuser.team.players[10].photoadress);
        this->ui->image_11->setPixmap(im1);
        this->ui->image_11->setScaledContents(true);
        this->ui->image_11->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_11->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_11->display("-");
        this->ui->label_11p->setText(QString::fromStdString("-"));

        ui->progressBar_11->setRange(0, 100);
        ui->progressBar_11->setValue(0);
        this->ui->image_11->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 12
    if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
        this->ui->label_12->setAlignment(Qt::AlignCenter);
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));

        ui->progressBar_12->setRange(0, 100);
        ui->progressBar_12->setValue(theuser.team.players[11].energy);
        QPixmap im1(theuser.team.players[11].photoadress);
        this->ui->image_12->setPixmap(im1);
        this->ui->image_12->setScaledContents(true);
        this->ui->image_12->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
        this->ui->label_12->setAlignment(Qt::AlignCenter);
        this->ui->lcdNumber_12->display("-");
        this->ui->label_12p->setText(QString::fromStdString("-"));

        ui->progressBar_12->setRange(0, 100);
        ui->progressBar_12->setValue(0);
        this->ui->image_12->setText(QString::fromStdString("        NO PICTURE "));
}

    // Budget Display
    this->ui->lcdNumber_16->display(theuser.budget);


    // Energy Left Display
    this->ui->lcdNumber_13->display(theuser.team.energy);
}


Training::~Training()
{
    delete ui;
}

void Training::on_pushButton_5_clicked()
{
    emit backButtonClicked(*(this->myuser));
    std::cout<<"signal emitted"<<std::endl;
    this -> hide();
}

//Defense training
void Training::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=5000;
            myuser->team.Training1();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {   //uncomment this if you want 'no' to send you to the mainwindw
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }


}
//second training
void Training::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=8000;
            myuser->team.Training2();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//third training
void Training::on_pushButton_3_clicked()
{   QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=7000;
            myuser->team.Training3();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }

}
//fourth training
void Training::on_pushButton_4_clicked()
{   QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=10000;
            myuser->team.Training4();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

