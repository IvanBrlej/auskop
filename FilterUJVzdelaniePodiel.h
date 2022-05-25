#pragma once
#include "Filter_FI.h"
#include "KriteriumUJVzdelaniePodiel.h"

class FilterUJVzdelaniePodiel : public Filter_FI<UzemnaJednotka, double>
{
public:
	FilterUJVzdelaniePodiel(double minValue, double maxValue) :
		Filter_FI(new KriteriumUJVzdelaniePodiel(), minValue, maxValue)
	{}
};