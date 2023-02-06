// GSM Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include<string>
#include<map>

using namespace std;

class Phone {
public:

    bool operator < (const Phone& p) const
    { 
        return phoneName < p.phoneName;
    }
        

    Phone() {
        phoneName = "unknown";
        modelName = "unknown";
        formFactor = "unknown";
        yearOfIssue = 0;
        screenSizeInches = 0;
        price = 0;
    }

    Phone(string myphoneName, string mymodelName, string myformFactor, int myyearOfIssue, float myscreenSizeInches, float myprice)
    {
        phoneName = myphoneName;
        modelName = mymodelName;
        formFactor = myformFactor;
        yearOfIssue = myyearOfIssue;
        screenSizeInches = myscreenSizeInches;
        price = myprice;
    }


    string GetPhoneName() {
        return phoneName;
    }
    string GetPhoneModel() {
        return modelName;
    }
    string GetFormFactor()
    {
        return formFactor;
    }
    int GetYearOfIssue() {
        return yearOfIssue;
    }

    float GetScreenSizeInches() {
        return screenSizeInches;
    }

    float GetPrice() {
        return price;
    }


    string phoneName;
    string modelName;
    string formFactor;
    int yearOfIssue;
    float screenSizeInches;
    float price;
};

class FFComparator
{
public:
    bool operator()(const Phone& phone1, const Phone& phone2) {
        return phone1.formFactor < phone2.formFactor;
    }
};

class ScreemSizeComparator
{
public:
    bool operator()(const Phone& phone1, const Phone& phone2) {
        return phone1.screenSizeInches < phone2.screenSizeInches;
    }
};

class PhoneShop {
private:
    list <Phone> phones;

public:
    void AddPhone()
    {
        string phoneName;
        string modelName;
        string formFactor;
        int yearOfIssue;
        float screenSizeInches;
        float price;
        cout << "Type the name of the phone" << endl;
        getline(cin, phoneName);
        cout << "Type the name of the model" << endl;
        getline(cin, modelName);
        cout << "Type the form factor" << endl;
        getline(cin, formFactor);
        cout << "Type the year of issue" << endl;
        cin >> yearOfIssue;
        cout << "Type the screen size (in inches)" << endl;
        cin >> screenSizeInches;
        cout << "Type the price of the phone" << endl;
        cin >> price;
        phones.push_back(Phone(phoneName, modelName, formFactor, yearOfIssue, screenSizeInches, price));
    }

    void AddPhone(Phone phone)
    {
        phones.push_back(phone);
    }

    void DeletePhone()
    {
        int number;
        cout << "Which Phone do you want do delete? (choose number)\n";
        Report();
        cin >> number;
        auto it = phones.begin();
        for (int i = 0; i < number; i++)
            it++;

        phones.erase(it);
    }

    void Report()
    {
        int skip;
        int choice;
        system("CLS");
        cout << "Do you want to see them sorted:\n";
        cout << "By brand? (1)\n";
        cout << "By formFactor? (2)\n";
        cout << "By screen Size? (3)\n";
        cout << "Only the most popular brand? (4)\n";
        cout << "Top-3 screen sizes? (5)\n";
        cin >> choice;

        switch (choice) {
        case 1:
            ReportBrand();
            cout << "\n(Press 1 to continue)";
            cin >> skip;
            break;
        case 2:
            ReportFormFactor();
            break;
        case 3:
            ReportScreenSize();
            break;
        case 4:
            ReportMostPopularBrand();
            break;
        case 5:
            ReportTopThree();
            break;
        }

    }

    void ReportAll()
    {
        int i = 0;
        cout << "ID\t" << "Name\t" << "Model\t" << "FF\t" << "Year\t" << "Screen\t" << "Price\n";
        for (auto v : phones) {
            cout << i << "\t";
            cout << v.GetPhoneName() << "\t";
            cout << v.GetPhoneModel() << "\t";
            cout << v.GetFormFactor() << "\t";
            cout << v.GetYearOfIssue() << "\t";
            cout << v.GetScreenSizeInches() << "\t";
            cout << v.GetPrice() << "\n";
        }
    }

    void ReportBrand() {
        phones.sort();
        ReportAll();
    }

    void ReportFormFactor() {
        phones.sort(FFComparator());
        ReportAll();
    }

    void ReportScreenSize() {
        phones.sort(ScreemSizeComparator());

    }
    void ReportMostPopularBrand() {


    }
    void ReportTopThree() {

    }
};

class Interface {
private:
    PhoneShop myPhoneShop;

public:
    void AddPhone(Phone phone) {
        myPhoneShop.AddPhone(phone);
    }
    void Start() {

        string skip = "";
        int choice;
        bool isInShop = true;

        while (isInShop) {
            system("CLS");
            cout << "Welcome to my humble store! What do you want to do?\n";
            cout << "Add a phone? Press 1\n";
            cout << "Delete a phone ? Press 2\n";
            cout << "Get a report? Press 3\n";
            cout << "I do not like your store. Press 4\n";

            cin >> choice;
            system("CLS");

            switch (choice) {
            case 1:
                myPhoneShop.AddPhone();
                cout << "Thanks for adding that phone. I couldn't do that without you.\n(Press 1 to continue)";
                cin >> skip;

                break;
            case 2:
                myPhoneShop.DeletePhone();
                cout << "Thanks for deleting that phone. I couldn't do that without you.\n(Press 1 to continue)";
                cin >> skip;
                break;
            case 3:
                myPhoneShop.Report();
                cout << "\n(Press 1 to continue)";
                cin >> skip;

                break;
            case 4:
                isInShop = false;
                break;
            }
        }
    }

};

int main()
{
    Interface myInterface;
    myInterface.AddPhone(Phone("Samsung", "A01", "SFF", 1990, 2, 50.00));
    myInterface.AddPhone(Phone("Samsung", "A51", "SFF", 2020, 6.5, 2000.00));
    myInterface.AddPhone(Phone("Samsung", "S2", "SFF", 2018, 6.0, 3000.00));
    myInterface.AddPhone(Phone("Samsung", "A03", "SFF", 1990, 2, 50.00));
    myInterface.AddPhone(Phone("Huwawie", "2", "FFS", 1800, 5, 2000.00));
    myInterface.AddPhone(Phone("Huwawie", "65M", "FFS", 1800, 4, 2000.00));
    myInterface.AddPhone(Phone("Samsung", "S6", "SFF", 2018, 12.0, 8000.00));

    myInterface.Start();


   

}
