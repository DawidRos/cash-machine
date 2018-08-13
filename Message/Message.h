#pragma once

#include <string>

enum class ORDER
{
    CardIn,
    CardOut
};

struct Message
{
    ORDER order;
    std::string message;
    Message(ORDER o , std::string msg) : order(o) , message(msg) {}
};