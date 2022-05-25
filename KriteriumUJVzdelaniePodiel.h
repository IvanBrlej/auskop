#pragma once
#include "KriteriumUJ.h"
#include "KriteriumUJVzdelaniePocet.h"

class KriteriumUJVzdelaniePodiel : public KriteriumUJ<double>
{
private:
	int vzdelanie_;
public:
	KriteriumUJVzdelaniePodiel(int vzdelanie) {
		vzdelanie_ = vzdelanie;
	}
	double evaluate(UzemnaJednotka& object) override;
};

inline double KriteriumUJVzdelaniePodiel::evaluate(UzemnaJednotka& object) {
	KriteriumUJVzdelaniePocet* vzdelanieKriterium = new KriteriumUJVzdelaniePocet(vzdelanie_);
	int pocet = vzdelanieKriterium->evaluate(object);
	delete vzdelanieKriterium;
	return 100.0 * ((double)pocet / (double)object.getPocetObyvatelov());
}