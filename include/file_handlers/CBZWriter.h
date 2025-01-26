#ifndef CBZWRITER_H
#define CBZWRITER_H

#include "Writer.h"

class CBZWriter : public Writer
{
public:
    explicit CBZWriter(const QString &outputFile);
    bool createFromImages(const QStringList &images) override;
};

#endif // CBZWRITER_H
