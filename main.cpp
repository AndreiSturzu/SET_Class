#include <iostream>
#include <vector>
#include <sstream>

#include "Multime.h"
#include "Multime.cpp"

using namespace std;


std::vector<Multime> Sets;
char selection;


void menu()
{
        do{

        cout<<"\n Menu";
        cout<<"\n========";
        cout<<"\n C - Create sets";
        cout<<"\n A - Add element to a set";
        cout<<"\n R - Reunion of sets";
        cout<<"\n I - Intersection of sets";
        cout<<"\n D - Difference of sets";
        cout<<"\n X - Exit\n";
        cout<<"\n Enter selection: ";

        // read the input
        cin>>selection;

        switch(selection)
        {
            case 'C' :
            case 'c' :
            {
                cout<<"\n To create sets\n";
                Multime Set;
                Sets = Set.CreateSets();
            }
            break;

            case 'A' :
            case 'a' :
            {
                cout<<Sets;
                int i, element;
                std::vector<int> index;
                cout<<"\n To add an element to a set\n";
                cout<<"Input the Set index you want to add an element to:\n";
                cin>>i;

                cout<<"\n Input the element you want to add:\n";
                cin>>element;
                Sets[i].addElement(element);

                cout<<Sets;
            }
            break;

            case 'R' :
            case 'r' :
            {
                cout<<Sets;
                int i;
                std::vector<int> indexes;
                cout<<"\n To perform a reunion on sets\n";
                cout<<"Input the Set indexes for reunion (INPUT A NEGATIVE NUMBER WHEN FINISHED):\n";

                do
                {   cin>>i;
                    indexes.push_back(i);
                }while(i>=0);

                indexes.pop_back();

                Multime Result;
                for(auto i: indexes)
                {
                    Result = Result+Sets[i];
                }
                cout<<"Reunion set is: "<<Result<<endl;
            }
            break;

            case 'I' :
            case 'i' :
            {
                cout<<Sets;
                int i;
                std::vector<int> indexes;
                cout<<"\n To perform a intersection on sets\n";
                cout<<"Input the Set indexes for intersection(input a negative number when finished):\n";

                do
                {
                    cin>>i;
                    indexes.push_back(i);
                }while(i>=0);

                indexes.pop_back();

                Multime Result = Sets[indexes[0]];
                for(auto i: indexes)
                {
                    Result = Result*Sets[i];
                }
                cout<<"Intersection set is: "<<Result<<endl;
            }
            break;

            case 'D' :
            case 'd' :
            {
                cout<<Sets;
                int i;
                std::vector<int> indexes;
                cout<<"\n To perform difference of sets:\n";
                cout<<"Input the Set indexes for the 2 sets:\n";
                int index;
                for(int i=0; i<2; i++)
                {
                    cin>>index;
                    indexes.push_back(index);
                }
                Multime Result = Sets[indexes[0]] - Sets[indexes[1]];

                cout<<"Difference set is: "<<Result<<endl;

            }
            break;

            case 'X' :
            case 'x' :
            {
                cout<<"\n To exit the menu";
            }
            break;

            // other than C, R, I, D and X...
            default : cout<<"\n Invalid selection";
            // no break in the default case
            }

            cout<<"\n";

    } while(selection!='x' && selection!='X');

}

int main()
{
    menu();

    return 0;
}
