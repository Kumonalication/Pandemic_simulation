#ifndef CHARACTER_H
#define CHARACTER_H

#include "place.h"
#include "basis.h"
//±©Ò»³À 202130270029

extern double Rt;
extern bool report;
extern place build;
class people {
private:
	bool is_sick; // if he has been infected
	bool mask_on; // if he wears a mask
	bool vaccinated; //if he is vaccinated
	int home_node;// the number of node where he lives
protected:
	place* location; //current location
	place* destination; // in some cases, it shows where he is headed
	double anti_value; // his resistence to virus
	double active; //his willing to hang out
	int latency; // in latency, he is infected but will not infect others
	bool symptom; // in some cases, if he has symptom, he is reported to the authority
	int ongoing; //how long before he arrives
	bool isolated; //if he has been isolated
	int stay; // how long before he leaves current location
	int speed; //how fast will he be isolated
public:
	people(int node = 0, bool mask = false);
	const bool infected(bool PCR = false, bool nofake = false) const;
	const place* locate() const;
	const bool masked() const;
	const int get_home() const;
	const int infect(double place);
	void isolate();
	const bool move(int time);
};
class student : public people{
public:
	student(int node = 0, bool mask = false);
};
class cencus {
private:
	int number;
	int total_inf;
	people* stu;
public:
	cencus(int num,int sick) : number(num), total_inf(0){
		stu = new student[num];
		for (int i = 0; i < sick; ++i)
			total_inf += stu[i].infect(888);
	}
	void move(int time) {
		for (int i = 0; i < number; ++i)
			if (stu[i].move(time))
				++total_inf;
	}
	void PCR(place* loc) {
		for (int i = 0; i < number; ++i) {
			if (stu[i].locate() == loc)
				if (stu[i].infected(true))
					stu[i].isolate();
		}
	}
	const int infected() const {
		return total_inf;
	}
};

#endif
