#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTimer>

#include <iostream>
#include <fstream>

#include <qhttp/src/qhttpserver.hpp>
#include <qhttp/src/qhttpserverresponse.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    cout << "Starting Webserver application" << endl;

    QCommandLineParser parser;

    parser.addHelpOption();

    parser.process(app);

    using namespace qhttp::server;
    QHttpServer server(&app);
    server.listen( // listening on 0.0.0.0:8081
        QHostAddress::Any, 8081,
        [](QHttpRequest* req, QHttpResponse* res) {
            Q_UNUSED(req);
            // http status 200
            res->setStatusCode(qhttp::ESTATUS_OK);
            // the response body data
            res->end("Hello World!\n");
            // automatic memory management for req/res
    });

    if ( !server.isListening() ) {
        qDebug("failed to listen");
        return -1;
    }

    app.exec();

    cout << "Webserver application finished" << endl;
}
