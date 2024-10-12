#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

string check(string& name1 , string& name2 , string& name3, string& age, string& phone , string& address , string& street , string& house) {
    regex fioPattern("[A-Z][a-z]*");
    regex agePattern("\\d{2}");
    regex phonePatterns[] = {
            regex("\\+7\\([0-9]{3}\\)[0-9]{3}-[0-9]{4}"),
            regex("\\+7[0-9]{10}"),
            regex("8[0-9]{10}"),
            regex("7[0-9]{10}"),
            regex("\\+7\\([0-9]{3}\\)-[0-9]{3}-[0-9]{2}-[0-9]{2}")
    };
    regex addressPattern("g\\.[A-Z]{3},");
    regex streetPattern("ul\\.[A-Z][a-z]*,");
    regex housePattern("d\\.[0-9]{2,}");
    bool check_phone = false;

    for (auto& pattern : phonePatterns) {
        if (regex_match(phone, pattern)) {
            check_phone = true;
            break;
        }
    }

    if (!regex_match(name1, fioPattern) ||
        !regex_match(name2, fioPattern) || !regex_match(name3, fioPattern) ||
        !regex_match(age, agePattern) ||
        !check_phone ||
        !regex_match(address, addressPattern) || !regex_match(street, streetPattern) || !regex_match(house , housePattern)) {
        return "NO";
    }
    return "YES";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int m;
    std::cin >> m;
    std::cin.ignore();
    vector<string> results;
    for (int i = 0; i < m; ++i) {
        string a;
        getline(std::cin, a);
        istringstream s(a);
        vector<std::string> questions;
        string ss;
        while (s>>ss) {
            questions.push_back(ss);
        }

        if (questions.size() == 8) {
            string name1, name2, name3, age, phone, address, street, house;
            name1 = questions[0];
            name2 = questions[1];
            name3 = questions[2];
            age = questions[3];
            phone = questions[4];
            address = questions[5];
            street = questions[6];
            house = questions[7];
            results.push_back(check(name1, name2, name3 , age, phone , address , street , house));
        } else {
            results.push_back("NO");
        }
    }


    for (auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
