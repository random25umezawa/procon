#include <iostream>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
static const double pi = 3.141592653589793;
const double PI = acos(-1.0);

using namespace std;

vector<string> split(const std::string& s, const std::string& delim)
{
		vector<string> result;

		using string = std::string;
		string::size_type pos = 0;

		while(pos != string::npos )
		{
				string::size_type p = s.find(delim, pos);

				if(p == string::npos)
				{
						result.push_back(s.substr(pos));
						break;
				}
				else {
						result.push_back(s.substr(pos, p - pos));
				}

				pos = p + delim.size();
		}
    return result;
}

int main() {
  string input;
  getline(cin,input);
  for(string s : split(input," / ")) {
    cout << s << endl;
  }
  cout << input.find("jf");

	cout << sin(PI) << endl;
	cout << sin(pi/6) << endl;
	cout << sin(pi/4) << endl;

  return 0;
}
