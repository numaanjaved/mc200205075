//Question no 11
//xi.	Write a program to calculate GPA of the semester, assuming there are 5 courses and each course is having following break-up:
//Mid-Term Marks: 35
//Final: 50
//Quiz: 5
//Assignment: 10


#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<iomanip>
using namespace std;
class Assignment{
    private:
        int obtainedMarks;
        int totalMarks;
        float weightedMarks;
        float weightedTotalMarks;
    public:
        Assignment(){
            this->setTotalMarks(20);
            this->setWeightedTotalMarks(2.5);
        }
        void setObtainedMarks(int obtainedMark){
            this->obtainedMarks = obtainedMark;
        }
        int getObtainedMarks(){
            return this->obtainedMarks;
        }
        void setTotalMarks(int totalMark){
            this->totalMarks = totalMark;
        }
        int getTotalMarks(){
            return this->totalMarks;
        }
        void setWeightedMarks(float weightedMark){
            this->weightedMarks = weightedMark;
        }
        float getWeightedMarks(){
            return this->weightedMarks;
        }
        void setWeightedTotalMarks(float weightedTotalMark){
            this->weightedTotalMarks = weightedTotalMark;
        }
        float getWeightedTotalmarks(){
            return this->weightedTotalMarks;
        }
        void display(int number){
            cout << "Assignment no. " << number + 1 << " score: " << this->getObtainedMarks() << " out of " << this->getTotalMarks() << endl;
        }
        void inputObtainedMarks(int number){
            cout << "Please Enter Your Assignment no. " << number + 1 << " marks: ";
            int assignmentScore;
            cin >> assignmentScore;
            while(assignmentScore > this->totalMarks || assignmentScore < 0){
                cout << "You have entered incorrect marks, please enter your correct obtained marks: ";
                cin >> assignmentScore;
            }
            this->setObtainedMarks(assignmentScore);  
            this->calculateWeightedMarks();   
        }
        void calculateWeightedMarks(){
            float score = float(this->obtainedMarks) / float(this->totalMarks);
            
            this->weightedMarks = this->weightedTotalMarks * score;
        }
};
class Quiz{
    private:
        int obtainedMarks;
        int totalMarks;
        float weightedMarks;
        float weightedTotalMarks;
    public:
        Quiz(){
            this->setTotalMarks(10);
            this->setWeightedTotalMarks(2.5);
        }
        void setObtainedMarks(int obtainedMark){
            this->obtainedMarks = obtainedMark;
        }
        int getObtainedMarks(){
            return this->obtainedMarks;
        }
        void setTotalMarks(int totalMark){
            this->totalMarks = totalMark;
        }
        int getTotalMarks(){
            return this->totalMarks;
        }
        void setWeightedMarks(float weightedMark){
            this->weightedMarks = weightedMark;
        }
        float getWeightedMarks(){
            return this->weightedMarks;
        }
        void setWeightedTotalMarks(float weightedTotalMark){
            this->weightedTotalMarks = weightedTotalMark;
        }
        float getWeightedTotalmarks(){
            return this->weightedTotalMarks;
        }
        void display(int number){
            cout << "Quiz no. " << number + 1 << " score: " << this->getObtainedMarks() << " out of " << this->getTotalMarks() << endl;
        }
        void inputObtainedMarks(int number){
            cout << "Please Enter Your Quiz no. " << number + 1 << " marks: ";
            int quizScore;
            cin >> quizScore;
            while(quizScore > this->totalMarks || quizScore < 0){
                cout << "You have entered incorrect marks, please enter your correct obtained marks: ";
                cin >> quizScore;
            }
            this->setObtainedMarks(quizScore);
            this->calculateWeightedMarks();   
        }
        void calculateWeightedMarks(){
            float score = float(this->obtainedMarks) / float(this->totalMarks);
            this->weightedMarks = this->weightedTotalMarks * score;
        }
};
class Midterm{
    private:
        int obtainedMarks;
        int totalMarks;
        float weightedMarks;
        float weightedTotalMarks;
    public:
        Midterm(){
            this->setTotalMarks(38);
            this->setWeightedTotalMarks(35);
        }
        void setObtainedMarks(int obtainedMark){
            this->obtainedMarks = obtainedMark;
        }
        int getObtainedMarks(){
            return this->obtainedMarks;
        }
        void setTotalMarks(int totalMark){
            this->totalMarks = totalMark;
        }
        int getTotalMarks(){
            return this->totalMarks;
        }
        void setWeightedMarks(float weightedMark){
            this->weightedMarks = weightedMark;
        }
        float getWeightedMarks(){
            return this->weightedMarks;
        }
        void setWeightedTotalMarks(float weightedTotalMark){
            this->weightedTotalMarks = weightedTotalMark;
        }
        float getWeightedTotalmarks(){
            return this->weightedTotalMarks;
        }
        void inputObtainedMarks(){
            cout << "Please enter your Obtained marks in Midterm: ";
            int obtainedMarks;
            cin >> obtainedMarks;
            while(obtainedMarks > this->totalMarks || obtainedMarks < 0){
                cout << "You have entered incorrect marks, please enter your correct obtained marks: ";
                cin >> obtainedMarks;
            }
            this->setObtainedMarks(obtainedMarks);
            this->calculateWeightedMarks(); 
            cin.ignore();
        }
        void calculateWeightedMarks(){
            float score = float(this->obtainedMarks) / float(this->totalMarks);
            this->weightedMarks = this->weightedTotalMarks * score;
        }
};
class Final{
    private:
        int obtainedMarks;
        int totalMarks;
        float weightedMarks;
        float weightedTotalMarks;
    public:
        Final(){
            this->setTotalMarks(60);
            this->setWeightedTotalMarks(50);
        }
        void setObtainedMarks(int obtainedMark){
            this->obtainedMarks = obtainedMark;
        }
        int getObtainedMarks(){
            return this->obtainedMarks;
        }
        void setTotalMarks(int totalMark){
            this->totalMarks = totalMark;
        }
        int getTotalMarks(){
            return this->totalMarks;
        }
        void setWeightedMarks(float weightedMark){
            this->weightedMarks = weightedMark;
        }
        float getWeightedMarks(){
            return this->weightedMarks;
        }
        void setWeightedTotalMarks(float weightedTotalMark){
            this->weightedTotalMarks = weightedTotalMark;
        }
        float getWeightedTotalmarks(){
            return this->weightedTotalMarks;
        }
        void inputObtainedMarks(){
            cout << "Please enter your Obtained marks in Final: ";
            int obtainedMarks;
            cin >> obtainedMarks;
            while(obtainedMarks > this->totalMarks || obtainedMarks < 0){
                cout << "You have entered incorrect marks, please enter your correct obtained marks: ";
                cin >> obtainedMarks;
            }
            this->setObtainedMarks(obtainedMarks);
            this->calculateWeightedMarks();
            cin.ignore();
        }
        void calculateWeightedMarks(){
            float score = float(this->obtainedMarks) / float(this->totalMarks);
            this->weightedMarks = this->weightedTotalMarks * score;
        }
};
class Course{
    private:
        string name; 
        
    public:
        Assignment* assignments[4];
        Quiz* quizzes[2];
        Midterm* midterm;
        Final* final;
        float obtainedWeightedAssignmentMarks;
        float totalWeightedAssignmentMarks;
        float obtainedWeightedQuizMarks;
        float totalWeightedQuizMarks;
        float obtainedWeightedMidtermMarks;
        float totalWeightedMidtermMarks;
        float obtainedWeightedFinalMarks;
        float totalWeightedFinalMarks;
        float obtainedWeightage;
        float totalWeightage;
        Course(){
            for(int i = 0; i < 4; ++i){
                this->assignments[i] = new Assignment();
            }
            this->obtainedWeightedAssignmentMarks = 0;
            this->totalWeightedAssignmentMarks = 0;
            for(int i = 0; i < 2; ++i){
                this->quizzes[i] = new Quiz();
            }
            this->obtainedWeightedQuizMarks = 0;
            this->totalWeightedQuizMarks = 0;
            this->midterm = new Midterm();
            this->final = new Final(); 
            this->totalWeightedMidtermMarks = this->midterm->getWeightedTotalmarks();
            this->totalWeightedFinalMarks = this->final->getWeightedTotalmarks();
        }
        void setName(string aName){
            this->name = aName;
        }
        string getName(){
            return this->name;
        }
        void inputAssignmentNumbers(){
            for(int assignmentCount = 0; assignmentCount < 4; ++assignmentCount){
                this->assignments[assignmentCount]->inputObtainedMarks(assignmentCount);
                this->obtainedWeightedAssignmentMarks += this->assignments[assignmentCount]->getWeightedMarks();
                this->totalWeightedAssignmentMarks += this->assignments[assignmentCount]->getWeightedTotalmarks();
            }
            cin.ignore();
        }
        void inputQuizNumbers(){
            for(int quizCount = 0; quizCount < 2; ++quizCount){
                this->quizzes[quizCount]->inputObtainedMarks(quizCount);
                this->obtainedWeightedQuizMarks += this->quizzes[quizCount]->getWeightedMarks();
                this->totalWeightedQuizMarks += this->quizzes[quizCount]->getWeightedTotalmarks();
            }
            cin.ignore();
        }
        
        void display(){
            cout << this->getName() << endl;
            cout << "Total Weighted Assignment Score is " << this->obtainedWeightedAssignmentMarks << " out of " << this->totalWeightedAssignmentMarks << endl;
            cout << "Total Weighted Quiz Score is " << this->obtainedWeightedQuizMarks << " out of " << this->totalWeightedQuizMarks << endl;
            cout << "Total Weighted Midterm Score is " << this->obtainedWeightedMidtermMarks << " out of " << this->totalWeightedMidtermMarks << endl;
            cout << "Total Weighted Final Score is " << this->obtainedWeightedFinalMarks << " out of " << this->totalWeightedFinalMarks << endl;
        }
        void input(int number){
            string name;
            cout << "Course " << number + 1 << endl;
            cout << "Please enter your course name: ";
            getline(cin, name);
            this->setName(name);
            this->inputAssignmentNumbers();
            this->inputQuizNumbers();
            this->midterm->inputObtainedMarks();            
            this->final->inputObtainedMarks();    
            this->calculateWeightage();        
        }
        void calculateWeightage(){
            this->obtainedWeightedMidtermMarks = this->midterm->getWeightedMarks();
            this->obtainedWeightedFinalMarks = this->final->getWeightedMarks();
            this->obtainedWeightage = this->obtainedWeightedAssignmentMarks + this->obtainedWeightedQuizMarks + this->obtainedWeightedMidtermMarks + this->obtainedWeightedFinalMarks;
            this->totalWeightage = this->totalWeightedAssignmentMarks + this->totalWeightedQuizMarks + this->totalWeightedMidtermMarks + this->totalWeightedFinalMarks;
        }
};
float calculatePercentage(float a, float b){
    return a * 100 / b;
}

float calculateGPA(int percentage){
    float GPA = 0;
    float gpaTable[101][2];
    for(int i = 0; i < 101; ++i){
        gpaTable[i][0] = i;
        if(i == 0){
            gpaTable[i][1] = 0;
        }
        else if(i == 1){
            gpaTable[i][1] = 0.03;
        }
        else if(i < 50 || i == 79){
            gpaTable[i][1] = gpaTable[i-1][1]+0.02;
        }
        else if(i == 50 || i == 68 || i == 75 || i == 80){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.01;
        }
        else if((i > 50 && i < 61) || (i > 61 && i < 68) || (i > 72 && i < 75) || (i > 75 && i < 79) || (i > 81 && i < 85)){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.1;
        }
        else if(i == 61){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.05;
        }
        else if(i < 71){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.11;
        }
        else if(i < 73){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.12;
        }
        else if(i == 81){
            gpaTable[i][1] = gpaTable[i - 1][1] + 0.04;
        }
        else{
            gpaTable[i][1] = gpaTable[i - 1][1]; 
        }
    }
    for(int i = 0; i < 101; ++i){
        if(percentage == i){
            GPA =  gpaTable[i][1];
        }
    }
    return GPA;
}
int main(){
    cout << "Please Enter your Semester Score." << endl;
    cout << "Your courses are predefined as 5" << endl;
    const int count = 5;
    Course* subjects[count];
    float obtainedWeightage = 0;
    float totalWeightage = 0;
    float percentage;
    cout << count << endl;
    for(int i = 0; i < count; ++i){
        subjects[i] = new Course();
        subjects[i]->input(i);   
        obtainedWeightage += subjects[i]->obtainedWeightage;
        totalWeightage += subjects[i]->totalWeightage;      
    }
    percentage = calculatePercentage(obtainedWeightage, totalWeightage);
    cout << "Your GPA is " << setprecision(2) << calculateGPA(percentage) << endl;
    // for(Course* subject : subjects){
    //     subject->display();
    // }
    return 0;
}