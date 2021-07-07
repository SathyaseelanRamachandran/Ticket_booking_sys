
/**
Name:Sathyaseelan s/o Ramachandran
Student ID: P16007762
Question1
**/

//standard library that allows cin from user(keyboard)
#include <stdio.h>
#include <iostream>

using namespace std;

char seats[10][10];     //seats in the cinema hall. 'A' if available, 'B' if booked, 'C' if checked in
int book_id[10][10];

int id=0;       //total number of bookings so far
int total_b=0;    //total number of seats booked so far
int total_c=0;      //total number of check ins so far
int total_seats_checkin = 0;    //total number of seats checked in so far

void display()
{
    for(int i=1;i<=10;i++)//for loop the defines the row
        cout<<i<<"\t";
    
    for(int i=0;i<10;i++)//for loop column
    {
        cout<<"\nRow "<<i+1<<"\t";
        for(int j=0;j<10;j++)
        {
            if(seats[i][j]=='A')
                cout<<"_\t";
            else 
                cout<<"X\t";
        }
    }    
}

void book()
{
    cout<<"\nSelect the seats you wish to book.\nYou can book a maximum of ten seats in one booking.";
    display();
    char ch;
    
    ++id;
    
    int count,row,col;
    do{
        cout<<"\nEnter seat number :";
        cout<<"\nEnter row: ";
        cin>>row;
        cout<<"\nEnter column : ";
        cin>>col;
        
        if((row<1)||(row>10)||(col<1)||(col>10))
        {
            cout<<"\nInvalid seat! Enter again";
            continue;
        }
        
        if(seats[row-1][col-1]!='A')
        {
            cout<<"\nSeat already taken. Try another seat";
            continue;
        }
        
        ++count;
        seats[row-1][col-1] = 'B';
        book_id[row-1][col-1] = id;
        
        cout<<"Would you like to book another seat ? (y or n): ";
        cin>>ch;
        
    }while((ch=='y')&&(count<=10));
    
    cout<<"\nCongrats! You have made a booking of "<<count<<" seats.\n";
    total_b+=count;
}

void summary()
{
    cout<<"\nTotal number of seats booked so far = "<<total_b;
    cout<<"\nNumber of seats remaining = "<<100-total_b;
    cout<<"\nTotal number of checkins so far = "<<total_c;
    cout<<"\nTotal number of seats checked in so far = "<<total_seats_checkin;
}

void checkin()
{
    int a;
    cout<<"\nEnter your booking id to checkin:\t";    
    cin>>a;
    if(a>id)
    {
        cout<<"\nInvalid id";
        return;
    }
    cout<<"\nYou have checked in.";
    total_c++;
    
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(book_id[i][j]==a)
            {
                seats[i][j]='C';
                total_seats_checkin++;
            }
}

void booking_status()
{
    int a;
    cout<<"\nEnter your booking id to checkin:\t";    
    cin>>a;
    if(a>id)
    {
        cout<<"\nInvalid id";
        return;
    }
    
    cout<<"\nSeats you have booked: \n";
    
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(book_id[i][j]==a)
            {
                cout<<"\nRow "<<i+1<<", seat "<<j+1;
                if(seats[i][j]=='B')
                    cout<<"Booked";
                else
                    cout<<"Checked in";
            }
}

int main()
{
    struct booking* ptr = NULL;
       
    //All seats are initially empty
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            seats[i][j]='A';
            
    int choice;
    
    do{
        cout<<"\nSelect an option: ";
        cout<<"\n1. Make a booking";
        cout<<"\n2. View summary of bookings";
        cout<<"\n3. Checkin";
        cout<<"\n4. View your booking status";
        cout<<"\n5. Exit";
        cin>>choice;
        
        switch(choice)
        {
            case 1: book(); break;
            case 2: summary(); break;
            case 3: checkin(); break;
            case 4: booking_status(); break;
            case 5: break;
            default: break;
        }
        
    }while((1<=choice)&&(choice<=4));
    
    cout<<"\********************Ticket Booking System***********************";
    cout<<endl;

    return 0;
}

Copyright at Sathyaseelanramachandran@2020_OSD
