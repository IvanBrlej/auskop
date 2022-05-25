#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/unsorted_sequence_table.h"
#include <string>
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"
 
class VsetkyUzemneJednotky {
public:
	VsetkyUzemneJednotky();
	~VsetkyUzemneJednotky();

	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* getUtriedenaTabulka();
	//structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>* getNeutriedenaTabulka();

private:
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* vsetkyUzemneJednotky_;
	//structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>* vsetkyUzemneJednotkyNeutriedene_;
	
	void nacitanieDat(string subor);
	ifstream subor_;
};