#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Image
{
private:
	map<string, vector<string>> images;

public:
	Image();
	void ShowImage(string name);

};

