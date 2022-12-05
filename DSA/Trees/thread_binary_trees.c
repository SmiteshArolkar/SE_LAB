#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
    struct node *left;
    bool lthread;
    int info;
    bool rthread;
    struct node *right;
};
struct node *insert(struct node *root,int ikey)
{   int f=0;
    struct node *ptr,*par,*temp;
    ptr=root;
    par=NULL;
    while (ptr!=NULL)
    {
        if(ptr->info==ikey)
        {
            f=1;
            break;
        }
        par=ptr;
       if(ikey<ptr->info)
            {
                if(ptr->lthread==false)
                    ptr=ptr->left;
                else 
                     break;
            }
       else
            {
                if(ptr->rthread==false)
                    ptr=ptr->right;
                else 
                    break;
            }
    }
    if(f==1)
    printf("Duplicate Key\n");
    else{
       temp=(struct node*)malloc(sizeof(struct node));
       temp->info=ikey;
       temp->lthread=true;
       temp->rthread=true;
       if(par==NULL)
       {   root=temp;
           temp->left=NULL;
           temp->right=NULL;
       }
       else if(ikey<par->info)
        {
            temp->left=par->left;
            temp->right=par;
            par->lthread=false;
            par->left=temp;
        }
        else
        {
            temp->left=par;
            temp->right=par->right;
            par->rthread=false;
            par->right=temp;
        }
       }
    return root;
}
struct node *insucc(struct node *ptr)
{
    if(ptr->rthread==true)
            return ptr->right;
    else 
      {  ptr=ptr->right;
        while(ptr->lthread==false)
                ptr=ptr->left;
        return ptr;
      } 
}
struct node *inpre(struct node *ptr)
{
    if(ptr->lthread==true)
         return ptr->left;
    else
    {
        ptr=ptr->left;
        while(ptr->rthread==false)
                ptr=ptr->right;
        return ptr;
    }
}
struct node *case_a(struct node *root,struct node *par,struct node *ptr)
{
    if(par==NULL)
       root=NULL;
    else if(ptr==par->left)
    {
        par->left=ptr->left;
        par->lthread=true;
    }
    else
    {
        par->right=ptr->right;
        par->rthread=true;
    }
    free(ptr);
    return root;
}
struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
    struct node *child,*s,*p;
    if(ptr->lthread==false)
        child=ptr->left;
    else
        child=ptr->right;
    if(par==NULL)
        root=child;
    else if(ptr==par->left)
            par->left=child;
    else 
        par->right=child;
    s=insucc(ptr); 
    p=inpre(ptr);
    if(ptr->lthread==false)
         p->right=s;
    else
    {
        if(ptr->rthread==false)
           s->left=p;
    }     
    free(ptr);
    return root;
}
struct node *case_c(struct node *root,struct node *par,struct node *ptr)
{
    struct node *parsucc,*succ;
    parsucc=ptr;
    succ=ptr->right;
    while(succ->left!=ptr)
     {
        parsucc=succ;
        succ=succ->left;
     }
     ptr->info=succ->info;
     if(succ->lthread==true&&succ->rthread==true)
         root=case_a(root,parsucc,succ);
    else 
        root=case_b(root,parsucc,succ);
    return root;
}
struct node *del(struct node *root,int dkey)
{   int f=1;
    struct node *ptr,*par;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(ptr->info==dkey)
        { f=0;
        break;
        }
        par=ptr;
       if(dkey<ptr->info)
            {
                if(ptr->lthread==false)
                    ptr=ptr->left;
                else 
                     break;
            }
       else
            {
                if(ptr->rthread==false)
                    ptr=ptr->right;
                else 
                    break;
            }
    }
    if(f==1)
    printf("Key not found\n");
    else
    {
        if(ptr->lthread==false&&ptr->rthread==false)
            root=case_c(root,par,ptr);
        else if(ptr->right==false||ptr->lthread==false)
            root=case_b(root,par,ptr);
        else 
            root= case_a(root,par,ptr);
    }
    return root;
}
struct node *search(struct node *root,int ikey)
{ 
    struct node *ptr=root;
    while(ptr->lthread!=true&&ptr->rthread!=true)
    {
        if(ikey<ptr->info)
            ptr=ptr->left;
        else if(ikey>ptr->info)
               ptr=ptr->right;
        else
            return ptr;
    }
    printf("Not Found\n");
    return NULL;
}
void inoder(struct node *root)
{
    struct node *ptr=root;
    if(root==NULL){
       printf("Tree is Empty\n");
       return;
    }
    while(ptr->left!=NULL)
          ptr=ptr->left;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=insucc(ptr);
    }
    printf("\n");
}
int main()
{
    struct node *root=NULL,*p;
    int ch,key;
     while(1)
    {
    printf("1] Insert Node\n");
	printf("2] Delete Node\n");
    printf("3] Search a Node\n");
	printf("4] Inorder Travesal\n");
	printf("5] Exit\n");    
	printf("what do you want to do\n");
	scanf("%d",&ch);
	switch(ch)
    {
        case 1:
        printf("Enter Node \n");
        scanf("%d",&key);
        root=insert(root,key);
        break;
        case 2:
        printf("Enter Node \n");
        scanf("%d",&key);
        root=del(root,key);
        break;
        case 3:
        printf("Enter the Node to be Search\n");
        scanf("%d",&key);
        p=search(root,key);
        if(p!=NULL)
           printf("Search is Successful\n");
        break;
        case 4:
        inoder(root);
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Wrong choice\n");
    }
    }
}
