#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 30
void billentry(char* item,int quantity,float rate,float add_charges,float custom_duty,float add_duty)
{
float asvalue,ca,ta,tt;
asvalue=(quantity*rate)+add_charges;
ca=custom_duty+add_duty;
ta=asvalue+ca;
tt=(ta*10)/100;
printf("\n item\tAssessable_value\tcustom_duty+add_charges\ttaxable_amt\ttax");
printf("\n------------------------------------------------------------------------------------");
printf("\n%s\t%f\t\t%f\t\t%f\t%f",item,asvalue,ca,ta,tt);
printf("\n------------------------------------------------------------------------------------");
}
struct comm_invoice_sender
{
char scompany[10],saddress1[30],saddress2[30],slocation[20],scity[20];
char sender_name[20],semail[20],sdate[20],scurrency[10],sreason[30],termsofsale[20];
int snumber,svatno,rvatno,invoice_no;
long long int stelephone;
};
struct receiver
{
char company[10],address1[30],address2[30],location[20],city[20];
char receiver_name[20],adate[20],email[20];
long long int telephone;
struct comm_invoice_sender inv1;
}inv2;
struct rec_data
{
    int bol,amount,sq,r,diff;
    char rName[MAX],paid[10];
    struct rec_data *next;

};
struct labour_data
{
    int count,sum;
    char lName[MAX],bname[MAX],eid;
    char handling1[20];
    struct labour_data *lnext;

};
 //dcontact[10];
 void print_commercial(struct receiver *ci);
 void print_commercials(struct  comm_invoice_sender *cii);
 void print_billoflading(struct receiver *bol1);
 void print_billofladings(struct comm_invoice_sender *bol2);


void print_commercial(struct  receiver *ci)
{
printf("\n-------------------------------------");
printf("\nRECEIVER DETAIL");
printf("\n-------------------------------------");
printf("\ncompany:%s",ci->company);
printf("\nAddress line1:%s",ci->address1);
printf("\nAddress line2:%s",ci->address2);
printf("\nCity:%s",ci->city);
printf("\nLocation:%s",ci->location);
//printf("\nSender Name:%s",ci->sender_name);
printf("\nReceiver Name:%s",ci->receiver_name);
printf("\nEmail:%s",ci->email);
printf("\nTelephone:%i",ci->telephone);
//printf("\nInvoice No.:%d",ci->invoice_no);
//printf("\nShipping date:%s",ci->sdate);
printf("\nArrival date:%s",ci->adate);
//printf("\nShipment number:%d",ci->snumber);
//printf("\nCurrency:%s",ci->currency);
//printf("\nReason for export:%s",ci->reason);
//printf("\nSender VAT number:%d",ci->svatno);
//printf("\nReceiver VAT number:%d",ci->rvatno);
//printf("\nTerms of Sale:%s",ci->termsofsale);
//printf("\nDelivery contact:%s",ci->dcontact);
}

void print_commercials(struct  comm_invoice_sender *cii)
{
printf("\n-------------------------------------");
printf("\n\tCOMMERCIAL INVOICE");
printf("\n-------------------------------------");
printf("\nSENDER DETAILS");
printf("\ncompany:%s",cii->scompany);
printf("\nAddress line1:%s",cii->saddress1);
printf("\nAddress line2:%s",cii->saddress2);
printf("\nCity:%s",cii->scity);
printf("\nLocation:%s",cii->slocation);
printf("\nSender Name:%s",cii->sender_name);
//printf("\nReceiver Name:%s",ci->receiver_name);
printf("\nEmail:%s",cii->semail);
printf("\nTelephone:%i",cii->stelephone);
printf("\nInvoice No.:%d",cii->invoice_no);
printf("\nShipping date:%s",cii->sdate);
printf("\nShipment number:%d",cii->snumber);
printf("\nCurrency:%s",cii->scurrency);
printf("\nReason for export:%s",cii->sreason);
printf("\nSender VAT number:%d",cii->svatno);
printf("\nReceiver VAT number:%d",cii->rvatno);
printf("\nTerms of Sale:%s",cii->termsofsale);
//printf("\nDelivery contact:%s",cii->dcontact);
}

void print_billoflading(struct receiver *bol1)
{
printf("\n\tBILL OF LADING");
printf("\nConsignee:Due Date:%s",bol1->adate);
printf("\n---------------------------------");
printf("\n%s",bol1->address1);
printf("\n%s",bol1->address2);
printf("\n%s",bol1->city);
printf("\n(%s)%i",bol1->receiver_name,bol1->telephone);
printf("\n---------------------------------");
printf("\nReference Number:na");
printf("\n---------------------------------");

}
void print_billofladings(struct comm_invoice_sender *bol2)
{
printf("\n\tBILL OF LADING");
printf("\nShipper:Ship date:%s",bol2->sdate);
printf("\n---------------------------------");
printf("\n%s",bol2->saddress1);
printf("\n%s",bol2->saddress2);
printf("\n%s",bol2->scity);
printf("\n(%s)%i",bol2->sender_name,bol2->stelephone);
printf("\n---------------------------------");
printf("\nReference Number:na");
printf("\n---------------------------------");

}

struct rec_data *insert(struct rec_data *front, int ino, char rname[],int amt,int sft,int r1,int di)
{
    struct rec_data *newnode;

    newnode = (struct rec_data*)malloc(sizeof(struct rec_data));

    if (newnode == NULL)
    {
	printf("\n Allocation failed \n");
	exit(2);
    }
    newnode->bol = ino;
    strcpy(newnode->rName, rname);
    //newnode->telephone=tel;
    newnode->amount=amt;
    newnode->sq=sft;
    newnode->r=r1;
    newnode->diff=di;
    newnode->next = front;
    front = newnode;
if(newnode->diff==0)
{
strcpy(newnode->paid, "paid");
}
else
{
strcpy(newnode->paid, "pending");
}

    return(front);
}
/*  End of insert() */
struct labour_data *linsert(struct labour_data *lfront,char m[],char hd[])
{
    struct labour_data *lnewnode;

    lnewnode = (struct labour_data*)malloc(sizeof(struct labour_data));

    if (lnewnode == NULL)
    {
	printf("\n Allocation failed \n");
	exit(2);
    }
     //lnewnode->eid = eno;
    strcpy(lnewnode->lName, m);
    strcpy(lnewnode->bname, hd);
    lnewnode->lnext = lfront;
    lfront = lnewnode;
    return(lfront);
}
/*  End of linsert() */

/*  Function to display a customer node in a linked list */
void printNode(struct rec_data *p)
{
    printf("\n receiver Details...\n");
    printf("\n Bill Of lading no       : %d", p->bol);
    printf("\n Name           : %s", p->rName);
    //printf("\n Contact    : %d\n", p->telephone);
    printf("\n Pending   : %d\n", p->diff);
    printf("\n Status      : %s\n",p->paid);
    printf("-------------------------------------\n");
}
/*  End of printNode() */
/*  Function to display labour  node in a linked list */
void lprintNode(struct labour_data *p)
{    printf("\n-------------------------------------\n");
    printf("\n Employee Details...\n");
    printf("\n Name          : %s", p->lName);
    printf("\n handling          : %s", p->bname);
    printf("\n-------------------------------------\n");
}
/*  End of lprintNode() */

struct rec_data* deleteNode(struct rec_data *front, int bno)
{
    struct rec_data *ptr;
    struct rec_data *bptr;

    if (front->bol == bno)
    {
	ptr = front;
	printf("\n Node deleted:");
	printNode(front);
	front = front->next;
	free(ptr);
	return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
bptr = bptr->next)
    {
	if (ptr->bol == bno)
	{
	    printf("\n Node deleted:");
	    printNode(ptr);
	    bptr->next = ptr->next;
	    free(ptr);
	    return(front);
	}
    }
    printf("\n BOL Number %d not found ", bno);
    return(front);
}
/*  End of deleteNode() */

/*  Searching list using the bol number */
void search(struct rec_data *front, int key)
{
    struct rec_data *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
	if (ptr->bol == key)
	{
	    printf("\n Key found:");
	    printNode(ptr);
	    return;
	}
    }
    printf("\n BOL Number %d not found ", key);
}
/*  End of search() */


/*  Searching list based on status */
void search2(struct rec_data *front,char status[])
{
    struct rec_data *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
	if(strcmp(ptr->paid,status)==0)
	{
	    printf("\n Key found:");
	    printNode(ptr);
	    return;
	}
    }
        printf("\n No pending payments");
}
/*  End of search() */



/*counting occurances of handling*/
int count(struct labour_data* lfront, char type[])
{
    struct labour_data* ptr=lfront;
    int sum=0;
    //struct labour_data count=0;
    //for (ptr = lfront; ptr != NULL; ptr = ptr -> lnext)


     while(ptr!=NULL)
     {   int count=0;
        if(strcmp(ptr->bname,type)==0)
        {
        count++;
        }
        sum=sum+count;
        ptr = ptr->lnext;
     }
        printf("%d",sum);
}
int members(struct labour_data* lfront,char type[],int *wt)
{
    struct labour_data* ptr=lfront;
    int req=0,weight;
    //weight=wgt;
         printf("enter the weight of the good");
          scanf("%d",&weight);

        if(strcmp(ptr->bname,type)==0)
        {

        if(weight<=15)
        {
          req=1;
         // requirement(req);
         printf("requirement of ppl is 1");
        }
          else if(weight<=25)
          {


              req=2;
              printf("requirement of ppl is 2");
            //  requirement(req);
          }
          else if(weight<=35)
          {


              req=3;
              printf("requirement of ppl is 3");
             // requirement(req);
          }
          else
            printf("not available");
        wt=&req;

        return(req);
        }
        }
void requirement(struct labour_data *lfront,char type[],int r)
{
    struct labour_data *ptr;
    int empsearch=0;
    int x=0;
    //struct labour_data count=0;
    for (ptr = lfront; ptr != NULL; ptr = ptr -> lnext)
    {
	if(strcmp(ptr->bname,type)==0)
	{
	   //printf("\n %d",r);
	    if(x<r){
	    lprintNode(ptr);

	    x++;
	}
	else{
		break;
	}

	}

    }


}



/*end of counting occurances of handling*/

/*search for employee based on handling type*/

void empsearch(struct labour_data *lfront,char type[])
{
    struct labour_data *ptr;
    int empsearch=0;
    //struct labour_data count=0;
    for (ptr = lfront; ptr != NULL; ptr = ptr -> lnext)
    {
	if(strcmp(ptr->bname,type)==0)
	{
	    printf("\n Key found:");
	    lprintNode(ptr);
	    //printf("%d",count);
	}
       /* if (ptr->bname == type)
            empsearch++;
        ptr = ptr->lnext;

         printf("%d",empsearch);
         */
    }
        //printf("\n No Available employee");

}
/*end of search for employee based on handling type*/
/*display customer data*/
void display(struct rec_data  *front)
{
    struct rec_data *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
	printNode(ptr);
    }
}
/*  End of display() */

/*display labour data*/
void ldisplay(struct labour_data  *lfront)
{
    struct labour_data *ptr;

    for (ptr = lfront; ptr != NULL; ptr = ptr->lnext)
    {
	lprintNode(ptr);
    }
}
/*  End of ldisplay() */

void menu()
{

printf("\n---------------------------------------------\n");
printf("\nPress 1 for bill of entery\n");
printf("Press 2 for Transhipment\n");
printf("Press 3 for commercial invoice\n");
printf("Press 4 for bill of lading \n");
printf("\n---------------------------------------------\n");
printf("Press 5 for calculating Shipping Charge\n");
printf("\n---------------------------------------------\n");
printf("Press 6 to INSERT a node into the list       \n");
printf("Press 7 to DELETE a node from the list       \n");
printf("Press 8 to DISPLAY the list                 \n");
printf("Press 9 to SEARCH the list                   \n");
printf("Press 10 to Search Pending list               \n");
printf("Press 11 to INSERT a node into labour list    \n");
printf("Press 12 to DISPLAY a node into labour list  \n");
printf("Press 13 to SEARCH a node into labour list   \n");
printf("Press 14 to EXIT                              \n");
printf("---------------------------------------------\n");

}

void bill_details(){

double weight, miles, rate1;
int dd;
int entry,quantity,wgt,stamt;
int sl_no,container_no,truckno,custom_seal_no,bond_no,net_weight,gross_weight,import_no;
float rate,add_charges,custom_duty,add_duty,taxable_amt,tax;
char item[10],date[10],port[10],paid[10],arrival_date[20];
char des[100],Authorizedcarrier_code[10],description[100],destination[30],lcs[20];
char company[20],gate_out_time[10];
    struct rec_data *linkList;
    struct labour_data *ll;
    char name[21],hd[21],m[20];
    char choice,status[10],type[10];
    int bno,amt,sft,r1,rent=5000,di,eno;

	printf("\n-------------------------------------------------");
printf("\tBILL OF ENTRY DETAILS");
printf("\n-------------------------------------------------");

//scanf("%d",&entry);
entry=123;
strcpy(date,"11/4/20");
strcpy(port,"XYZ port");
strcpy(paid,"Cash");
strcpy(item,"Books");
quantity=8000;
rate=3;
add_charges=300;
custom_duty=200;
add_duty=300;
printf("\nBill of entry#\t%d",entry);
printf("\nDate\t%s",date);
printf("\nPort:%s",port);
printf("\npaid through\t%s",paid);
//scanf("%s",paid);
printf("\n-------------------------------------------------");
printf("\nItem name:\t");
//scanf("%s",item);
printf("\nQuantity:\t%d",quantity);
//scanf("%d",&quantity);
printf("\nRate of interest:%f",rate);
//scanf("%f",&rate);
printf("\nAdditional charges:%f",add_charges);
//scanf("%f",&add_charges);
printf("\nCustom duty:%f",custom_duty);
//scanf("%f",&custom_duty);
printf("\nadditional duty:%f",add_duty);
//scanf("%f",&add_duty);
billentry(item,quantity,rate,add_charges,custom_duty,add_duty);
getch();
}



int main()
{
double weight, miles, rate1;
int dd;
int entry,quantity,wgt,stamt;
int sl_no,container_no,truckno,custom_seal_no,bond_no,net_weight,gross_weight,import_no;
float rate,add_charges,custom_duty,add_duty,taxable_amt,tax;
char item[10],date[10],port[10],paid[10],arrival_date[20];
char des[100],Authorizedcarrier_code[10],description[100],destination[30],lcs[20];
char company[20],gate_out_time[10];
    struct rec_data *linkList;
    struct labour_data *ll;
    char name[21],hd[21],m[20];
    char choice,status[10],type[10];
    int bno,amt,sft,r1,rent=5000,di,eno;
    //long int tel;

    linkList = NULL;
    ll = NULL;
int ch;
//clrscr();

while(1)
{

	menu();
printf("\nenter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
   bill_details();
break;

case 2:
strcpy(Authorizedcarrier_code,"AWZD");
bond_no=12;
strcpy(arrival_date,"12/05/20");
container_no=40;
custom_seal_no=55;
truckno=11;
net_weight=60;
gross_weight=50;
sl_no=1;
strcpy(destination,"Delhi");
strcpy(description,"Hard product");
strcpy(gate_out_time,"10:30AM");
strcpy(lcs,"Ayur Vigyan Nagar");
import_no=111;
printf("\nTranshipment of imported goods between port to the land custom station");
printf("\n\tDeparture Manifest to be filed at port");
printf("\n-----------------------------------------------------------");
printf("\nAuthorized Carrier code:%s",Authorizedcarrier_code);
//scanf("%s",Authorizedcarrier_code);
printf("\t|Bond no. of authorised carrier:%d",bond_no);
//scanf("%d",&bond_no);
printf("\nPort:%s",port);
//scanf("%s",port);
printf("\t|departure Manifest No and Date:auto generated");
printf("\n------------------------------------------------------------");
printf("\nSL.NO:%d",sl_no);
//scanf("%d",&sl_no);
printf("\nArrival Manifest no./date by which cargo arrived at port:%s",arrival_date);
//scanf("%s",arrival_date);
//printf("Line no:");
printf("\n goods description:%s",description);
//scanf("%s",description);
printf("\ncontainer no. & custom seal no.%d\t%d",container_no,custom_seal_no);
//scanf("%d\t%d",&container_no,&custom_seal_no);
printf("\n Train No/Truck No.:%d",truckno);
//scanf("%d",&truckno);
printf("\n destination:%s",destination);
//scanf("%s",destination);
printf("\nNet Wt & Gross Wt. in case of non-containerized cargo:%d\t%d",net_weight,gross_weight);
//scanf("%d\t%d",&net_weight,&gross_weight);
printf("\nGate out Time from the port:%s",gate_out_time);
//scanf("%d",&gate_out_time);
printf("\n---------------------------------------------------------------");
printf("\n");
printf("\n(b)Arrival Manifest to be filed at Land Customs Stations");
printf("\n-----------------------------------------------------------------");
printf("\nAuthorised Carrier Code:%s",Authorizedcarrier_code);
printf("\tBond No. of Authorised Carrier:%d",bond_no);
printf("\n-----------------------------------------------------------------");
printf("\nLand Customs Stations(LCS):%s",lcs);
//scanf("%s",lcs);
printf("\nDeparture Manifest No. and Date:auto generated");
printf("\n------------------------------------------------------------------");
printf("\nSL No:%d",sl_no);
printf("\nImport report no. by which the cargo arrived at LCS:%d",import_no);
//scanf("%d",&import_no);
printf("\nContainer No. & Customs Seal no.:%d\t%d",container_no,custom_seal_no);
printf("\nDestination:%s",destination);
printf("\nGoods description:%s",description);
printf("\ntrain No./Truck No.%d",truckno);
printf("\nNet Wt & Gross Wt. in case of non-containerized cargo:%d\t%d",net_weight,gross_weight);
printf("\nGate out Time:%s",gate_out_time);
printf("\n---------------------------------------------------------------------");
break;

case 3:
strcpy(inv2.inv1.scompany,"abc");
strcpy(inv2.inv1.saddress1,"#12 Near Teachers colony");
strcpy(inv2.inv1.saddress2,"Sharjah ");
strcpy(inv2.inv1.scity,"Dubai");
strcpy(inv2.inv1.slocation,"Fujairah, Ras al-Khaimah");
strcpy(inv2.inv1.sender_name,"xyz");
strcpy(inv2.inv1.semail,"abc123@gmail.com");
inv2.inv1.stelephone=78654321234;
inv2.inv1.invoice_no=9867;
strcpy(inv2.inv1.sdate,"12/09/2019");
inv2.inv1.snumber=1234;
strcpy(inv2.inv1.scurrency,"Dirham");
strcpy(inv2.inv1.sreason,"the export the commodities");
inv2.inv1.svatno=6765;
inv2.inv1.rvatno=456;
strcpy(inv2.inv1.termsofsale,"FREE ALONGSIDE SHIP.");
print_commercials(&inv2.inv1);


//struct receiver inv2={"bbb ltd","#12 EasyFlowers. Jain Mandir Market South ","#12 EasyFlowers. Jain Mandir Market South ","Ayur Vigyan Nagar","New Delhi","max","20/09/2019","123bbb@gmail.com",987545234};

strcpy(inv2.company,"bbb");
strcpy(inv2.address1,"#12 EasyFlowers. Jain  ");
strcpy(inv2.address2,"Mandir Market South ");
strcpy(inv2.city,"New Delhi");
strcpy(inv2.location,"Ayur Vigyan Nagar");
strcpy(inv2.receiver_name,"max");
strcpy(inv2.email,"123bbb@gmail.com");
inv2.telephone=987545234;
strcpy(inv2.adate,"20/09/2019");

print_commercial(&inv2);

break;

case 4:
strcpy(inv2.inv1.saddress1,"#12 Near Teachers colony");
strcpy(inv2.inv1.saddress2,"Sharjah ");
strcpy(inv2.inv1.scity,"Dubai-67890");
strcpy(inv2.inv1.sender_name,"Bill");
inv2.inv1.stelephone=7865432123;

strcpy(inv2.address1,"#12 EasyFlowers,Jain Mandir ");
strcpy(inv2.address2,"Ayur Vigyan Nagar ");
strcpy(inv2.city,"New Delhi-555898");
strcpy(inv2.receiver_name,"Max");
inv2.telephone=987545234;

print_billofladings(&inv2.inv1);
print_billoflading(&inv2);
break;

case 5:
    printf("Enter the weight of the package:");
	scanf("%lf", &weight);

	// When weight is greater than 50
	if (weight > 50.0) {
		puts("Sorry, we only ship packages of 50 pounds or less.");
		return 0;
	}

	// User enters the mileage
	printf("Enter the amount of miles it would take:");
	scanf("%lf", &miles);

	// When weight is less than or equal 10
	if (weight <= 10.0)
		rate1= 2.00;

	// When weight is greater than 10
	else
		rate1 = 4.50;

	// Calculate and display the result
	printf("Shipping charge is $%.2lf \n", (int)((miles + 499.0) / 500.0) * rate1);
	break;


		case 6:
	    printf("\n Enter the BOL Number      : ");
	    scanf("%d", &bno);
	    printf("Enter the Receiver name        : ");
	    fflush(stdin);
	    gets(name);
	    //printf("Enter the Telephone number : ");
	    //scanf("%d", &tel);
	    printf("Rent is:%d",rent);
	    printf("\nrequired square foot:");
	    scanf("%d",&sft);
	    stamt=sft*rent;
	    printf("\ntotal amount:%d",stamt);
	    printf("\nEnter the Rent amount paid:");
	    scanf("%d",&amt);
	    r1=sft*rent;
	    di=r1-amt;
	    linkList = insert(linkList,bno,name,amt,sft,r1,di);
	    break;
	case 7:
	    printf("\n\n Enter the Receiver number to be deleted: ");
	    scanf("%d", &bno);
	    linkList = deleteNode(linkList, bno);
	    break;
	case 8:
	    if (linkList == NULL)
	    {
		printf("\n List empty.");
		break;
	    }
	    display(linkList);
	    break;
	case 9:
	    printf("\n\n Enter the BOL number to be searched: ");
	    scanf("%d", bno);
	    search(linkList, bno);
	    break;
    case 10:
	    printf("Status:");
	    scanf("%s",status);
	    search2(linkList,status);
	    break;
    case 11:
        //printf("\n Enter the employee Number      : ");
	    //scanf("%d", &eno);
	    printf("\n Enter employee name     : ");
	    scanf("%s",m);
	    printf("Enter the product handling type        : ");
	    fflush(stdin);
	    gets(hd);
	   // scanf("%s",hd);
	    ll=linsert(ll,m,hd);
	    break;
    case 12:
	    /*if (ll == NULL)
	    {
		printf("\n List empty.");
		break;
	    }
	    ldisplay(ll);
	    break;*/
	    if (ll == NULL)
	    {
		printf("\n List empty.");
		break;
	    }
	    ldisplay(ll);
	    break;

    case 13:
        printf("product type:");
	    scanf("%s",type);
	    empsearch(ll,type);
	    count(ll,type);
	    //printf("enter the weight of the good");
        //scanf("%d",&wgt);
	    dd=members(ll,type,wgt);
	    requirement(ll,type,dd);
        break;


case 14:
exit(0);
break;
}
}
getch();
}
