#include <iostream>
#include <vector>
#include <algorithm>

#include "Multime.h"

using namespace std;


    //constructor
Multime::Multime()
{
	this->v = std::vector<int> ();
	this->num_elements = 0;
}

    //constructor transforms a vector into Multime
Multime::Multime(std::vector<int> &v)
{
    auto end = v.end();
    for (auto i = v.begin(); i != end; i++) {
        end = std::remove(i + 1, end, *i);
    }

    v.erase(end, v.end());

    this->v = v;
    this->num_elements = v.size();
}

std::vector<int> Multime::getElements()
{
    return this->v;
}

int Multime::getSize()
{
    return this->num_elements;
}


void Multime::addElement(int element)
{
    this->v.push_back(element);
    this->num_elements = this->v.size();
}

void Multime::setValues(vector<int> &v)
{
    this->num_elements = v.size();
    auto end = v.end();
    for (auto i = v.begin(); i != end; i++)
    {
        end = std::remove(i + 1, end, *i);
    }

    v.erase(end, v.end());

    this->v = v;
    this->num_elements = v.size();
}


    //ctor copiere
Multime::Multime(const Multime& A)
{
    this->v = A.v;
    this->num_elements = this->v.size();
}

    //dtor
Multime::~Multime()
{
    if(this->num_elements != 0)
    {
        this->v = std::vector<int> ();
        this->num_elements = 0;
    }
    //std::cout<<"Multimea a fost stearsa"<<endl;
}


    //Reunion
Multime Multime::operator+(Multime A)
{
    std::vector<int> s;
    s = this->v;

    for(int i = 0; i < A.num_elements; i++)
    {
        s.push_back(A.v[i]);
    }

    Multime S = Multime(s);

    return S;
}

    //Intersection
Multime Multime::operator*(Multime A)
{
    Multime I;
    std::vector<int> intersection;

    for (int i = 0; i < this->num_elements; i++)
    {
        for (int j = 0; j < A.num_elements; j++)
        {
            if (this->v[i] == A.v[j])
               intersection.push_back(A.v[j]);
        }
    }

    return Multime(intersection);
}


    //Difference
Multime Multime::operator-(Multime A)
{
    Multime I = Multime(this->v)*A;

    std::vector<int> d;
    std::vector<int> freq(this->num_elements,1); //flag for numbers in this->v

    for(int i=0; i<this->num_elements; i++)
    {
        for(int y:I.v)
        {
            if(this->v[i] == y)
            {
                freq[i] = 0;//if number form this Multime is in Intersection, we set flag to 0 (which means the number is in Multime B)
            }
        }
    }

    for(int i=0; i<this->num_elements; i++)
    {
        if(freq[i] == 1)
            d.push_back(this->v[i]);
    }

    return Multime(d);
}


std::ostream& operator<<(std::ostream& os, Multime& A)
{
    for(int i = 0; i < A.getSize(); i++)
    {
        os<<A.getElements()[i]<<' ';
    }
    return os<<endl;

}

std::ostream& operator<<(std::ostream& os, std::vector<Multime>&Sets)
{
    os<<"Created sets are: "<<endl<<endl;
    for (int i=0; i<Sets.size(); i++)
        os<<"Set index "<<i<<": "<<Sets[i]<<endl;

    return os;
}


std::istream& operator>> (std::istream& os, Multime& A)
{
    int elem;
    vector<int> elements;

    cout<<"Input the number of elements of the set: ";
    os>>A.num_elements;

    for(int i = 0; i < A.num_elements; i++)
    {
        os>>elem;
        elements.push_back(elem);

    }
    A = Multime(elements);
    return os;

}


std::vector<Multime> Multime::CreateSets()
{
    int n;
    cout<<"Input the number of sets to be created: ";

    while (true)
    {
    cin >> n;
    if (!cin)
    {
      cout << "Wrong input!"<<endl<<"Enter an integer: ";
      cout<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    else break;
    }

    vector<Multime> Sets;
    for(int i=0; i<n; i++)
    {
        Multime A;
        cin>>A;
        Sets.push_back(A);
    }

    cout<<endl;

    cout<< "Created sets are: "<<endl<<endl;
    for (int i=0; i<n; i++)
        cout<<"Set index "<<i<<": "<<Sets[i]<<endl;

    return Sets;

}

