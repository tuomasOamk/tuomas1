#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define PRINT(a) prinf(#a" : %d", a)
#define PRINT_ALL(...) ? ? ? THE PROBLEM ? ? ?

#include <QMainWindow>
#include <qnetwork.h>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_btnshowaccount_clicked();
    void on_btnTransaction_clicked();
    void on_btnshowtransaction_clicked();
    void on_btnshowcustomer_clicked();

    void on_btn20_clicked();
    void on_btn40_clicked();
    void on_btn60_clicked();
    void on_btn100_clicked();
    void on_btn200_clicked();
    void on_btn500_clicked();

private slots:
    void getTransactionSlot(QNetworkReply *reply);
    void getCardSlot(QNetworkReply *reply);
    void getCustomerSlot(QNetworkReply *reply);
    void getAccountSlot(QNetworkReply *reply);


private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *manager;
    QNetworkAccessManager *oneAccountManager;
    QNetworkAccessManager *oneCardManager;
    QNetworkAccessManager *oneTransactionManager;
    QNetworkAccessManager *oneCustomerManager;
    QNetworkReply *reply;


};
#endif // MAINWINDOW_H
