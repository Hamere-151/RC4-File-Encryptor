#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{ 
  string key = "INSA2026";
  ifstream input("file.txt" , ios::binary);
  if (!input)
  {
    cout << "can not open file.txt"  << endl;
  return 1;
  }
  return 0;
}
