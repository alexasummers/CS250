#include "Airplane.hpp"


//! Move traveller onto airplane
/**
    For the traveller passed in, push it into the airplane's stack.

    @param <Traveller*> traveller
    @return <void>
*/
void Airplane::Board(Traveller* traveller)
{
    m_passengers.Push(traveller);
}

//! Pull traveller off airplane
/**
    Get the next (top-most) traveller from the airplane stack,
    remove them from the stack and return the traveller.

    @return <Traveller*>
*/
Traveller* Airplane::Disembark()
{
    cout << "There are " << m_passengers.Size() << " passengers" << endl;
    // m_passengers (Stack<Traveller*>)
Traveller* traveller = m_passengers.Top();
m_passengers.Pop();

    cout << "There are " << m_passengers.Size() << " now" << endl;

return traveller;
}

//! Return whether the airplane is empty (no passengers)
/**
    If the size of the stack is 0, then the airplane is empty.

    @return <bool>
*/
bool Airplane::IsEmpty()
{
    cout << "Passenger size: " << m_passengers.Size() << endl;
    if (m_passengers.Size() == 0)
    {
        cout << "The airplane is empty." << endl;
        return true;
    }
    else
    {
        return false;

    }
}

