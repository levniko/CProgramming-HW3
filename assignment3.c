#include<stdio.h>
#include<math.h> // fabs()
#define FULL 1
#define EMPTY 0
int distance_calculator(int x1, int y1, int x2, int y2)
{
    /**
    * Computes distance of two place according to axis values
    * @param x1 x axis value of first place
    * @param y1 y axis value of first place
    * @param x2 x axis value of second place
    * @param y2 y axis value of second place
    * @return distance
    */

    int distance= fabs(x1-x2)+ fabs(y1-y2);
    return distance;

}


int main(void)
{
    int carsnumber;
    int i,j,n;
    int size;
    int xaxis; 
    int yaxis;
    int counter=0; //counts the distance array
    int counter2=0; // counts the totalDistance array
    int largest=0;
    int largesti_value=0;
    int largestj_value=0;

    //gets the number of cars and size of place
    printf("Size: "); scanf("%d",&size);
    printf("Cars: "); scanf("%d",&carsnumber);


    while(carsnumber>size*size){//controls the size and number of cars
    printf("Enter the smaller number of cars than %d!\n",size*size);

    printf("enter the size: "); scanf("%d",&size);
    printf("enter the number of cars: "); scanf("%d",&carsnumber);
    }
    if(size*size==carsnumber){

        largesti_value=-1;
        largestj_value=-1;

    }
    else{

    // THESE ARE THE ARRAYS THAT STORES ALL THE DATA

    int cars_location[size][size];//it stores cars location
    int distance[carsnumber]; //it stores temporarily each empty spaces to all the cars
    int totalDistance[size*size-carsnumber];   //stores each empty places total distance to all cars ; size of it is number of empty spaces ex: emp1 istance,emp2distance...
    int emptyi[size*size-carsnumber]; //stores each empty spaces row value
    int emptyj[size*size-carsnumber]; //stores each empty spaces column value
    int fulli[carsnumber]; //stores each cars row value
    int fullj[carsnumber];//stores each cars column value
	int i, j;//For loop index
       //initilaze arrays 0
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                cars_location[i][j]=0;
            }
        }
        for(i=0;i<carsnumber;i++){
            distance[i]=0;
            fulli[carsnumber]=0;
            fullj[carsnumber]=0;
        }
        for(i=0;i<size*size-carsnumber;i++){
            totalDistance[i]=0;
            emptyi[size*size-carsnumber]=0;
            emptyj[size*size-carsnumber]=0;
        }
    //
	int n;//For loop index
    for(n=0;n<carsnumber;n++){ // gets the locations of cars and transforms the inputs for compatibility according to array
        printf("Locations: "); scanf("%d %d",&xaxis,&yaxis);
        if((xaxis>size)||(yaxis>size)||(xaxis<=0)||(yaxis<=0)){
            printf("Enter a proper location!\n");
            n--;
            continue;
        }
        int j=xaxis-1;
        int i=yaxis-1;
        if(cars_location[i][j]==FULL){
            printf("This location is already entered. Please enter another location!\n");
            n--;
            continue;
        }
        cars_location[i][j]=FULL;


    }


    for(i=0;i<size;i++){//this if for empty place search rows

        for(j=0;j<size;j++){//this if for empty place search colm

            if(cars_location[i][j]==EMPTY){//FINDS THE EMPTY PLACE

                emptyi[counter]=i;
                emptyj[counter]=j;
                counter++;
            }
        }
    }

	int k, l;//For loop index
    for(k=0;k<size;k++){//this if for full place search row

        for(l=0;l<size;l++){//this if for full place search colm
            if(cars_location[k][l]==FULL){//FINDS THE FULL PLACE

                fulli[counter2]=k;
                fullj[counter2]=l;
                counter2++;
            }
        }

    }


    // THE DISTANCE CALCULATION AND STORING THAT INFORMATION


    for(i=0;i<size*size-carsnumber;i++){ //calculate distance according to arrays


        for(j=0;j<carsnumber;j++){

            distance[j]=distance_calculator(emptyi[i],emptyj[i],fulli[j],fullj[j]);

            if(j==carsnumber-1){
                //calculate total distance
                int temp_total=0;
                int z;//For loop index
                for(z=0;z<carsnumber;z++){
                    temp_total=temp_total+distance[z];
                }

                totalDistance[i]=temp_total;
            }
        }
    }
	int z;//For loop index
    // HERE IS THE COMPARISION PART ACCORDING TO ARRAYS : emptyi,emptyj,totalDistance
    int c1=0,c2=0;
    for(z=0;z<size*size-carsnumber;z++){ //compare distances first

        if(z==0){//initilize largest to first distance
            largest=totalDistance[z];
            largesti_value=emptyi[c1];
            largestj_value=emptyj[c2];
            c1++;
            c2++;
        }
        else{//after z>0
            if(totalDistance[z]>=largest){
                if(totalDistance[z]==largest){
                    if(emptyj[c2]<largestj_value){//pick smaller x ==> smaller j
                        largest=totalDistance[z];
                        largesti_value=emptyi[c1];
                        largestj_value=emptyj[c2];
                        c1++;
                        c2++;

                    }
                    else if(emptyj[c2]==largestj_value){//if x's equal to =>>if  j's equal to each other

                        if(emptyi[c1]<largesti_value){
                            largest=totalDistance[z];
                            largesti_value=emptyi[c1];
                            largestj_value=emptyj[c2];
                            c1++;
                            c2++;
                        }
                        else{
                            largest=largest;
                            largesti_value=largesti_value;
                            largestj_value=largestj_value;
                            c1++;
                            c2++;
                        }


                    }
                    else{// if x is bigger ==Z if j is bigger
                        largest=largest;
                        largesti_value=largesti_value;
                        largestj_value=largestj_value;
                        c1++;
                        c2++;
                    }


            }
            else{// if totalDistance> largest
                largest=totalDistance[z];
                largesti_value=emptyi[c1];
                largestj_value=emptyj[c2];
                c1++;
                c2++;
            }

        }
        else{ //if totalDistance < largest

            largest=largest;
            largesti_value=largesti_value;
            largestj_value=largestj_value;
            c1++;
            c2++;
            }
        }
    }

    }

    //TRANSFORM i,j TO x axis y axis and prints output
    printf("\nBest Slot Found In: %d %d",largestj_value+1,largesti_value+1);

}



