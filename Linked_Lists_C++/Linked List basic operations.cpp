#include<iostream>
#include<vector>
using namespace std;

class Student
{
public:
  string name;
  int id;
  Student *link;
  Student(){}
  Student(string n,int i)
  {
      this->name=n;
      this->id=i;
      link=NULL;
  }
};

class LinkedList
{
  public:
    Student *head=NULL;
    LinkedList()
    {
        this->head=NULL;
    }
    int Count();
    void InsertAtBeg(Student);
    void DeleteStudent(string);
    void InsertAtPos(int,Student);
    void Reverse();
    void Print();
    void Rreverse();
    void VectorToList(vector<pair<string,int>>);
};

void LinkedList::InsertAtBeg(Student s)
{
    Student* temp=new Student();
    temp->name=s.name;
    temp->id=s.id;
    temp->link=head;
    head=temp;
}

void LinkedList::InsertAtPos(int pos,Student s)
{
    int cnt=1;
    Student *temp=head;
    Student *prev=NULL;
    while(temp)
    {
        if(cnt==pos)
        {
            Student *t=new Student(s.name,s.id);
            t->link=temp;
            if(prev)
                prev->link=t;
            else
            {
                head=t;
            }
            cout<<s.name<<" successfully added\n";
            return;
        }
        cnt++;
        prev=temp;
        temp=temp->link;
    }
    if(pos==cnt)
    {
        Student *t=new Student(s.name,s.id);
            t->link=NULL;
            if(prev)
                prev->link=t;
            else
            {
                head=t;
            }
            cout<<s.name<<" successfully added\n";
            return;
    }
    cout<<"pos out of range\n";
}

void LinkedList::DeleteStudent(string s)
{
    Student *temp=head;
    Student *prev=NULL;
    while(temp)
    {
        if(temp->name==s)
        {
            if(prev)
            {
                prev->link=temp->link;    
            }
            else
            {
                head=temp->link;
            }
            temp->link=NULL;
            delete temp;
            cout<<s<<" deleted\n";
            return;
        }
        prev=temp;
        temp=temp->link;
    }
    cout<<"element not found\n";
}

void LinkedList::Reverse()
{
    Student *current=head;
    Student *prev=NULL, *next=NULL;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    if(head==NULL)
    {
        cout<<"\nempty list\n";
        return;
    }
    head=prev;
    cout<<"\n list reversed\n";
    return;
}

void LinkedList::VectorToList(vector<pair<string,int>> v)
{
    for(auto x:v)
    {
        Student *temp=new Student();
        temp->name=x.first;
        temp->id=x.second;
        InsertAtBeg(*temp);
    }
}

Student *RevUtil(Student *t,Student *&ans)
{
    if(t->link==NULL)
    {
        ans=t;
        return t;
    }
    Student *lastOfReverse=RevUtil(t->link,ans);
    t->link=NULL;
    lastOfReverse->link=t;
    return t;
}

void LinkedList::Rreverse()
{
    Student *ans;
    RevUtil(head,ans);
    head=ans;
}

void LinkedList::Print()
{
    Student *temp=head;
    while(temp)
    {
        cout<<temp->name<<" "<<temp->id<<"-->";
        temp=temp->link;
    }
    cout<<endl;
}
int LinkedList::Count()
{
    Student *temp=head;
    int cnt=0;
    while(temp->link)
    {
        cnt++;
        temp=temp->link;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif // !ONLINE_JUDGE
    Student s1("shubham",1),s2("mansi",2),s3("isha",3),s4("anvita",4);
    LinkedList *ll=new LinkedList();
    ll->InsertAtBeg(s1);
    ll->InsertAtBeg(s2);
    ll->InsertAtBeg(s3);
    ll->Print();
    //ll->InsertAtPos(5,s4);
    cout<<ll->Count();
    return 0;
}
