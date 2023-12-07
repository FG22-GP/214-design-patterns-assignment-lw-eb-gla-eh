#pragma once
#include <vector>


class MulticastDelegate
{
    
};
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void OnNotify() = 0;
    
};
template <class Test, class Parameter>
class Event
{
public:
    std::vector<Observer*> Subscribers;
};
