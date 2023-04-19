P0

while(1){
    CS
    RS
}

///////////////////

P1

while(1){
    CS
    RS
}

//////////////////////


P0(){
    while(1){
        Entry
        CS
        Exit
        RS
    }
}
////////////////////////

P1(){
    while(1){
        Entry
        CS
        Exit
        RS
    }
}





P0(){
    Entry
    CS
    Exit
}
////////////////////////

P1(){
    Entry
    CS
    Exit
}


///// Start Share 
int share=0;
//// End of Share

P0(){
    Entry
    CS
    Exit
}
////////////////////////

P1(){
    Entry
    CS
    Exit
}


///////////////////
bool flag = false;
//////////////////////


P0(){
    while(1){
        while(flag == true)
          ;
        flag = true;
        CS
        flag = false;
        RS
    }
}
////////////////////////

P1(){
    while(1){
        while(flag == true)
          ;
        flag = true;
        CS
        flag = false;
        RS
    }
}

//////////////////////


while(flag == true)
  ;
flag = true;
CS
flag = false;

//////////////////////////////////

/////////// share ///////////////
int turn = 0;
////////////////////////////////

P0(){
    while(1){
        while(turn == 1)
          ;
        CS
        turn = 1;
        RS
    }
}
////////////////////////

P1(){
    while(1){
        while(turn == 0)
          ;
        CS
        turn = 0;
        RS
    }
}

//////////////////////



//////////////////////////////////

/////////// share ///////////////
int turn = 0;
////////////////////////////////

P0(){
    while(1){
        while(turn == 1)
          ;
        CS
        turn = 1;
        RS
    }
}
///////////

P1(){
    while(1){
        while(turn == 0)
          ;
        CS
        turn = 0;
        RS
    }
}

/////////



//////////////////////////////////

/////////// share ///////////////
bool need[2] = {false,false};
////////////////////////////////

P0(){
    while(1){
        need[0]=true
        while(need[1] == true)
          ;
        CS
        need[0]=false;
        RS
    }
}
///////////

P1(){
    while(1){
        need[1]=true
        while(need[0] == true)
          ;
        CS
        need[1]=false;
        RS
    }
}

/////////


//////////////////////////////////

/////////// share ///////////////
bool need[2] = {false,false};
int turn = 0;
////////////////////////////////

P0(){
    while(1){
        need[0]=true
        while(need[1] == true 
          && turn == 1)   ;
        CS
        need[0]=false;
        RS
    }
}
///////////

P1(){
    while(1){
        need[1]=true
        while(need[0] == true
          && turn == 0)   ;
        CS
        need[1]=false;
        RS
    }
}

/////////


//////////////////////////////////

/////////// share ///////////////
bool need[2] = {false,false};
int turn = 0;
////////////////////////////////

P0(){
    while(1){
        need[0]=true;
        turn=1;
        while(need[1] == true 
          && turn == 1)   ;
        CS
        need[0]=false;
        RS
    }
}
///////////

P1(){
    while(1){
        need[1]=true;
        turn=0;
        while(need[0] == true
          && turn == 0)   ;
        CS
        need[1]=false;
        RS
    }
}

/////////


//////////////////////////////////

/////////// share ///////////////
bool need[2] = {false,false};
int turn = 0;
////////////////////////////////

P0
////
need[0]=true;
turn=1;
while(need[1] == true 
  && turn == 1)   ;
CS
need[0]=false;

////////////////

P1
////
need[1]=true;
turn=0;
while(need[0] == true
  && turn == 0)   ;
CS
need[1]=false;

//////////////////////////////////

/////////// share ///////////////
bool need[2] = {false,false};
int turn = 0;
////////////////////////////////

Pi
////
turn=j;
need[i]=true;
while(need[j] == true 
  && turn == j)   ;
CS
need[i]=false;

////////////////

Pj
////
turn=j;
need[i]=true;
while(need[j] == true
  && turn == j)   ;
CS
need[i]=false;






/////////////////


bool testAndSet(bool &target){
    bool rv=target;
    target=true;
    return rv;
}


//////////////

while(testAndSet(lock))  ;
CS
lock=false;


/////////////////////

Object buffer[9000];

void producer(void){
    Object temp;
    int in = 0;
    do{
        x = produce();
        buffer[in] = x;
        in ++;
    }while(1);
}
void consumer(void){
    Object temp;
    int out = 0;
    do{
        temp = buffer[out];
        out ++;
        consume(temp)
    }while(1);
}
int main(){
   producer();
   consumer();
   return 0;
}


/////////////////////////
