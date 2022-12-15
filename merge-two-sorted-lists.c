#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
};


 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode * node, * temp;
    struct ListNode * MergedList;
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }else if(list1 == NULL){
        return list2;
    }else if(list2 == NULL){
        return list1;
    }else{
        if(list1->val <= list2->val){
            MergedList = list1;
            node = list2;
        }else{
            MergedList = list2;
            node = list1;
        }

        struct ListNode * head = MergedList;

        while(node != NULL){
            while(MergedList->next->val < node->val && MergedList->next != NULL){
                MergedList = MergedList->next;
            }
            temp = node;
            node = node->next;
            temp->next = MergedList->next;
            MergedList->next = temp;
        }
        return head;
    } 
}

struct ListNode * add(int val){
    struct ListNode * node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode * addtoend(struct ListNode * list,int val){
    struct ListNode * node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    struct ListNode * temp = list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return list;
}

int main(){
    struct ListNode * list1, * list2, *finalList;

    list1 = add(1);
    list1 = addtoend(list1, 2);
    list1 = addtoend(list1, 4);
    list2 = add(1);
    list2 = addtoend(list2, 3);
    list2 = addtoend(list2, 4);

    finalList = mergeTwoLists(list1, list2);

    while(finalList != NULL){
        printf("%d ->", finalList->val);
        finalList = finalList->next;
    }
    
    return 0;
}