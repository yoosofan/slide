// https://codereview.stackexchange.com/a/38954
// https://codereview.stackexchange.com/questions/38879/parsing-text-file-in-c
// https://www.codespeedy.com/cpp-program-to-create-a-text-file-open-and-read-a-particular-line/
// http://www.cplusplus.com/forum/beginner/11304/
// https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus
// https://www.geeksforgeeks.org/encrypt-and-decrypt-text-file-using-cpp/
// https://coderedirect.com/questions/119182/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
// https://www.codegrepper.com/code-examples/cpp/getline+from+file+c%2B%2B
// https://www.educba.com/c-plus-plus-getline/
// https://www.codegrepper.com/code-examples/cpp/getline+from+file+c%2B%2B
// https://stackoverflow.com/questions/43573658/c-how-to-read-a-line-of-text-from-file-to-char-array
// https://www.geeksforgeeks.org/getline-string-c/

struct Person
{
    std::string name;
    std::string age;
    std::string salary;
    std::string hoursWorked;
    std::string randomText;

    friend std::istream& operator>>(std::istream& str, Person& data)
    {
        std::string line;
        Person tmp;
        if (std::getline(str,line))
        {
            std::stringstream iss(line);
            if ( std::getline(iss, tmp.name, ':')        && 
                 std::getline(iss, tmp.age, '-')         &&
                 std::getline(iss, tmp.salary, ',')      &&
                 std::getline(iss, tmp.hoursWorked, '[') &&
                 std::getline(iss, tmp.randomText, ']'))
             {
                 /* OK: All read operations worked */
                 data.swap(tmp);  // C++03 as this answer was written a long time ago.
             }
             else
             {
                 // One operation failed.
                 // So set the state on the main stream
                 // to indicate failure.
                 str.setstate(std::ios::failbit);
             }
        }
        return str;
    }
    void swap(Person& other) throws() // C++03 as this answer was written a long time ago.
    {
        swap(name,        other.name);
        swap(age,         other.age);
        swap(salary,      other.salary);
        swap(hoursWorked, other.hoursWorked);
        swap(randomText,  other.randomText)
    }
};
