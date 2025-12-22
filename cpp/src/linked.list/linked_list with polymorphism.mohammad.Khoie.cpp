#include <iostream>
#include <cstdlib>
using namespace std;
class person{
    protected:
    char name[100];
    char family[100];
    public:
    int calc_lenth_str(char* a){
        int count;
        for(count=0;a[count];count++);
        return count;
    }
    void copy_str(char* a, const char* b){
        int i;
        for(i=0;b[i] && i<100;i++)
            a[i]=b[i];
        a[i]='\0';
    }
    bool compare_str(char* a, char* b){
        if(calc_lenth_str(a)!=calc_lenth_str(b))
            return false;
        else{
            for(int i=0;a[i] && b[i];i++){
                if(a[i]!=b[i]){
                    return false;
                }
            }
            return true;     
        }
    }
    person(const char* _name=0,const char* _family=0){
        copy_str(name,_name);copy_str(family,_family);
        
    }
    virtual void print(){
        cout<<"name:"<<endl;
        cout<<name<<endl;
        cout<<"family:"<<endl;
        cout<<family<<endl;
    }
    virtual bool compare_person(person* p1){
        if(compare_str(name,p1->name) && compare_str(family,p1->family))
            return true;
        else
            return false;
    }
    char* get_name(){return name;}
    char* get_family(){return family;}
    virtual char* get_student_id(){return name;}
};
class student :public person {
    protected:
    char* student_id;
    public:
    student(const char* _name="",const char* _family="",const char* _studentid=""):person(_name,_family){
        copy_str(student_id,_studentid);
    }
    virtual void print(){
        person::print();
        cout<<"student_id:"<<endl;
        cout<<student_id<<endl;
    }
    virtual bool compare_person(person* p1){
        if(person::compare_person(p1) && person::compare_str(student_id,p1->get_student_id()))
            return true;
        else
            return false;
    }
    virtual char* get_student_id(){return student_id;}
};
class node{
    friend class linked_list;
    person* p;
    node* next;
    public:
    node(person* _p){
        p=_p;
        next=0;
    }
};
class linked_list{
    node* head;
    public:
    linked_list(){
        head=0;
    }
    void append_last( person* _p){
        if(head){
            node* pa=head;
            for(;pa->next;pa=pa->next);
            pa->next=new node(_p);
        }
        else
        {
            head=new node(_p);
        }
    }
    void append_first(person* _p=0){
        node* temp=new node(_p);
        if(head){
            temp->next=head;
            head=temp;
        }
        else{
            head=temp;
        }
    }
    void print_linked_list(){
        for(node* pa=head;pa;pa=pa->next)
            (pa->p)->print();
    }
    int lenth_linked_list(){
        node* pa=head;
        int count=0;
        for(;pa;pa=pa->next,count++);
        return count;
    }
    void delete_by_data( person* _p){
        node *pa,*pb;
        pa=head;
        for(;pa && !(_p->compare_person(pa->p));pa=pa->next)
            pb=pa;
        if(pa==head){
            head=pa->next;
        }
        else if(!pa){
            pb->next=0;
        }
        else{
            pb->next=pa->next;
        }

    }
};
int main(){
    person p1("javad","mobini");
    student s1("farid","khooie","9421170013");
    student s2("mohsen","safari","932116789");
    linked_list l1;
    l1.append_last(&s1);
    l1.append_first(&p1);
    l1.append_last(&s2);
    l1.print_linked_list();
    l1.delete_by_data(&s2);
    l1.print_linked_list();
    return 0;
}
