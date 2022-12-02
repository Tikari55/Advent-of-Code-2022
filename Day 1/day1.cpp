#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

class Elf {
public:

    vector<int> foodItem;
    int totalCals{};
};

bool comapre(const Elf& elf1, const Elf& elf2)
{
    return (elf1.totalCals > elf2.totalCals);
}


int main()
{

    vector<Elf> elves;

    string line;
    ifstream inputfile;
    inputfile.open("input.txt");
    if (!inputfile)
    {
        perror("open failure");
    }

    Elf elf;

    while ( getline (inputfile,line) ) {

        if (!line.empty()) {
            elf.foodItem.push_back(stoi(line));
        } else {
            elf.totalCals = accumulate(elf.foodItem.begin(), elf.foodItem.end(),0); // calculate sum
            elves.push_back(elf);
            elf.foodItem.clear();
        }
    }
    inputfile.close();

    sort(elves.begin(), elves.end(), comapre);
    // Part 1
    cout << elves[0].totalCals << endl;
    // Part 2
    cout << elves[0].totalCals + elves[1].totalCals + elves[2].totalCals << endl;
}