#pragma once

#include "../Member/Member.h"

class Observer
{
private:
    const::std::string name;
    std::vector<Message_Port> looking_at_list;
public:
    Observer(std::string n) : name(n) {}
    virtual ~Observer() {}

    virtual void subscribeMember(std::shared_ptr<Member>) = 0;
    virtual void unsubscribeMember(std::string) = 0;
    virtual void newMessage(ORDER) const = 0;
    const std::string getName() const { return name; }

};