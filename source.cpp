#include <iostream>
#include <vector>
#include <map>
#include "matplotlibcpp.h"
double getAverage(std::vector<double> v)
{
double sum = 0;
for (auto x : v)
{
sum += x;
}
return sum / v.size();
}
double getRMS(std::vector<double>& v, double mu)
{
double sum = 0;
for (size_t i = 0; i < v.size(); ++i)
{
sum += pow(v.at(i) - mu, 2);
}
return sqrt( sum / (v.size() - 1));
}
std::vector<double> getGaussiana(std::vector<double> v, double mu,
double rms)
{
std::vector<double> y;
std::sort(v.begin(), v.end());
for (size_t i = 0; i < v.size(); ++i)
{double val = exp (-0.5 * pow((v.at(i)- mu) / rms,
2)) / (rms * sqrt(2*M_PI));
y.push_back(val);
}
return y;
}
int main()
{
double name, north, east, height;
std::vector<double> n, e, h;
while (std::cin >> name >> north >> east >> height)
{
n.push_back(north);
e.push_back(east);
h.push_back(height);
}
std::map < std::string, std::string > settings;
settings ["marker"]=".";
settings ["linewidth"]= "0";
settings ["color"]= "red";
//
//
matplotlibcpp::plot3(n, e, h, settings);
matplotlibcpp::show();
matplotlibcpp::hist( n , 15, "green", 0.5, false);
matplotlibcpp::grid(true);
double mu = getAverage(n);
double rms = getRMS(n, mu);
std::vector<double> gaussiana = getGaussiana(n, mu, rms);
for (size_t i=0; i < n.size(); ++i)
{
std::cout << n.at(i) << " " << gaussiana.at(i) <<
std::endl;
}
std::sort(n.begin(), n.end());
matplotlibcpp::plot(n, gaussiana, "r-");
matplotlibcpp::show();
}
