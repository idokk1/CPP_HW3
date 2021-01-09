﻿#include <iostream>
#include <fstream>
#include "Citizen.h"
#include "UnifiedDistrict.h"
#include "DividedDistrict.h"
#include "SimpleElectionRound.h"
#include "RegularElectionRound.h"
#include "Party.h"
#include "consts.h"


void addDistrict(ElectionRound& electionRound);
void addCitizen(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType);
void addParty(ElectionRound& electionRound);
void setCitizenAsPartyRepresentive(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType);
void printAllDistricts(ElectionRound& electionRound);
void printAllCitizens(ElectionRound& electionRound);
void printAllParties(ElectionRound& electionRound);
void vote(ElectionRound& electionRound);
void showElectionResults(ElectionRound& electionRound);
ELECTION_ROUND_TYPE loadElectionRound(ElectionRound* &electionRound);
void saveElectionRound(ElectionRound* electionRound);

void addDistrictMOCK(ElectionRound& electionRound, string name, int representativeNum, int districtType);
void voteMOCK(ElectionRound& electionRound, string citizenId, int partyId);
void addCitizenMOCK(ElectionRound& electionRound, string name, string id, int districtNum, ELECTION_ROUND_TYPE electionRoundType, int birthYear);
void addPartyMOCK(ElectionRound& electionRound, string name, string id);
void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, string representiveId, int partyId, int districtId, ELECTION_ROUND_TYPE electionRoundType);

using namespace std;

int main()
{
    ElectionRound* electionRound = nullptr;
    try {
        OPTIONS option = OPTIONS::showElectionResults;
        //TODO
        ELECTION_ROUND_OPTIONS electionRoundOption = ELECTION_ROUND_OPTIONS::newElectionRound;
        int day = 1, month = 1, year = 2018, electionRoundTypeNum = 0;
        ELECTION_ROUND_TYPE electionRoundType;
        int optionNum, electionRoundOptionNum = 1;

        cout << "enter one of the options-" << endl
            << "1 - add new election round" << endl
            << "2- load election round" << endl;
        cin >> electionRoundOptionNum;
        if ((electionRoundOptionNum != (int)ELECTION_ROUND_OPTIONS::newElectionRound) && (electionRoundOptionNum != (int)ELECTION_ROUND_OPTIONS::loadElectionRound))
            throw invalid_argument("invalid option");

        electionRoundOption = (ELECTION_ROUND_OPTIONS)electionRoundOptionNum;
        switch (electionRoundOption)
        {
        case ELECTION_ROUND_OPTIONS::newElectionRound:
        {
            //            cout << "enter elections date DD MM YYYY ";
            //            cin >> day >> month >> year;
            cout << "enter elections round type (0 for regular, 1 for simple) ";
            cin >> electionRoundTypeNum;

            if ((electionRoundTypeNum != (int)ELECTION_ROUND_TYPE::regular) && (electionRoundTypeNum != (int)ELECTION_ROUND_TYPE::simple))
                throw invalid_argument("invalid election round type");

            electionRoundType = (ELECTION_ROUND_TYPE)electionRoundTypeNum;
            if (electionRoundType == ELECTION_ROUND_TYPE::regular) electionRound = new RegularElectionRound(day, month, year);
            else
            {
                int numOfRepresentative;
                cout << "enter number of representative ";
                cin >> numOfRepresentative;
                electionRound = new SimpleElectionRound(day, month, year, numOfRepresentative);
            }
            break;
        }
        case ELECTION_ROUND_OPTIONS::loadElectionRound:
            electionRoundType = loadElectionRound(electionRound);
        }

        //        addDistrictMOCK(*electionRound, const_cast<char*>("A"), -8, 1);  // invalid
        //        addDistrictMOCK(*electionRound, const_cast<char*>("A"), 4, 7);  // invalid
        addDistrictMOCK(*electionRound, const_cast<char*>("A"), 4, 1);
        addDistrictMOCK(*electionRound, const_cast<char*>("B"), 10,1);
        addDistrictMOCK(*electionRound, const_cast<char*>("C"), 2, 0);

//                addCitizenMOCK(*electionRound, const_cast<char*>("A1"), const_cast<char*>("000000011"), 1, electionRoundType, 2009);// invalid
//                addCitizenMOCK(*electionRound, const_cast<char*>("A1"), const_cast<char*>("0011"), 1, electionRoundType, 1880);// invalid
        addCitizenMOCK(*electionRound, const_cast<char*>("A1"), const_cast<char*>("000000011"), 1, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("A2"), const_cast<char*>("000000012"), 1, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("A3"), const_cast<char*>("000000013"), 1, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("A4"), const_cast<char*>("000000014"), 1, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("A5"), const_cast<char*>("000000015"), 1, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B1"), const_cast<char*>("000000021"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B2"), const_cast<char*>("000000022"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B3"), const_cast<char*>("000000023"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B4"), const_cast<char*>("000000024"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B5"), const_cast<char*>("000000025"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B6"), const_cast<char*>("000000026"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B7"), const_cast<char*>("000000027"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B8"), const_cast<char*>("000000028"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B9"), const_cast<char*>("000000029"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("B10"), const_cast<char*>("000000210"), 2, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("C1"), const_cast<char*>("000000031"), 3, electionRoundType, 1880);
        addCitizenMOCK(*electionRound, const_cast<char*>("C2"), const_cast<char*>("000000032"), 3, electionRoundType, 1880);

//                addPartyMOCK(*electionRound, const_cast<char*>("one"), const_cast<char*>("4"));  //  invalid no such citizen
        addPartyMOCK(*electionRound, const_cast<char*>("one"), const_cast<char*>("000000012"));
//                addPartyMOCK(*electionRound, const_cast<char*>("one"), const_cast<char*>("000000012")); //  invalid already head
        addPartyMOCK(*electionRound, const_cast<char*>("two"), const_cast<char*>("000000021"));
        addPartyMOCK(*electionRound, const_cast<char*>("three"), const_cast<char*>("000000022"));

//                setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000011"), 2, 9, electionRoundType); //  invalid district
//                setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000011"), 9, 2, electionRoundType); //  invalid party
//                setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("7"), 2, 2, electionRoundType); //  invalid no such citizen
//                setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000012"), 2, 2, electionRoundType); //  invalid already head
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000011"), 2, 2, electionRoundType);
//                setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000011"), 2, 2, electionRoundType); //  invalid already rep
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000014"), 1, 1, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000023"), 2, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000024"), 2, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000025"), 2, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000026"), 2, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000015"), 2, 1, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000031"), 3, 3, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000032"), 3, 3, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000027"), 3, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000028"), 3, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000029"), 3, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000210"), 3, 2, electionRoundType);
        setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("000000013"), 3, 1, electionRoundType);

//                voteMOCK(*electionRound, const_cast<char*>("000000011"), 8); // invalid party
//                voteMOCK(*electionRound, const_cast<char*>("7"), 2); // invalid citizen
        voteMOCK(*electionRound, const_cast<char*>("000000011"), 2);
        voteMOCK(*electionRound, const_cast<char*>("000000013"), 2);
        voteMOCK(*electionRound, const_cast<char*>("000000014"), 1);
        voteMOCK(*electionRound, const_cast<char*>("000000015"), 1);
        voteMOCK(*electionRound, const_cast<char*>("000000023"), 2);
        voteMOCK(*electionRound, const_cast<char*>("000000024"), 2);
        voteMOCK(*electionRound, const_cast<char*>("000000025"), 2);
        voteMOCK(*electionRound, const_cast<char*>("000000026"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000027"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000028"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000029"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000210"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000031"), 3);
        voteMOCK(*electionRound, const_cast<char*>("000000032"), 3);

        while (option != OPTIONS::exit) {
            try {
                cout << "enter one of the options-" << endl
                    << "1 - add district " << endl
                    << "2- add citizen " << endl
                    << "3- add party " << endl
                    << "4- add citizen as party representive " << endl
                    << "5- show all districts " << endl
                    << "6- show all citizens " << endl
                    << "7- show all parties " << endl
                    << "8- vote " << endl
                    << "9- show election results " << endl
                    << "10- exit the program " << endl
                    << "11- save the election round " << endl
                    << "12- load exist election round " << endl;

                cin >> optionNum;
                option = (OPTIONS)optionNum;
                if (optionNum < (int)OPTIONS::addDistrict || optionNum >(int)OPTIONS::loadElectionRound)
                    throw invalid_argument("invalid option");
                switch (option)
                {
                case OPTIONS::addDistrict:
                    addDistrict(*electionRound);
                    break;
                case OPTIONS::addCitizen:
                    addCitizen(*electionRound, electionRoundType);
                    break;
                case OPTIONS::addParty:
                    addParty(*electionRound);
                    break;
                case OPTIONS::addCitizenAsPartyRepresentive:
                    setCitizenAsPartyRepresentive(*electionRound, electionRoundType);
                    break;
                case OPTIONS::showAllDistricts:
                    printAllDistricts(*electionRound);
                    break;
                case OPTIONS::showAllCitizens:
                    printAllCitizens(*electionRound);
                    break;
                case OPTIONS::showAllParties:
                    printAllParties(*electionRound);
                    break;
                case OPTIONS::vote:
                    vote(*electionRound);
                    break;
                case OPTIONS::showElectionResults:
                    showElectionResults(*electionRound);
                    break;
                case OPTIONS::exit:
                    cout << "see you soon" << endl;
                    break;
                case OPTIONS::saveElectionRound:
                    saveElectionRound(electionRound);
                    break;
                case OPTIONS::loadElectionRound:
                    delete electionRound;
                    electionRound = nullptr;
                    loadElectionRound(electionRound);
                    break;
                }
            }
            catch (invalid_argument ex) {
                cout << "You enter invalid argument :(" << endl << "details: " << ex.what() << endl << "pls try again" << endl;
            }
            catch (out_of_range ex) {
                cout << "You enter out of range argument :(" << endl << "details: " << ex.what() << endl << "pls try again" << endl;
            }
        }
    }
    catch (invalid_argument ex) {
                cout << "You enter out of range argument :(" << endl << "details: " << ex.what() << "." << endl << "pls try again" << endl;
    } catch (...) {
        if (electionRound != nullptr) delete electionRound;
        electionRound = nullptr;
    }
    if (electionRound != nullptr) delete electionRound;
}

void addDistrictMOCK(ElectionRound& electionRound, string name, int representativeNum, int districtTypeNum) {
    District* district;
    DISTRICT_TYPE districtType;
    if ((districtTypeNum != (int)DISTRICT_TYPE::divided) && (districtTypeNum != (int)DISTRICT_TYPE::unified))
        throw invalid_argument("invalid district type");
    districtType = (DISTRICT_TYPE)districtTypeNum;
    if (representativeNum <= 0)
        throw invalid_argument("Sorry a district have a positive number of represenative number");
    if (districtType == DISTRICT_TYPE::unified) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}

void addDistrict(ElectionRound &electionRound) {
    string name;
    int representativeNum; 
    int districtTypeNum;
    DISTRICT_TYPE districtType;
    District* district;
    cout << "enter name, number of representative and district type (1 for divided, 0 for unified) ";
    cin >> name >> representativeNum >> districtTypeNum;
    if ((districtTypeNum != (int)DISTRICT_TYPE::divided) && (districtTypeNum != (int)DISTRICT_TYPE::unified))
        throw invalid_argument("invalid district type");
    districtType = (DISTRICT_TYPE)districtTypeNum;
    if (representativeNum <= 0) 
        throw invalid_argument("Sorry a district have a positive number of represenative number");
    if (districtType == DISTRICT_TYPE::unified) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}

void addCitizenMOCK(ElectionRound& electionRound, string name, string id, int districtNum, ELECTION_ROUND_TYPE electionRoundType, int birthYear){
    if (electionRound.isCitizenIdIsAlreadyExist(id)) throw invalid_argument("This Citizen id already exists");
    if (electionRound.getYear() - birthYear < 18) throw out_of_range("citizen must be at least 18 years old");

    districtNum = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtNum : 1;
    District* district = electionRound.getDistrictByID(districtNum); 
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addCitizen(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType) {
    string name;
    string id;
    int birthYear, districtNum;
    cout << "enter name, id, birth year, district number ";
    cin >> name >> id >> birthYear >> districtNum;
    if (electionRound.isCitizenIdIsAlreadyExist(id)) throw invalid_argument("This Citizen id already exists");
    if (electionRound.getYear() - birthYear < 18) throw out_of_range("citizen must be at least 18 years old");

    districtNum = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtNum : 1;
    District* district = electionRound.getDistrictByID(districtNum); 
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addPartyMOCK(ElectionRound& electionRound, string name, string id){
    Citizen* head = electionRound.getCitizenByID(id);
    if (head->getIsPartyMember()) {
        throw invalid_argument("This citizen already set as party head.");
    }
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void addParty(ElectionRound& electionRound) {
    string name;
    string id;
    cout << "enter name and the party head's id ";
    cin >> name >> id;
    Citizen* head = electionRound.getCitizenByID(id);
    if (head->getIsPartyMember()) {
        throw invalid_argument("This citizen already set as party head.");
    }
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, string representiveId, int partyId, int districtId, ELECTION_ROUND_TYPE electionRoundType){
    districtId = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtId : 1;
    electionRound.getDistrictByID(districtId);
    Citizen* citizen = electionRound.getCitizenByID(representiveId);
    if (citizen->getIsPartyMember()) {
        throw invalid_argument("This citizen already set as represantive or head.");
    }
    citizen->setIsPartyMember();
    Party* party = electionRound.getPartyByID(partyId);
    party->addRepresentive(districtId, citizen);
}

void setCitizenAsPartyRepresentive(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType) {
    string representiveId;
    int partyId;
    int districtId;
    cout << "enter representive ID, party ID, district ID ";
    cin >> representiveId >> partyId >> districtId;
    districtId = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtId : 1;
    electionRound.getDistrictByID(districtId);
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (citizen->getIsPartyMember()) {
        throw invalid_argument("This citizen already set as represantive or head.");
    }
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    party->addRepresentive(districtId, citizen);
}

void printAllDistricts(ElectionRound& electionRound) {
    electionRound.printAllDistricts();
}

void printAllCitizens(ElectionRound& electionRound) {
    electionRound.printAllCitizens();
}

void printAllParties(ElectionRound& electionRound) {
    electionRound.printAllParties();
}

void voteMOCK(ElectionRound& electionRound, string citizenId, int partyId){
    Party* party = electionRound.getPartyByID(partyId);
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district = voter->getDistrict();
    district->addVote(voter, partyId);
    party->increaseNumberOfVotes();
}

void vote(ElectionRound& electionRound){
    string citizenId;
    int partyId;
    cout << "enter citizen ID, party ID ";
    cin >> citizenId >> partyId;
    Party* party = electionRound.getPartyByID(partyId);
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    party->increaseNumberOfVotes();
}

void showElectionResults(ElectionRound& electionRound){
    electionRound.showElectionRoundDate();
    for (auto district: electionRound.getDistricts())
    {
        cout << "--------------" << *district << " -------------------" << endl;
        district->printElectionResult(electionRound.getParties().size(), electionRound.getParties());
    }
    cout << "-------------- Summary -------------------" << endl;
    vector<Party*> parties = electionRound.getSortedParties();
    for (auto party : electionRound.getParties()) {
        cout <<*party <<endl
             << "   winning number of represantives-  " << party->getNumberOfWinningRepresantives() << endl
             << "   total number of votes from all districts- "<< party->getNumberOfVotes() << endl;
    }

}

ELECTION_ROUND_TYPE loadElectionRound(ElectionRound* &electionRound)
{
    int typenum;
    ELECTION_ROUND_TYPE type;
    string fileName;
//    cout << "enter file name ";
//    cin >> fileName;
//    ifstream infile(fileName, ios::binary);
    ifstream infile("romi.bin", ios::binary);
    if (!infile) {
        cout << "Error with infile" << endl;
        exit(-1);
    }
    infile.read(rcastc(&typenum), sizeof(typenum));
    type = (ELECTION_ROUND_TYPE)typenum;
    switch (type) {
    case ELECTION_ROUND_TYPE::regular:
        electionRound = new RegularElectionRound(infile);
        break;
    case ELECTION_ROUND_TYPE::simple:
        electionRound = new SimpleElectionRound(infile);
        break;
    }
    infile.close();
    return type;
}

void saveElectionRound(ElectionRound* electionRound)
{
    string fileName;
//    cout << "enter file name ";
//    cin >> fileName;
//    ofstream outfile(fileName, ios::binary | ios::trunc);
    ofstream outfile("romi.bin", ios::binary | ios::trunc);
    if (!outfile) {
        cout << "Error with infile" << endl;
        exit(-1);
    }
    electionRound->save(outfile);
    outfile.close();
}

