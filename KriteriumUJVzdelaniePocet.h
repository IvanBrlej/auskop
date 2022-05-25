#pragma once
#include "KriteriumUJ.h"

class KriteriumUJVzdelaniePocet : public KriteriumUJ<int>
{
private:
	int pocet_;
public:
	KriteriumUJVzdelaniePocet(int pocet) {
		pocet_ = pocet;
	}

	int evaluate(UzemnaJednotka& object) override
	{
		return object.getVzdelaniePocet();
	}
};