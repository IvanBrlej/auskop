#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "structures/table/sorted_sequence_table.h"
#include "UzemnaJednotka.h"


using namespace std;
using namespace structures;
class NacitanieDat {
public:
	void nacitanieDat(string subor);
private:
	ifstream obecSubor;
	ifstream krajSubor;
	ifstream okresSubor;
};