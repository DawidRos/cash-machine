#include <iostream>
#include <gtest/gtest.h>

#include "../MessagePort/MessagePort_01.h"
#include "../MessagePort/MessagePort.h"
#include "../Message/Message.h"
#include "MessagePort_01Mock.h"


struct MessagePort_01Test : public testing::Test
{
    MessagePort_01 sut;
};

TEST_F(MessagePort_01Test , when_add_new_message_then_move_them_to_the_back_of_messageList)
{
   const std::string txt ="abc";
   const Message msg(ORDER::CardIn,"zxc");
   sut.addMessage(txt,msg);
   EXPECT_EQ(sut.getLastMessage().order,ORDER::CardIn);
   std::string check = "zxc";
   EXPECT_EQ(sut.getLastMessage().message,check);
}

TEST_F(MessagePort_01Test , when_getLastMessage_from_empty_messageList_then_throw_exception)
{
    EXPECT_ANY_THROW(sut.getLastMessage());
}

TEST_F(MessagePort_01Test , when_add_few_message_then_return_vector)
{
    MessagePort_01 sut;

    sut.addMessage("123",{ORDER ::CardIn,"asd"});
    sut.addMessage("456",{ORDER ::CardIn,"fgh"});
    sut.addMessage("789",{ORDER ::CardIn,"jkl"});
    std::vector<std::pair<const std::string,Message>> vec {{"123",{ORDER ::CardIn,"asd"}},
                                                           {"456",{ORDER ::CardIn,"fgh"}},
                                                           {"789",{ORDER ::CardIn,"jkl"}}};
    EXPECT_EQ(sut.getHistory()[0].first,vec[0].first);
    EXPECT_EQ(sut.getHistory()[1].second.order,vec[2].second.order);
    EXPECT_EQ(sut.getHistory()[2].second.message,vec[2].second.message);
}

TEST_F(MessagePort_01Test , when_unsubscribeObserver_ther_is_no_observer_throw_exception)
{
    EXPECT_ANY_THROW(sut.unsubscribeObserver("asd"));
}

TEST_F(MessagePort_01Test , when_subscribeObserver_then_countObserver_rise)
{
    EXPECT_EQ(sut.countObserver(),0);
    sut.subscribeObserver(std::make_shared<ObserverMock>("a"));
    EXPECT_EQ(sut.countObserver(),1);
    sut.subscribeObserver(std::make_shared<ObserverMock>("b"));
    EXPECT_EQ(sut.countObserver(),2);
}

TEST_F(MessagePort_01Test , when_unsubscribeObserver_then_countObserver_degree)
{
    sut.subscribeObserver(std::make_shared<ObserverMock>("a"));
    sut.subscribeObserver(std::make_shared<ObserverMock>("b"));
    EXPECT_EQ(sut.countObserver(),2);
    sut.unsubscribeObserver("a");
    EXPECT_EQ(sut.countObserver(),1);
}

TEST_F(MessagePort_01Test , when_subscribe_existing_observer_then_throw)
{
    sut.subscribeObserver(std::make_shared<ObserverMock>("a"));
    EXPECT_ANY_THROW(sut.subscribeObserver(std::make_shared<ObserverMock>("a")));
}

TEST_F(MessagePort_01Test , when_unsubscribeObserver_that_no_exist_then_throw)
{
    sut.subscribeObserver(std::make_shared<ObserverMock>("z"));
    EXPECT_ANY_THROW(sut.unsubscribeObserver("a"));
}

