#ifndef PLACE_H
#define PLACE_H

//±©Ò»³À 202130270029

class place {
protected:
	int max_total; //total number of people in building
	int infected_total; //total number of infected people in building
	double inf_rate; //basic infected rate for people in building
	//int* inside; //see who is currently inside the building
public:
	place(int num, double bas_rate) :max_total(num), infected_total(0), inf_rate(bas_rate) {
	}
	const double rate() {
		return inf_rate*double(infected_total)/max_total;
	}
	void infected() {
		++infected_total;
	}
	void leaving(bool infect) {
		if (infect)
			--infected_total;
	}
	bool getin(int id, bool infect) {
		if (infect)
			++infected_total;
	}
	void check() {

	}
};
#endif
