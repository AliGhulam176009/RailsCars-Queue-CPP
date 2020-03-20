// RailRoadQueue.cpp : Defines the entry point for the console application.
#include <iostream>
#include <queue>
using namespace std;
 

 template <class T>
void display(T arr[], int no)
{
	cout<<"pattren: ";
    for(int i = 0; i < no; i++)
    {
        cout<<arr[i] << ",";
    }
    cout << "\n"<<endl;
}


bool Hold(queue<int> Queue[], int no, int totalholding)
{
    for(int i=0; i<totalholding; i++)
    {
        if(Queue[i].empty() or (!Queue[i].empty() and Queue[i].back() < no))
        {
            cout<<"H "<<i<<" hold car "<< no<< endl;
            Queue[i].push(no);
            return true;// we already find a holding track, so break the loop. 
        }
    }
    return false;
}



void result(queue<int> Queue[], int no, int totalholding, int& min)
{
    for(int i = 0;i< totalholding; i++)
    {
        if(!Queue[i].empty() and Queue[i].front() == min)
        {
            cout << "Car " << Queue[i].front() << " Move from H" << i << " to output" << endl;
            Queue[i].pop();
            min++;
            i = -1;// find next car from the first holding track 0
        }
    }
}


 
int main()
{
    int no = 9;
    int holding = 2;   // 2 queue take
    queue<int> q[holding];
    int min = 1;
    int arr[no] = {5,8,1,7,4,2,9,6,3};
    
    display(arr, no);
    int i;
    for(i = no-1; i >=0; i--)
    {
        if(arr[i] == min)
        {
            cout<<"\ncar " << arr[i] << " Move from input to output" << endl;
            min++;
            //move cars from holding tracks
            result(q,arr[i],holding,min);
        }

        else
        {// move cars to holding tracks
            if(!Hold(q, arr[i] ,holding))
            {
               cout<<"Not holding"<< endl;
               break;
            }
        }
    }
    return 0;
}