#include <stdio.h>
#include <iostream>
#include <vector>

double min_move(std::vector<double> &v);

int main()
{
 std::vector<double> l = {3.01, 3, 15.01, 15};
 std::cout << min_move(l);

 return 0;
}

double min_move(std::vector<double> &v)
{

 // the idea is to igualate to the mean,because this the point where we have the smallest combined distance

 double sum = 0;
 for (int i = 0; i < v.size(); i++)
 {
  sum += v[i];
 }
 double mean = sum / v.size();

 double dif = mean - (int)mean;
 if (dif <= 0.1)
 {
  mean = (int)mean;
 }

 for (int i = 0; i < v.size(); i++)
 {
  v[i] -= mean;
 }

 double sum_1 = 0;
 double sum_2 = 0;

 for (int i = 0; i < v.size(); i++)
 {
  if (v[i] < 0)
  {
   sum_1 += (-1.0) * v[i];
  }
  else
  {
   sum_2 += v[i];
  }
 }

 // sum_1 can be different of sum_2 because the computer has to truncate some numbers to represent in bianary

 // std::cout << sum_1 << " " << sum_2 << '\n';

 if (sum_1 > sum_2)
 {
  return sum_2;
 }
 return sum_1;
}
