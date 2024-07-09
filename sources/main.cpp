#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WebSocketServer server(1234); // Задайте порт для WebSocket сервера

    return a.exec();
}
