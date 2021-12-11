#include <QCoreApplication>
#include <QDebug>
#include <QGuiApplication>

#include "coverter.hpp"
#include "cp.hpp"
#include "mainwindow.h"
#include "notification.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), trayIcon(new QSystemTrayIcon(this)) {
    auto menu = this->createMenu();
    this->trayIcon->setContextMenu(menu);

    auto appIcon = QIcon(":/assets/icon.png");
    this->trayIcon->setIcon(appIcon);

    this->trayIcon->show();
    connect(trayIcon, &QSystemTrayIcon::activated, this,
            &MainWindow::iconActivated);
}

void MainWindow::handleClipboardAction() {
    auto [img, status] =
            readImageFromClipboard(this, QGuiApplication::clipboard());
    if (status != 0) {
        QMessageBox::information(this, tr("提示"), tr("剪贴板内没有图片！"));
    } else {
        auto b64 = pixmap2b64(img);
        write2Clipboard(QGuiApplication::clipboard(), b64, "png");
        QMessageBox::information(this, tr("提示"),
                                 tr("已成功将base64写入剪贴板！"));
    }
}

QMenu *MainWindow::createMenu() {
    auto menu = new QMenu(this);

    auto clipboardAction = new QAction("从剪贴板转换", this);
    connect(clipboardAction, &QAction::triggered, this,
            &MainWindow::handleClipboardAction);
    menu->addAction(clipboardAction);

    menu->addSeparator();

    auto quitAction = new QAction("退出程序", this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    menu->addAction(quitAction);

    return menu;
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason_) {
    //    switch (reason_) {
    //        case QSystemTrayIcon::Trigger:
    //            this->trayIcon->showMessage("右键", "右键");
    //            break;
    //        default:;
    //    }
}
