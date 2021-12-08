#ifndef COVERTER_HPP
#define COVERTER_HPP

#include <QBuffer>
#include <QPixmap>

QByteArray pixmap2b64(const QPixmap &pixmap) {
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    return buffer.data().toBase64();
}

#endif// COVERTER_HPP