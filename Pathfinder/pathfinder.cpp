#include <iostream>
#include <stdio.h>
#include "image.h"
#include "deque.hpp"
#include "linked_list.hpp"
#include <algorithm>
#include <array>

struct State{
int row;
int col;
State(){
  row=0;col=0;
}
State& operator=(const State& x){
  row=x.row;
col=x.col;
return *this;
}
};
class Problem{
private: 
State state;
Image<Pixel> im;

public:
Problem(std::string x){
im=readFromFile(x);
}
State& initial(){
  for(int i=0;i<im.width();i++){
    for(int j=0;j<im.height();j++){
      if(im(i,j)==RED){
        //std::cout<<i<<std::endl;
        //std::cout<<j<<std::endl;
        state.row=i;
        state.col=j;
        
        //break;
      }
    }
  }
  return state;
}
bool goal(State &goal){
  if(goal.row==0&&im(goal.row,goal.col)==WHITE){
    return true;
  }
  else if(goal.row==im.height()-1&&im(goal.row,goal.col)==WHITE){
    return true;
  }
  else if(goal.col==0&&im(goal.row,goal.col)==WHITE){
    return true;
  }
  else if(goal.col==im.width()-1&&im(goal.row,goal.col)==WHITE){
    return true;
  }
 
  
  else return false;
}

std::array<State,4> actions(State next){
  std::array<State,4> next_states;
  /*if(next.row>0){
    next_states[0].row=next.row-1;
    next_states[0].col=next.col;
  }
 if(im.height()-1>next.row){
   next_states[1].row=next.row+1;
    next_states[1].col=next.col;
 }
  if(next.col>0){
     next_states[2].row=next.row;
    next_states[2].col=next.col-1;
  }
  if(im.width()-1>next.col){
     next_states[3].row=next.row;
    next_states[3].col=next.col+1;
  }
*/
      if(next.row -1 >= 0 && next.row < im.height() && next.col >= 0 && next.col < im.width()) {
        next_states[0].row = next.row - 1;
        next_states[0].col = next.col;
      }

      //nextrow
      if(next.row + 1 < im.height() && next.row >= 0 && next.col >= 0 && next.col < im.width()) {
        next_states[1].row = next.row + 1;
        next_states[1].col = next.col;
      }
      

      //previouscolumn 
      if(next.col - 1 >= 0 && next.col < im.width() && next.row >= 0 && next.row < im.height()) {
        next_states[2].col = next.col - 1;
        next_states[2].row = next.row;
      }
    
      //nextcolumn
      if(state.col + 1 < im.width() && state.col >= 0 && state.row >= 0 && state.row < im.height()) {
        next_states[3].col = state.col + 1;
        next_states[3].row = state.row; 
      }
    return next_states;
}
};

State breath_first_search(Problem p,Image<Pixel> im){

State s;
std::array<State,4> s_next;
s=p.initial();
std::cout<<s.row<<std::endl;
std::cout<<s.col<<std::endl;

if(p.goal(s)){
  std::cout<<"Solution found"<<std::endl;
  return s;
}
Deque<State,LinkedList<State>> frontier;
bool explored [im.width()][im.height()];
for(int i=0;i<im.width();i++){
  for(int j=0;j<im.height();j++){
    explored[i][j]=false;
  }
}
frontier.pushBack(s);
//std::cout<<std::endl<<"frontier"<<std::endl;

  while(true){
    if(frontier.isEmpty()){
      std::cout<<"no Solution Found"<<std::endl;
      exit(EXIT_FAILURE);
      break;
    }
    s=frontier.front();
    frontier.popFront();
    explored[s.row][s.col]=true;
    s_next=p.actions(s);
    
     for(int j=0;j<s_next.size();j++){
       if(explored[s_next[j].row][s_next[j].col] == false){
         if(p.goal(s_next[j])){
           return s_next[j];
         }
       
        if(im(s_next[j].row,s_next[j].col)==WHITE){
     frontier.pushBack(s_next[j]);
     explored[s_next[j].row][s_next[j].col]=true;
        }
     //std::cout<<"s_next";
      //std::cout<<s_next[j].row<<std::endl;
      //std::cout<<s_next[j].col<<std::endl;}
     //break;
     }
       }
       
       
       
     }
     
   
 return s;
};

int main(int argc, char *argv[])
{
  if (argc != 3) {
    std::cout << "Usage: pathfinder"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }
  

  //std::cout<<"start";
    State solution;
    Problem prob(argv[1]);
    Image<Pixel> im=readFromFile(argv[1]);
    

    for (intmax_t i = 0; i < im.width(); ++i){
      for (intmax_t j = 0; j < im.height(); ++j) {
	if(im(i,j)!=WHITE&&im(i,j)!=RED&&im(i,j)!=BLACK ){
	  //std::cout<<"1failed";
    return EXIT_FAILURE;
	  break;
	}
  if(im(i,j)==RED){
    for(int k=i+1;k<im.height();k++){
      for(int l=j+1;l<im.width();l++){
        if(im(k,l)==RED){
          
          //std::cout<<"2failed";
          return EXIT_FAILURE;
          break;
        }
      }
    }
  }
     
      }
    }
  //std::cout<<"bfs";
    solution=breath_first_search(prob,im);
     std::cout<<solution.row<<std::endl;
    std::cout<<solution.col<<std::endl;
    
    im(solution.row,solution.col)=GREEN;
    writeToFile(im,argv[2]);
   
    return EXIT_SUCCESS; 

}


