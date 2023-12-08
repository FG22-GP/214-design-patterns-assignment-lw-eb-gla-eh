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
    typedef RetType (TClass::*MemberFunc)(Param1); 
    typedef RetType (TClass::*ConstMemberFunc)(Param1) const; 

    RE_DelegateMember1(ObjectPtr object, MemberFunc func) { Bind(object, func); }
    RE_DelegateMember1(ObjectPtr object, ConstMemberFunc func) { Bind(object, func);	}
    RE_DelegateMember1() :	m_object(nullptr), m_func(nullptr) { }
    

    /// Bind a member function to a delegate. 
    void Bind(ObjectPtr object, MemberFunc func) {
        m_object = object;
        m_func = func; }

    /// Bind a const member function to a delegate. 
    void Bind(ObjectPtr object, ConstMemberFunc func)	{
        m_object = object;
        m_func = reinterpret_cast<MemberFunc>(func); }
    
    //virtual RE_DelegateMember1* Clone() const { return new RE_DelegateMember1(*this); }
    virtual RE_DelegateMember1* Clone() const
    {
        //RE_DelegateMember1* ptr2 = new RE_DelegateMember1(*this);
        return new RE_DelegateMember1(*this);
    }

    // Invoke the bound delegate function
    
    virtual RetType Broadcast(Param1 p1) {
        return (*m_object.*m_func)(p1); }

    virtual bool operator==(const RE_DelegateBase& rhs) const 	{
        const RE_DelegateMember1<TClass, Param1, RetType>* derivedRhs = dynamic_cast<const RE_DelegateMember1<TClass, Param1, RetType>*>(&rhs);
        return derivedRhs &&
            m_func == derivedRhs->m_func && 
            m_object == derivedRhs->m_object; }

    bool Empty() const { return !(m_object && m_func); }
    void Clear() { m_object = nullptr; m_func = nullptr; }

    explicit operator bool() const { return !Empty();  }

private:
    ObjectPtr m_object;		// Pointer to a class object
    MemberFunc m_func;   	// Pointer to an instance member function
};



class RE_MulticastDelegateBase
{
public:
    RE_MulticastDelegateBase() : InvocationHead(nullptr){}
    
    /// Destructor
    virtual ~RE_MulticastDelegateBase() { Clear(); }

    /// Any registered delegates?
    bool Empty() const { return InvocationHead != nullptr; }

    /// Removal all registered delegates.
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
    RE_MulticastDelegate1()
    {
    }
    
    void BroadCast(Param1 Parameter1);

    InvocationNode* Node = GetInvocationHead();

    void operator+=(const RE_Delegate1<Param1>& Delegate) { RE_MulticastDelegateBase::operator+=(Delegate); }
    void operator-=(const RE_Delegate1<Param1>& delegate) { RE_MulticastDelegateBase::operator-=(delegate); }

private:
    // Prevent copying objects
    RE_MulticastDelegate1(const RE_MulticastDelegate1&);
    RE_MulticastDelegate1& operator=(const RE_MulticastDelegate1&);
};

template <typename Param1>
void RE_MulticastDelegate1<Param1>::BroadCast(Param1 Parameter1)
{
    Node = GetInvocationHead();
    while (Node != nullptr)
    {
        //TODO: check if we understood correctly part 2
        RE_Delegate1<Param1>* Delegate = static_cast<RE_Delegate1<Param1>*>(Node->Delegate);
        Delegate->Broadcast(Parameter1);
        // (*delegate)(Parameter1);	// Invoke delegate callback
        Node = Node->Next;
    }
}
