#pragma once
#include "Filte_fi.h"
#include "KriteriumUJNazov.h"
#include <string>

class FilterNazov : public Filter_fi<UzemnaJednotka, std::string>
{
public:
	FilterNazov(std::string nazov) :
		Filter_fi(new KriteriumUJNazov(), nazov)
	{}
};

//inline FilterNazov::FilterNazov(std::string nazov) :
//	Filter_fi(new KriteriumUJNazov(), nazov)
//{}