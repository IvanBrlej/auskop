#pragma once
#include "KriteriumUJ.h"
#include <string>

class KriteriumUJNazov : public KriteriumUJ<std::string>
{	
public:
	std::string evaluate(UzemnaJednotka& object) override
	{
		return object.getOfficialTitle();
	}
};