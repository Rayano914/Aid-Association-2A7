#ifndef ORANGESMS_H
#define ORANGESMS_H

#include <QObject>
#include <QtNetwork>
#include <QJsonDocument>
#include <QtCore>

class OrangeSMS : public QObject
{
    Q_OBJECT
    /**
     * @brief baseUrl
     */
    QString baseUrl;
    /**
     * @brief clientId
     */
    QString clientId;
    /**
     * @brief clientSecret
     */
    QString clientSecret;
    /**
     * @brief token
     */
    QString token;
    /**
     * @brief response
     */
    QString response;
    /**
     * @brief processStatut
     */
    bool processStatut=false;

public:
    /**
     * @brief OrangeSMS
     * @param clientId
     * @param clientSecret
     */
    explicit OrangeSMS(QString clientId,QString clientSecret);
    /**
     * @brief sendSMS
     * @param senderAddress
     * @param receiverAddress
     * @param message
     * @param senderName
     */
    void sendSMS( QString senderAddress, QString receiverAddress, QString message, QString senderName );
    /**
     * @brief executeRequest
     * @param request
     * @param method
     * @param body
     */
    void executeRequest(QNetworkRequest request,QString method,QString body);
    /**
     * @brief getTokenFromConsumerKey
     */
    void getTokenFromConsumerKey();


    QString getBaseUrl() const;
    void setBaseUrl(const QString &value);

    QString getClientId() const;
    void setClientId(const QString &value);

    QString getClientSecret() const;
    void setClientSecret(const QString &value);

    QString getToken() const;
    void setToken(const QString &value);

    QString getResponse() const;
    void setResponse(const QString &value);

    bool getProcessStatut() const;
    void setProcessStatut(bool value);

signals:
    /**
     * @brief ready
     * @param response
     */
    void responseReady(QString response);
    /**
     * @brief tokenReady
     */
    void tokenReady();

public slots:
    /**
     * @brief onReady
     * @param reply
     */
    void onReady(QNetworkReply *reply);
};

#endif // ORANGESMS_H
