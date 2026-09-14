#include <iostream>
#include <cmath> // एडवांस्ड मैथ फंक्शन्स जैसे sqrt और power के लिए

using namespace std;

// फंक्शन को पहले से डिक्लेयर करना ताकि कोड साफ दिखे
void showHeader();
void showMenu();

int main() {
    showHeader();

    double num1, num2, result;
    int choice;
    char restart = 'y';

    // लूप ताकि कैलकुलेटर बार-बार चलता रहे और बंद न हो
    while (restart == 'y' || restart == 'Y') {
        showMenu();
        cout << "\nअपना विकल्प चुनें (1-6): ";
        cin >> choice;

        // अगर यूजर एग्जिट (6) चुनता है
        if (choice == 6) {
            cout << "\nकैलकुलेटर का उपयोग करने के लिए धन्यवाद, ऋषभ! मिशन 2029 जारी है... 🚀" << endl;
            break;
        }

        // सही विकल्प की चेकिंग
        if (choice >= 1 && choice <= 5) {
            cout << "पहला नंबर (Number 1) दर्ज करें: ";
            cin >> num1;
            
            // स्क्वायर रूट में दूसरे नंबर की जरूरत नहीं होती
            if (choice != 5) {
                cout << "दूसra नंबर (Number 2) दर्ज करें: ";
                cin >> num2;
            }
        } else {
            cout << "🚨 गलत इनपुट! कृपया 1 से 6 के बीच का नंबर चुनें।" << endl;
            continue;
        }

        // स्विच केस - सुपरफास्ट लॉजिक प्रोसेसिंग
        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "➔ परिणाम (Addition): " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "➔ परिणाम (Subtraction): " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "➔ परिणाम (Multiplication): " << result << endl;
                break;
            case 4:
                // एज केस हैंडलिंग: 0 से भाग देने पर कोड क्रैश होने से बचाना
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "➔ परिणाम (Division): " << result << endl;
                } else {
                    cout << "🚨 एरर: गणित में 0 से भाग देना संभव नहीं है!" << endl;
                }
                break;
            case 5:
                // एज केस हैंडलिंग: नेगेटिव नंबर का स्क्वायर रूट रोकना
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "➔ " << num1 << " का वर्गमूल (Square Root): " << result << endl;
                } else {
                    cout << "🚨 एरर: ऋणात्मक संख्या का वर्गमूल वास्तविक नहीं होता!" << endl;
                }
                break;
            default:
                cout << "कुछ गड़बड़ हुई!" << endl;
        }

        cout << "\nक्या आप कोई और कैलकुलेशन करना चाहते हैं? (y/n): ";
        cin >> restart;
        cout << "-----------------------------------------" << endl;
    }

    return 0;
}

void showHeader() {
    cout << "=========================================" << endl;
    cout << "   RISHAV'S SMART TECH CALCULATOR v1.0   " << endl;
    cout << "=========================================" << endl;
}

void showMenu() {
    cout << "\n--- ऑपरेशंस मेनू ---" << endl;
    cout << "1. जोड़ (Addition [+])" << endl;
    cout << "2. घटाव (Subtraction [-])" << endl;
    cout << "3. गुणा (Multiplication [*])" << endl;
    cout << "4. भाग (Division [/])" << endl;
    cout << "5. वर्गमूल (Square Root [√])" << endl;
    cout << "6. बाहर निकलें (Exit)" << endl;
}