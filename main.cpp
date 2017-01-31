#include <libnotify/notify.h>
#include <libnotify/notification.h>
#include <QCoreApplication>
#include <QtCore/QDebug>
#include <QUuid>

void NotificationClosedCallback(NotifyNotification* notification,
                                gpointer user_data)
{
    qDebug() << "closed";
}

void NotificationClickedCallback(NotifyNotification* notification,
                                 gpointer user_data) {
    qDebug() << "clicked";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "starting";

    QString my_name("AppName2");
    char * app_name = my_name.toLatin1().data();

    notify_init(app_name);
    NotifyNotification* notification_;
    notification_ = notify_notification_new(
                QUuid::createUuid().toString().toUtf8().data(),
                "A content",
                nullptr);

    notify_notification_clear_actions(notification_);
    g_signal_connect(
                notification_, "closed", G_CALLBACK(NotificationClosedCallback), nullptr);

    notify_notification_add_action(
                notification_, "action_name22223", "Seeme2", (NotifyActionCallback)NotificationClickedCallback, nullptr,
                nullptr);

    GError* error = nullptr;
    notify_notification_show(notification_, nullptr);

    return a.exec();
}
