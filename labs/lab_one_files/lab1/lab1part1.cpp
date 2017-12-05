//Alexa Summers- Lab #1

#include <iostream> //required for cout
#include <vector> //required for vector
#include <string> //required for string
using namespace std;

void AddIngredients (vector<string>& ingredients )
{
    ingredients.push_back( "lettuce" );
    ingredients.push_back( "tomato" );
    ingredients.push_back( "mayo" );
    ingredients.push_back( "bread" );
}

void DisplayIngredients (const vector<string>& ingredients )
{
    for (int counter = 0; counter < 4; counter++)
    {
        cout << counter << "." << ingredients[counter] << endl;
    }

}

int main()
{
    vector<string> ingredients;
    AddIngredients(ingredients);
    DisplayIngredients(ingredients);
    return 0;
}
