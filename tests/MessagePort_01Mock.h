#pragma once

#include <gmock/gmock.h>

#include "../Observer/Observer.h"

class ObserverMock : public Observer
{
public:
    ObserverMock(const std::string n) : Observer(n) {}
    void subscribeMember (std::shared_ptr<Member>) override {}
    void unsubscribeMember(std::string) override {}
    void newMessage(ORDER o) const override {}
    ~ObserverMock() {}
};



