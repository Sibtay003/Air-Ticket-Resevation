#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <dos.h>
#include <graphics.h>

union REGS in,out;

void ml()
{
in.x.ax=1;
int86 (0x33,&in,&out);
}

void gl()
{
int g=DETECT, G;
initgraph(&g,&G,"c:\\tc\\bgi");
setbkcolor(6);
}
void bl()
{
in.x.ax=3;
int86 (0x33,&in,&out);
}

void menu()
{
setcolor(BLUE);
settextstyle(TRIPLEX_FONT,0,4);
outtextxy(80,20,"Air Ticket Management System");
setcolor(15);
settextstyle(SANS_SERIF_FONT,0,2);
outtextxy(220,90,"-> Ticket Information");
outtextxy(220,120,"-> Seach Ticket");
outtextxy(220,150,"-> Delete Ticket");
outtextxy(220,180,"-> Flight Schdule");
outtextxy(220,210,"-> Seach Flight");
outtextxy(220,240,"-> Delete Flight");
outtextxy(220,270,"-> Exit");
}

struct link
{
char name[20];
char add[20];
char cell[20];
char tn[20];
char pn[20];
char fn[20];
char ff[20];
link *next;
};

class list
{
link *first;

public:

list()
{
first = NULL;
}

void add(char a[],char b[],char c[],char d[],char e[],char f[],char g[])
{
if ( first == NULL )
{
first = new link;
strcpy(first -> name,a);
strcpy(first -> add,b);
strcpy(first -> cell,c);
strcpy(first -> tn,d);
strcpy(first -> pn,e);
strcpy(first -> fn,f);
strcpy(first -> ff,g);
first -> next = NULL;
}
else
{
link *ptr, *temp;
ptr = first;
while(ptr->next != NULL)
{
ptr = ptr -> next;
}
temp = new link;
strcpy(temp -> name,a);
strcpy(temp -> add,b);
strcpy(temp -> cell,c);
strcpy(temp -> tn,d);
strcpy(temp -> pn,e);
strcpy(temp -> fn,f);
strcpy(temp -> ff,g);
temp -> next = NULL;
ptr -> next= temp;
}}



void del(char d[])
{
link *pre, *ptr;

ptr=first;
int h=strcmp(ptr->tn,d);
if(h==0)
{
first=ptr->next;
cout<<"Value is Found ";
delete ptr;
return;
}
else
{
pre=first;
while ( ptr!=NULL)
{
int h=strcmp(ptr->tn,d);
if(h==0)
{
pre->next=ptr->next;
cout<<"Value is Found ";
delete ptr;
return;
}
pre=ptr;
ptr=ptr->next;
}
cout<<" value not found ";
}}



void search(char d[])
{
link *ptr = first;
while( ptr!=NULL)
{
int h=strcmp(ptr->tn,d);
if(h==0)
{
cout<<"  Name:              "<<ptr -> name
<<"\n  Address:           "<<ptr ->add
<<"\n  Mobile No.:        "<<ptr ->cell
<<"\n  Ticket No.:        "<<ptr -> tn
<<"\n  Passport No.:      "<<ptr -> pn
<<"\n  Flight No.:        "<<ptr -> fn
<<"\n  Flight Fair:       "<<ptr -> ff<<endl;
return;
}
ptr=ptr->next;
}
cout<<" value not found ";
}



void writeFile()
{
ofstream o("Ticket.txt");
link *ptr;
ptr = first;
while(ptr != NULL )
{
o<<ptr -> name
<<"\t\t"<<ptr ->add
<<"\t\t"<<ptr ->cell
<<"\t\t"<<ptr -> tn
<<"\t\t"<<ptr -> pn
<<"\t\t"<<ptr -> fn
<<"\t\t"<<ptr -> ff<<endl;
ptr=ptr->next;
}
o.close();
}};


struct linked1
{
char fn[20];
char fd[20];
char dp[20];
char dt[20];
char ap[20];
char at[20];
char sp[20];
char st[20];
char pc[20];
linked1 *next1;
};

class listed1
{
linked1 *first1;

public:

listed1()
{
first1 = NULL;
}

void add(char a[],char b[],char c[],char d[],char e[],char f[],char g[],char h[],char i[])
{
if ( first1 == NULL )
{
first1 = new linked1;
strcpy(first1 -> fn,a);
strcpy(first1 -> fd,b);
strcpy(first1 -> dp,c);
strcpy(first1 -> dt,d);
strcpy(first1 -> ap,e);
strcpy(first1 -> at,f);
strcpy(first1 -> sp,g);
strcpy(first1 -> st,h);
strcpy(first1 -> pc,i);
first1 -> next1 = NULL;
}
else
{
linked1 *ptr1, *temp1;
ptr1 = first1;
while(ptr1->next1 != NULL)
{
ptr1 = ptr1 -> next1;
}
temp1 = new linked1;
strcpy(temp1 -> fn,a);
strcpy(temp1 -> fd,b);
strcpy(temp1 -> dp,c);
strcpy(temp1 -> dt,d);
strcpy(temp1 -> ap,e);
strcpy(temp1 -> at,f);
strcpy(temp1 -> sp,g);
strcpy(temp1 -> st,h);
strcpy(temp1 -> pc,i);
temp1 -> next1 = NULL;
ptr1 -> next1= temp1;
}}



void del(char d[])
{
linked1 *pre1, *ptr1;

ptr1=first1;
int h=strcmp(ptr1->fn,d);
if(h==0)
{
first1=ptr1->next1;
cout<<"Value is Found ";
delete ptr1;
return;
}
else
{
pre1=first1;
while ( ptr1!=NULL)
{
int h=strcmp(ptr1->fn,d);
if(h==0)
{
pre1->next1=ptr1->next1;
cout<<"Value is Found ";
delete ptr1;
return;
}
pre1=ptr1;
ptr1=ptr1->next1;
}
cout<<" value not found ";
}}



void search(char d[])
{
linked1 *ptr1 = first1;
while( ptr1!=NULL)
{
int h=strcmp(ptr1->fn,d);
if(h==0)
{
cout<<"  Flight No.:               "<<ptr1 -> fn
<<"\n  Flight Date:              "<<ptr1 -> fd
<<"\n  Departure Place:          "<<ptr1 -> dp
<<"\n  Departure Time:           "<<ptr1 -> dt
<<"\n  Arrival Place:            "<<ptr1 -> ap
<<"\n  Arrival Time:             "<<ptr1 -> at
<<"\n  Stay Place:               "<<ptr1 -> sp
<<"\n  Stay Time:                "<<ptr1 -> st
<<"\n  Passenger Capacity:       "<<ptr1 -> pc<<endl;
return;
}
ptr1=ptr1->next1;
}
cout<<" value not found ";
}



void writeFile()
{
ofstream o("flight.txt");
linked1 *ptr1;
ptr1 = first1;
while(ptr1 != NULL )
{
o<<ptr1 -> fn
<<"\t\t"<<ptr1 ->fd
<<"\t\t"<<ptr1 ->dp
<<"\t\t"<<ptr1 -> dt
<<"\t\t"<<ptr1 -> ap
<<"\t\t"<<ptr1 -> at
<<"\t\t"<<ptr1 -> sp
<<"\t\t"<<ptr1 -> st
<<"\t\t"<<ptr1 -> pc<<endl;
ptr1=ptr1->next1;
}
o.close();
}};




void main()
{
gl();
clrscr();
list s; listed1 t;int z = 3;
char j[20],k[20],l[20],m[20],n[20],o[20],p[20],q[20],r[20];
ifstream i("Ticket.txt");
while(!i.eof())
{
i>>l>>m>>n>>o>>p>>q>>r;
s.add(l,m,n,o,p,q,r);
}
i.close();
ifstream i1("Flight.txt");
while(!i1.eof())
{
i1>>j>>k>>l>>m>>n>>o>>p>>q>>r;
t.add(j,k,l,m,n,o,p,q,r);
}
i1.close();

while(z>2)
{
clrscr();
cleardevice();
ml();
menu();
bl();
int x1,y1;
x1=out.x.cx;
y1=out.x.dx;
if(out.x.bx==1 && (x1>220 && x1<435)  &&  (y1>95 && y1<115))
{
clrscr();
cleardevice();
cout<<"Enter Person Name \n";
cin>>j;
cout<<"Enter Address\n";
cin>>k;
cout<<"Enter Mobile Number\n";
cin>>l;
cout<<"Enter Tickat Number\n";
cin>>m;
cout<<"Enter Passport Number\n";
cin>>n;
cout<<"Enter Flight Number\n";
cin>>o;
cout<<"Enter Flight Fair\n";
cin>>p;
s.add(j,k,l,m,n,o,p);
}
else
if(out.x.bx==1 && (x1>220 && x1<380)  &&  (y1>125 && y1<145))
{
clrscr();
cleardevice();
cout<<"Enter Ticket Number for Search\n";
cin>>m;
s.search(m);
getch();
}
else
if(out.x.bx==1 && (x1>220 && x1<380)  &&  (y1>155 && y1<175))
{
clrscr();
cleardevice();
cout<<"Enter Ticket Number for Delete\n";
cin>>m;
s.del(m);
getch();
}
else
if(out.x.bx==1 && (x1>220 && x1<390)  &&  (y1>185 && y1<205))
{
clrscr();
cleardevice();
cout<<"Enter Flight Number\n";
cin>>j;
cout<<"Enter Flight Date\n";
cin>>k;
cout<<"Enter Departure Place\n";
cin>>l;
cout<<"Enter Departure Time\n";
cin>>m;
cout<<"Enter Arrival Place\n";
cin>>n;
cout<<"Enter Arrival Time\n";
cin>>o;
cout<<"Enter Stay Place\n";
cin>>p;
cout<<"Enter Stay Time\n";
cin>>q;
cout<<"Enter Passenger Capacity\n";
cin>>r;
t.add(j,k,l,m,n,o,p,q,r);
}
else
if(out.x.bx==1 && (x1>220 && x1<380)  &&  (y1>215 && y1<235))
{
clrscr();
cleardevice();
cout<<"Enter Flight Number for Search\n";
cin>>m;
t.search(m);
getch();
}
else
if(out.x.bx==1 && (x1>220 && x1<380)  &&  (y1>245 && y1<265))
{
clrscr();
cleardevice();
cout<<"Enter Flight Number for Delete\n";
cin>>m;
t.del(m);
getch();
}
else
if(out.x.bx==1 && (x1>220 && x1<300)  &&  (y1>275 && y1<295))
{
s.writeFile();
t.writeFile();
closegraph();
break;
}
delay(100);
}}