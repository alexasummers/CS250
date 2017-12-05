#include "project1_LinkedList.hpp"

Node::Node()
{
//    int nullptr = NULL;
//    struct node *next = nullptr;
//    struct node *prev = nullptr;

    m_ptrNext = nullptr;
    m_ptrPrev = nullptr;
//    Node* m_ptrNext;
//    Node* m_ptrPrev;
//    throw runtime_error( "Node() not yet implemented" );


}

LinkedList::LinkedList()
{
    m_ptrFirst = nullptr;
    m_ptrLast = nullptr;
    m_itemCount = 0;
}

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Clear()
{
   while (!IsEmpty())
     {
    PopFront();
    //PopBack();
    }
}

void LinkedList::PushFront( CustomerData newData )
{
    Node* newNode = new Node;
    newNode->m_data = newData;
    m_itemCount++;

    if (m_ptrFirst == nullptr && m_ptrLast == nullptr)
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
    }
    else
    {
        m_ptrFirst->m_ptrPrev = newNode;
        newNode->m_ptrNext = m_ptrFirst;
        m_ptrFirst = newNode;
    }
}

void LinkedList::PushBack( CustomerData newData )
{
    Node* newNode = new Node;
    newNode->m_data = newData;
    m_itemCount++;

    if (m_ptrFirst == nullptr && m_ptrLast == nullptr)
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
    }
    else
    {
        m_ptrLast->m_ptrNext = newNode;
        newNode->m_ptrPrev = m_ptrLast;
        m_ptrLast = newNode;
    }
}

void LinkedList::PopFront() noexcept
{
    if (m_ptrFirst == m_ptrLast)
    {
        delete m_ptrFirst;
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount--;
    }
    else
    {
        Node *ptrSecond = m_ptrFirst-> m_ptrNext;
        ptrSecond->m_ptrPrev = nullptr;
        delete m_ptrFirst;
        m_ptrFirst = ptrSecond;
        m_itemCount--;
    }

}

void LinkedList::PopBack() noexcept
{
    if (m_ptrFirst == m_ptrLast)
    {
        delete m_ptrLast;
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount--;
    }
    else
    {
        Node *ptrSecond = m_ptrLast-> m_ptrPrev;
        ptrSecond->m_ptrNext = nullptr;
        delete m_ptrLast;
        m_ptrLast = ptrSecond;
        m_itemCount--;
    }
}

CustomerData LinkedList::GetFront()
{
    if (m_ptrFirst == nullptr || m_ptrLast == nullptr)
    {
        throw out_of_range ("Out of range.");
    }
    return m_ptrFirst->m_data;

}

CustomerData LinkedList::GetBack()
{
    if (m_ptrFirst == nullptr || m_ptrLast == nullptr)
    {
        throw out_of_range ("Out of range.");
    }
    return m_ptrLast->m_data;
}

CustomerData& LinkedList::operator[]( const int index )
{

    int counter =0;
    Node * ptrCurrent = m_ptrFirst;
    if (index < 0 || index >= Size())
    {
        throw logic_error ("Index is invalid.");
    }

    while (counter != index)
    {
        ptrCurrent = ptrCurrent-> m_ptrNext;
        counter++;
    }
        return ptrCurrent->m_data;
}

bool LinkedList::IsEmpty()
{
    if (m_itemCount == 0)
        return true;
    else
        return false;
}

int LinkedList::Size()
{
    return m_itemCount;
}

