#ifndef MULTIME_H
#define MULTIME_H
#include<iostream>


class Multime
{
    private:
        int num_elements; //number of elements
        std::vector<int> v;

    public:
        ~Multime(); //destructor
        Multime(); //constructor
        Multime(std::vector<int> &nums); //transforms vector nums to Multime
        Multime(const Multime& A); //copy


        std::vector<int> getElements();
        int getSize();

        void addElement(int element);
        void setValues(std::vector<int>& elemets);

        Multime operator+ (Multime B); //reunion
        Multime operator* (Multime B); //intersection
        Multime operator- (Multime B); //difference

        friend std::ostream& operator<<(std::ostream&, Multime&);
        friend std::ostream& operator<<(std::ostream&, std::vector<Multime>& Sets);
        friend std::istream& operator>>(std::istream&, Multime&);

        std::vector<Multime> CreateSets();

    protected:

};

#endif // MULTIME_H
