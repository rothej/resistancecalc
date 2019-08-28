/*******************************************************************
*** Resistance Calculator                           Joshua Rothe ***
********************************************************************
*** Filename: resistance_calc.cpp                                ***
*** --- Rev: 1.0.0 - Initial release                             ***
********************************************************************
*** This module calcualates total resistance of a number of      ***
*** resistors in series or parallel.                             ***
********************************************************************/

#include<iostream>	// allows cout and cin
#include<iomanip>
using namespace std;

int main()
{
	double A[100];    
	int r,n,x=0; 
	double Rin, sum=0;	
	cout<< "Select 1 for series or 2 for parallel." <<endl; 
	cin>>r;	
	cout<< "Please enter number of resistors, 1 thru 3" <<endl; 
	cin>>n;			
	if(r==1)	// series	
	{
		for(x=0;x<n;x++)	
		{
			cout<<"Please enter Rin"<<endl; 
			cin>>A[x];		
			sum = sum + A[x];	// enter number of resistors in series, added up
		}
	}
	else		// parallel  
	{
		for(x=0;x<n;x++)  
		{
			cout<<"Please enter Rin"<<endl;
			cin>>A[x];  
			if(A[x]!=0)  
			{
				sum = (sum*A[x])/(A[x]+sum);  // enter resistors in parallel, computed
			}
		}
	}
	if(sum<1000)	// displays as Ohm
	{			
		cout<<"Total resistance = "<<fixed<< int(sum)<<" Ohm."<<endl;
		cout<<"R1= "<<int (A[0])<<" R2= "<<int(A[1])<<" R3= "<<int(A[2])<<endl<<endl;
	}
	else			// displys as KOhm and a decimal
	{			
		sum= sum/1000;
		cout<<"R1= "<<A[0]<<" R2= "<<A[1]<<" R3= "<<A[2]<<endl<<endl;
		cout<<"Total resistance = "<<sum<<fixed<<showpoint<<setprecision(3)<<" KOhm."<<endl;
	}
	system ("pause");
}
