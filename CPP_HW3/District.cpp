#include "District.h"

District::District(): votersPercentage(0), voteCount(0), citizenNum(0) {
    this->name = "";
    this->id = -1; 
    this->representativeNum = 0;
}

District::District(string name, int representativeNum):
        votersPercentage(0), voteCount(0), citizenNum(0) {
	this->name = name;
	this->id = this->generateID();
	this->representativeNum = representativeNum;
}

int District::getID() { return this->id; }

string District::getName() { return this->name; }

string District::getName() const { return this->name; }

int District::getRepresentativeNum(){return this->representativeNum; }

int District::getRepresentativeNum() const { return this->representativeNum; }

map<int, int> District::getElectionResults(){ return this->electionResults; }

void District::printType(std::ostream& os) const{}

District::District(const District& other)
{
    *this = other;
}

void District::operator=(const District& other)
{
    this->voteCount=other.voteCount;
    this->name = other.name;
    this->id = other.id;
    this->citizenNum=other.citizenNum;
    this->votersPercentage = other.votersPercentage;
    this->electionResults = other.electionResults;
    this->representativeNum = other.representativeNum;
}

District::~District()
{
}

int District::generateID(int val)
{
	static int id = 0;
    if (val != 0)
    {
        id = val;
        return id;
    }
	return ++id;
}

void District::addVote(Citizen* voter, const int partyNum)
{
    if (! voter->getIsAlreadyVote()) {
        this->addToElectionResult(partyNum);
        voter->setIsAlreadyVote();
        this->voteCount ++;
        this->votersPercentage= (static_cast<float>(this->voteCount) / static_cast<float>(this->citizenNum)) * 100;
    } else {
        cout << "already voted!" << endl;
    }
}

void District::addToElectionResult(const int partyNum)
{
    if (this->electionResults.find(partyNum) ==  this->electionResults.end() ) {
        this->electionResults.insert(pair<int, int>(partyNum, 1));
    }
    else this->electionResults[partyNum]++;
}

void District::increaseCitizenNum()
{
    this->citizenNum++;
}

int District::getWinningParty(){
    pair<int, int> max = make_pair(1,-1);
    for (auto item : this->electionResults){
        if (item.second > max.second){
            max = item;
        }
    }
    return max.first;
}

map <int,int> District::getNumOfRepresantivesPerParty()
{
    map <int,float> percentagePerParty = this->getPercentagePerParty();
    map <int,int> numOfRepresantivesPerParty;
    for (auto const& pair : electionResults)
    {
        numOfRepresantivesPerParty[pair.first]=
                round(percentagePerParty[pair.first] * this->representativeNum / 100);
    }

    return numOfRepresantivesPerParty;
}

map <int,float> District::getPercentagePerParty()
{
    map <int,float> percentagePerParty;
    for (auto const& pair : electionResults)
    {
       percentagePerParty[pair.first]= (pair.second / static_cast<float>(this->voteCount)) * 100;
    }

    return percentagePerParty;
}

float District::getVotePercentage()
{
    return ((this->citizenNum==0)? 0 : static_cast<float>(this->voteCount) / static_cast<float>(this->citizenNum)) * 100;
}

ostream& operator<<(ostream& os, const District& district)
{
    os << "District ID "<<district.id << " District Name: " << district.getName() << ", num of representative: " << district.getRepresentativeNum()<<" ";
    district.printType(os);
    return os;
}

void District::printElectionResult(vector<Party*> parties, map<int,int>& winningRep)
{

    Party* party;
    string headName;
    int partyIndex;
    map <int, int> electionResults = this->getElectionResults();
    map <int,float> percentagePerParty = this->getPercentagePerParty();
    map <int,int> numOfRepresantivesPerParty = this->getNumOfRepresantivesPerParty();
    
    cout << "total voters percentage- " << this->votersPercentage << "%" << endl;
    cout << "--- parties results --- " << endl;
    vector<pair<int, int>> votersPerParty = getMapSortByValue(electionResults);

    for (auto & pair : votersPerParty)
    {
        partyIndex=pair.first-1;
        cout << "    Party " << (parties[partyIndex]->getName()) <<":"<< endl;
        cout << "        number of voters- " << pair.second << endl
             << "        percentage of all votes - " << percentagePerParty[pair.first]<< "%" << endl;
        cout << "        represantives - " << endl;
        parties[partyIndex]->printFirstNRepresantives( (int)numOfRepresantivesPerParty[pair.first], this->getID());
    }
    for (auto party : parties){
        if (this->electionResults.find(party->getID()) == this->electionResults.end()) {
            cout << "    Party " << (party->getName()) << ":" << endl;
            cout << "        number of voters" << " - 0" << endl
                 << "        percentage of all votes - 0%" << endl;
        }
    }
}


void District::setGenerateIDtoValue(int val)
{
    this->generateID(val);
}


void District::save(ostream& out) const
{
    int nameLen=this->name.length();
    out.write(rcastcc(&nameLen),sizeof(nameLen));
    out.write(&this->name[0], nameLen);

    out.write(rcastcc(&this->id), sizeof(this->id));
    out.write(rcastcc(&this->citizenNum), sizeof(this->citizenNum));
    out.write(rcastcc(&this->votersPercentage), sizeof(this->votersPercentage));
    out.write(rcastcc(&this->voteCount), sizeof(this->voteCount));
    saveMap(out, this->electionResults);
    out.write(rcastcc(&this->representativeNum), sizeof(this->representativeNum));
}

void District::load(istream& in)
{
    int nameLen;
    in.read(rcastc(&nameLen), sizeof(nameLen));
    this->name.resize(nameLen);
    in.read(&this->name[0], nameLen);

    in.read(rcastc(&this->id), sizeof(this->id));
    in.read(rcastc(&this->citizenNum), sizeof(this->citizenNum));
    in.read(rcastc(&this->votersPercentage), sizeof(this->votersPercentage));
    in.read(rcastc(&this->voteCount), sizeof(this->voteCount));
    this->electionResults=loadMap(in, this->electionResults);
    in.read(rcastc(&this->representativeNum), sizeof(this->representativeNum));
}

