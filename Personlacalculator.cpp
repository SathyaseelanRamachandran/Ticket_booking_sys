



/**
Name:Sathyaseelan s/o Ramachandran
Student ID: P16007762
Question1
**/

//standard library that allows cin from user(keyboard)
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float a,i=0,e=0;
    
    //Accept the incomes
    
    cout<<"\nEnter salary: \t";
    cin>>a;
    i+=a;
    
    cout<<"\nEnter rent: \t";
    cin>>a;
    i+=a;
    
    cout<<"\nEnter bonus: \t";
    cin>>a;
    i+=a;
    
    //Display total income
    cout<<"\nTotal income = "<<i<<"\n";
    
    //Accept the expenses
    cout<<"\nEnter household spending: \t";
    cin>>a;
    e+=a;
    
    cout<<"\nEnter loans: \t";
    cin>>a;
    e+=a;
    
    cout<<"\nEnter entertainment: \t";
    cin>>a;
    e+=a;
    
    //Display total expense
    cout<<"\nTotal expense = "<<e<<"\n";
    
    
    //Display appropriate message
    if(i>e)
        cout<<"\nCongratulation, you have remaining of "<<i-e<<" this month. You can save "<<i-e<<" according to the x% you set.\n";
    else if(i<e)
        cout<<"\nyou have overspent for this month and no saving could be made";
    else
        cout<<"\nincome = expense, no savings!";
    
    return 0;
}

