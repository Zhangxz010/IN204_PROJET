#ifndef PDFREADER_H
#define PDFREADER_H

#include "Reader.h"

class PDFReader : public Reader
{
public:
    explicit PDFReader(const QString &filePath);
    QStringList extractImages() override;

private:
    QString prepareOutputDirectory();
};

#endif
