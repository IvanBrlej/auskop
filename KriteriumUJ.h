#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

template <typename ResultType>
class KriteriumUJ : public Kriterium<UzemnaJednotka, ResultType>
{
public:
	virtual ResultType evaluate(UzemnaJednotka& o) {};
};