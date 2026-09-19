#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// क्विज के सवाल का ढांचा (OOPs Struct)
struct Question {
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctOption;
};

// फ़ंक्शन 01: फ़ाइल से सवालों को लोड करना (Data Driven Logic)
vector<Question> loadQuestions() {
    vector<Question> bank;
    ifstream file("questions.txt");
    
    // अगर फ़ाइल नहीं है, तो ये डिफ़ॉल्ट सवाल लोड हो जाएंगे (ताकि ऐप क्रैश न हो)
    if (!file) {
        bank.push_back({"C++ में 'cout' का क्या काम है?", "A. Input लेना", "B. Output दिखाना", "C. Memory खाली करना", "D. एरर ढूंढना", 'B'});
        bank.push_back({"DSA में Arrays का इंडेक्स कहाँ से शुरू होता है?", "A. 1", "B. -1", "C. 0", "D. कहीं से भी", 'C'});
        return bank;
    }

    string q, a, b, c, d;
    char ans;
    // फ़ाइल से व्यवस्थित तरीके से डेटा रीड करना
    while (getline(file, q) && getline(file, a) && getline(file, b) && getline(file, c) && getline(file, d) && (file >> ans)) {
        file.ignore(); // अगले सवाल के लिए बफर साफ करना
        bank.push_back({q, a, b, c, d, ans});
    }
    
    file.close();
    return bank;
}

int main() {
    cout << "==================================================" << endl;
    cout << "      🔥 ऋषभ का एआई-प्रूफ क्विज एप्लीकेशन 🔥     " << endl;
    cout << "==================================================" << endl;

    vector<Question> quizAnswers = loadQuestions();
    int totalQuestions = quizAnswers.size();
    int score = 0;
    char userAns;

    cout << "कुल सवाल: " << totalQuestions << " | सही जवाब: +4 | गलत जवाब: -1\n" << endl;

    for (int i = 0; i < totalQuestions; ++i) {
        cout << "सवाल " << (i + 1) << ": " << quizAnswers[i].questionText << endl;
        cout << quizAnswers[i].optionA << endl;
        cout << quizAnswers[i].optionB << endl;
        cout << quizAnswers[i].optionC << endl;
        cout << quizAnswers[i].optionD << endl;
        
        cout << "अपना सही विकल्प चुनें (A, B, C, D): ";
        cin >> userAns;
        userAns = toupper(userAns); // छोटे अक्षर को भी कैपिटल में बदलना

        if (userAns == quizAnswers[i].correctOption) {
            cout << "✅ बिल्कुल सही जवाब! (+4 अंक)\n" << endl;
            score += 4;
        } else {
            cout << "❌ गलत जवाब! सही विकल्प " << quizAnswers[i].correctOption << " था। (-1 अंक)\n" << endl;
            score -= 1;
        }
    }

    cout << "==================================================" << endl;
    cout << "               🎯 फाइनल स्कोरकार्ड               " << endl;
    cout << "==================================================" << endl;
    cout << "ऋषभ भाई, आपका कुल स्कोर है: " << score << " / " << (totalQuestions * 4) << endl;
    
    double percentage = (double)score / (totalQuestions * 4) * 100;
    if (percentage >= 70) {
        cout << "🔥 प्रदर्शन: शानदार भाई! पैकेज पक्का है।" << endl;
    } else {
        cout << "⏳ प्रदर्शन: थोड़ा और रिवीजन की ज़रूरत है भाई!" << endl;
    }
    cout << "==================================================" << endl;

    return 0;
}

