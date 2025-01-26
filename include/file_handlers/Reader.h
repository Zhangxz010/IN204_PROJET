#ifndef READER_H
#define READER_H

#include <QString>
#include <QStringList>

class Reader
{
public:
    explicit Reader(const QString &filePath) : m_filePath(filePath) {}
    virtual ~Reader() = default;

    virtual QStringList extractImages() = 0;

protected:
    QString m_filePath;
};

#endif
