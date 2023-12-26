#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) {
	if(fromwho==WATER||fromwho==PLAYER){
        if(size==1||size==2){
		   size=size+1;
		   return 0;
	    }
		if(size==3){
		   set2void(x,y,splash);
		   size=0;
		   if(x>0){
               splash->score+=splash->map[x-1][y]->act(DOWN,WATER);
		   }
		   if(x<splash->size-1){
               splash->score+=splash->map[x+1][y]->act(UP,WATER);
		   }
		   if(y>0){
			   splash->score+=splash->map[x][y-1]->act(RIGHT,WATER);
		   }
		   if(y<splash->size-1){
			   splash->score+=splash->map[x][y+1]->act(LEFT,WATER);
		   }
		   return 1;
        }
	}else if(fromwho==TOXIC){
		if(size==1){
			set2void(x,y,splash);
			size=0;
			return 0;
		}
		if(size==2||size==3){
            size=size-1;
			return 0;
		}
	}
	
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	if(fromwho==PLAYER){
		cout<<"Error: Cannot act a Void."<<endl;
	}
	if(fromwho==WATER||fromwho==TOXIC){
		switch(fromwhere) {
			case LEFT:
			    if(y<splash->size-1){
			        splash->score+=splash->map[x][y+1]->act(LEFT,fromwho);
		        }
				break;
			case RIGHT:
			    if(y>0){
			        splash->score+=splash->map[x][y-1]->act(RIGHT,fromwho);
		        }
				break;
			case UP:
			    if(x<splash->size-1){
                    splash->score+=splash->map[x+1][y]->act(UP,fromwho);
		        }
				break;
			case DOWN:
                if(x>0){
                    splash->score+=splash->map[x-1][y]->act(DOWN,fromwho);
		        }
				break;
		}
	}
	return 0;
}
int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	if(fromwho==PLAYER){
        cout<<"Error: Cannot act a Barrier."<<endl;
	}
	return 0;
}
int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	if(fromwho==TOXIC||fromwho==PLAYER){
        if(size==1||size==2){
		   size=size+1;
		   return 0;
	    }
	    if(size==3){
		   set2void(x,y,splash);
		   size=0;
		   if(x>0){
               splash->score+=splash->map[x-1][y]->act(DOWN,TOXIC);
		   }
		   if(x<splash->size-1){
               splash->score+=splash->map[x+1][y]->act(UP,TOXIC);
		   }
		   if(y>0){
			   splash->score+=splash->map[x][y-1]->act(RIGHT,TOXIC);
		   }
		   if(y<splash->size-1){
			   splash->score+=splash->map[x][y+1]->act(LEFT,TOXIC);
		   }
		   return -1;
        }
	}else if(fromwho==WATER){
		if(size==1){
			set2void(x,y,splash);
			size=0;
			return 0;
		}
	    if(size==2||size==3){
            size=size-1;
			return 0;
		}
	}
	
}