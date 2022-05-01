#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnTransaction_clicked()
{   QString site_url="http://localhost:3000/transaction";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    oneTransactionManager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(getTransactionSlot(QNetworkReply*)));
    reply = manager->get(request);
}

void MainWindow::on_btn20_clicked()
{

        QString site_url="http://localhost:3000/transaction";
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        oneTransactionManager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(getTransactionSlot(QNetworkReply*)));
        reply = manager->get(request);
}

void MainWindow::on_btn40_clicked()
{

}

void MainWindow::on_btn60_clicked()
{

}

void MainWindow::on_btn100_clicked()
{

}

void MainWindow::on_btn200_clicked()
{

}

void MainWindow::on_btn500_clicked()
{

}


void MainWindow::getTransactionSlot(QNetworkReply *reply)
{

    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
  //QJsonArray josn_array = json_doc.array();
  //QJsonObject json_obj = json_array[0].toObject();
    for_each ( QJsonValue &0 json_array) {
    transaction+=QString::number(json_obj["id_card"].toInt())+","+json_obj["id_account"].toInt()+","+json_obj["id_transaction"].toInt()+","+json_obj["time"].toInt()+","+json_obj["sum"].toInt()+"/r";
    ui->txtTransactions->setText(transaction);
    }

\
}

