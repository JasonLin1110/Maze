#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *getword(char *line,char *word)
{
    char *ptr,*qtr;
    ptr=line;
    while(isspace(*ptr)&&*ptr!='\0'){
        ptr++;
    }
    qtr=word;
    *qtr++=*ptr++;
    *qtr='\0';
    if(strlen(word)==0){
        return NULL;
    }
    else{
        return ptr;
    }
}

int main()
{
    char line[103],*ptr,word[2];
    ptr=malloc(sizeof(char)*103);
    int maze[2][101][101]={0},x=0,y=0,z=0;
    int Rx,Ry,Rz,Jx,Jy,Jz,round=1,Rstep=0,Jstep=0;
    while(scanf("%d\n",&x)!=EOF){
        if(x==1){
            x=0;
            for(y=0;y<101;y++){
                scanf("%s\n",line);
                ptr=line;
                for(z=0;z<101;z++){
                    ptr=getword(ptr,word);
                    if(strcmp(word,"X")==0){
                        maze[x][y][z]=0;
                    }
                    else if(strcmp(word,".")==0){
                        maze[x][y][z]=1;
                    }
                    else if(strcmp(word,"o")==0){
                        maze[x][y][z]=2;
                    }
                }
            }
        }
        if(x==2){
            x=1;
            for(y=0;y<101;y++){
                scanf("%s\n",line);
                ptr=line;
                for(z=0;z<101;z++){
                    ptr=getword(ptr,word);
                    if(strcmp(word,"X")==0){
                        maze[x][y][z]=0;
                    }
                    else if(strcmp(word,".")==0){
                        maze[x][y][z]=1;
                    }
                    else if(strcmp(word,"o")==0){
                        maze[x][y][z]=2;
                    }
                }
            }
        }
        if(x==1 && y==101 && z==101){
            round=0;
            x=0;
            y=0;
            z=0;
            Rstep=0;
            Jstep=0;
            int Rstack[10201][4]={0},Jstack[10201][4]={0};
            int Rroad[2][101][101]={0},Jroad[2][101][101]={0};
            Rx=0;
            Ry=1;
            Rz=1;
            Jx=1;
            Jy=99;
            Jz=99;
            Rstack[0][0]=0;
            Rstack[0][1]=1;
            Rstack[0][2]=1;
            Jstack[0][0]=1;
            Jstack[0][1]=99;
            Jstack[0][2]=99;
            Rroad[0][1][1]=1;
            Jroad[0][99][99]=1;
            while((Rx!=1||Ry!=99||Rz!=99) && (Jx!=0||Jy!=1||Jz!=1)){
                round++;
                if(maze[Rx][Ry][Rz+1]!=0 && Rstack[Rstep][3]<1 && (Rstack[Rstep-1][0]!=Rx || Rstack[Rstep-1][1]!=Ry || Rstack[Rstep-1][2]!=Rz+1 || Rstep==0) && Rroad[Rx][Ry][Rz+1]==0){
                    Rstack[Rstep][3]=1;
                    Rstep++;
                    Rstack[Rstep][0]=Rx;
                    Rstack[Rstep][1]=Ry;
                    Rstack[Rstep][2]=Rz+1;
                    Rz=Rz+1;
                    Rroad[Rx][Ry][Rz]=1;
                }
                else if(maze[Rx][Ry+1][Rz]!=0 && Rstack[Rstep][3]<2 && (Rstack[Rstep-1][0]!=Rx || Rstack[Rstep-1][1]!=Ry+1 || Rstack[Rstep-1][2]!=Rz || Rstep==0) && Rroad[Rx][Ry+1][Rz]==0){
                    Rstack[Rstep][3]=2;
                    Rstep++;
                    Rstack[Rstep][0]=Rx;
                    Rstack[Rstep][1]=Ry+1;
                    Rstack[Rstep][2]=Rz;
                    Ry=Ry+1;
                    Rroad[Rx][Ry][Rz]=1;
                }
                else if(maze[Rx][Ry-1][Rz]!=0 && Rstack[Rstep][3]<3 && (Rstack[Rstep-1][0]!=Rx || Rstack[Rstep-1][1]!=Ry-1 || Rstack[Rstep-1][2]!=Rz || Rstep==0) && Rroad[Rx][Ry-1][Rz]==0){
                    Rstack[Rstep][3]=3;
                    Rstep++;
                    Rstack[Rstep][0]=Rx;
                    Rstack[Rstep][1]=Ry-1;
                    Rstack[Rstep][2]=Rz;
                    Ry=Ry-1;
                    Rroad[Rx][Ry][Rz]=1;
                }
                else if(maze[Rx][Ry][Rz-1]!=0 && Rstack[Rstep][3]<4 && (Rstack[Rstep-1][0]!=Rx || Rstack[Rstep-1][1]!=Ry || Rstack[Rstep-1][2]!=Rz-1 || Rstep==0) && Rroad[Rx][Ry][Rz-1]==0){
                    Rstack[Rstep][3]=4;
                    Rstep++;
                    Rstack[Rstep][0]=Rx;
                    Rstack[Rstep][1]=Ry;
                    Rstack[Rstep][2]=Rz-1;
                    Rz=Rz-1;
                    Rroad[Rx][Ry][Rz]=1;
                }
                else{
                    Rstack[Rstep][3]=0;
                    Rroad[Rx][Ry][Rz]=0;
                    Rstep--;
                    Rx=Rstack[Rstep][0];
                    Ry=Rstack[Rstep][1];
                    Rz=Rstack[Rstep][2];
                }
                if(maze[Rx][Ry][Rz]==2 && Rx==0){
                    Rx=1;
                    while(Rstep>0){
                        Rstack[Rstep][0]=0;
                        Rstack[Rstep][1]=0;
                        Rstack[Rstep][2]=0;
                        Rstack[Rstep][3]=0;
                        Rstep--;
                    }
                    Rstep=0;
                    Rstack[0][0]=Rx;
                    Rstack[0][1]=Ry;
                    Rstack[0][2]=Rz;
                    Rstack[0][3]=0;
                    Rroad[Rx][Ry][Rz]=1;
                }
                if(Rx==Jx&&Ry==Jy&&Rz==Jz){
                    printf("==Round: %d==\nRomeo: (%d,%d,%d)\n",round,Rx,Ry,Rz);
                    break;
                }
                if(maze[Jx][Jy][Jz-1]!=0 && Jstack[Jstep][3]<1 && (Jstack[Jstep-1][0]!=Jx || Jstack[Jstep-1][1]!=Jy || Jstack[Jstep-1][2]!=Jz-1 || Jstep==0) && Jroad[Jx][Jy][Jz-1]==0){
                    Jstack[Jstep][3]=1;
                    Jstep++;
                    Jstack[Jstep][0]=Jx;
                    Jstack[Jstep][1]=Jy;
                    Jstack[Jstep][2]=Jz-1;
                    Jz=Jz-1;
                    Jroad[Jx][Jy][Jz]=1;
                }
                else if(maze[Jx][Jy-1][Jz]!=0 && Jstack[Jstep][3]<2 && (Jstack[Jstep-1][0]!=Jx || Jstack[Jstep-1][1]!=Jy-1 || Jstack[Jstep-1][2]!=Jz || Jstep==0) && Jroad[Jx][Jy-1][Jz]==0){
                    Jstack[Jstep][3]=2;
                    Jstep++;
                    Jstack[Jstep][0]=Jx;
                    Jstack[Jstep][1]=Jy-1;
                    Jstack[Jstep][2]=Jz;
                    Jy=Jy-1;
                    Jroad[Jx][Jy][Jz]=1;
                }
                else if(maze[Jx][Jy+1][Jz]!=0 && Jstack[Jstep][3]<3 && (Jstack[Jstep-1][0]!=Jx || Jstack[Jstep-1][1]!=Jy+1 || Jstack[Jstep-1][2]!=Jz || Jstep==0) && Jroad[Jx][Jy+1][Jz]==0){
                    Jstack[Jstep][3]=3;
                    Jstep++;
                    Jstack[Jstep][0]=Jx;
                    Jstack[Jstep][1]=Jy+1;
                    Jstack[Jstep][2]=Jz;
                    Jy=Jy+1;
                    Jroad[Jx][Jy][Jz]=1;
                }
                else if(maze[Jx][Jy][Jz+1]!=0 && Jstack[Jstep][3]<4 && (Jstack[Jstep-1][0]!=Jx || Jstack[Jstep-1][1]!=Jy || Jstack[Jstep-1][2]!=Jz+1 || Jstep==0) && Jroad[Jx][Jy][Jz+1]==0){
                    Jstack[Jstep][3]=4;
                    Jstep++;
                    Jstack[Jstep][0]=Jx;
                    Jstack[Jstep][1]=Jy;
                    Jstack[Jstep][2]=Jz+1;
                    Jz=Jz+1;
                    Jroad[Jx][Jy][Jz]=1;
                }
                else{
                    Jstack[Jstep][3]=0;
                    Jroad[Jx][Jy][Jz]=0;
                    Jstep--;
                    Jx=Jstack[Jstep][0];
                    Jy=Jstack[Jstep][1];
                    Jz=Jstack[Jstep][2];
                }
                if(maze[Jx][Jy][Jz]==2 && Jx==1){
                    Jx=0;
                    while(Jstep>0){
                        Jstack[Jstep][0]=0;
                        Jstack[Jstep][1]=0;
                        Jstack[Jstep][2]=0;
                        Jstack[Jstep][3]=0;
                        Jstep--;
                    }
                    Jstep=0;
                    Jstack[Jstep][0]=Jx;
                    Jstack[Jstep][1]=Jy;
                    Jstack[Jstep][2]=Jz;
                    Jstack[Jstep][3]=0;
                    Jroad[Jx][Jy][Jz]=1;
                }
                printf("==Round: %d==\nRomeo: (%d,%d,%d)\nJuliet: (%d,%d,%d)\n",round,Rx,Rz,Ry,Jx,Jz,Jy);
                if(Rx==Jx && Ry==Jy && Rz==Jz){
                    break;
                }
            }
            if(Rx==Jx&&Ry==Jy&&Rz==Jz){
                printf("They encounter each other in (%d,%d,%d)",Rx,Rz,Ry);
            }
            else{
                printf("They do not encounter each other in this maze.");
            }
        }
    }
    return 0;
}
