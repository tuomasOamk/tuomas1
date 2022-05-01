#include "interfacerestapi.h"
#include "interfacerestapi.h"


InterfaceRestApi::InterfaceRestApi(QObject * parent):QObject(parent)
{
  qDebug()<<"DLL luotu";
  pEngine = new engine;
  connect(pEngine,SIGNAL(sendAccountToInterface(QString)),
          this,SLOT(receiveAccountValueFromEngine(QString)));
}

InterfaceRestApi::~InterfaceRestApi()
{
    qDebug()<<"DLL tuhottu";
    delete pEngine;
    pEngine = nullptr;
}

void InterfaceRestApi::getAccount()
{
    pEngine->sendAccountValueToExe();
}

void InterfaceRestApi::getCard()
{
    pEngine->sendCardValueToExe();

}

void InterfaceRestApi::getCustomer()
{
    pEngine->sendCustomerValueToExe();

}

void InterfaceRestApi::getTransaction()
{
    pEngine->sendTransactionValueToExe();

}

void InterfaceRestApi::receiveAccountValueFromEngine(QString tili)
{
    emit sendAccountValueToExe(tili);
}

void InterfaceRestApi::receiveCardValueFromEngine(QString kortti)
{
    emit sendCardValueToExe(kortti);
}

void InterfaceRestApi::receiveCustomerValueFromEngine(QString asiakas)
{
    emit sendCustomerValueToExe(asiakas);
}

void InterfaceRestApi::receiveTransactionValueFromEngine(QString raha)
{
    emit sendTransactionValueToExe(raha);
}
