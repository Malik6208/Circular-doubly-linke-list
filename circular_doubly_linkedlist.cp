//implementation of circular doubly linked list
 #include<stdio.h>
 #include<stdlib.h>
 #include<process.h>
 struct node
 {
 	int info;
 	struct node *llink,*rlink;
 };
 struct node *first=NULL,*last=NULL;
 void create();
 void display();
 void sinsert();
 void einsert();
 void pinsert();
 void sdelete();
 void edelete();
 void pdelete();
 void search();
 void countnode();
 void sort();
 void reverse();
 void main()
 {
 	int choice;
 	do
 	{
 		printf("\nenter 1.for create a new node");
		printf("\nenter 2.for display all nodes");
		printf("\nenter 3.for sinsert");
		printf("\nenter 4.for einsert");
		printf("\nenter 5.for pinserrt");
		printf("\nenter 6.for sdelete");
		printf("\nenter 7.for edelete");
		printf("\nenter 8.for pdelete");
		printf("\nenter 9.for searching node");
		printf("\nenter 10.for print total no of nodes");
		printf("\nenter 11.for sorting a node");
		printf("\nenter 12.for reverse");
		printf("\nenter 13.for exit from program");
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				sinsert();
				break;
			case 4:
				einsert();
				break;
			case 5:
				pinsert();
				break;
			case 6:
				sdelete();
				break;
			case 7:
				edelete();
				break;
			case 8:
				pdelete();
				break;
			case 9:
				search();
				break;
			case 10:
				countnode();
				break;
			case 11:
				sort();
				break;
			case 12:
				reverse();
				break;
			case 13:
				exit(0);
				break;
			default:
				printf("\ninvalid choice");
		}
	 }
	 while(choice>=1 && choice <=13);
 }
 void create()
 {
 	struct node *new;
 	new=(struct node *)malloc(sizeof(struct node));
 	printf("\nenter value of node:");
 	scanf("%d",&new->info);
 	if(first==NULL)
 	first=new;
 	else
 	{
 	last->rlink=new;
	new->llink=last;	
	}
	last=new;
	last->rlink=first;
	first->llink=last;
 }
 void display()
 {
 	struct node *temp;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		printf("\nall nodes are:");
 		temp=first;
 		do
 		{
 			printf("%d\t",temp->info);
 			temp=temp->rlink;
		}
		while(temp!=first);
		printf("\n");
	}
 }
 void sinsert()
 {
 	struct node *new;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		new=(struct node *)malloc(sizeof(struct node));
 		printf("\nenter value of node:");
 		scanf("%d",&new->info);
 		first->llink=new;
 		new->rlink=first;
 		first=new;
 		first->llink=last;
 		last->rlink=first;
	}
 }
 void einsert()
 {
 	struct node *new;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		new=(struct node *)malloc(sizeof(struct node));
 		printf("\nenter value of new node:");
 		scanf("%d",&new->info);
 		last->rlink=new;
 		new->llink=last;
 		last=new;
 		last->rlink=first;
 		first->llink=last;
	 }
 }
 void pinsert()
 {
 	struct node *new,*temp,*prev;
 	int position,i,count=0;
 	if(first==NULL)
 	printf("\nno any node");
 	else
 	{
 		printf("\nenter value of position:");
 		scanf("%d",&position);
 		for(temp=first;temp!=last;temp=temp->rlink)
 		{
 			count++;
		}
		if(position>1 && position<=count)
		new=(struct node *)malloc(sizeof(struct node));
		printf("\nenter value of node:");
		scanf("%d",&new->info);
		for(temp=first,i=1;i!=position;i++,temp=temp->rlink)
		{
			prev=temp;
		}
		prev->rlink=new;
		new->llink=prev;
		new->rlink=temp;
		temp->llink=new;
	 }
 }
 void sdelete()
 {
 	if(first==NULL)
 	printf("no any node");
	else
	{
		printf("\ndeleted node=%d\n",first->info);
		first=first->rlink;
		first->llink=last;
		last->rlink=first;
	}
 }
 void edelete()
 {
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		printf("\ndeleted node=%d\n",last->info);
 		last=last->llink;
 		last->rlink=first;
 		first->llink=last;
	}
 }
 void pdelete()
 {
 	struct node *prev,*temp;
 	int position,i,count=0;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		printf("\nenter value of position:");
 		scanf("%d",&position);
 		temp=first;
 		do
 		{
 			count++;
 			temp=temp->rlink;
		 }
		 while(temp!=first);
		 if(position>1 && position<count)
		 {
		 for(temp=first,i=1;i!=position;i++,temp=temp->rlink)
		 {
		 	prev=temp;
		 }
		 printf("\ndeleted node=%d\n",temp->info);
		 prev->rlink=temp->rlink;
		 temp->llink=prev;
		}
		 else
		 printf("invalid position\n");
	 }
 }
 void search()
 {
 	struct node *temp;
 	int svalue,flag=0;
 	if(first==NULL)
 	printf("\nno any node");
 	else
 	{
 		printf("\nenter searching value:");
 		scanf("%d",&svalue);
 		temp=first;
 		do
 		{
 			if(temp->info==svalue)
 			{
 			flag=1;
 			break;
 			}
 			temp=temp->rlink;
		}
		while(temp!=first);
		if(flag==1)
		printf("searching found\n");
		else
		printf("searching not found\n");
	}
 }
 void countnode()
 {
 	struct node *temp;
 	int count=0;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		temp=first;
 		do
 		{
 			count++;
 			temp=temp->rlink;
		 }
		 while(temp!=first);
		 printf("\n total no of nodes=%d\n",count);
	 }
 }
 //problem
 void sort()
 {
 	int temp;
 	struct node *temp1,*temp2;
 	if(first==NULL)
 	printf("no any node");
 	else
 	{
 		for(temp1=first;temp2!=last;temp1=temp1->rlink)
 		{
 			for(temp2=temp1->rlink;temp2!=last;temp2=temp2->rlink)
		 	{
		 	 if(temp1->info > temp2->info)
		 		{
		 		temp=temp1->info;
				temp1->info=temp2->info;
				temp2->info=temp;
		 		}
	 		}
 		}
	}
}
void reverse()
{
	struct node *temp;
	int i,j,a[50];
	if(first==NULL)
	printf("no any node");
	else
	{
		printf("\nall nodes are:");
		temp=first,i=1;
		do
		{
			a[i]=temp->info;
			temp=temp->rlink,i++;
		}
		while(temp!=first);
		for(j=i-1;j>=1;j--)
		printf("%d\t",a[j]);
		printf("\n");
	}
}
