#pragma once

#include <QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QList>

class WebSocketServer : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketServer(quint16 port, QObject* parent = nullptr);
    ~WebSocketServer();

private slots:
    void onNewConnection();
    void processMessage(QString message);
    void socketDisconnected();
private:
    QWebSocketServer *m_webSocketServer;
    QList<QWebSocket *> m_clients;
};

