#include <iostream>
#include <memory>
#include <vector>

// Abstract interface representing a general Notification.
// This interface is open for extension: new notification types can be added by implementing this interface,
// while the code relying on Notification (e.g., notifyAll function) does not need to change.
class Notification
{
public:
    virtual void send(const std::string &message) const = 0;
    virtual ~Notification() = default;
};

// Concrete implementation of Notification for sending email notifications.
// New notification types can be added as additional classes implementing Notification.
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

// The notifyAll function is closed for modification but open for extension.
// It works with the abstract Notification interface, so if you add new notification types,
// you do not need to modify this function.
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

    // The notifyAll function uses polymorphism to call the appropriate send() method.
    // There is no need to modify notifyAll if a new notification type is added.
    notifyAll(notifications, "You have a new notification!");

    return 0;
}