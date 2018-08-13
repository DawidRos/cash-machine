#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../Message/Message.h"
#include "../Observer/Observer.h"

using sender_message = std::pair<const std::string, const Message>;
using message_list = std::vector<sender_message>;

class MessagePort
{
public:
    MessagePort() = default;
    virtual ~MessagePort() = default;
    virtual void addMessage(const std::string sender, const Message msg) = 0;
    virtual const Message& getLastMessage() const = 0;
    virtual  message_list getHistory() const = 0;
    virtual void subscribeObserver(std::shared_ptr<Observer> obs) = 0;
    virtual void unsubscribeObserver (const std::string name) = 0;
    virtual unsigned countObserver() const = 0;
private:
    virtual void newMessage(const Message& msg) const = 0;

};

//MessagePort::MessagePort() {}