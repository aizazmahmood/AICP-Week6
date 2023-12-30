// All the three tasks will be updated one by one in Git Commits

#include <iostream>
#include <string>
using namespace std;

class Sack {
private:
    double weight;
    char content;

public:
    Sack() : weight(0.0), content('\0') {}

    
    void setWeight(double w) {
        weight = w;
    }

    
    void setContent(char c) {
        content = c;
    }

   
    bool isValidSack() const {
        if ((content == 'C' && weight >= 24.9 && weight <= 25.1) ||
            ((content == 'G' || content == 'S') && weight >= 49.9 && weight <= 50.1)) {
            return true;
        }
        return false;
    }

    
    void displaySack() const {
        if (isValidSack()) {
              cout << "Accepted Sack:\n";
              cout << "Content: " << content << "\n";
              cout << "Weight: " << weight << " kilograms\n";
        } else {
              cout << "Rejected Sack:\n";
              cout << "Reason(s): ";
            if (!(content == 'C' || content == 'G' || content == 'S')) {
                   cout << "Invalid content. ";
            }
            if (!((content == 'C' && weight >= 24.9 && weight <= 25.1) ||
                  ((content == 'G' || content == 'S') && weight >= 49.9 && weight <= 50.1))) {
                   cout << "Invalid weight.";
            }
               cout << "\n";
        }
    }
};

int main() {
    Sack sack;

    double weight;
    cout << "Enter the weight of the sack in kilograms: ";
    cin >> weight;
    sack.setWeight(weight);

    
    char content;
    cout << "Enter the content of the sack (C for cement, G for gravel, S for sand): ";
    cin >> content;
    sack.setContent(toupper(content)); // Convert to uppercase to ensure case insensitive checking

    
    sack.displaySack();

    return 0;
}
