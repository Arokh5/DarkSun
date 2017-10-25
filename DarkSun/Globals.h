#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>

using namespace std;

bool Same(const string& a, const string& b);
void Tokenize(const string& line, vector<string>& arguments);
int RandomRange(const int minValue, const int maxValue);

#endif