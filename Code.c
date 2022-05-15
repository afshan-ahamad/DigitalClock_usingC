#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delay(unsigned int milliseconds);	//(DECLARATION) TIME DELAY
void num1(int j11);			//(DECLARATION) PRINTING DIGIT1
void num2(int j22);			//(DECLARATION) PRINTING DIGIT2
void num3(int j33);			//(DECLARATION) PRINTING DIGIT3
void num4(int j44);			//(DECLARATION) PRINTING DIGIT4
void num5(int j55);			//(DECLARATION) PRINTING DIGIT5
void num6(int j66);			//(DECLARATION) PRINTING DIGIT6
void num7(int j77);			//(DECLARATION) PRINTING DIGIT7
void num8(int j88);			//(DECLARATION) PRINTING DIGIT8
void num9(int j99);			//(DECLARATION) PRINTING DIGIT9
void num0(int j00);			//(DECLARATION) PRINTING DIGIT0
void colon(int jcolcol);		//(DECLARATION) PRINTING COLON
void moveDown(int positions);		//(DECLARATION) CHANGING THE CURSOR POSITION DOWN
void moveRight(int positions);		//(DECLARATION) CHANGING THE CURSOR POSITION RIGHT
void moveTo(int row, int col);		//(DECLARATION) CHANGING THE CURSOR POSITION TO SPECIFIC ROW,COLUMN


int main(int argc, char **argv){
    int color=37;   			//COLOR VALUE
    int v;
    if(argc==3){     			//CHANGING TO LOWER LETTER THE ARGUMENT COLOR
        for(v=0;v<=strlen(argv[2]);v++){
            if(argv[2][v]>=65 && argv[2][v]<=90){
                argv[2][v]=argv[2][v]+32;
            }
        }
    }


    if( argc>3 || (argc==2 && strcmp(argv[1],"-h")!=0 ) || (argc==3 && strcmp(argv[1],"-c")!=0) ){  //CHECK WHETHWR ITS CORRECT ARGUMENT
        printf("Incorrect usage of arguments.\n");
	printf("usage :\n");
        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
        printf("%s -h for the help about the program\n",argv[0]);
	return -1;
    }else if( (argc==2 && strcmp(argv[1],"-h")==0) ){           				//PRINTING USAGE
        printf("usage : clock -h                quick help on cmd\n");
        printf("usage : clock -c <color>        print clock with a color\n");
	return -1;
    }else if( argc==3 && (strcmp(argv[2],"black")!=0 && strcmp(argv[2],"red")!=0 && strcmp(argv[2],"green")!=0 && strcmp(argv[2],"yellow")!=0 && strcmp(argv[2],"blue")!=0 && strcmp(argv[2],"magenta")!=0 && strcmp(argv[2],"cyan")!=0)){
        printf("%s :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n",argv[2]);                  //PRINTING IF COLOR IS INVALID
	return -1;
    }else if(argc==1 || (argc==3 && strcmp(argv[1],"-c")==0 &&(strcmp(argv[2],"black")==0 || strcmp(argv[2],"red")==0 || strcmp(argv[2],"green")==0 || strcmp(argv[2],"yellow")==0 || strcmp(argv[2],"blue")==0 || strcmp(argv[2],"magenta")==0 || strcmp(argv[2],"cyan")==0)) ) {
           
	    if(strcmp(argv[2],"black")==0)           //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=30;			     //COLOR CODE CHANGE
            else if(strcmp(argv[2],"red")==0)        //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=31;                            //COLOR CODE CHANGE
            else if(strcmp(argv[2],"green")==0)      //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=32;                            //COLOR CODE CHANGE
            else if(strcmp(argv[2],"yellow")==0)     //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=33;                            //COLOR CODE CHANGE
            else if(strcmp(argv[2],"blue")==0)       //CHANGE COLOR CODE IF ARGUMENT IS VALID
               color=34;                             //COLOR CODE CHANGE
            else if(strcmp(argv[2],"magenta")==0)    //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=35;                            //COLOR CODE CHANGE
            else if(strcmp(argv[2],"cyan")==0)       //CHANGE COLOR CODE IF ARGUMENT IS VALID
                color=36;                            //COLOR CODE CHANGE
    }
    while(1){					     // TIME AND PRINT LOOP
   
	system("clear");
        printf("\x1b[0d");
        time_t(systemTime);
        time(&systemTime);
        struct tm *myTime = localtime(&systemTime);
        int x,y,z;
	int hdig1,hdig2,mdig1,mdig2,sdig1,sdig2;
	x = myTime->tm_hour;
	y = myTime->tm_min;
	z = myTime->tm_sec;
	hdig1 = x%10;				     //SEPERATING DIGITS OF HOUR ONES
	hdig2 = x/10;				     //SEPERATING DIGITS OF HOUR TENS
	mdig1 = y%10;				     //SEPERATING DIGITS OF MINUTE ONES
	mdig2 = y/10;				     //SEPERATING DIGITS OF MINUTE TENS
	sdig1 = z%10;				     //SEPERATING DIGITS OF SECOND ONES
	sdig2 = z/10;				     //SEPERATING DIGITS OF SECOND TENS
	moveTo(1,1);
	moveDown(1);
	printf("\x1b[%dm",color);		     //CHANGING TO THE SELECTED COLOR

	if(hdig2==1){				     //CHECKING THE HOUR TENS DIGIT VALUE
		num1(0);
	}else if(hdig2==2){
		num2(0);
	}else if(hdig2==3){
		num3(0);
	}else if(hdig2==4){
		num4(0);
	}else if(hdig2==5){
		num5(0);
	}else if(hdig2==6){
		num6(0);
	}else if(hdig2==7){
		num7(0);
	}else if(hdig2==8){
		num8(0);
	}else if(hdig2==9){
		num9(0);
	}else if(hdig2==0){
		num0(0);
	}
	moveTo(1,1);
	moveDown(1);
	if(hdig1==1){				     //CHECKING THE HOUR ONES DIGIT VALUE
                num1(8);
        }else if(hdig1==2){
                num2(8);
        }else if(hdig1==3){
                num3(8);
        }else if(hdig1==4){
                num4(8);
        }else if(hdig1==5){
                num5(8);
        }else if(hdig1==6){
                num6(8);
        }else if(hdig1==7){
                num7(8);
        }else if(hdig1==8){
                num8(8);
        }else if(hdig1==9){
                num9(8);
        }else if(hdig1==0){
                num0(8);
        }
	moveTo(1,1);
	moveDown(1);
	colon(15);
	moveTo(1,1);
	moveDown(1);
        if(mdig2==1){				    //CHECKING THE MINUTE TENS DIGIT VALUE
                num1(20);
        }else if(mdig2==2){
                num2(20);
        }else if(mdig2==3){
                num3(20);
        }else if(mdig2==4){
                num4(20);
        }else if(mdig2==5){
                num5(20);
        }else if(mdig2==6){
                num6(20);
        }else if(mdig2==7){
                num7(20);
        }else if(mdig2==8){
                num8(20);
        }else if(mdig2==9){
                num9(20);
        }else if(mdig2==0){
                num0(20);
        }
	moveTo(1,1);
	moveDown(1);
        if(mdig1==1){				  //CHECKING THE MINUTE ONES DIGIT VALUE
                num1(27);
        }else if(mdig1==2){
                num2(27);
        }else if(mdig1==3){
                num3(27);
        }else if(mdig1==4){
                num4(27);
        }else if(mdig1==5){
                num5(27);
        }else if(mdig1==6){
                num6(27);
        }else if(mdig1==7){
                num7(27);
        }else if(mdig1==8){
                num8(27);
        }else if(mdig1==9){
                num9(27);
        }else if(mdig1==0){
                num0(27);
        }
	moveTo(1,1);
	moveDown(1);
	colon(34);				
	moveTo(1,1);
	moveDown(1);
        if(sdig2==1){				 //CHECKING THE SECOND TENS DIGIT VALUE
                num1(39);
        }else if(sdig2==2){
                num2(39);
        }else if(sdig2==3){
                num3(39);
        }else if(sdig2==4){
                num4(39);
        }else if(sdig2==5){
                num5(39);
        }else if(sdig2==6){
                num6(39);
        }else if(sdig2==7){
                num7(39);
        }else if(sdig2==8){
                num8(39);
        }else if(sdig2==9){
                num9(39);
        }else if(sdig2==0){
                num0(39);
        }
	moveTo(1,1);
	moveDown(1);
        if(sdig1==1){				//CHECKING THE SECOND ONES DIGIT VALUE
                num1(46);
        }else if(sdig1==2){
                num2(46);
        }else if(sdig1==3){
                num3(46);
        }else if(sdig1==4){
                num4(46);
        }else if(sdig1==5){
                num5(46);
        }else if(sdig1==6){
                num6(46);
        }else if(sdig1==7){
                num7(46);
        }else if(sdig1==8){
                num8(46);
        }else if(sdig1==9){
                num9(46);
        }else if(sdig1==0){
                num0(46);
        }
	moveTo(1,1);
	moveDown(7);
	moveRight(22);
	printf("%i-%02i-%02i\n", myTime->tm_year + 1900, myTime->tm_mon +1, myTime->tm_mday);		//PRINTING THE YYYY-MM-DD
	printf("\x1b[0m\n");										//RESETTING THE COLOUR
	delay(1000);
        system("clear");
    }

   
    return 0;
}

void moveDown(int positions){		        		//CHANGING THE CURSOR POSITION DOWN	
        printf("\x1b[%dB", positions);
}

void moveRight(int positions){					//CHANGING THE CURSOR POSITION RIGHT
        printf("\x1b[%dC", positions);
}

void moveTo(int row, int col){					//CHANGING THE CURSOR POSITION TO SPECIFIC ROW,COLUMN
        printf("\x1b[%d;%df", row, col);
}

void delay(unsigned int milliseconds){				//TIME DELAY

    clock_t start = clock();

    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

void num1(int j11){						//PRINTING DIGIT1
	int i1,j1;
	for(i1=1;i1<=5;i1++){
		moveRight(j11);
		for(j1=1;j1<=6;j1++){
			if(j1<=4){
				printf(" ");
			}else{
				printf("█");
			}
		}
		printf("\n");
	}
}

void num2(int j22){						//PRINTING DIGIT2
	int i2,j2;
	for(i2=1;i2<=5;i2++){
		moveRight(j22);
		for(j2=1;j2<=6;j2++){
			if(i2==2 && j2<=4){
			       printf(" ");
			 }else if(i2==4 && j2>2){
  				printf(" ");      
			}else{
			 	printf("█");
			} 
 		}
		printf("\n");
	}
}

void num3(int j33){						//PRINTING DIGIT3
	int i3,j3;
	for(i3=1;i3<=5;i3++){
		moveRight(j33);
		for(j3=1;j3<=6;j3++){
			if(i3==2 && j3<=4){
				printf(" ");
			}else if(i3==4 && j3<=4){
				printf(" ");
			}else{
				printf("█");
			}
		}
		printf("\n");
	}
}

void num4(int j44){						//PRINTING DIGIT4
	int i4,j4;
	for(i4=1;i4<=5;i4++){
		moveRight(j44);
		for(j4=1;j4<=6;j4++){
			if(i4>3 && j4<=4){
				printf(" ");
			}else if(i4<=2 && (j4==3 ||j4==4)) {
				printf(" ");
			}else{
				printf("█");
			}
		}
		printf("\n");
	}
}

void num5(int j55){						//PRINTING DIGIT5
	int i5,j5;
	for(i5=1;i5<=5;i5++){
		moveRight(j55);
		for(j5=1;j5<=6;j5++){
			if(i5==2 && j5>2){
				printf(" ");
			}else if(i5==4 && j5<5){
				printf(" ");
			}else{
				printf("█");
			}
		}
		printf("\n");
	}

}

void num6(int j66){						//PRINTING DIGIT6
        int i6,j6;
        for(i6=1;i6<=5;i6++){
		moveRight(j66);
                for(j6=1;j6<=6;j6++){
                        if(i6==2 && j6>2){
                                printf(" ");
                        }else if(i6==4 && (j6==3 || j6==4)){
                                printf(" ");
                        }else{
                                printf("█");
                        }
                }
                printf("\n");
	}
}

void num7(int j77){						//PRINTING DIGIT7
        int i7,j7;
        for(i7=1;i7<=5;i7++){
		moveRight(j77);
                for(j7=1;j7<=6;j7++){
                        if(i7>1 && j7<=4){
                                printf(" ");
                        }else{
                                printf("█");
                        }
                }
                printf("\n");
	}
}

void num8(int j88){						//PRINTING DIGIT8
        int i8,j8;
        for(i8=1;i8<=5;i8++){
		moveRight(j88);
                for(j8=1;j8<=6;j8++){
                        if((i8==2 || i8 == 4) && (j8==3 || j8==4)){
                                printf(" ");
                        }else{
                                printf("█");
                        }
                }
                printf("\n");
        }
}

void num9(int j99){						//PRINTING DIGIT9
        int i9,j9;
        for(i9=1;i9<=5;i9++){
		moveRight(j99);
                for(j9=1;j9<=6;j9++){
                        if(i9==2 && (j9==3 || j9==4)){
                                printf(" ");
			}else if(i9==4 && j9<=4){
				printf(" ");
			}else{
                                printf("█");
                        }
                }
                printf("\n");
        }
}

void num0(int j00){						//PRINTING DIGIT0
        int i0,j0;
        for(i0=1;i0<=5;i0++){
		moveRight(j00);
                for(j0=1;j0<=6;j0++){
                        if((i0==2 || i0 == 3 || i0==4) && (j0==3 || j0==4)){
                                printf(" ");
                        }else{
                                printf("█");
                        }
                }
                printf("\n");
        }
}

void colon(int jcolcol){					//PRINTING COLON
	int icol,jcol;
        for(icol=1;icol<=5;icol++){
                moveRight(jcolcol);
                for(jcol=1;jcol<=4;jcol++){
                        if(icol==1 || icol == 3 || icol == 5){
                                printf(" ");
			}else if(jcol==1 || jcol==4){
				printf(" ");
			}else if((icol==2 || icol==4) && (jcol==1 || jcol==4)){
				printf(" ");
			}else{
                                printf("█");
                        }
		}
                printf("\n");
        }
}




