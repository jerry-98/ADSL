#include<iostream>
using namespace std;

class node{
	int data;
	int lbit,rbit;
	node* left;
	node* right;
	int child;
	public:
	node(int x)
	{
		data = x;
		lbit = 1;
		rbit = 1;
		left = NULL;
		right = NULL;
		child = -1;
	}
	friend class tbt;
};

class tbt{
	node* root;
	public:
	tbt()
	{
		root = new node(-1);
		root->left = root;
		root->right = root;
	}

	void create();
	void creator(node* ,int );
	node* in_successor(node* );
	node* pre_successor(node* );
	node* post_successor(node* );
	void In_order();
	void Pre_order();
	void Post_order();
};

void tbt::create()
{
	creator(root,0);
}

void tbt::creator(node* father,int child)
{
	int x;
	cout<<"enter data:";
	cin>>x;

	if(x == -1)
	{
		return ;
	}
	node* p = new node(x);

	if(child == 0)
	{
		p->child = 0;
		p->left = father->left;
		p->right = father;
		father->lbit = 0;
		father->left = p;
	}
	else
	{
		p->child = 1;
		p->left = father;
		p->right = father->right;
		father->rbit = 0;
		father->right = p;
	}

	cout<<"for left of "<<x<<endl;
	creator(p,0);
	cout<<"for right of "<<x<<endl;
	creator(p,1);
}

void tbt::Pre_order()
{
	node* p = root->left;
	cout<<"Pre-Order Display:";
	while(p != root)
	{
		cout<<p->data<<" ";
		p = pre_successor(p);
	}
}

node* tbt::pre_successor(node* p)
{
	if(p->lbit == 0)
	{
		return p->left;
	}

	while(p->rbit == 1 && p != root)
	{
		p = p->right;
	}
	return p->right;
}

void tbt::In_order()
{
	node* p = root->left;
	while(p->lbit == 0)
	{
		p = p->left;
	}

	while(p != root)
	{
		cout<<p->data<<" ";
		p = in_successor(p);
	}
}

node* tbt::in_successor(node* p)
{
	if(p->rbit == 1)
	{
		return p->right;
	}

	p = p->right;
	while(p->lbit == 0)
	{
		p = p->left;
	}
	return p;
}

void tbt::Post_order()
{
	node* p = root->left;
	while(p->lbit == 0 || p->rbit == 0)
	{
		if(p->lbit == 0)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	while(p != root)
	{
		cout<<p->data<<" ";
		p = post_successor(p);
	}

}

node* tbt::post_successor(node* p)
{
	if(p->child == 1)
	{
		if(p->lbit == 1)
		{
			return p->left;
		}
		while(p->lbit == 0)
		{
			p = p->left;
		}
		return p->left;
	}
	else
	{
		while(p->rbit == 0)
		{
			p = p->right;
		}

		p = p->right;

		if(p->rbit == 1)
		{
			return p;
		}
		else
		{
			p = p->right;
			while(p->lbit == 0 || p->rbit == 0)
			{
				if(p->lbit == 0)
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}
			return p;
		}
	}
}

int main()
{
	tbt a;
	a.create();
	a.Post_order();
	a.Pre_order();
	a.Post_order();
	return 0;
}

