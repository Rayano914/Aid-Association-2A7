#include "OrangeSMS.h"

QString OrangeSMS::getBaseUrl() const
{
    return baseUrl;
}

void OrangeSMS::setBaseUrl(const QString &value)
{
    baseUrl = value;
}

QString OrangeSMS::getClientId() const
{
    return clientId;
}

void OrangeSMS::setClientId(const QString &value)
{
    clientId = value;
}

QString OrangeSMS::getClientSecret() const
{
    return clientSecret;
}

void OrangeSMS::setClientSecret(const QString &value)
{
    clientSecret = value;
}

QString OrangeSMS::getToken() const
{
    return token;
}

void OrangeSMS::setToken(const QString &value)
{
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8());
    QJsonObject object = document.object();
    QJsonValue finalValue = object.value(QString("access_token"));

    token=finalValue.toString();

    emit tokenReady();
}

QString OrangeSMS::getResponse() const
{
    return response;
}

void OrangeSMS::setResponse(const QString &value)
{
    response = value;
    setProcessStatut(true);
}

void OrangeSMS::onReady(QNetworkReply *reply)
{
    QString response;
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                response = QString::fromUtf8(buffer);
            }
        } else {
            response = tr("Error: %1 status: %2").arg(reply->errorString(), reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
            qDebug() << response;
        }

        reply->deleteLater();
    }

    if (response.trimmed().isEmpty()) {
        response = tr("Unable to retrieve response");
    }

    emit responseReady(response);
}

bool OrangeSMS::getProcessStatut() const
{
    return processStatut;
}

void OrangeSMS::setProcessStatut(bool value)
{
    processStatut = value;
}

OrangeSMS::OrangeSMS(QString clientId,QString clientSecret)
{
    setBaseUrl("https://api.orange.com");
    setClientId(clientId);
    setClientSecret(clientSecret);
}

void OrangeSMS::sendSMS(QString senderAddress, QString receiverAddress, QString message, QString senderName)
{
    QJsonObject outBound,principal,messageJson;

    QString fullSenderAddress="+21654055545"+senderAddress.toLatin1().toPercentEncoding();
    QString fullReceiverAddress="+21654055545"+receiverAddress.toLatin1().toPercentEncoding();

    outBound["address"] = fullReceiverAddress;
    outBound["senderAddress"] = fullSenderAddress;
    outBound["senderName"] = senderName;
    messageJson["message"]= message;
    outBound["outboundSMSTextMessage"]=messageJson;
    principal["outboundSMSMessageRequest"] = outBound;


    QString url = getBaseUrl()+"/smsmessaging/v1/outbound/"+fullSenderAddress+"/requests";
    const QUrl finalUrl(url);

    QNetworkRequest request(finalUrl);
    request.setRawHeader("Authorization"," Bearer "+getToken().toLatin1());
    request.setRawHeader("Content-Type","application/json");

    QJsonDocument jsonDocument(principal);

    QString body=jsonDocument.toJson(QJsonDocument::Compact);

    executeRequest(request,"POST",body);
}

void OrangeSMS::executeRequest(QNetworkRequest request, QString method, QString body)
{
    QNetworkAccessManager* networkAccessManager=new QNetworkAccessManager;

    if(method=="POST"){
        networkAccessManager->post(request,body.toLatin1());
    }else{
        networkAccessManager->get(request);
    }

    bool ok = connect(networkAccessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onReady(QNetworkReply*)));
    Q_ASSERT(ok);
    Q_UNUSED(ok);
}

void OrangeSMS::getTokenFromConsumerKey()
{
    QString body="grant_type=client_credentials";
    QString url = getBaseUrl()+"/oauth/v2/token";
    const QUrl finalUrl(url);
    QString credentials=getClientId()+":"+getClientSecret();

    QNetworkRequest request(finalUrl);
    request.setRawHeader("Authorization"," Basic "+credentials.toLatin1().toBase64());
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");

    executeRequest(request,"POST",body);
}
