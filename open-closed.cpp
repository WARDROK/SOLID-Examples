#include <iostream>
#include <memory>
#include <vector>

class Notification
{
public:
    virtual void send(const std::string &message) const = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification
{
public:
    void send(const std::string &message) const override
    {
        std::cout << "Sending email: " << message << std::endl;
    }
};

class SMSNotification : public Notification
{
public:
    void send(const std::string &message) const override
    {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

class PushNotification : public Notification
{
public:
    void send(const std::string &message) const override
    {
        std::cout << "Sending push notification: " << message << std::endl;
    }
};

void notifyAll(const std::vector<std::unique_ptr<Notification>> &notifications, const std::string &message)
{
    for (const auto &notification : notifications)
    {
        notification->send(message);
    }
}

int main()
{
    std::vector<std::unique_ptr<Notification>> notifications;
    notifications.push_back(std::make_unique<EmailNotification>());
    notifications.push_back(std::make_unique<SMSNotification>());
    notifications.push_back(std::make_unique<PushNotification>());

    notifyAll(notifications, "You have a new notification!");

    return 0;
}