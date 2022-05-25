#pragma once
#include "KriteriumUJ.h"

class KriteriumUJTyp : public KriteriumUJ<TypUzemnejJednotky>
{
public:
	TypUzemnejJednotky evaluate(UzemnaJednotka& object) override
	{
		return object.getTypUzemnejJednotky();
	}
};