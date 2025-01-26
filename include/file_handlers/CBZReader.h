#ifndef CBZREADER_H
#define CBZREADER_H

#include "Reader.h"

class CBZReader : public Reader
{
public:
    explicit CBZReader(const QString &filePath);
    QStringList extractImages() override;
};

#endif
