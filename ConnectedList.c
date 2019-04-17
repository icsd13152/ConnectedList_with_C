

#include <stdio.h>
#include <stdlib.h>

//orismos domhs komvou
struct node
{
    double num;//periexomeno
    struct node *prev;//deikths sto prohgoumeno stoixeio
    struct node *next;//deikths sto epomeno stoixeio
};

struct node *head3=NULL;//global metavliti gia to head ths tritis listas
struct node *tail3=NULL;//global metavliti gia to tail ths tritis listas

//protypa synarthsewn poy ylopoioume
void addNodeSingle(struct node **,struct node **,double,int);
void displayList(struct node **,struct node **);
void countList(struct node **,struct node **);
void deleteLast(struct node **,struct node **);
void deleteNode(struct node **,struct node **,double);
struct node* appendLists(struct node **,struct node **,struct node **,struct node **);
struct node* searchData(struct node **,struct node **,double);
//voithitikh synarthsh gia auksousa taksinomisi ths listas
void sortListASC(struct node **,struct node **);
void ReversedisplayList(struct node **,struct node **);
void swapElements(struct node **,struct node **);

int main()
{
    //dhmiourgia tis prwtis listas, dhladh tou deikth head kai tou deikth tail pou arxika deixnoun NULL
    struct node *head,*tail;
    head=NULL;
    tail=NULL;

    addNodeSingle(&head,&tail,5.0,0);
    //displayList(&head,&tail);
    addNodeSingle(&head,&tail,6.0,0);
    //displayList(&head,&tail);
    addNodeSingle(&head,&tail,7.0,1);
    //displayList(&head,&tail);
    addNodeSingle(&head,&tail,9.0,1);
    //displayList(&head,&tail);

    countList(&head,&tail);

    deleteLast(&head,&tail);
    //displayList(&head,&tail);

    deleteNode(&head,&tail,5.0);
    //displayList(&head,&tail);
    deleteNode(&head,&tail,4.0);
    //displayList(&head,&tail);

    //dhmiourgia tis deuteris listas
    struct node *head2,*tail2;
    head2=NULL;
    tail2=NULL;
    addNodeSingle(&head2,&tail2,1.0,0);
    addNodeSingle(&head2,&tail2,2.0,0);
    addNodeSingle(&head2,&tail2,3.0,1);

    printf("\nLIST1: ");
    displayList(&head,&tail);

    printf("\nLIST2: ");
    displayList(&head2,&tail2);

    //dhmiourgia triths listas gia synenwsh twn dyo parapanw

    printf("\nLIST3: ");
    displayList(&head3,&tail3);

    struct node *append;
    append=appendLists(&head,&tail,&head2,&tail2);
    if (append==NULL)
    {
        printf("\nH lista einai adeia\n");
    }
    else
    {
        printf("\nH dieuthinsi tou deikth head ths neas taksinomhmenhs listas einai: %d\n",append);
    }

    printf("\nmain: ");
    displayList(&append,&tail3);


    //anazhthsh arithnou sthn trith lista
    struct node *search;
    search=searchData(&head3,&tail3,7.0);

    if (search==NULL)
    {
        printf("\nO arithmos den yparxei sth lista.\n");
    }
    else
    {
        printf("\nO arithmos yparxei sth lista");
        printf("\nH dieuthinsi tou deikth tou komvou einai: %d\n",search);
    }

    printf("\nTrith lista: ");
    displayList(&head3,&tail3);

    printf("\nReversed Trith lista: ");
    ReversedisplayList(&head3,&tail3);

    printf("\nTriti Lista meta to swap: ");
    swapElements(&head3,&tail3);

    return 0;
}

//synarthseis gia ta erwthmata tou fylladiou

//1
void addNodeSingle(struct node **hd,struct node **tl,double nm,int ch)
{
    //dhmiourgia dyo komvwn k kai temp
    struct node *k;
    k=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    //elegxos an h lista einai adeia
    if (*hd==NULL)
    {
        //efoson h lista einai adeia, tote to head kai to tail deixnoun ston idio komvo
        *hd=k;
        *tl=k;
        k->num=nm;
        k->next=NULL;
        k->prev=(*hd);
    }
    else
    {
        if (ch==0)//an vazei komvo sthn arxh ths listas
        {
            temp=(*hd);
            k->num=nm;
            k->next=temp;
            k->prev=(*hd);
            temp->prev=k;
            *hd=k;
        }
        else//alliws an vazei sto telos ths listas
        {
            temp=(*hd);
            //prospelash ths listas
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=k;//to teleutaio tis listas deixnei sto neo kombo
            k->num=nm;
            k->prev=temp;//o prev tou neou kombou deixnei ston prohoumeno teleutaio
            *tl=k;//to tail deixnei ston kainourgio komvo
            k->next=NULL;
        }
    }
}

//2
void countList(struct node **hd,struct node **tl)
{
    int count=0;
    struct node *current=(*hd);
    //prospelash ths listas mexri na brei to tail
    while (current!=(*tl))
    {
        current=current->next;
        count++;
        if (current==(*tl))
            count++;
    }
    printf("\nPlithos stoixeiwn listas: %d\n", count);
}

//3
void displayList(struct node **hd,struct node **tl)
{
    struct node *current=(*hd);
    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }
    printf("\nHEAD -> ");
    //prospelash ths listas mexri to tail
    while (current!=(*tl))
    {
        printf("%.1lf -> ", current->num);
        current=current->next;
        if (current==(*tl))
            printf("%.1lf -> ",current->num);
    }
    printf("TAIL");
    printf("\n");
}

//4
void deleteLast(struct node **hd,struct node **tl)
{
    //o komvos temp einai ena mprosta tou current
    struct node *current=(*hd);
    struct node *temp=current->next;

    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }

    //prospelash ths listas mexri na ginei tail
    while (current!=(*tl))
    {
        //an o temp einai adeios, dhladh to telos ths listas
        if (temp==(*tl))
        {
            *tl=current;//to tail pleon deixnei sto proteleutaio stoixeio
            current->next=NULL;//o deikths next deixnei se NULL
            free(temp);//apodesmeush mnhmhs
        }
        else//alliws prospelash ths listas
        {
            temp=temp->next;
            current=current->next;
        }
    }
}

//5
void deleteNode(struct node **hd,struct node **tl,double nm)
{
    //o komvos temp einai ena mprosta tou current
    struct node *current=(*hd);
    struct node *temp=current->next;
    int flag=0;

    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }

    //prospelash ths listas
    while (current!=(*tl))
    {
        if (temp->num==nm)
        {
            current->next=temp->next;//o prohgoumenos komvos dixnei sto epomeno tou epomenou apo ton komvo pou tha diagrafei
            current->prev=temp->prev;
            free(temp);//apodesmeush mnhmhs
            flag=1;
        }
        else//prospelash ths listas me tis dyo metavlhtes se komvo
        {
            temp=temp->next;
            current=current->next;
        }
    }
    if(flag==0)
    {
        printf("\nO arithmos den vrethike sth lista!\n");
    }
}

//6
struct node* appendLists(struct node **hd1,struct node **tl1,struct node **hd2,struct node **tl2)
{
    //dhhlwsh triwn deiktwn se lista
    struct node *k1=(*hd1);
    struct node *k2=(*hd2);
    struct node *k3;

    k3=NULL;

    //prospelash ths prwths listas
    while (k1!=(*tl1))
    {
        addNodeSingle(&k3,&tail3,k1->num,0);//ekxwrish tou trexontos stoixeiou ths prwths sthn arxh ths triths kathe fora mesw ths synarthshs addNodeSingle
        k1=k1->next;
        if (k1==(*tl1))
            addNodeSingle(&k3,&tail3,k1->num,0);
    }

    //prospelash ths deuterhs listas
    while (k2!=(*tl2))
    {
        addNodeSingle(&k3,&tail3,k2->num,0);//ekxwrish tou trexontos stoixeiou ths deuterhs sthn arxh ths triths kathe fora mesw ths synarthshs addNodeSingle
        k2=k2->next;
        if (k2==(*tl2))
            addNodeSingle(&k3,&tail3,k2->num,0);
    }

    printf("\nk3 arxika: ");
    displayList(&k3,&tail3);

    //auksousa taksinomisi ths triths listas
    sortListASC(&k3,&tail3);

    printf("\nk3 SORTED: ");
    displayList(&k3,&tail3);

    head3=k3;
    return k3;//epistrofh tou head, mesw tou topikou k3, efoson to tail3 to exoume kanei global
}

//7
struct node* searchData(struct node **hd,struct node **tl,double nm)
{
    struct node *current=(*hd);
    int flag=0;

    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }

    //prospelash ths listas
    while (current!=(*tl))
    {
        if (current->num==nm)//an to stoixeio pou dwsame vrethei sth lista
        {
            flag++;
            return current;
        }
        else//alliws synexizei h prospelash ths listas
        {
            current=current->next;
            if (current==(*tl))
            {
                if (current->num==nm)//an to stoixeio pou dwsame vrethei sth lista
                {
                    flag++;
                    return current;
                }
            }
        }
    }
    if (flag==0)
        return NULL;
}

//voithitkh synarthsh gia auksousa taksinomish ths listas pou dexetai ws parametro
void sortListASC(struct node **hd,struct node **tl)
{
    int i,flag;
    struct node *current=(*hd);
    struct node *ptr=NULL;

    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }
    //oso h flag einai 0
    do
    {
        flag=0;
        current=(*hd);
        //diatrexoume th lista kathe fora gia kathe stoixeio, kai to sygkrinoume me kathe epomeno gia na ginei h taksinomisi
        while (current->next!=ptr)
        {
            //an to trexon periexomeno einai megalutero apo to epomeno periexomeno
            if ( (current->num) > (current->next->num) )
            {
                //swap twn stoixeiwn ths listas gia taksinomisi me th voitheia mias int metavlitis temp
                double temp = current->num;
                current->num = current->next->num;
                current->next->num = temp;
                flag=1;
            }
            current=current->next;
        }
        //epomeno stoixeio gia sigkrisi me ta ypoloipa
        ptr=current;
    }
    while (flag!=0);
}

void ReversedisplayList(struct node **hd,struct node **tl)
{
    struct node *current=(*hd);
    struct node *temp;
    //elegxos an h lista einai adeia
    if (current==NULL)
    {
        printf("\nH lista einai adeia!");
    }
/*
    while(current!=(*tl))
    {
        printf("\nhead=%d \n",*hd);

        temp=current;
        current=current->next;
        printf("\ncurrent->prev=%d \n",current->prev);
    }*/
    current=(*tl);
    printf("\nTAIL -> ");
    while(current!=(*hd))
    {
        printf("%.1lf -> ",current->num);
        current=current->prev;
        if(current==(*hd))
        {
            printf("%.1lf -> ",current->num);
        }
    }
    printf("HEAD\n");
}

void swapElements(struct node **hd,struct node **tl)
{
    struct node *first=(*hd);
    struct node *last=(*tl);

    struct node *temp=first;
    struct node *temp2;

    temp2->num=(*tl)->num;

    while (first!=(*tl))
    {
        first=first->next;
        if (first==(*tl))
        {
            first->num=temp->num;
        }
    }

   while (last!=(*hd))
    {
        last=last->prev;
        if (last==(*hd))
        {
            last->num=temp2->num;
        }
    }

    displayList(&last,&first);
}
