#pragma once

#include "UJenum.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/array/array.h"
#include <string>
#include "NacitanieDat.h"
#include "structures/heap_monitor.h"


class UzemnaJednotka
{
protected:
	int sortNumber_;
	std::string code_;
	std::string officialTitle_;
	std::string mediumTitle_;
	std::string shortTitle_;
	std::string note_;
	TypUzemnejJednotky typJednotky_;
	int pocetObyvatelov_;
	UzemnaJednotka* vyssiaUzemnaJednotka_;
	int vzdelaniePocet_;
	double vzdelaniePodiel_;
	structures::Array<int>* vzdelanieTabulka_  = new structures::Array<int>(8);

	//TypUzemnejJednotky typUzemnejJednotky = SLOVENSKO;

public:
	UzemnaJednotka();
	~UzemnaJednotka();

	void setSortNumber(int sortNumber);
	void setCode(std::string code);
	void setOfficialTitle(std::string officialTitle);
	void setMediumTitle(std::string mediumTitle);
	void setShortTitle(std::string shortTitle);
	void setNote(std::string note);
	void setTypUzemnejJednotky(TypUzemnejJednotky typJednotky);
	void setPocetObyvatelov(int obyvatelia);
	UzemnaJednotka& getVyssiaUzemnaJednotka();
	structures::Array<int>& getVzdelanieTabulka();

	int getSortNumber();
	std::string getCode();
	std::string getOfficialTitle();
	std::string getMediumTitle();
	std::string getShortTitle();
	std::string getNote();
	TypUzemnejJednotky getTypUzemnejJednotky();
	std::string getStringTypUzemnejJednotky();
	int getPocetObyvatelov();
	int getVzdelaniePodiel();
	int getVzdelaniePocet();

	int vypocitajPocetObyvatelov(std::string obec);
	void setVyssiaUzemnaJednotka(UzemnaJednotka* vyssia);
};