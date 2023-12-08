#include "RE_DelegateBase.h"

void RE_MulticastDelegateBase::Clear()
{
    //Delete all of the pointers
    while (InvocationHead)
    {
        InvocationNode* Current = InvocationHead;
        InvocationHead = Current->Next;
        delete Current->Delegate;
        delete Current;
    }
}

void RE_MulticastDelegateBase::operator+=(const RE_DelegateBase& NewDelegate)
{
    InvocationNode* Node = new InvocationNode();
    Node->Delegate = NewDelegate.Clone();
	
    if (InvocationHead == nullptr)
    {
        InvocationHead = Node;
    }
    else
    {
        InvocationNode* Current = InvocationHead;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        Current->Next = Node;
    }
}

void RE_MulticastDelegateBase::operator-=(const RE_DelegateBase& NewDelegate)
{
    InvocationNode* Current = InvocationHead;
    InvocationNode* prev = nullptr;
    while (Current != nullptr)
    {
        if (*Current->Delegate == NewDelegate)
        {
            if (Current == InvocationHead)
            {
                InvocationHead = Current->Next;
            }
            else
            {
                prev->Next = Current->Next;
            }
            delete Current->Delegate;
            delete Current;
            break;
        }
        prev = Current;
        Current = Current->Next;
    }	
}

// template <typename Param1>
// void RE_MulticastDelegate1<Param1>::BroadCast(Param1 Parameter1)
// {
//     while (Node != nullptr)
//     {
//         //TODO: check if we understood correctly part 2
//         RE_Delegate1<Param1>* Delegate = static_cast<RE_Delegate1<Param1>*>(Node->Delegate);
//         Delegate->Broadcast(Parameter1);
//         // (*delegate)(Parameter1);	// Invoke delegate callback
//         Node = Node->Next;
//     }
// }

