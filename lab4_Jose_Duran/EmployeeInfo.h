#include <string>

// class EmployeeInfo that holds employeeid and name
class EmployeeInfo 
{
private:
    int employeeId;
    std::string employeeName;
public:
    EmployeeInfo() : employeeId(0), employeeName("") {} // Default constructor
    EmployeeInfo(int id, const std::string& name) : employeeId(id), employeeName(name) {} // constructor
    int getEmployeeID() const { return employeeId; } // getEmployeeID
    std::string getEmployeeName() const { return employeeName; } // getEmployeeName
};