#include "MessagePort_01.h"
#include <exception>

void MessagePort_01::newMessage(const Message& msg) const
{
    for(const auto& x : observerAddressList)
        x.second->newMessage(msg.order);
}

MessagePort_01::~MessagePort_01()
{
    for (auto& x : observerAddressList)
    {
        x.second->addWatched(nullptr);
    }
}

void MessagePort_01::addMessage(const std::string sender, const Message msg)
{
    messageList.push_back(std::make_pair<const std::string, const Message>(std::move(sender),std::move(msg)));
    newMessage(getLastMessage());
}

const Message& MessagePort_01::getLastMessage() const
{
    if(messageList.empty())
        throw std::exception();
    return messageList.back().second;
}

message_list MessagePort_01::getHistory() const
{
    return messageList;
}

void MessagePort_01::subscribeObserver(std::shared_ptr<Observer> obs)
{
    if (observerAddressList.insert(std::pair<const std::string,std::shared_ptr<Observer>>(obs->getName(),obs)).second == false)
        throw std::exception();
    obs->addWatched(this);
}

void MessagePort_01::unsubscribeObserver (const std::string name)
{
    auto pt = observerAddressList.find(name);
    if (pt == observerAddressList.end())
        throw std::exception();
    //pt->second->addWatched(nullptr);
    observerAddressList.erase(name);
}

unsigned MessagePort_01::countObserver() const
{
    return observerAddressList.size();
}