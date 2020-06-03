#include <iostream>
#include <string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    free_throws one = {"zhangsan", 13, 14};
    free_throws two = {"lisi", 10, 16};
    free_throws three = {"wangwu", 7, 9};
    free_throws four = {"zhaoliu", 5, 9};
    free_throws five = {"lurenjia", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    // use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    // use return value in assignment
    dup = accumulate(team, five);
    std::cout << "Display team:\n";
    display(team);
    std::cout << "Display dup after assignment:\n";
    display(dup);
    std::cout << "Display address &dum = " << &dup << " &team = " << &team << std::endl;
    set_pc(four);
    // ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Dispalay dup after ill-advised assignment:\n";
    display(dup);
    display(team);
    std::cout << "Display address &dum = " << &dup << " &four = " << &four << std::endl;
    return 0;
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << " Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}