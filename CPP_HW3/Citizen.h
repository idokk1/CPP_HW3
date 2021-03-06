#pragma once
#include <iostream>
#include "consts.h"
#include <vector>

using namespace std;

class District;

class Citizen
{
    public:
		Citizen();
        Citizen(string name, string id, unsigned int birthYear, District* district);
        Citizen(const Citizen& other);
        Citizen(istream& in, vector<District*> districts);
		~Citizen();
		string getID() const;
		Citizen& operator=(const Citizen& other);
        District* getDistrict();
        District* getDistrict() const;
        string getName();
        string getName() const;
		bool setIsPartyMember();
		bool getIsPartyMember() const;
        bool setIsAlreadyVote();
        bool getIsAlreadyVote() const;

		friend ostream& operator<<(ostream&, const Citizen&);
		void save(ostream& out) const;
		void load(istream& in, vector<District*> districts);
    private:
		string name;
        string id;
		int birthYear;
		District* district;
		bool isPartyMember; //head or represantive
        bool isAlreadyVote;
};