#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cmath>    
#include <iomanip>   
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int studentID;
    float gpa;
    float wgpa;
    vector<string> courses;

public:
    Student() {}

    Student(string sn, int stID, float g, float wg, vector<string> classes) {
        name = sn;
        studentID = stID;
        gpa = g;
        wgpa = wg;
        courses = classes;
    }

    string getName() { return name; }
    int getStudentID() { return studentID; }
    float getGPA() { return gpa; }
    float getWGPA() { return wgpa; }
    vector<string> getCourses() { return courses; }
    
    // For sorting by weighted GPA
    bool operator<(const Student& other) const {
        if (wgpa != other.wgpa) {
            return wgpa > other.wgpa; 
        }
        return gpa > other.gpa; // Tiebreaker
    }
};

int main() {
    vector<Student> students;
    // Top 50 most popular first names (boys and girls combined)
    vector<string> firstName = {
        "Liam", "Noah", "Oliver", "Elijah", "James", 
        "William", "Benjamin", "Lucas", "Henry", "Alexander",
        "Olivia", "Emma", "Charlotte", "Amelia", "Ava",
        "Sophia", "Isabella", "Mia", "Evelyn", "Harper",
        "Michael", "Daniel", "Matthew", "David", "Joseph",
        "Emily", "Abigail", "Elizabeth", "Mila", "Ella",
        "Avery", "Sofia", "Camila", "Aria", "Scarlett",
        "Jackson", "Sebastian", "Jack", "Aiden", "Owen",
        "Samuel", "Jacob", "Asher", "John", "Luke",
        "Lily", "Chloe", "Victoria", "Grace", "Zoey"
    };

    // Top 50 most common last names in the US
    vector<string> lastName = {
        "Smith", "Johnson", "Williams", "Brown", "Jones",
        "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
        "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson",
        "Thomas", "Taylor", "Moore", "Jackson", "Martin",
        "Lee", "Perez", "Thompson", "White", "Harris",
        "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson",
        "Walker", "Young", "Allen", "King", "Wright",
        "Scott", "Torres", "Nguyen", "Hill", "Flores",
        "Green", "Adams", "Nelson", "Baker", "Hall",
        "Rivera", "Campbell", "Mitchell", "Carter", "Roberts"
    };

    vector<string> english9choices = {
        "English I", 
        "Academic English I", 
        "Honors English I"
    };

    vector<string> english10choices = {
        "English II", 
        "Academic English II", 
        "Honors English II"
    };

    vector<string> english11choices = {
        "English III", 
        "Academic English III", 
        "Honors English III",
        "AP Language & Composition"
    };

    vector<string> english12choices = {
        "English IV: Literature and Film",
        "English IV: Sci. Fiction & Fantasy",
        "English IV: Contemporary Lit.",
        "English IV: Mystery And Crime",
        "Honors English IV",
        "English IV College Composition",
        "AP English IV-Lit/Comp"
    };

    vector<string> history9choices = {
        "The American Experiment: Democracy in Action",
        "Academic American Experiment: Democracy in Action",
        "Honors American Experiment: Democracy in Action"
    };

    vector<string> history10choices = {
        "US History",
        "Academic U.S. History",
        "Honors U.S. History",
        "AP US History"
    };

    vector<string> history11choices = {
        "Global Studies",
        "Academic Global Studies",
        "Honors Global Studies",
        "AP World History: Modern"
    };

    vector<string> history12choices = {
        "Holocaust & Genocide Studies",
        "Human Behavior in the 21st Century",
        "Human Behavior",
        "Child Psychology",
        "Military History",
        "Political Literacy & Civic Education",
        "Race, Class, Gender and LGBT History",
        "Honors Race, Class, Gender and LGBT History",
        "AP European History",
        "AP African American Studies",
        "AP Government and Politics",
        "AP Comparative Government & Politics",
        "AP Psychology",
        "Pop Culture in US History",
        "History Through Film",
        "The Vietnam Era",
        "Sociology",
        "Anthropology",
        "Perspectives On 9/11 and Terrorism in America",
        "Crime and Justice in America"
    };

    vector<string> math9choices = {
        "Algebra I",
        "Algebra I Plus",
        "Advanced Geometry"
    };

    vector<string> math10choices = {
        "Geometry",
        "Elements Of Geometry",
        "Advanced Geometry"
    };

    vector<string> math11choices = {
        "Algebra II",
        "Advanced Algebra II",
        "Honors Algebra II"
    };

    vector<string> math12choices = {
        "Precalculus",
        "Advanced Pre-Calculus",
        "Honors Pre-AP Calculus",
        "Calculus",
        "Discrete Math I",
        "College Calculus",
        "AP Calculus-AB",
        "AP Calculus-BC",
        "Multivariable Calculus & Linear Algebra",
        "Differential Equations",
        "Introduction To Statistics",
        "AP Statistics"
    };

    vector<string> science9choices = {
        "Physical & Earth Science",
        "Physics I",
        "Honors Physics",
        "AP Physics I"
    };

    vector<string> science10choices = {
        "Chemistry I",
        "Honors Chemistry I",
        "Biology I",
        "Honors Biology I"
    };

    vector<string> science11choices = {
        "Biology I",
        "Honors Biology I",
        "Biology II",
        "Science Technology & Society",
        "AP Biology",
        "AP Chemistry",
        "AP Environmental Science"
    };

    vector<string> science12choices = {
        "Honors Human Anatomy & Physiology",
        "Astronomy",
        "Biotechnology",
        "Epidemiology",
        "Forensic Science",
        "Forensics II",
        "Intro to Nutrition",
        "AP Biology",
        "AP Chemistry",
        "Organic Chemistry",
        "AP Environmental Science",
        "AP Physics C",
        "Modern Physics"
    };

    srand(time(0));

    for (int i = 1; i <= 500; i++) {
        int randomFirstNameIndex = rand() % firstName.size();
        int randomLastNameIndex = rand() % lastName.size();
        string fullName = firstName[randomFirstNameIndex] + " " + lastName[randomLastNameIndex];

        vector<string> indvSchedule;
        double gradePoint = 0;
        double wGradePoint = 0;

        for (int j = 1; j <= 4; j++) {
            if (j == 1) {
                indvSchedule.push_back(english9choices[rand() % english9choices.size()]);
                indvSchedule.push_back(history9choices[rand() % history9choices.size()]);
                indvSchedule.push_back(math9choices[rand() % math9choices.size()]);
                indvSchedule.push_back(science9choices[rand() % science9choices.size()]);
            } else if (j == 2) {
                indvSchedule.push_back(english10choices[rand() % english10choices.size()]);
                indvSchedule.push_back(history10choices[rand() % history10choices.size()]);
                indvSchedule.push_back(math10choices[rand() % math10choices.size()]);
                indvSchedule.push_back(science10choices[rand() % science10choices.size()]);
            } else if (j == 3) {
                indvSchedule.push_back(english11choices[rand() % english11choices.size()]);
                indvSchedule.push_back(history11choices[rand() % history11choices.size()]);
                indvSchedule.push_back(math11choices[rand() % math11choices.size()]);
                indvSchedule.push_back(science11choices[rand() % science11choices.size()]);
            } else if (j == 4) {
                indvSchedule.push_back(english12choices[rand() % english12choices.size()]);
                indvSchedule.push_back(history12choices[rand() % history12choices.size()]);
                indvSchedule.push_back(math12choices[rand() % math12choices.size()]);
                indvSchedule.push_back(science12choices[rand() % science12choices.size()]);
            }
        }

        cout << fixed << setprecision(4);
        cout << fullName << "\nCourses and Grades:\n";

        for (const string& course : indvSchedule) {
            double baseGPA = 0;
            double wGPA = 0;
            
            int cG = rand() % 101; 
            double courseGrade = static_cast<double>(cG) / 100; 
            for(int c = 0; c < 3; c++){
                courseGrade = sqrt(courseGrade);                  
            }                 
            courseGrade = round(courseGrade * 100); 

            if (courseGrade >= 93){
                baseGPA = 4.0;
                wGPA = 4;
            }
            else if (courseGrade >= 90){ 
                baseGPA = 3.67;
                wGPA = 3.67;
            } else if (courseGrade >= 87){ 
                baseGPA = 3.33;
                wGPA = 3.33;
            }
            else if (courseGrade >= 83){
                baseGPA = 3.0;
                wGPA = 3;
            }
            else if (courseGrade >= 80){
                baseGPA = 2.67;
                wGPA = 2.67;
            }
            else if (courseGrade >= 77){
                baseGPA = 2.33;
                wGPA = 2.33;
            }
            else if (courseGrade >= 73){
                baseGPA = 2.0;
                wGPA = 2;
            }
            else if (courseGrade >= 70){
                baseGPA = 1.67;
                wGPA = 1.67;
            }
            else if (courseGrade >= 65){
                baseGPA = 1.0;
                wGPA = 1;
            }
            else {
                baseGPA = 0;
                wGPA = 0;
            }

            if ((course.find("AP") != string::npos ||course.find("Organic") != string::npos || course.find("College") != string::npos ||course.find("Multivariable") != string::npos || course.find("Differential") != string::npos || course.find("Modern") != string::npos) && courseGrade > 65)
                wGPA += 1.0;
            else if (course.find("Honors") != string::npos && courseGrade > 65)
                wGPA += 0.5;

            gradePoint += baseGPA;
            wGradePoint += wGPA;

            cout << course << " | " << fixed << setprecision(2) << courseGrade << "\n";
        }

        float gpa = roundf((gradePoint / indvSchedule.size()) * 10000) / 10000.00f;
        float wgpa = roundf((wGradePoint / indvSchedule.size()) * 10000) / 10000.00f;

        students.push_back(Student(fullName, i, gpa, wgpa, indvSchedule));
        cout << "UW GPA: " << gpa << "\n";
        cout << "W GPA: " << wgpa << "\n\n";
    }

    sort(students.begin(), students.end());

    cout << "\n\nRanked Students by Weighted GPA:\n";
    cout << "Rank\tName\t\t\tWeighted GPA\tUnweighted GPA\n";
    cout << "--------------------------------------------------\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << i+1 << "\t" << students[i].getName();

        if (students[i].getName().length() < 16) cout << "\t";
        if (students[i].getName().length() < 8) cout << "\t";
        cout << "\t" << fixed << setprecision(4) << students[i].getWGPA() 
             << "\t\t" << students[i].getGPA() << "\n";
    }

    return 0;
}
