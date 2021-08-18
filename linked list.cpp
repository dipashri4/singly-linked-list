
/*   @shinde dipashri
      code on singly linked list
*/

#include<iostream>
using namespace std;
struct node{
	int data;
	node *head,*tail,*temp;
	node* next;
};
class Ll{
public:
	node *head,*tail,*temp;
	bool createnew(){
		node* nnode=new node;
		if(head==NULL){
    		head=tail=nnode;
    		cout<<"data inserted successfully\n";
        }
        else
            return 0;
	}
	bool emptyll(){
		if(head==NULL){
		cout<<"linked list is empty\n";
    }
    else{
    	return 0;
    }
	}
void insertatend(){
	node* nnode=new node;
    nnode->next=NULL;
	cout<<"\nenter data\n";
    cin>>nnode->data;
	if(head==NULL){
		head=tail=nnode;
    	cout<<"data inserted successfully\n";
	}
    else{
    	tail->next=nnode;
    	tail=nnode;
        	
	}
}
void insertatstart(){
	node* nnode=new node;
	nnode->next=NULL;
    cout<<"\nenter data\n";
	cin>>nnode->data;
	if(head==NULL){
		head=tail=nnode;
    	cout<<"data inserted successfully\n";
    }
    else{
    	nnode->next=head;
    	head=nnode;
    }
}
void insertatany(){
	int n;
	node* nnode=new node;
	nnode->next=NULL;
    cout<<"\nenter data\n";
	cin>>nnode->data;
	if(head==NULL){
		head=tail=nnode;
    	cout<<"data inserted successfully\n";
    }
    else{
    	cout<<"enter node value after which insertion is to be performed "<<endl;
    	cin>>n;
    	cout<<"data inserted successfully\n";
    	temp=head;
    	while(temp->data!=n){
    		temp=temp->next;
		}
		nnode->next=temp->next;
		temp->next=nnode;
	}
}

/*void deletehead(){
	if(emptyll()){
    }
    else{
    	temp=head;
    	head=head->next;
    	delete temp;
    	cout<<"node deleted successfully\n";
	}
}*/
/*void deletetail(){
	node* temp1;
	if(emptyll()){
    }
    else{
    	temp1=head;
    	temp=temp1->next;
    	while(temp->next!=NULL){
		    temp=temp->next;
		    temp1=temp1->next;
	    }
	    tail=temp1;
    	delete temp;
    	tail->next=NULL;
    	cout<<"node deleted successfully\n";
	}
}*/
void deleteany(){   //it is combine function for delete head node, delete tail node ,delete intermediate node
	int m;
	node* temp1;
	if(emptyll()){
    }
    else{
    	cout<<"\nwhich node to be deleted\n";
    	cin>>m;
    	if(head->data==m){
    		temp=head;
    	    head=head->next;
        	delete temp;
        	cout<<"node deleted successfully\n";
		}
		else{
			temp1=head;
    	    temp=temp1->next;
        	while(temp->data!=m){
        		temp=temp->next;
	    	    temp1=temp1->next;
   	        }
    	    if(temp->next==NULL){
    	    	tail=temp1;
        	    delete temp;
        	    tail->next=NULL;
            	cout<<"node deleted successfully\n";
	    	}
    		else{
    			temp1->next=temp->next;
            	delete temp;
            	cout<<"node deleted successfully\n";
	    	}
    	}
	}
}
void display(){
	if(emptyll()){
    }
    else{
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
    }
}
void search(){
	int c,found=0;
	if(emptyll()){
    }
    else{
	cout<<"\nwhich node to be search ";
	cin>>c;
	cout<<endl;
	temp=head;
	while(temp!=NULL){
		if(temp->data==c){
    		found=1;
    		break;
    	}
    	else{
    		temp=temp->next;
    	}
    }
    if(found==1){
    	cout<<"node is found\n ";
	}
    else{
    	cout<<"node not found \n";
	}
    }
}
void reverse(){
	if(emptyll()){
    }
    else{
	    node* prevptr=NULL;
	    node* curr=head;
    	node* nextptr;
    	while(curr!=NULL){
    		nextptr=curr->next;//make a nextptr
      		curr->next=prevptr;//chage a link
		
    		//make new prevptr,curr,nextptr
    		prevptr=curr;//new name=old name
    		curr=nextptr;
    	}
    	head=prevptr;
    }
}
};
int main(){
	Ll obj;
	int n;
	while(1){
	    cout<<"\nenter your choice\n1:insert_at_start\n2:insert at end\n3:insert_in between_position\n4:delete node\n5:search\n6:reverse a linked list\n7:display ";
	    cin>>n;
	    switch(n){
	    	case 1:{
			    obj.insertatstart();
			    cout<<"\nlinked list is "<<endl;
		    	obj.display();
			    break;
	    	}
	    	case 2:{
			    obj.insertatend();
			    cout<<"\nlinked list is "<<endl;
		    	obj.display();
			    break;
	    	}
	    	case 3:{
			    obj.insertatany();
			    cout<<"\nlinked list is "<<endl;
		    	obj.display();
			    break;
	    	}
	    	case 4:{
			    obj.deleteany();
			    cout<<"\nlinked list is "<<endl;
		    	obj.display();
			    break;
	    	}
	    	case 5:{
			    obj.search();
			    break;
	    	}
	    	case 6:{
			    obj.reverse();
			    cout<<"\nreverse linked list is "<<endl;
		    	obj.display();
			    break;
	    	}
	    	case 7:{
	    		cout<<"\nlinked list is "<<endl;
		    	obj.display();
		    	break;
	    	}
	    	default:{
	    		cout<<"\nenter valid choice\n";
				break;
			}
		
    	}
    } 
	return 0;
}
