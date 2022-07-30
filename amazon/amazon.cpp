#include <iostream>
#include <string>
#include <set>

using namespace std;

//search for the clossest common boss from two employees
//from some huge corporation


struct employee{
    long   ID_;
    string name_;
    employee const *manager_;
    set <employee>  empSet_;
    static long id_cnt;
    
    employee(string const &name="", employee const *manager=nullptr)
        :ID_(id_cnt++), name_(name), manager_(manager){
    }
    
};

long employee::id_cnt=0;

employee const *searchClosestCommonManager(employee const &a, employee const &b){
    for (employee const *a_ptr=&a; a_ptr->manager_!=nullptr; a_ptr=a_ptr->manager_){
        for (employee const *b_ptr=&b; b_ptr->manager_!=nullptr; b_ptr=b_ptr->manager_){
            if (a_ptr->manager_->ID_==b_ptr->manager_->ID_) return a_ptr->manager_;
        }
    }

    return nullptr;
}

int main(){
    employee    ceo("ceo");
    employee    boss2("boss2", &ceo);
    employee    boss3("boss3", &ceo);
    employee    boss4("boss4", &boss2);
    employee    boss5("boss5", &boss2);
    employee    boss6("boss6", &boss3);
    employee    boss7("boss7", &boss3);
    employee    e1("e1", &boss4);
    employee    e2("e2", &boss5);
    employee    e3("e3", &boss5);
    
    const employee    *found=searchClosestCommonManager(e1, e2);
    cout<<"common clossest boss from  e1, e2: "<<found->name_<<endl;
    return 0;
}
