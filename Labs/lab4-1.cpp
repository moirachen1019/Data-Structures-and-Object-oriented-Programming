#include <iostream>
using namespace std;

class Room{
public:
Room *left_room;
Room *right_room;
int index;
Room(){

}
//add constructor or functions if you need
};

void insert(class Room**head, int data){
class Room* newroom = new Room;
newroom -> index = data;
newroom -> right_room = (*head);
newroom -> left_room = NULL;

if ((*head)!= NULL){
(*head) -> left_room = newroom;
}
(*head) = newroom;
}

int main() {
Room* last = new Room;
Room* first = new Room;
int num_of_room;
int num_of_movement;
int room_num;
string move;

first -> index = -1;
first -> right_room = last;

last ->index = -1;
last ->left_room = first;

cin >> num_of_room;
for (int i = 0; i < num_of_room; i++){
cin >> room_num;

Room* temp = new Room;
last -> left_room -> right_room = temp;
temp -> left_room = last -> left_room;
temp -> right_room = last;
last -> left_room = temp;
temp -> index = room_num;
}

Room* now = first -> right_room;

cin >> num_of_movement;

for (int i = 0; i < num_of_movement; i++){
if (i == 0){
cout << now -> index << " ";
}

cin >> move;

if (move == "r"){
now = now -> right_room;
cout << now -> index << " ";
if (now -> index == -1){
now = now -> left_room;
}
}
else{
now = now -> left_room;
cout << now -> index << " ";
if (now -> index == -1){
now = now -> right_room;
}
}
}

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
return 0;
}
