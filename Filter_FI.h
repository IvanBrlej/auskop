#pragma once
#include "Kriterium.h"

template <typename ObjectType, typename ValueType>
class Filter_FI : public public FilterKriterium<ObjectType, ValueType>
{
private:
	ValueType valueMax_;
	ValueType valueMin_;
public:
	Filter_FI(Kriterium<ObjectType, ValueType>* kriterium, ValueType valueMin, ValueType valueMax)
	{
		valueMin_ = valueMin;
		valueMax_ = valueMax;
	};
protected:
	bool presielFilter(ValueType value) override
	{
		return value >= valueMin_ && value <= valueMax_;
	};
};