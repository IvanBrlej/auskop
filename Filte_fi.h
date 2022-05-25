#pragma once
#include "Kriterium.h"

template <typename ObjectType, typename ValueType>
class Filter_fi : public FilterKriterium<ObjectType, ValueType>
{
private:
	ValueType value_;
public:
	Filter_fi(Kriterium<ObjectType, ValueType>* kriterium, ValueType value)
	{
		value_ = value;
	};
	
protected:
	bool presielFilter(ValueType value) override
	{
		return value_ == value;
	};
};