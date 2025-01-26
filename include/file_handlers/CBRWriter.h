#ifndef CBRWRITER_H
#define CBRWRITER_H

#include "Writer.h"

class CBRWriter : public Writer
{
public:
    explicit CBRWriter(const QString &outputFile);
    bool createFromImages(const QStringList &images) override;
};

#endif
