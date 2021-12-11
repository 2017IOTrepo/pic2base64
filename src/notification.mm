//
// Created by xmmmmmovo on 2021/12/11.
//

#include "notification.hpp"
#include <Foundation/Foundation.h>

#ifdef Q_OS_MAC

void postNotification(QString title, QString message) {
    NSUserNotification *notification = [[NSUserNotification alloc] init];
    notification.title               = title.toNSString();
    notification.informativeText     = message.toNSString();
    notification.soundName =
            NSUserNotificationDefaultSoundName;//Will play a default sound
    [[NSUserNotificationCenter defaultUserNotificationCenter]
            deliverNotification:notification];
    [notification autorelease];
}

#endif//Q_OS_MAC