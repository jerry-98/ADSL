#include<iostream>
#include<iomanip>
using namespace std;

class node
{
	node *left;
	node *right;
	string keyword;
	string meaning;
public :
	node()
	{
		left=NULL;
		right=NULL;
		keyword='\0';
		meaning='\0';
	}
	friend class dictionary;
};

class dictionary
{
	node *root;
	int count;
public:
	dictionary()
	{
		count=0;
		root=NULL;
	}
	void insert();
	node* insert(node*,const string,const string);
	void display();
	void ascending(node *);
	void descending(node *);
	void find();
	node* find(node*,const string);
	node* Delete(node*,const string);
	void Delete();
	void update();
	void operator=(dictionary);
	void copy(node *,node *);

};

void dictionary :: insert()
{
	string t1,t2;
	cout<<endl;
	cout<<"Keyword :: ";cin>>t1;
	cout<<"Meaning :: ";cin>>t2;
	root=insert(root,t1,t2);
	cout<<"Data Inserted."<<endl<<endl;
}

node * dictionary :: insert(node *temp,const string t1,const string t2)
{
	if(temp==NULL)
	{
		count++;
		node *newnode=new node;
		newnode->keyword=t1;
		newnode->meaning=t2;
		return newnode;
	}

	else if (t1<=temp->keyword)
		temp->left=insert(temp->left,t1,t2);

	else if(t1>temp->keyword)
		temp->right=insert(temp->right,t1,t2);

	else if(t1==temp->keyword)
	{
		if(t2<=temp->meaning)
			temp->left=insert(temp->left,t1,t2);

		else
			temp->right=insert(temp->right,t1,t2);
	}
	return temp;
}

void dictionary :: display()
{
	if(root==NULL)
	{
		cout<<"The Dictionary is Empty."<<endl;
		return;
	}

	int choice=0;
	cout<<endl;
	cout<<"1. Ascending."<<endl;
	cout<<"2. Descending."<<endl;
	cout<<"Enter your choice :: ";cin>>choice;
	cout<<endl;
	cout<<setw(15)<<"Keyword"<<setw(8)<<"|"<<setw(4)<<" "<<setw(15)<<"Meaning "<<endl<<endl;
	switch(choice)
	{
	case 1:
		this->ascending(root);
		break;
	case 2:
		this->descending(root);
		break;
	default:
		cout<<"You have entered a wrong choice."<<endl;
		break;
	}
}

void dictionary::ascending(node *temp)
	{
		if(temp==NULL)
			return;
		ascending(temp->left);
		cout<<setw(15)<<temp->keyword<<setw(8)<<"|"<<setw(4)<<" "<<setw(15)<<temp->meaning<<endl;
		ascending(temp->right);
	}

void dictionary ::descending(node *temp)
	{
		if(temp==NULL)
			return;
		descending(temp->right);
		cout<<setw(15)<<temp->keyword<<setw(8)<<"|"<<setw(4)<<" "<<setw(15)<<temp->meaning<<endl;
		descending(temp->left);
	}

int flag=0;
int comp=0;

void dictionary :: find()
{
	if(root==NULL)
	{
		cout<<"Dictionary is Empty."<<endl;
		return;
	}
	string temp;
	flag=0;
	comp=0;
	cout<<"Enter the Keyword to search :: ";cin>>temp;
	root=find(root,temp);
	if(flag==0)
	{
		cout<<"No Record Found."<<endl;
		cout<<endl;
		return;
	}
}

node* dictionary :: find(node *temp,const string t)
{
	if(temp==NULL)
		return NULL;
	else if(t==temp->keyword)
	{
		comp++;
		cout<<"Keyword Found. "<<endl;
		cout<<temp->keyword<<" :: "<<temp->meaning<<endl;
		cout<<"Number of Comparisons required :: "<<comp<<endl<<endl;
		flag=1;
	}

	else if(t<temp->keyword)
	{
		comp++;
		temp->left=find(temp->left,t);
	}

	else if(t>temp->keyword)
	{
		comp++;
		temp->right=find(temp->right,t);
	}
	return temp;

}

void dictionary::Delete()
{
	string temp;
	flag=0;
	cout<<"Enter the Keyword you want to delete :: ";cin>>temp;
	root=Delete(root,temp);
	if(flag==0)
		cout<<"The Keyword was not found."<<endl;
}

node* dictionary::Delete(node *temp,const string t)
{
	if(temp==NULL)
		return NULL;
	else if(t<temp->keyword){
		temp->left=Delete(temp->left,t);
	}

	else if(t>temp->keyword){
		temp->right=Delete(temp->right,t);
	}

	else if(t==temp->keyword)
	{
		flag=1;
		if(temp->left==NULL&&temp->right==NULL)
		{
			delete temp;
			return NULL;
		}

		else if(temp->left==NULL)
		{
			node *temp1=temp->right;
			delete temp;
			return temp1;
		}

		else if(temp->right==NULL)
		{
			node *temp1=temp->left;
			delete temp;
			return temp1;
		}

		else
		{
			node *temp1=temp->right;
			while(temp1->left!=NULL)
				temp1=temp1->left;
			temp->keyword=temp1->keyword;
			temp->meaning=temp1->meaning;
			temp->right=Delete(temp->right,temp->keyword);
			return temp;
		}
	}
}

void dictionary::update()
{
	if(root==NULL)
	{
		cout<<"The Dictionary has no entry."<<endl;
		return;
	}
	string s;
	cout<<"Enter the Keyword you want to update ::";cin>>s;
	node *temp=root;
	while(temp!=NULL)
	{
		if(s==temp->keyword)
		{
			cout<<"Write the new meaning :: ";cin>>temp->meaning;
			cout<<"Entry updated."<<endl;
			flag=1;
			break;
		}

		else if(s<temp->keyword)
			temp=temp->left;

		else if(s>temp->keyword)
			temp=temp->right;
	}
	if(flag==0)
		cout<<"No such Keyword Found."<<endl;
}

void dictionary :: operator=(dictionary d)
{
	root=d.root;
	copy(root,d.root);
}

void dictionary :: copy(node *t1,node *t2)
{
	if(t2==NULL)
	{
		t1=NULL;
	}
	t1=new node();
	t1->keyword=t2->keyword;
	t1->meaning=t2->meaning;
	copy(t1->left,t2->left);
	copy(t1->right,t2->right);
}

int main()
{
	dictionary d;
	int choice=1;
	while(choice!=6)
	{
		cout<<"1. Enter Data into dictionary."<<endl;
		cout<<"2. Display Data of dictionary."<<endl;
		cout<<"3. Delete a keyword from dictionary."<<endl;
		cout<<"4. Search the dictionary."<<endl;
		cout<<"5. Update an Entry."<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter your Choice :: ";cin>>choice;
		switch(choice)
		{
		case 1:
			d.insert();
			break;

		case 2:
			d.display();
			break;

		case 3:
			d.Delete();
			break;

		case 4:
			d.find();
			break;

		case 5:
			d.update();
			break;

		case 6:
			cout<<"Dictionary Completed."<<endl;
			break;

		default:
			cout<<"Wrong Choice Entered."<<endl;
			cout<<"Re-enter your Choice."<<endl;
			break;
		}
	}
	return 0;
}
