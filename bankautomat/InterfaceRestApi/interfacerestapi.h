#ifndef INTERFACERESTAPI_H
#define INTERFACERESTAPI_H

#include "InterfaceRestApi_global.h"
#include <QObject>
#include "engine.h"

class INTERFACERESTAPI_EXPORT InterfaceRestApi:public QObject
{
    Q_OBJECT

public:
    InterfaceRestApi(QObject * parent = nullptr);
    ~InterfaceRestApi();


signals:
 void sendAccountValueToExe(QString);
 void sendCardValueToExe(QString);
 void sendCustomerValueToExe(QString);
 void sendTransactionValueToExe(QString);


public slots:
 void getAccount();
 void getCard();
 void getCustomer();
 void getTransaction();
 void receiveAccountValueFromEngine(QString tili);
 void receiveCardValueFromEngine(QString kortti);
 void receiveCustomerValueFromEngine(QString asiakas);
 void receiveTransactionValueFromEngine(QString raha);

private:
   class engine*pEngine;
};

#endif // INTERFACERESTAPI_H
