//Alexa Summers- Lab #1 part 2

#include <iostream>
#include <list>
#include <string>
using namespace std;

void AddCourses( list <string>& courses)
{
    courses.push_back( "cs 250" );
    courses.push_back( "cs 200" );
    courses.push_back( "cs 210" );
    courses.push_back( "cs 235" );
    courses.push_back( "cs 134" );
    courses.push_back( "cs 211" );

}

void SortList ( list <string>& courses)
{
    courses.sort();
}


void ReverseList ( list <string>& courses)
{
    courses.reverse();
}

void DisplayCourses ( list <string>& courses)
{
    int counter = 0;
//This is how we iterate through a list
    for(list<string>::iterator it = courses.begin();
            it != courses.end(); it++ )
    {
        if (counter != 0)
        {
            cout << " , ";
        }
        cout << counter++ << " . " << (*it);
    }
}

int main()
{

    cout << "Normal order: " << endl;
    list<string> courses;
    AddCourses(courses);
    DisplayCourses(courses);
    cout << endl;
    cout << endl;

    cout << "Sorted order: " << endl;
    SortList(courses);
    DisplayCourses(courses);
    cout << endl;
    cout << endl;

    cout << "Reverse order: " << endl;
    ReverseList(courses);
    DisplayCourses(courses);
    cout << endl;
    cout << endl;
    return 0;

}
