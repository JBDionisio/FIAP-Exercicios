#include <iostream>
#include <cstring>

using namespace std;
#define SIZE_MIN 10
#define SIZE_ALL 30

int main()
{
    char result[SIZE_ALL] = "Name: ";
    char name[SIZE_MIN];
    char job[SIZE_MIN];
    cout << "Say your first name, please: " << "\n";
    cin.getline(name, SIZE_MIN);
    cout << "Hello, " << name << "\n";
    cout << "Now, write your job: " << "\n";
    cin.getline(job, SIZE_MIN);

    strcat(result, name);
    strcat(result, ", job:");
    strcat(result, job);

    cout << result << "\n";

    return 0;
}
