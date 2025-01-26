#include "file_handlers/Writer.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>

Writer::Writer(const QString &outputFile)
{
    m_outputFile = prepareOutputFile(outputFile, "/output2");
}

QString Writer::prepareOutputFile(const QString &outputFile, const QString &subDir)
{
    QString outputPath = QDir::currentPath() + subDir;
    QDir().mkpath(outputPath);
    QString fullOutputPath = outputPath + "/" + QFileInfo(outputFile).fileName();
    qDebug() << "Output file set to:" << fullOutputPath;
    return fullOutputPath;
}
