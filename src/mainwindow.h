#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason);
    void handleClipboardAction();

private:
    QSystemTrayIcon *trayIcon;
    QMenu           *menu;
    QMenu           *createMenu();
};
#endif// MAINWINDOW_H
