#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTimer>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    cout << "Starting Webserver application" << endl;

    QCommandLineParser parser;

    parser.addHelpOption();

    parser.process(app);

    QTimer::singleShot(100, &app, &QCoreApplication::quit);

    app.exec();

    cout << "Webserver application finished" << endl;
}
