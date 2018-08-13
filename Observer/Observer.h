#pragma once

#include "../Member/Member.h"
#include "../MessagePort/MessagePort.h"

class MessagePort;

class Observer
{
private:
    const::std::string name;
    MessagePort* watched { nullptr };
public:
    Observer(std::string n) : name(n) {}
    virtual ~Observer()
    {
        if(watched != nullptr) {}
 //          watched->unsubscribeObserver(name);
    }

    virtual void addWatched(MessagePort* ptr) { watched = ptr; }
    virtual void subscribeMember(std::shared_ptr<Member>) = 0;
    virtual void unsubscribeMember(std::string) = 0;
    virtual void newMessage(ORDER) const = 0;
    const std::string getName() const { return name; }
};
