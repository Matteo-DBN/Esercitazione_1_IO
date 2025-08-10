
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

double mapping(double x, double a, double b, double c, double d)
{
    return c + ((x-a)/(b-a)) * (d-c);
}

int main()
{
    std::ifstream file("data.txt");
    std::ofstream outputFile("result.txt");

    if(file.fail())
    {
        std::cerr << "Non è stato possibile aprire il file" << std::endl;
        return 1;
    }
    
    if(outputFile.fail())
    {
        std::cerr << "Non è stato possibile creare il file" << std::endl;
        return 1;
    }


    outputFile << "# N Values: \n" << endl;

    double val;
    double mapped_val;
    unsigned int i = 1;
    double sum = 0;

    while(file >> val)
    {
        mapped_val = mapping(val, 1.0, 5.0, -1.0, 2.0);
        sum = sum + mapped_val;
        outputFile << i << " " << scientific << setprecision(16) << sum/i << endl;
        i++;
    }
    
    return 0;
}