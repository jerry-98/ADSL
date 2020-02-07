#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<iomanip>
using namespace std;
class node
{
	string name;
	int weight;
	node *next;
public:
	node()
	{
		weight=0;
		next=NULL;
	}
	friend class Graph;
};

class Graph
{
	int n;
	node *head;
public:
	Graph()
	{
		n=0;
		cout<<"Enter the number of cities :: ";cin>>n;
		head= new node[n];
	}
	void insert_cities();
	void BFS_traversal();
	void insert();
	void traversal();
};

void Graph::insert_cities()
{
	string city;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter City :: ";cin>>city;
		head[i].name=city;
	}
}

void Graph::insert()
{
	string city1;
	string city2;
	int t_weight=0;
	cout<<"Enter the name of city you want to connect :: ";cin>>city1;
	int i=0;
	while(head[i].name!=city1&&i<n)
		i++;
	if(i==n)
	{
		cout<<"No Such city found."<<endl;
		return;
	}
	node *temp=new node;
	cout<<"Enter the name of connecting city ::";cin>>city2;
	cout<<"Enter the distance between the two cities :: ";cin>>t_weight;
	temp->name=city2;
	temp->weight=t_weight;
	node *temp2=&head[i];
	while(temp2->next!=NULL)
		temp2=temp2->next;
	temp2->next=temp;
	cout<<"Data inserted Succesfully."<<endl;
}

void Graph::BFS_traversal()
{
	cout<<"\nThe Cities are ::"<<endl;
	queue<node*> q;
	map<string,bool> visited;
	pair<string,bool> p;
	for(int i=0;i<n;i++)
	{
		visited.insert(pair<string,bool>(head[i].name,0));
	}
	int i=0;
	q.push(&head[i]);
	node *temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		visited[temp->name]=1;
		cout<<temp->name<<" ";
		node *temp2=&head[i];
		while(temp2!=NULL)
		{
			if(visited[temp2->name]==0)
			{
				q.push(temp2);
				visited[temp2->name]=1;
			}
			temp2=temp2->next;
		}
		i++;
		if(i<n&&visited[head[i].name]==0)
		{
			q.push(&head[i]);
			visited[head[i].name]=1;
		}
	}
}

void Graph::traversal()
{
	cout<<endl<<endl;
	cout<<"Flight Paths : "<<endl;
	cout<<setw(10)<<"S.NO"<<setw(15)<<"City 1"<<setw(5)<<" -> "<<setw(15)<<"City2"<<setw(25)<<"Distance(in Km)"<<endl;
	int j=1;
	for(int i=0;i<n;i++)
	{
		node *temp=&head[i];
		node *temp1=temp->next;
		while(temp1!=NULL)
		{
			cout<<setw(10)<<j<<setw(15)<<temp->name<<setw(5)<<" -> "<<setw(15)<<temp1->name<<setw(15)<<temp1->weight<<endl;
			j++;
			temp1=temp1->next;
		}
	}
}

int main()
{
	Graph g;
	g.insert_cities();
	int num=0;
	cout<<"Enter the number of paths :: ";cin>>num;
	for(int i=0;i<num;i++)
		g.insert();
	g.BFS_traversal();
	g.traversal();
	return 0;
}
