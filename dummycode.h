#include <string>

using namespace std;

/*class Classes
{
private:
	string className, period;
public:
	Classes();
	// getters and setters
	string getClassName();
	void setClassName(string newClass);
	
};*/
class SchedOpt
{
public: 
	void printSched(string classes[],int schedA);
	void modStrings(string classes[]);
	void saveWeekly(string classes[],string fileName);
	void saveSched(string classes[],string fileName);
	void exportCL(string classes[],string fileName);
};	

