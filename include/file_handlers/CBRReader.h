#ifndef CBRREADER_H
#define CBRREADER_H

#include "Reader.h"

class CBRReader : public Reader
{
public:
    explicit CBRReader(const QString &filePath);
    QStringList extractImages() override;

private:
    QString prepareOutputDirectory();
    bool executeUnrar(const QString &outputDir);
};

#endif
