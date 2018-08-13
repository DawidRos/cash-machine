#pragma once

#include <map>

#include "MessagePort.h"


class MessagePort_01 : public MessagePort
{
private:
    std::vector<std::pair<const std::string, const Message>> messageList;
    std::map<const std::string,std::shared_ptr<Observer>> observerAddressList;
    void newMessage(const Message& msg) const override;
public:
    MessagePort_01() {}
    MessagePort_01(const MessagePort_01& ) = delete;
    MessagePort_01(MessagePort_01&& ) = delete;
    MessagePort_01 operator=(const MessagePort_01& ) = delete;
    ~MessagePort_01();

    void addMessage(const std::string sender, const Message msg) override;
    const Message& getLastMessage() const override;
    message_list getHistory() const override;
    void subscribeObserver(std::shared_ptr<Observer> obs) override;
    void unsubscribeObserver(const std::string name) override;
    unsigned countObserver() const override;
};