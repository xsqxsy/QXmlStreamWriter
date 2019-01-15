#include "myxmlstreamwriter.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>


MyXmlStreamWriter::MyXmlStreamWriter()
{
    writeXml();
}

void MyXmlStreamWriter::writeXml()
{
    QFile file("../QXmlStreamWriter/test.xml");
    bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(isOk)
    {
        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);

        writer.writeStartDocument();
        writer.writeStartElement("bookindex");

        writer.writeStartElement("entry");
        writer.writeAttribute("term", "sidebearings");
        writer.writeTextElement("page", "10");
        writer.writeTextElement("page", "34-35");
        writer.writeTextElement("page", "307-308");
        writer.writeEndElement();

        writer.writeStartElement("entry");
        writer.writeAttribute("term", "subtraction");

        writer.writeStartElement("entry");
        writer.writeAttribute("term", "of pictures");
        writer.writeTextElement("page", "115");
        writer.writeTextElement("page", "224");
        writer.writeEndElement();

        writer.writeStartElement("entry");
        writer.writeAttribute("term", "of vectors");
        writer.writeTextElement("page", "9");
        writer.writeEndElement();

        writer.writeEndElement();

        writer.writeEndElement();
        writer.writeEndDocument();

        file.close();

        qDebug() << "Successfully accomplished the xml file";
    }
    else
    {
        qDebug() << "failed to open file!";
    }
}
