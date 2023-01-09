#include "Group.h"


int main() {
    List* list = new List(0);
    Teacher teacher;
    string number = "";
    string answer = "";
    bool flag = false;
    bool leave = false;
    
    while (leave == false) {
        do {
            flag = false;
            cout << "Choose one option:" << endl;
            cout << "[1] - Add student to the list" << endl;
            cout << "[2] - Delete student from list" << endl;
            cout << "[3] - Print list of students" << endl;
            cout << "[4] - Calculate overall rating of a student" << endl;
            cout << "[5] - Change info about student" << endl;
            cout << "[6] - Create new group from this list/group" << endl;
            cout << "[0] - Exit" << endl << endl << ">";
            cin >> answer;
            try {
                if (stoi(answer) >= 0 && stoi(answer) < 7) {
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

        switch (answer[0]) {
        case '1':
            list->append();
            system("pause");
            system("cls");
            break;
        case '2':
            try {
                list->print();
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
                if (stoi(number) > 0 && stoi(number) <= list->length())
                    if (list->remove(stoi(number) - 1) == 0)
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
        case '3':
            try {
                list->print();
            }
            catch (length_error e) {
                cout << e.what();
            }
            system("pause");
            system("cls");
            break;
        case '4':
            try {
                list->print();
                cout << "\nInput number of a student:\n>";
                cin >> number;
                if (stoi(number) > 0 && stoi(number) <= list->length())
                    cout << "\nAverage rating of a student is: " << list->list[stoi(number) - 1].average_marks->get_average_rating() << endl;
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
        case '5':
            try {
                list->print();
                cout << "\nInput number of a student you want to change:\n>";
                cin >> number;
                if (stoi(number) > 0 && stoi(number) <= list->length()) {
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
                            if (list->list[stoi(number) - 1].full_name->input_full_name() == 0) flag = true;
                            break;
                        case '2':
                            if (list->list[stoi(number) - 1].input_gender() == 0) flag = true;
                            break;
                        case '3':
                            if (list->list[stoi(number) - 1].average_marks->input_average_marks() == 0) flag = true;
                            break;
                        case '4':
                            if (list->list[stoi(number) - 1].adress->input_adress() == 0) flag = true;
                            break;
                        case '5':
                            if (list->list[stoi(number) - 1].contacts->input_contacts() == 0) flag = true;
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
        case '6':
            if (list->length() > 0) {
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
                        list = new Group<int>(list, stoi(answer), teacher);
                        cout << "\nGroup was created with template int.\n\n";
                    }
                    catch (invalid_argument ex) {
                        list = new Group<string>(list, answer, teacher);
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
        default:
            leave = true;
            break;
        }

    }
    if (list != NULL) {
        list->clear();
        delete list;
    }
}