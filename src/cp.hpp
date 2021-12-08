#ifndef CP_HPP
#define CP_HPP

#include <QClipboard>
#include <QMessageBox>
#include <QMimeData>
#include <QPixmap>
#include <tuple>

std::tuple<QPixmap, int> readImageFromClipboard(QWidget          *ctx,
                                                const QClipboard *clipboard) {
    if (clipboard->pixmap().isNull()) {
        return std::make_tuple(clipboard->pixmap(), 1);
    }
    return std::make_tuple(clipboard->pixmap(), 0);
}

int write2Clipboard(QClipboard *clipboard, const QString &content,
                    const QString &type) {
    QString res = "";
    res += "data:image/" + type + ";base64," + content;
    clipboard->setText(res);
    return 0;
}

#endif// CP_HPP
