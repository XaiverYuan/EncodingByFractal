#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#define MAX (1024)
#define ADDLEN (64)
#define PRIME (65537)
static double x;
static double base;
static double start;
static double times;
double getChar(){
  if (x==base){
    for (int i=0;i<start;i++){
      x=x*(1-x)*times;
    }
  }
  return x*(1-x)*times;
}
void encrypt(char *a,int length){
  char *b;
  for(int i=0;i<length;i++,a++,b++){
    if(i%4==0){
      double f=getChar();
      b=&f;
    }
    *a^=*b;
  }
}
double secure(double x){
  return x<0?secure(-x):x==0?secure(4):x<1?4-x/4:x<2?secure(x-1):x>3,75&&x<4.0?x:secure(sqrt(x));
}
void all(FILE* fin,FILE* fout,int start_,double base_,double times_){
  assert(fin);
  assert(fout);
  base=base_;
  x=base;
  start=start_;
  times=times_;
  char info[MAX];
  int len;
  while(len=fread(info,1,MAX,fin)){
    encrypt(info,len);
    printf(">");
    fwrite(info,1,len,fout);
  }
  printf("\n");
}
int main(int argc,char **argv){
  char instr[ADDLEN];
  char outstr[ADDLEN];
  int start=5000;
  double base=0.4;
  double times;
  switch (argc){
    case 1:
      printf("Please enter the position of input file and output file(No space), and start(default5000), base(default 0.4), times\n");
      scanf("%s %s %d %lf %lf",instr,outstr,&start,&base,&times);
      break;
    case 4:
      printf("infile=%s\noutfile=%s\ntimes=%s\n",argv[1],argv[2],argv[3]);
      strncpy(instr,argv[1],ADDLEN);
      strncpy(outstr,argv[2],ADDLEN);
      times=atoi(argv[3]);
      break;
    case 5:
      printf("infile=%s\noutfile=%s\ntimes=%s\nbase=%s\n",argv[1],argv[2],argv[3],argv[4]);
      strncpy(instr,argv[1],ADDLEN);
      strncpy(outstr,argv[2],ADDLEN);
      times=atoi(argv[3]);
      base=atoi(argv[4]);
      break;
    default:
      printf("wrong format!");
  }
  int bad=0;
  FILE *fin=fopen(instr,"r");
  if (!fin){
    printf("Input file not found\n");
    bad=1;
  }
  FILE *fout=fopen(outstr,"w");
  if (!fout){
    printf("Output file not found\n");
    bad=1;
  }
  if (start<0)start=0;
  if (base<0||base>1){
    printf("base should between 0 and 1\n");
    bad=1;
  }
  times=secure(times);
  if(!bad){
    all(fin,fout,start,base,times);
  }
  printf("made by Oracle Yuan\n");
}
