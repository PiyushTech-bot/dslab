#include<iostream>
using namespace std;

class Student{
private:
    string student_id;
    string name;
    string subjects[100];
    float scores[100];
    int count;
public:
    Student(string id, string n){
        student_id = id;
        name = n;
        count = 0;
    }
    void add_grade(string subject, float score){
        if(score < 0 || score > 100){
            cout << "Error! Score must be between 0 and 100."<< endl;
            return;
        
        }
        for(int i = 0; i < count; i++){
            if(subjects[i] == subject){ // to find out if there is any existing subject
                scores[i] = score;
                return;
            }
        }
        subjects[count] = subject;
        scores[count] = score;
        count++;
    }
    float calculate_average(){
        if(count == 0) return 0; // prevents divion of sum by zero 
        float sum = 0;
        for(int i = 0; i < count; i++){
            sum += scores[i];
        }
        return sum/count;
    }
    char get_grade(){
        float avg = calculate_average();
        if (avg >= 90) return 'A';
        if (avg >= 80) return 'B';
        if (avg >= 70) return 'C';
        if (avg >= 60) return 'D';
        return 'F';

    }
};
int main(){
    Student s("S101","Bob");
    s.add_grade("Math", 95);
    s.add_grade("CS", 85);
    cout << "Average: " << s.calculate_average() << endl;
    cout << "Letter Grade: " << s.get_grade() << endl;
    return 0;
}