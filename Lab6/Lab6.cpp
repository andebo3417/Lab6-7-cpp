#include "Group.h"
#include <vector>
#include <algorithm>

bool comp(List*, List*);

bool comp_name(List*);

Full_name desiredName;

int main() {
    vector<List*> Lists;
    vector<List*>::iterator it;
    Teacher teacher;
    string number = "";
    string answer = "";
    bool flag = false;
    bool leave = false;
    int curList = 0;
    Lists.push_back(new List(0));
    
    while (leave == false) {
        do {
            flag = false;
            cout << "Choose one option:" << endl;
            cout << "[1] - Add student to the Lists[curList]" << endl;
            cout << "[2] - Delete student from Lists[curList]" << endl;
            cout << "[3] - Print Lists[curList] of students" << endl;
            cout << "[4] - Calculate overall rating of a student" << endl;
            cout << "[5] - Change info about student" << endl;
            cout << "[6] - Create new group from this Lists[curList]/group" << endl;
            cout << "[7] - Create New list" << endl;
            cout << "[8] - Switch list" << endl;
            cout << "[9] - Found student by name" << endl;
            cout << "[10] - Sort lists of students by size in descending order" << endl;
            cout << "[0] - Exit" << endl << endl << ">";
            cin >> answer;
            try {
                if (stoi(answer) >= 0 && stoi(answer) < 11) {
                    flag = true;
                }
                else {
                    cout << "\nChosen number is out of range.\n\n";
                    system("pause");
                    system("cls");
                }
            }
            catch (invalid_argument ex) {
                flag = false;
                cout << "\nIncorrect input.\n\n";
                system("pause");
                system("cls");
            }
            catch (out_of_range ex) {
                flag = false;
                cout << "\nNumber is too big or too small.\n\n";
                system("pause");
                system("cls");
            }
        } while (flag == false);

        switch (stoi(answer)) {
        case 1:
            Lists[curList]->append();
            system("pause");
            system("cls");
            break;
        case 2:
            try {
                Lists[curList]->print();
            }
            catch (length_error e) {
                cout << e.what();
                system("pause");
                system("cls");
                break;
            }
            cout << "\nInput number of a student you want to delete:\n>";
            cin >> number;
            try {
                if (stoi(number) > 0 && stoi(number) <= Lists[curList]->length())
                    if (Lists[curList]->remove(stoi(number) - 1) == 0)
                        cout << "\nStudent was deleted.\n\n";
                else
                    cout << "\nNumber of student is out of range.\n";
            }
            catch (invalid_argument ex) {
                cout << "\nIncorrect input.\n\n";
            }
            catch (out_of_range ex) {
                cout << "\nNumber is too big or too small.\n\n";
            }
            catch (length_error e) {
                cout << e.what();
            }
            system("pause");
            system("cls");
            break;
        case 3:
            try {
                Lists[curList]->print();
            }
            catch (length_error e) {
                cout << e.what();
            }
            system("pause");
            system("cls");
            break;
        case 4:
            try {
                Lists[curList]->print();
                cout << "\nInput number of a student:\n>";
                cin >> number;
                if (stoi(number) > 0 && stoi(number) <= Lists[curList]->length())
                    cout << "\nAverage rating of a student is: " << Lists[curList]->list[stoi(number) - 1].average_marks->get_average_rating() << endl;
                else
                    cout << "\nNumber of student is out of range.\n";
            }
            catch (invalid_argument ex) {
                cout << "\nIncorrect input.\n\n";
            }
            catch (out_of_range ex) {
                cout << "\nNumber is too big or too small.\n\n";
            }
            catch (length_error e) {
                cout << e.what();
            }
            system("pause");
            system("cls");
            break;
        case 5:
            try {
                Lists[curList]->print();
                cout << "\nInput number of a student you want to change:\n>";
                cin >> number;
                if (stoi(number) > 0 && stoi(number) <= Lists[curList]->length()) {
                    cout << "\n[1] - Name" << endl;
                    cout << "[2] - Gender" << endl;
                    cout << "[3] - Marks" << endl;
                    cout << "[4] - Adress" << endl;
                    cout << "[5] - Contacts" << endl;
                    cout << "[0] - Exit" << endl;
                    cout << "\nInput number of a field you want to change:\n>";
                    cin >> answer;

                    flag = false;
                    if (stoi(answer) >= 0 && stoi(answer) <= 5) {
                        switch (answer[0])
                        {
                        case '1':
                            if (Lists[curList]->list[stoi(number) - 1].full_name->input_full_name() == 0) flag = true;
                            break;
                        case '2':
                            if (Lists[curList]->list[stoi(number) - 1].input_gender() == 0) flag = true;
                            break;
                        case '3':
                            if (Lists[curList]->list[stoi(number) - 1].average_marks->input_average_marks() == 0) flag = true;
                            break;              
                        case '4':               
                            if (Lists[curList]->list[stoi(number) - 1].adress->input_adress() == 0) flag = true;
                            break;              
                        case '5':               
                            if (Lists[curList]->list[stoi(number) - 1].contacts->input_contacts() == 0) flag = true;
                            break;
                        default:
                            flag = false;
                            break;
                        }
                        if (flag == true) {
                            cout << "\nData was changed.\n";
                        }
                        else {
                            cout << "\nNothing was changed.\n";
                        }
                    }
                }
                else {
                    cout << "\nNumber of student is out of range.\n";
                }
            }
            catch (invalid_argument ex) {
                cout << "\nIncorrect input.\n\n";
            }
            catch (out_of_range ex) {
                cout << "\nNumber is too big or too small.\n\n";
            }
            catch (length_error e) {
                cout << e.what();
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (Lists[curList]->length() > 0) {
                flag = true;
                cout << "\nPlease input group name:\n>";
                cin >> answer;
                if (answer.length() <= 0) {
                    flag = false;
                    cout << "\nIncrorrect input.\n\n";
                }
                if (teacher.input_data() != 0) flag = false;
                if (flag == true) {
                    try {
                        Lists[curList] = new Group<int>(Lists[curList], stoi(answer), teacher);
                        cout << "\nGroup was created with template int.\n\n";
                    }
                    catch (invalid_argument ex) {
                        Lists[curList] = new Group<string>(Lists[curList], answer, teacher);
                        cout << "\nGroup was created with template string.\n\n";
                    }
                    catch (...) {
                        flag = false;
                    }
                }
                if (flag == false)
                    cout << "\nGroup was not created.\n\n";
            }
            else {
                cout << "\nList is empty.\n\n";
            }
            system("pause");
            system("cls");
            break;
        case 7:
            Lists.push_back(new List(0));
            curList++;
            cout << "\nNew List was created and is currently selected.\n\n";
            system("pause");
            system("cls");
            break;
        case 8:
            try {
                cout << "Enter number of list (1 - " << Lists.size() << ")\n>";
                cin >> number;
                if (stoi(number) - 1 == curList) {
                    cout << "\nThis list is already selected.\n\n";
                }
                else if (stoi(number) > 0 && stoi(number) <= Lists.size()) {
                    curList = stoi(number) - 1;
                }
                else {
                    cout << "\nNumber of list is out of range.\n\n";
                }
            }
            catch (invalid_argument ex) {
                cout << "\nIncorrect input.\n\n";
            }
            catch (out_of_range ex) {
                cout << "\nNumber is too big or too small.\n\n";
            }
            system("pause");
            system("cls");
            break;
        case 9:
            desiredName.input_full_name();
            it = find_if(Lists.begin(), Lists.end(), comp_name);
            if (it == Lists.end()) {
                cout << "\nDesired student was not found.\n\n";
            }
            else cout << "\nDesired student is in list " << it - Lists.begin() + 1 << endl << endl;
            system("pause");
            system("cls");
            break;
            break;
        case 10:
            sort(Lists.begin(), Lists.end(), comp);
            cout << "\nLists were sorted.\n\n";
            system("pause");
            system("cls");
            break;
            break;
        default:
            leave = true;
            break;
        }

    }
    for (List* var : Lists) {
        if (var != NULL) {
            var->clear();
            delete var;
        }
    }
    
}

bool comp(List* list1, List* list2) {
    return list1->length() > list2->length();
}

bool comp_name(List* list) {
    for (int i = 0; i < list->length(); i++) {
        if (list->list[i].full_name->get_full_name() == desiredName.get_full_name()) return true;
    }
    return false;
}