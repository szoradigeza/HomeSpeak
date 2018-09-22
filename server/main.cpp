#include <iostream>

#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("HomeSpeak server");
    QCoreApplication::setApplicationVersion("0.1 alpha");

    QCommandLineParser parser;
    parser.setApplicationDescription("HomeSpeak server program");
    parser.addHelpOption();
    parser.addVersionOption();


    return 0;
}