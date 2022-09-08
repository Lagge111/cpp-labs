#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float first_price{};
    float last_price{};
    float stride{};
    float tax_percent{};
    float tax{};    
    float current_price{};
    
    cout << "INPUT PART\n" << setfill('=') << setw(11) << "Enter first price: ";
    cin >> first_price;
    while (first_price < 0) {
        cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << "Enter first price: ";
        cin >> first_price;
    }

    cout << "Enter last price " << setfill(' ') << setw(2) << ": ";
    cin >> last_price;
    while (last_price <= first_price) {
        cerr << "ERROR: Last price must be higher than first price" << endl;
        cout << "Enter last price " << setw(2) << ": ";
        cin >> last_price;
    }

    cout << "Enter stride " << setw(6) << ": ";
    cin >> stride;
    while (stride < 0.01f) {
        cerr << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride " << setw(6) << ": ";
        cin >> stride;
    }

    cout << "Enter tax percent: ";
    cin >> tax_percent;
    while (tax_percent < 0) {
        cerr << "ERROR: Tax percent must be at least 0 (zero)" << endl;
        cout << "Enter tax percent: ";
        cin >> tax_percent;
    }

    cout << "\nTAX TABLE\n" << setfill('=') << right << setw(10) << "\n";
    cout << setfill(' ') << setw(12) << "Price" << setw(17) << "Tax" << setw(21) << "Price with tax" << "\n" << setfill('-') << setw(51) << "\n";

    cout << setfill(' ') << fixed << setprecision(2); 
  
    int rows = ((last_price - first_price) / stride) + 1;
    current_price = first_price;

    for (int i{0}; i <= rows; i++) {
        tax = current_price * (tax_percent * 0.01);
        cout << setw(12) << current_price << setw(17) << tax << setw(21) << tax + current_price << endl;
        current_price = (first_price + (stride * i));
    }

    return 0;

}