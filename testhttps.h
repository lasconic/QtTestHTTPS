#ifndef TESTHTTPS_H
#define TESTHTTPS_H

#include <QNetworkReply>
#include <QObject>
#include <QNetworkAccessManager>

class TestHTTPS : public QObject{
      Q_OBJECT
      QNetworkAccessManager* _qnam;
public:
      TestHTTPS(QObject *parent = 0);
      void get();
public slots:
      void replyFinished(QNetworkReply* reply);
      };


#endif // TESTHTTPS_H
