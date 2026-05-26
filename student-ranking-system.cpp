#include <iostream>
#include <string>
using namespace std;

class Result
{
private:
    int roll;
    string name;
    int marks[5];
    int total;
    float percentage;

public:
    Result(int r, const string &n, int m[5])
        : roll(r), name(n), total(0), percentage(0.0f)
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
            total += marks[i];
        }
        percentage = total / 5.0f;
    }

    float getPercentage() const
    {
        return percentage;
    }

    void displayResult() const
    {
        cout << "\nRoll Number: " << roll << endl;
        cout << "Student Name: " << name << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
        }
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main()
{
    int n;

    cout << "Enter Number of Students: ";
    cin >> n;

    Result** students = new Result*[n];

    // Input Student Details
    for (int i = 0; i < n; i++)
    {
        int roll;
        string name;
        int marks[5];
        int totalCheck = 0; // Temporary tracker to catch the zero condition early

        cout << "\nEnter Details of Student " << i + 1 << endl;

        cout << "Roll Number: ";
        cin >> roll;

        cin.ignore(); // Clears buffer after roll number

        cout << "Student Name: ";
        getline(cin, name);

        cout << "Enter Marks of 5 Subjects:\n";
        for (int j = 0; j < 5; j++)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[j];
            totalCheck += marks[j];
        }

        // --- Visual Exception Handling ---
        if (totalCheck == 0)
        {
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            cout << "\nException: All Subject Marks are 0 for " << name;
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        }

        // Create the student object anyway to keep array tracking intact
        students[i] = new Result(roll, name, marks);

        // Only display the summary if they didn't trigger the 0 marks exception
        if (totalCheck > 0)
        {
            cout << "\n--- Instant Summary for Student " << i + 1 << " ---";
            students[i]->displayResult();
        }
    }

    // Sorting by Percentage
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (students[j]->getPercentage() > students[i]->getPercentage())
            {
                Result* temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Display Top Students
    cout << "\n\n=========== TOP STUDENTS (RANKED) ===========\n";
    int top = (n < 5) ? n : 5;
    for (int i = 0; i < top; i++)
    {
        // Don't print ranked cards for students with 0% 
        if (students[i]->getPercentage() > 0) 
        {
            cout << "\nRank " << i + 1;
            students[i]->displayResult();
        }
    }

    // Free Memory
    for (int i = 0; i < n; i++)
    {
        delete students[i];
    }
    delete[] students; 

    return 0;
}
