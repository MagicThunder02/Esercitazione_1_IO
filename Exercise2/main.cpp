#include <iostream>
#include <fstream>
#include <iomanip>

float mapToInterval(float a, float b, float c, float d, float x)
{
    float m = (d - c) / (b - a);
    float q = c - m * a;
    return m * x + q;
}

int main()
{
    std::string fileName = "data.csv"; // file name
    std::ifstream ifstr(fileName);

    if (ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    double val = 0;
    int i = 0;
    double numbers[1000];
    float a = 1;
    float b = 5;
    float c = -1;
    float d = 2;

    while (ifstr >> val)
    {
        numbers[i++] = val;
    }

    std::ofstream outFile("result.csv"); // if file does not exist, it is created

    for (int i = 1; i < 1001; i++)
    {
        double mean = 0;
        double sum = 0;

        for (int j = 0; j < i; j++)
        {
            sum += mapToInterval(a, b, c, d, numbers[j]);
        }

        mean = sum / i;

        outFile << i << " " << std::setprecision(17) << std::scientific << mean << std::endl; // write s on file
    }

    return 0;
}
