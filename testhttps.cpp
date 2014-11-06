#include "testhttps.h"
#include <QUrl>
#include <QDebug>

TestHTTPS::TestHTTPS(QObject *parent) : QObject(parent)
      {
      _qnam = new QNetworkAccessManager();
      }

void TestHTTPS::get() {
      connect(_qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
      _qnam->get(QNetworkRequest(QUrl("https://musescore.com")));
      }

void TestHTTPS::replyFinished(QNetworkReply* reply)
{
      QByteArray r =  reply->readAll();
      if (r.startsWith("<!DOCTYPE html>"))
            qDebug() << "HTTPS with QNAM : OK";
      else
            qDebug() << "HTTPS with QNAM : KO";
}


