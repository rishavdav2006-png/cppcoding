#include <iostream>
#include <fstream>  // फ़ाइल हैंडलिंग के लिए (डेटा परमानेंट सेव करने के लिए)
#include <string>

using namespace std;

// स्टूडेंट की क्लास - OOPs का असली इस्तेमाल
class Student {
public:
    int rollNo;
    string name;
    string branch;

    // डेटा इनपुट लेने का फंक्शन
    void acceptData() {
        cout << "\n-----------------------------------" << endl;
        cout << "रोल नंबर (Roll No) दर्ज करें: ";
        cin >> rollNo;
        cin.ignore(); // इनपुट बफर साफ करने के लिए
        cout << "विद्यार्थी का नाम (Name) दर्ज करें: ";
        getline(cin, name);
        cout << "ब्रांच (जैसे EE, CSE) दर्ज करें: ";
        getline(cin, branch);
    }
};

// फ़ंक्शन 01: डेटा को हार्ड डिस्क की फ़ाइल में सेव करना (Write Operations)
void addStudentToFile() {
    Student s;
    s.acceptData();

    // ios::app का मतलब है नया डेटा पुरानी फ़ाइल के नीचे जुड़ता जाएगा (Append)
    ofstream outFile("students_database.txt", ios::app);
    if (!outFile) {
        cout << "❌ डेटाबेस फ़ाइल खोलने में एरर आया!" << endl;
        return;
    }

    // फ़ाइल में डेटा राइट करना (हार्ड डिस्क में सेव हो रहा है)
    outFile << s.rollNo << "," << s.name << "," << s.branch << "\n";
    outFile.close();
    cout << "🎉 डेटा 'students_database.txt' फ़ाइल में परमानेंटली लॉक हो गया है!" << endl;
}

// फ़ंक्शन 02: फ़ाइल से डेटा रीड करके स्क्रीन पर दिखाना (Read Operations)
void viewAllStudents() {
    ifstream inFile("students_database.txt");
    if (!inFile) {
        cout << "\n🎉 डेटाबेस खाली है! अभी तक कोई रिकॉर्ड सेव नहीं हुआ है।" << endl;
        return;
    }

    cout << "\n================= कॉलेज स्टूडेंट रिकॉर्ड =================" << endl;
    string line;
    // फ़ाइल से एक-एक लाइन रीड करना
    while (getline(inFile, line)) {
        // बेसिक स्ट्रिंग पार्सिंग (Comma से डेटा अलग करना)
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            string rNo = line.substr(0, pos1);
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string branch = line.substr(pos2 + 1);

            cout << "🔹 [Roll]: " << rNo << " | [Name]: " << name << " | [Branch]: " << branch << endl;
        }
    }
    cout << "==========================================================" << endl;
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n=== 🏫 KIIT स्टूडेंट डेटाबेस मैनेजमेंट ===" << endl;
        cout << "1. नया स्टूडेंट रिकॉर्ड जोड़ें (Add Student)" << endl;
        cout << "2. सभी रिकॉर्ड देखें (View All Students)" << endl;
        cout << "3. ऐप से बाहर निकलें (Exit)" << endl;
        cout << "अपना विकल्प चुनें (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudentToFile(); break;
            case 2: viewAllStudents(); break;
            case 3: cout << "\nबाय ऋषभ भाई! डेटा सेफ है, कल मिलते हैं।" << endl; break;
            default: cout << "\n❌ गलत विकल्प! कृपया 1, 2 या 3 चुनें।" << endl;
        }
    } while (choice != 3);

    return 0;
}