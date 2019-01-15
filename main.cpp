#include <QCoreApplication>
#include "myxmlstreamwriter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyXmlStreamWriter writer;

    return a.exec();
}
