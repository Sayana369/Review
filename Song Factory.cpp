#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
using namespace std;

   /// Update & Insert Functions
	void insertfirst(int data, char albumname[25], char artistname[50],int quantity, float price);
	void insertmid(int pos, int data, char albumname[25], char artistname[50], int quantity,float price);
	void insertend(int data, char albumname[25], char artistname[50], int quantity,float price);
	void updatealbum(int udata, int uquantity);

     /// Display Function
	void albumlist();
	void order_view(int order, int quantity, int or_no);
	void main_menu();

    ///Delete & Count Function
	void deletealbum(int serial);
	int countitem();
	///extra design Function

	void echo(char print[]);
	void br(int line);
	void pre(int tab);
	void span(int space);
	void pwellcome();
	void loadingbar();
	void midline(void);
	void midtab(void);
	void backuploader(void);

    ///START Class Here

	class Node
	{
		public:
			char albumname[50];
			char artistname[50];
			int quantity;
			float price;
			int data;
			struct Node *next;

	}al;

   ///Global Type

	typedef struct Node node ;

	node *head, *list;

	int main(){

    	system("title Song factory Management System");
		system("mode con: cols=88 lines=30");
		loadingbar(); 
		system("cls");
		pwellcome();
		Sleep(300);
		system("cls");

		int c=0; int any;
		int cardno[100];
		float cardmoney[100];
		float totalmoney = 0;
		int total_order[100];
		int order_quantity[100];
		int order=0;
		int uquantity;
		int citem;

		head = NULL;
		insertfirst(1,"Blankspace  ","Taylor swift ",10,100.00);
		insertend(2,"Ik Vaari Aa ","Arjit Singh  ",12,130.67);
		insertend(3,"Emai Poyave ","Sid Sriram   ",34,420.83);
		insertend(4,"Love me like","Ellie Goudlng",12,370.23);
		insertend(5,"Baby        ","Justin Bieber",10,120.23);
		insertend(6,"Nenje Ezhu  ","AR Rahman    ",13,560.23);
		insertend(7,"Maiya Maiya ","Chinmayi     ",23,420.29);
		insertend(8,"Karma       ","Anirudh      ",41,835.13);
		insertend(9,"Parayuvan   ","Sid Sriram   ",12,260.13);


	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); cin>>main_menu_choice;

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			albumlist:

			system("cls");
			cout<<"=> 0. Main Menu ";
			albumlist();
		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			system("cls"); midline() ;   pre(4);  cout<<"1. Main Menu\n\n\t"; Sleep(300);
			cout<<"Please Enter Password or ( 1 to Back in Main Menu ) : ";
			fflush(stdin);  cin>>admin_panel_choice;

			if(admin_panel_choice==1234567){

				node *temp;

				temp = list;

				adminchoise:

				system("cls");  br(3); pre(4); echo(">>>> Admin Panel <<<<   \n\n");
				pre(4);
				cout<<" 1. Total Cash Today \n\n";Sleep(250);pre(4);
				cout<<" 2. View Card Pay \n\n";Sleep(250);pre(4);
				cout<<" 3. Add New Album \n\n";Sleep(250);pre(4);
				cout<<" 4. Delete Album \n\n";Sleep(250);pre(4);
				cout<<" 5. Instant Album List \n\n";Sleep(250);pre(4);
				cout<<" 6. Item Counter \n\n";Sleep(250);pre(4);
				cout<<" 7. Backup System\n\n";Sleep(250);pre(4);
				cout<<" 8. Instant Order Preview\n\n";Sleep(250);pre(4);
				cout<<" 0. Main Menu \n\n";
				cout<<"\tEnter Your Choice From 1-0: ";
				Sleep(250);

				int adminchoise;

				fflush(stdin);   cin>>adminchoise;

				if(adminchoise==1){

					system("cls");  midline(); pre(4);   cout<<"Todays Total Cash :  "<<totalmoney;

					Sleep(2000);

					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){

						system("cls");  br(3); pre(4);

						cout<<" ____________________________\n";pre(4);
						cout<<"|   Card NO.   |   Money $   |\n";pre(4);
						cout<<"------------------------------\n";pre(4);

						for(int z=1; z<=c;z++){

							cout<<cardno[z]<<" "<<cardmoney[z]<<" ";pre(4);
							cout<<"------------------------------\n";pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){
							system("cls");  midline(); pre(4);
							cout<<"No Card History\n";
							}
					Sleep(1500);
					goto adminchoise;
				}

				else if(adminchoise==3){

					albumadd:
					system("cls");

					char falbumname[25];
					char fartistname[25];
					int fdata;
					int fquantity;
					float fprice;
					int fposi;


					br(3);pre(4);      cout<<" Enter Album Name :  ";

					fflush(stdin);     cin>>falbumname;
					fartistname:
					fflush(stdin);

					br(2);pre(4);
					cout<<" Enter Artist Name :  ";
					cin>>fartistname; fflush(stdin);
					fquantity:
						fflush(stdin);
						br(2);pre(4);
						cout<<" Enter quantity : ";
						fflush(stdin);
						cin>>fquantity;

                        albumserial:
						br(2);pre(4);  cout<<" Enter Item Serial :  ";
                      	cin>>fdata;
                            node *exist;
                            exist = list;
                      	while(exist->data!=fdata){
                          		  if(exist->next==NULL){
                                	break;
                            		}
                        			exist=exist->next;
                      							}
                      if(exist->data==fdata){
                       system("cls"); br(5);pre(3);  cout<<" Album Serial Already Exist, Please Re-Enter  "; Sleep(2000);
                       goto albumserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  cout<<" Enter Item Price :  ";fflush(stdin);
					cin>>fprice;
					br(2);pre(4);  cout<<"Submitting your data";
					for(int cs=0;cs<4;cs++){cout<<" .";Sleep(500);}
					insertend(fdata,falbumname,fartistname,fquantity,fprice);
					br(2);pre(4);      cout<<"\nAdding Item  Successfull.......\n";

					Sleep(2000);

					goto adminchoise;

				}
				else if(adminchoise==4){

					system("cls");
					midline();pre(2);
					cout<<"Enter Serial No of the Item To Delete : ";
					fdelete:
					int fdelete;
					fflush(stdin); cin>>fdelete;
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletealbum(fdelete);
					}
					else{
						br(2); pre(2); cout<<"Please Enter Correct Number :  "; Sleep(500);
						goto fdelete;
					}
					goto adminchoise;
				}

				else if(adminchoise==5){

					system("cls");    albumlist(); Sleep(1000);

					br(2);pre(4);  cout<<"1. <-- back  \n\n";pre(5);
					fflush(stdin);   cin>>any;

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					system("cls");
					for(int cs=1;cs<=citem;cs++){
						midline(); pre(4);
						cout<<"Item Counting ";
						cout<<cs;
						Sleep(150);
						system("cls");
					}
					system("cls");
					midline();pre(4);
					cout<<"Total Item Item is -->   "<<citem<<endl; Sleep(2000);
					goto adminchoise;

				}

                    ///Backup System
				else if(adminchoise==7){
					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); cout<<"Error!"; Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); cout<<"Backup Successfull..."; Sleep(1500);
					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){

					system("cls");br(2);pre(2);
					cout<<"\n\t\t"; 
					cout<<"______________________________________________________ "; 
					cout<<"\n\t\t";  
					cout<<"|  Order No.  |   Item Name   |  Quantity |  In Stock |"; 
					cout<<"\n\t\t";  
					cout<<"------------------------------------------------------"; 
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  cout<<"1. <-- back  \n\n";pre(5);

					fflush(stdin); cin>>any;

					goto adminchoise;
				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); cout<<"Please Select From List :  "; Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  cout<<"Please Enter Correct Choice";
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			system("cls");
			midline(); pre(1); cout<<"Thank You For Visiting Thiya's Song Factory";
			cout<<"\n\n\n\n\n";
			 for(int i=0;i<15;i++)
			 cout<<" ";
			 cout<<"*         *";
			 cout<<endl;
			 
			 for(int j=0;j<13;j++)
			 cout<<" ";
			 cout<<"*   *     *   *";
			 cout<<endl;
			
			 for(int k=0;k<11;k++)
			 cout<<" ";
			 cout<<"*      *   *      *";
			 cout<<endl;
			
			 for(int l=0;l<11;l++)
			 cout<<" ";
			 cout<<"*       * *       *";
			 cout<<endl;
			 
			 for(int m=0;m<11;m++)
			 cout<<" ";
			 cout<<"*        *        *";
			 cout<<endl;
			 
			 for(int n=0;n<11;n++)
			 cout<<" ";
			 cout<<"*                 *";
			 cout<<endl;
			 
			 for(int o=0;o<12;o++)
			 cout<<" ";
			 cout<<"*               *";
			 cout<<endl; 
			
			 for(int p=0;p<13;p++)
			 cout<<" ";
			 cout<<"*             *";
			 cout<<endl;
			 
			 for(int q=0;q<14;q++)
			 cout<<" ";
			 cout<<"*           *";
			 cout<<endl;
			 
			 for(int r=0;r<15;r++)
			 cout<<" ";
			 cout<<"*         *";
			 cout<<endl;
			 
			 for(int s=0;s<17;s++)
			 cout<<" ";
			 cout<<"*     *";
			 cout<<endl;
			 
			 for(int t=0;t<20;t++)
			 cout<<" ";
			 cout<<"**";
			 cout<<endl;
			Sleep(1000);
			exit(1);

		}

	}
	else{
		br(2); pre(4); cout<<"Please Enter Correct Choice"; Sleep(300);
		goto mainmenu;
	}


	int get_album_choice;


	br(2); pre(3);fflush(stdin);
	cout<<"Select your album: " ;
	cin>>get_album_choice;

	if(get_album_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_album_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choice From List: "); br(2); Sleep(1000);
			goto albumlist;
		}

	}
	if(get_album_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		cout<<"Enter Item Quantity : ";

		int fcquantity;

		fflush(stdin); cin>>fcquantity; system("cls");
		if(fcquantity==0){
			system("cls"); midline();pre(3); cout<<"Quantity Can not be Zero "; Sleep(2000);
			system("cls");
			goto albumlist;
		}
		else if(fcquantity>temp->quantity){
			system("cls"); midline();pre(3); cout<<"Out of Stock ! "; Sleep(2000);

			goto albumlist;
		}

		midline();pre(4);  cout<<"Choice album is  "<<temp->albumname <<"its price is "<<temp->price*fcquantity<<endl<<endl;pre(4);
		cout<<"1. Confirm to buy this \n\n";pre(4);
		cout<<"2. Item List \n\n";
		cout<<"\t\tPress 1 to confirm and 2 to back to list :";

		confirm:
		int confirm;

		fflush(stdin); cin>>confirm;

		if(confirm == 1 ){

			br(2);pre(4);
			cout<<" 1. Cash ";
			br(2);pre(4);
            cout<<" 2. Credit\n";
            cout<<"\n\t\tSelect Method Of payment 1-2: ";
			payment:
			int payment;

			fflush(stdin);  cin>>payment;

			if(payment==1){
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_album_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatealbum(get_album_choice,uquantity);


				system("cls");midline();pre(4);  cout<<"\t  ===>THANK YOU<===";
				br(2);pre(4);  cout<<"Item Ordered Successfully ...";
				br(2);pre(4);  cout<<"1. Wanna Buy Another Album ? ";
				br(2);pre(4);  cout<<"2. Main Menu \n";
				br(2);pre(4);  cout<<"Select: ";
				psmenu:
				int ps_menu;

				fflush(stdin);  cin>>ps_menu;

				if(ps_menu==1){goto albumlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);cout<<"Please Choose from list : "; goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				system("cls");midline();pre(4); cout<<"Enter Your Card No : ";

				fflush(stdin);   cin>>card_number[c];
				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  cout<<"Enter Your Card Pin [we never save your pin]  : ";

				fflush(stdin); cin>>pin;

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_album_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatealbum(get_album_choice,uquantity);

				br(2);pre(4);  cout<<"Payment Success...";
				br(2);pre(4);  cout<<"1. Wanna Buy Another Album ? ";
				br(2);pre(4);  cout<<"2. Main Menu \n";
				br(2);pre(4);  cout<<"Select: ";
				psmenu2:
				int ps_menu2;

				cin>>ps_menu2;

				if(ps_menu2==1){goto albumlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);cout<<"Please Choice from list : "; goto psmenu2;}

			}

			else{

				br(2);pre(4);  cout<<"Enter Choice from List : ";
				goto payment;
				}


		}    ///END Confirm Y/y
			else if(confirm == 2){

			goto albumlist;

				}

		else{
			br(2);pre(4);    cout<<"Enter Choice from List : ";

			goto confirm;


		}  ///end confirm;


	}  


	else{

		br(2);pre(4);  echo("Please Choose From List "); br(2); Sleep(300);

		goto albumlist;

	}  
}

	void echo(char print[]){
			cout<<print;
		}

	void br(int line){
	for(int i=0; i<line;i++){
		cout<<endl;
		}
	}

	void pre(int tab){

	for(int i=0; i<tab;i++){
		cout<<"\t";
	}
	
	}
	void span(int space){

	for(int i=0; i<space;i++){
		cout<<" ";
		}

	}

	void main_menu(){

	system("cls");
	br(5); pre(3); echo(">> 1. Song Albums List"); Sleep(400);
	br(2); pre(3); echo(">> 2. Admin Panel"); Sleep(400);
	br(2); pre(3); echo(">> 3. Exit");  Sleep(400);
	br(1);

	}

	void insertend(int data, char albumname[25],char artistname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->albumname,albumname);
	strcpy(temp->artistname,artistname);
	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

	}

	void insertfirst(int data, char albumname[25],char artistname[25] ,int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->albumname,albumname);
	strcpy(temp->artistname,artistname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

	}

	void insertmid(int pos, int data, char albumname[25], char artistname[25],int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->albumname,albumname);
	strcpy(temp->artistname,artistname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	
	}

	void deletealbum(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			system("cls");
			cout<<"\n\n\n\n\t\t\tDeleting Item  "<<serial;for(int cs=0;cs<4;cs++){cout<<" .";Sleep(400);}

			cout<<"\n\n\n\n\t\t\tDeleted Successfully \n"; Sleep(500);

		}
		else{
			cout<<"\n\n\n\n\t\t\t Item Not Found\n"; Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		system("cls");
		cout<<"\n\n\n\n\t\t\tDeleting Item  "<<serial;for(int cs=0;cs<4;cs++){cout<<" .";Sleep(400);}

		cout<<"\n\n\n\n\t\t\tDeleted Successfully \n"; Sleep(500);

		head = temp ;

		list=head;
	}
}

	void updatealbum(int udata, int uquantity){

		node *temp;
		temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

	}

	int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

	}
	void albumlist(){

	cout<<"\n\n\t\t"; 			
	cout<<"____________________________________________________________________________________________ ";
	cout<<"\n\t\t";
	cout<<"|  Item No.    |   Album Name            |   Artist Name          |  Price    |   In Stock  |";
	cout<<"\n\t\t";
	cout<<"---------------------------------------------------------------------------------------------";

	node *temp;

	temp = list;

	while(temp != NULL){
		
		printf("\n\t\t|  %d           |   %s          |   %s        |  %0.2f   |     %d      |",temp->data,temp->albumname,temp->artistname,temp->price, temp->quantity);
		
		cout<<"\n\t\t";
		cout<<"---------------------------------------------------------------------------------------------";

		temp = temp->next ;

		Sleep(100);

		}
	}


	void order_view(int order, int quantity, int or_no){

	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){

		cout<<"\n\t\t"; 
		cout<<or_no<<"\t"<<temp->albumname <<"\t"<<quantity<<"\t"<<temp->quantity;
		cout<<"\n\t\t"; 
		cout<<"-------------------------------------------------------";
		Sleep(100);

	}

	}
	//STYLE FUNCTION
	void pwellcome(){
		
		char welcome[50]="WELCOME";
		char welcome2[50]=" TO";
		char welcome3[50]=" THIYA'S SONG FACTORY";
		char welcome4[50]=" MANAGEMENT SYSTEM :)";
		cout<<"\n\n\n\n\n\t\t\t";

	for(int wlc=0; wlc<strlen(welcome);wlc++){

		cout<<" "<<welcome[wlc];
		Sleep(100);
	}
	cout<<"\n\n\t\t\t\t ";
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		cout<<" "<<welcome2[wlc2];
		Sleep(100);
	}
	cout<<"\n\n\n\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			cout<<" "<<welcome3[wlc3];
		}
		else{

			cout<<" "<<welcome3[wlc3];
		}

		Sleep(100);
	}
	
	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			cout<<" "<<welcome4[wlc3];
		}
		else{

			cout<<" "<<welcome4[wlc3];
		}
		Sleep(100);
	}
	time_t t;
	time(&t);
	cout<<"\n\n\n\n";
		cout<<"\t\t-------------------------------------------------";
		cout<<"\n\t\tCurrent date and time : "<<ctime(&t);
		cout<<"\t\t-------------------------------------------------";
		cout<<endl<<endl;
		system("\n\t\tpause");
}
	void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		system("cls");
		system("COLOR 05");

		cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<i<<(" % Loading...\n\n\t\t");
		cout<<" ";

		for (int j=0; j<i;j+=2){
		cout<<" ";
		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

	}
	void backuploader(void){

	for (int i=15;i<=100;i+=5)
	{

		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<i<<(" % Backing UP DATA...\n\n\t\t");
		cout<<"";

		for (int j=0; j<i;j+=2){

			cout<<" ";
		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

	}
	void midline(void)
	{
		cout<<"\n\n\n\n\n\n\n";
	}

	void midtab(void)
	{
		cout<<"\t\t\t\t\t";
	}
