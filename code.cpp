// Practice final solution - instructor copy (Diba Mirza Dec 2, 2022)
// Write your perm number
// Do not include a main function in this file
// Only submit this file
// See code.h for the descriptions of each problem
#include "code.h"


/* Problem 1: 10 pts */
TeaPacket* bestPacket(TeaPacket *head){
   if(!head || !(head->next) ){
      return head;
   }
   int value = head->rarity * head->rating;
   TeaPacket *p = bestPacket(head->next);
   int otherValue = p->rarity* p->rating;
   if(value >= otherValue){
      return head;
   }else{
      return p;
   }
}

/* Problem 2: 10 points*/
Node* insert(Node *head, int value){
   Node* h = new Node{value, 0};

   // empty list
   if (!head) return h;

   Node *tmp = head;
   Node *pre = nullptr;
   bool middle = false;

   // at front
   if (value < head->data){
      h->next = head;
      head = h;
      return head;
   }

   // at middle
   while(tmp){
      if (value < tmp->data){
         pre->next = h;
         h->next = tmp;
         middle = true;
         break;
      }
      pre = tmp;
      tmp = tmp->next;
   }

   // at tail
   if (!middle && !tmp)
      pre->next = h;
   
   return head;
}

/* Problem 3: 10 points*/
bool isBalanced(std::string s){
   int countAs = 0;
   int countBs = 0;
   for(auto i:s){
      if(i=='A'){
         countAs++;
      }else if(i =='B'){
         countBs++;
      }
   }
   return countAs==countBs;
}

