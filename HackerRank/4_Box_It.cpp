#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box{
    //l,b,h are integers representing the dimensions of the box
    private:
        int l,b,h;
    // The class should have the following functions : 
    public:
    // Constructors: 
    Box();
    Box(int,int,int);
    Box(const Box& newBox);

    int getLength(); // Return box's length
    int getBreadth (); // Return box's breadth
    int getHeight ();  //Return box's height
    long long CalculateVolume(); // Return the volume of the box

    //Overload operator < as specified
    bool operator<(const Box& b);

    //Overload operator << as specified
    friend ostream& operator<<(ostream& out, Box& B);
};

Box::Box(void){
    l = 0;
    b = 0;
    h = 0;
}

Box::Box(int len, int breadth, int height){
    l = len;
    b = breadth;
    h = height;
}

Box::Box(const Box& newBox){
    l = newBox.l;
    b = newBox.b;
    h = newBox.h;
}

int Box::getLength(void){
    return(l);
}

int Box::getBreadth(void){
    return(b);
}

int Box::getHeight(void){
    return(h);
}

long long Box::CalculateVolume(void){
    return((long long)l*b*h);
}

bool Box::operator<(const Box& B){
    bool status;
    
    if((l<B.l)
    ||((b<B.b)&&(l==B.l))
    ||((h<B.h)&&(b==B.b)&&(l==B.l))){
        status = true;
    }
    else{
        status = false;
    }
    
    return (status);
}

ostream& operator<<(ostream& out, Box& B){
    out << B.l << ' ' << B.b << ' ' << B.h;
    return(out);
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

void check1()
{
    Box b1; // Should set b1.l = b1.b = b1.h = 0;
    Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
    b2.getLength();	// Should return 2
    b2.getBreadth(); // Should return 3
    b2.getHeight();	// Should return 4
    b2.CalculateVolume(); // Should return 24
    bool x = (b1 < b2);	// Should return true based on the conditions given
    cout<<b2; // Should print 2 3 4 in order.
}

int main()
{
	check2();
    check1();
}