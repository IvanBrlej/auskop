#include "NacitanieDat.h"

void NacitanieDat::nacitanieDat(string subor)
{
	SortedSequenceTable<string, UzemnaJednotka*>* uzemne_jednotky_table = new SortedSequenceTable<string, UzemnaJednotka*>();

	string line,line2, code, officialTitle, mediumTitle, shortTitle, sortNumber, note;

	obecSubor.open(subor);

	if (obecSubor.is_open()) {
		getline(obecSubor, line);
		getline(krajSubor, line2);

		while (getline(obecSubor, line)) {
			UzemnaJednotka* uzemna_jednotka = new UzemnaJednotka();

			stringstream lineStream(line);

			getline(lineStream, sortNumber, ';');
			uzemna_jednotka->setSortNumber(stoi(sortNumber));

			getline(lineStream, code, ';');
			uzemna_jednotka->setCode(code);

			getline(lineStream, officialTitle, ';');
			uzemna_jednotka->setOfficialTitle(officialTitle);

			getline(lineStream, mediumTitle, ';');
			uzemna_jednotka->setMediumTitle(mediumTitle);

			getline(lineStream, shortTitle, ';');
			uzemna_jednotka->setShortTitle(shortTitle);

			getline(lineStream, note, ';');
			uzemna_jednotka->setNote(note);

			uzemne_jednotky_table->insert(code, uzemna_jednotka);
			cout << uzemna_jednotka->getOfficialTitle() << endl;
		}
	}
	//UzemnaJednotka* okresik = new UzemnaJednotka();
	//uzemne_jednotky_table->tryFind("SK0101", okresik);
	//cout <<  okresik->getNazovOkresu() << endl;
	cout << uzemne_jednotky_table->size() << endl;
	obecSubor.close();
	krajSubor.close();
}
