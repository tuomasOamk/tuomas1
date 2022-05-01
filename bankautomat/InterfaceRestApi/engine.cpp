#include "engine.h"

engine::engine(QObject *parent):QObject(parent)
{

}

engine::~engine()
{

}

void engine::sendAccountValueToExe()
{
    QString site_url="http://localhost:3000/account";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU
    getManager = new QNetworkAccessManager(this);
    connect(getManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAccount(QNetworkReply*)));
    reply = getManager->get(request);
}



void engine::getAccount(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString account;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       account+=QString::number(json_obj["id_account"].toInt())+",\r"+QString::number(json_obj["id_customer"].toInt())+",\r"+QString::number(json_obj["balance"].toDouble())+"\r";
}
   reply->deleteLater();
   getManager->deleteLater();
   emit sendAccountToInterface(account);
}

void engine::sendCardValueToExe()
{
    QString site_url="http://localhost:3000/card";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCard(QNetworkReply*)));
    reply = getManager->get(request);
}


void engine::getCard(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString card;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       card+=QString::number(json_obj["id_card"].toInt())+",\r"+json_obj["id_account"].toInt()+",\r"+QString::number(json_obj["type"].toInt())+",\r"+QString::number(json_obj["locked"].toInt())+"\r";
       }
    reply->deleteLater();
    getManager->deleteLater();
    emit sendCardToInterface(card);

}


void engine::sendCustomerValueToExe()
{
    QString site_url="http://localhost:3000/customer";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU
    getManager = new QNetworkAccessManager(this);
    connect(getManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(getCustomer(QNetworkReply*)));
    reply = getManager->get(request);
}

void engine::getCustomer(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString customer;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
    customer+=QString::number(json_obj["id_Customer"].toInt())+",\r"+json_obj["fname"].toString()+",\r"+json_obj["lname"].toString()+",\r"+json_obj["address"].toString()+",\r"+QString::number(json_obj["telephone"].toInt())+"\r";
    }
    reply->deleteLater();
    getManager->deleteLater();
    emit sendCustomerToInterface(customer);
}


void engine::sendTransactionValueToExe()
{
    QString site_url="http://localhost:3000/transaction";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU
    getManager = new QNetworkAccessManager(this);
    connect(getManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(getTransaction(QNetworkReply*)));
    reply = getManager->get(request);
}

void engine::getTransaction(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transaction;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    transaction+=QString::number(json_obj["id_transaction"].toInt())+",\r"+QString::number(json_obj["id_account"].toInt())+",\r"+QString::number(json_obj["id_card"].toInt())+",\r"+QString::number(json_obj["time"].toInt())+",\r"+QString::number(json_obj["sum"].toDouble())+"\r";
   }
    reply->deleteLater();
    getManager->deleteLater();
    emit sendTransactionToInterface(transaction);
}

