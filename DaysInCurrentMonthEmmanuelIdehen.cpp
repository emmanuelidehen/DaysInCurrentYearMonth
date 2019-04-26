//
//  main.cpp
//  Array+pointer
//
//  Created by Emmanuel Idehen on 3/2/19.
//  Copyright © 2019 Emmanuel Idehen. All rights reserved.
//  Submoitted to Mr. Marcus Golden (Computer Programming II)
/*
 Write a program that can determine the number of days in a month for a specified month
 and year. The program should allow a user to enter two integers representing a month and
 a year, and it should determine how many days are in the specified month . The integers 1
 through 12 will be used to identify the months of January through December. The user
 indicates the end of input by entering O O for the month and year. At that point, the
 program prints the number of days in the current month and terminates.
 Use the following criteria to identify leap years:
 1. A year Y is divisible by 100. Then Y is a leap year if and only if it is divisible by
 400. For example, 2000 is a leap year but 2100 is not .
 2. A year Y is not divisible by 100. Then Y is a leap year if and only if it is divisible
 by 4. For example, 2008 is a leap year but 2009 is not .
 Here is sample run of the program:
 Enter mont h and year: 2 2008[Enter]
 29 days
 Enter mont h and year: 0 O[Enter]
 The current month, September 2009, has 30 days.
 
 
 */
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
int getDays(int,int);
int main()
{
    
    //decalre varaible 
    bool flag = false;
    int month,year,days(0);
    
    time_t rawtime;
    struct tm* timeinfo;
    
    
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    //use a string array to hold the data
    string months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    //take month and year
    
    cout<<"Enter the  month and year together(Enter 0 0 to return the current year!): ";
    cin>>month;
    cin>>year;
    
    //loop while not flag
    while(!flag)
    {
        //check month and year
        if( month==0 && year==0 )
        {
            flag = true;
            year=timeinfo->tm_year + 1900;
            days=getDays(timeinfo->tm_mon+1,year);
            
            cout<< "The current month, " << months[timeinfo->tm_mon] <<" "<<year<<" has ";
        }
        
        //validate input
        else if(month<1||month>12)
            cout<<"you have entered an invalid date\n";
        
        else
            days=getDays(month,year);
        
        cout<<days<<" days\n";
        
        
        //check flag
        if(!flag)
        {
            
            cout<<"Enter month and year(0 0 to terminate): ";
            cin>>month;
            cin>>year;
            
        }
    }
    
    
    
    return 0;
    
    
    
}
//return data to user

int getDays(int month,int year)
{
    int days;
    switch(month)//switch if month is case 4, 6,9 11, print 30 days else 31 else if years
    {            //modulus 4 == 0 then leap year
        case 4:
            days=30;
            break;
        case 6:
            days=30;
            break;
        case 9:
            
            days=30;
            break;
        case 11:
            days=30;
            break;
            
        case 2:
            days=28;
            if(year%4==0)
                
                if(year%100==0)
                    
                {
                    if(year%400==0)
                        days++;
                    
                }
                else
                    days++;
            break;
        default: days=31;
    }
    return days;
}
