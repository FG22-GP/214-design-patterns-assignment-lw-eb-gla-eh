#pragma once

class RE_DelegateBase
{
public:
    virtual ~RE_DelegateBase() {}

    virtual bool operator==(const RE_DelegateBase& OtherDelegate) const = 0;
    virtual bool operator!=(const RE_DelegateBase& OtherDelegate) { return !(*this == OtherDelegate); }
    virtual RE_DelegateBase* Clone() const = 0;
};

template <class Param1, class RetType=void>
class RE_Delegate1 : public RE_DelegateBase {
public:
    //TODO: check if we understood correctly part 1
    //virtual RetType operator()(Param1 p1) = 0;
    virtual RetType Broadcast(Param1 p1) = 0;
    virtual RE_Delegate1* Clone() const = 0;
};

template <class TClass, class Param1, class RetType=void> 
class RE_DelegateMember1 : public RE_Delegate1<Param1, RetType>
{
public:
    typedef TClass* ObjectPtr;
    typedef RetType (TClass::*Function)(Param1); 
    typedef RetType (TClass::*ConstFunction)(Param1) const; 

    RE_DelegateMember1() :	ObjectClassPtr(nullptr), FunctionPtr(nullptr) {}
    RE_DelegateMember1(ObjectPtr Object, Function Func) { Bind(Object, Func); }
    RE_DelegateMember1(ObjectPtr Object, ConstFunction Func) { Bind(Object, Func);}

    /// Bind a member function to a delegate. 
    void Bind(ObjectPtr object, Function func)
    {
        ObjectClassPtr = object;
        FunctionPtr = func;
    }

    /// Bind a const member function to a delegate. 
    void Bind(ObjectPtr Object, ConstFunction Func)
    {
        ObjectClassPtr = Object;
        FunctionPtr = reinterpret_cast<Function>(Func);
    }
    
    virtual RE_DelegateMember1* Clone() const { return new RE_DelegateMember1(*this); }
    virtual RetType Broadcast(Param1 Param) { return (*ObjectClassPtr.*FunctionPtr)(Param); }

    virtual bool operator==(const RE_DelegateBase& OtherDelegate) const
    {
        const RE_DelegateMember1<TClass, Param1, RetType>* DerivedDelegate = dynamic_cast<const RE_DelegateMember1<TClass, Param1, RetType>*>(&OtherDelegate);
        return DerivedDelegate &&
            FunctionPtr == DerivedDelegate->FunctionPtr && 
            ObjectClassPtr == DerivedDelegate->ObjectClassPtr;
    }
    bool Empty() const { return !(ObjectClassPtr && FunctionPtr); }
    void Clear() { ObjectClassPtr = nullptr; FunctionPtr = nullptr; }

    explicit operator bool() const { return !Empty();}
private:
    ObjectPtr ObjectClassPtr;		// Pointer to a class object
    Function FunctionPtr;   	// Pointer to an instance member function
};


class RE_MulticastDelegateBase
{
public:
    RE_MulticastDelegateBase() : InvocationHead(nullptr){}
    virtual ~RE_MulticastDelegateBase() { Clear(); }

    bool Empty() const { return InvocationHead != nullptr; }

    void Clear();
protected:
    
    struct InvocationNode
    {
        InvocationNode() : Next(nullptr), Delegate(nullptr) { }
        InvocationNode* Next;
        RE_DelegateBase* Delegate;
    };
    
    InvocationNode* GetInvocationHead() const { return InvocationHead; }
    void operator+=(const RE_DelegateBase& NewDelegate);
    void operator-=(const RE_DelegateBase& NewDelegate);
    
    explicit operator bool() const { return !Empty();  }

private:
    InvocationNode* InvocationHead;
};


template<typename Param1>
class RE_MulticastDelegate1 : public RE_MulticastDelegateBase
{
public:
    RE_MulticastDelegate1(){}
    
    void BroadCast(Param1 Parameter1);

    InvocationNode* Node = GetInvocationHead();
    void operator+=(const RE_Delegate1<Param1>& Delegate) { RE_MulticastDelegateBase::operator+=(Delegate); }
    void operator-=(const RE_Delegate1<Param1>& delegate) { RE_MulticastDelegateBase::operator-=(delegate); }

private:
    RE_MulticastDelegate1(const RE_MulticastDelegate1&);
    RE_MulticastDelegate1& operator=(const RE_MulticastDelegate1&);
};

template <typename Param1>
void RE_MulticastDelegate1<Param1>::BroadCast(Param1 Parameter1)
{
    Node = GetInvocationHead();
    while (Node != nullptr)
    {
        RE_Delegate1<Param1>* Delegate = static_cast<RE_Delegate1<Param1>*>(Node->Delegate);
        Delegate->Broadcast(Parameter1);
        Node = Node->Next;
    }
}
