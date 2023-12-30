// All the three tasks will be updated one by one in Git Commits

#include <iostream>
#include <string>
#include <vector>
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

    
    char getContent() const {
        return content;
    }

    
    bool isValidSack() const {
        if ((content == 'C' && weight >= 24.9 && weight <= 25.1) ||
            ((content == 'G' || content == 'S') && weight >= 49.9 && weight <= 50.1)) {
            return true;
        }
        return false;
    }

    
    double getRegularPrice() const {
        if (content == 'C') {
            return 3.0;
        } else if (content == 'G' || content == 'S') {
            return 2.0;
        }
        return 0.0; 
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

class Order {
private:
    vector<Sack> sacks;

public:
    
    void addSack(const Sack& sack) {
        sacks.push_back(sack);
    }

    
    void checkOrder() const {
        double totalWeight = 0.0;
        int rejectedSacks = 0;
        double regularPrice = 0.0;
        int specialPackCount = 0;

        cout << "Order Details:\n";

        for (const Sack& sack : sacks) {
            sack.displaySack();

            if (!sack.isValidSack()) {
                rejectedSacks++;
            } else {
                totalWeight += sack.isValidSack() ? sack.isValidSack() : 0;
                regularPrice += sack.getRegularPrice();

                
                if (sack.getContent() == 'C') {
                    
                    int sandCount = 0;
                    int gravelCount = 0;

                    for (const Sack& s : sacks) {
                        if (s.isValidSack()) {
                            if (s.getContent() == 'S') {
                                sandCount++;
                            } else if (s.getContent() == 'G') {
                                gravelCount++;
                            }
                        }
                    }

                    if (sandCount >= 2 && gravelCount >= 2) {
                        specialPackCount++;
                        regularPrice -= sack.getRegularPrice(); // Deduct regular price
                    }
                }
            }
        }

           cout << "Total Weight of the Order: " << totalWeight << " kilograms\n";
           cout << "Number of Rejected Sacks: " << rejectedSacks << "\n";
           cout << "Regular Price for the Order: $" << regularPrice << "\n";

        if (specialPackCount > 0) {
            double discountPrice = regularPrice - (specialPackCount * 10.0);
                cout << "Special Pack(s) Applied: " << specialPackCount << "\n";
                cout << "New Price for the Order: $" << discountPrice << "\n";
                cout << "Amount Saved: $" << regularPrice - discountPrice << "\n";
        }
    }
};

int main() {
    Order customerOrder;

    
    int numSacks;
    cout << "Enter the number of sacks for the order: ";
    cin >> numSacks;

    for (int i = 0; i < numSacks; ++i) {
        Sack sack;

        
        double weight;
        cout << "\nEnter the weight of the sack " << i + 1 << " in kilograms: ";
        cin >> weight;
        sack.setWeight(weight);

        
        char content;
        cout << "Enter the content of the sack " << i + 1 << " (C for cement, G for gravel, S for sand): ";
        cin >> content;
        sack.setContent(toupper(content)); // Convert to uppercase for case insensitive checking

        
        customerOrder.addSack(sack);
    }

    
    customerOrder.checkOrder();

    return 0;
}
