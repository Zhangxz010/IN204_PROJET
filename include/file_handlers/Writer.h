#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include <QStringList>

class Writer
{
public:
    explicit Writer(const QString &outputFile);
    virtual ~Writer() = default;

    virtual bool createFromImages(const QStringList &images) = 0;

protected:
    QString prepareOutputFile(const QString &outputFile, const QString &subDir);
    QString m_outputFile;
};

#endif
