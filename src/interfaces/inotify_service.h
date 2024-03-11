#ifndef INOTIFY_SERVICE_H
#define INOTIFY_SERVICE_H

class INotifyService {
    public:
        virtual void showSystemMessage(QString, QString) = 0;
};

#endif // INOTIFY_SERVICE_H