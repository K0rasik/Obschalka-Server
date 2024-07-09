#include "websocket_server.h"
#include <QDebug>

WebSocketServer::WebSocketServer(quint16 port, QObject *parent) :
    QObject(parent),
    m_webSocketServer(new QWebSocketServer(QStringLiteral("Chat Server"),
                                           QWebSocketServer::NonSecureMode,
                                           this))
{
    if (m_webSocketServer->listen(QHostAddress::Any, port)) {
        qDebug() << "WebSocket server listening on port" << port;
        connect(m_webSocketServer, &QWebSocketServer::newConnection,
                this, &WebSocketServer::onNewConnection);
    }
}

void WebSocketServer::onNewConnection()
{
    QWebSocket *socket = m_webSocketServer->nextPendingConnection();
    connect(socket, &QWebSocket::textMessageReceived,
        this,  &WebSocketServer::processMessage);
    connect(socket, &QWebSocket::disconnected,
        this, &WebSocketServer::socketDisconnected);
    m_clients << socket;
    qDebug() <<"New client connected";
}