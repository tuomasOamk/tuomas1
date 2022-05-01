#ifndef ENGINE_H
#define ENGINE_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QObject>


class engine:public QObject
{
    Q_OBJECT

public:
    engine(QObject * parent = nullptr);
    ~engine();
    void sendAccountValueToExe();
    void sendCardValueToExe();
    void sendCustomerValueToExe();
    void sendTransactionValueToExe();

private:
    short number;
    QNetworkReply *reply;
    QNetworkAccessManager *getManager;
    QNetworkAccessManager *AccountManager;
    QNetworkAccessManager *CardManager;
    QNetworkAccessManager *TransactionManager;
    QNetworkAccessManager *CustomerManager;
    QString credentials="bankuser:bankpass";
    QByteArray response_data;

signals:
    void sendAccountToInterface(QString);
    void sendCardToInterface(QString);
    void sendCustomerToInterface(QString);
    void sendTransactionToInterface(QString);


private slots:
    void getAccount(QNetworkReply *reply);
    void getCard(QNetworkReply *reply);
    void getCustomer(QNetworkReply *reply);
    void getTransaction(QNetworkReply *reply);

};

#endif // ENGINE_H
