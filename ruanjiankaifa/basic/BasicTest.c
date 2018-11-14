//
//  BasicTest.c
//  ruanjiankaifa
//

#include "BasicTest.h"
//输出函数printf
void printfTest(){
    //1.换行符号
    printf("hello c\n");
    //2.格式化符号%d
    int c=10;
    printf("hello c=%d\n",c);
    //3.空格
    char space=32;
    printf("hello%cc\n",space);
    //4.制表符号
    printf("hello\tc\tc\n");
    //5.占位符号
    printf("hello c=%4d,c=%4d,c=%4d\n",c,c,c);
}

void scanfTest(){
    
    //嵌入代码的方式1，输完就结束，不进行校验
    /*
     int n,range;
     printf("请输入元素个数n 以及范围range:\t\n");
     fflush(stdout);
     scanf("%d%d",&n,&range);
     */
    
    //嵌入代码的方式2，循环等待用户输入，满足条件退出循环😀
    
    int n,range;
    while (1) {
        printf("请输入元素个数n 以及范围range:\t\n");
        
        //fflush在 scanf之前执行 fflush(stdout) 在打开文件之前执行 fflush(stdin)
        fflush(stdout);
        scanf("%d%d",&n,&range);
        if (n>0&&n<1001) {
            break;
        }
    }
}

void fprintfTest(FILE*fp){
    printf("输入到文件测试 \n");
    fprintf(fp, "输入到文件:\n");
    
    //for循环输出变量到文件
    for (int i=0; i<10; i++) {
        fprintf(fp, "i=%d\n",i);
    }
}

//以字节的方式读取
void readFileTest(void){
  
    FILE*fp;
    fp = fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/in.txt","r");
    if(fp==NULL){
        puts("can't open the file!");
       
    }
    puts("open file success!\n");
    puts("文件内容是：");
    char ch=fgetc(fp);
    while(ch!=-1){
        putchar(ch);
        //这里还可以用fputc(ch,stdout);把屏幕看作一个文件，stdout就是指向这个文件的指针
        //fgetc()从文件读取到的字符，依次被字符变量ch指代，可以用putchar()输出，也可以用stdout指针写入到屏幕这个文件中
        
        ch=fgetc(fp);
    }
    puts("\n");
    int return_value=fclose(fp);
    if(return_value!=0)
    {
        puts("关闭文件失败！\n");
    }
    puts("文件成功关闭!\n");
  
}

/*字符串方式读取
 char *fgets(char *str,int n,FILE *stream);
 str是一个指向字符串的指针，n是读取的字符和字符串结束的标志"\0"
 stream是文件指针，指向将被读取数据的文件
 */
//fgets()函数一次从stream所指向的文件中读取n-1个字符，若是读取的字符包含换行符"\n"
//和文件结束标志，那么读取的字符串将在n-1个字符前终止。

void readFileTest2(void){
    FILE *fp;
    fp = fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/in.txt","r");
    if(fp==NULL){
        puts("can't open the file!");
    }
    puts("open file success!\n");
    puts("文件内容是：");
    char arr[20]={0};
    char *p=fgets(arr,20,fp);//开始以字符串方式读取文件中数据
    while(p!=NULL){
        printf("%s",arr);
        p=fgets(arr,20,fp);
    }
    printf("\n\n");
    int return_value=fclose(fp);
    if(return_value!=0)
    {
        puts("文件关闭失败！\n");
    }
    puts("文件成功关闭!\n");

    
}

/*二进制方式读取数据*/
/*  size_t   fread(void   *buffer,size_t   size, size_t count, FILE *stream)
   buffer   是读取的数据存放的内存的指针（可以是数组，也可以是新开辟的空间，
            buffer就是一个索引）
   size    是每次读取的字节数
   count     是读取次数
   stream  是要读取的文件的指针   */

void readFileTest3(void){
    FILE *fp_r,*fp_w;
    fp_r=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/src.jpg","rb");//打开图片文件
    fp_w=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/des.jpg","wb");//创建图片文件
    if(fp_r==NULL){
        puts("原始图片打开失败！\n");
    }
    if(fp_w==NULL){
        puts("文件2打开失败！\n");
    }
    puts("两个文件打开成功!\n");
    char ch;
    int i=fread(&ch,1,1,fp_r);//以二进制方式读取图片
    while(i!=0){
        fwrite(&ch,1,1,fp_w);//以二进制方式写入
        i=fread(&ch,1,1,fp_r);
    }
    int return_value=fclose(fp_r);
    if(return_value!=0)
    {
        puts("关闭原始图片失败!\n");
    }
    return_value=fclose(fp_w);
    if(return_value!=0)
    {
        puts("关闭文件2失败!\n");
    }
    puts("两个图片都关闭成功！\n");
   
    
}

//将source.txt文件复制成target.txt文件
void copyFileTest(void){
    printf("此程序执行将source.txt中的文本复制到target.txt之中!\n");
    
    FILE *fpin,*fpout;//定义两个文件指针，因为要对两个文件实施操作
    char c;
    //打开和错误判断
    if((fpin=fopen("source.txt","r"))==NULL)
    {
        printf("source file cannot open!");
        exit(0);
    }
    if ((fpout=fopen("target.txt", "w"))==NULL)
    {
        printf("target file cannot open!");
        exit(0);
    }
    
    
    //复制操作
    while((c=fgetc(fpin))!=EOF)
    {
        fputc(c,fpout);
    }
    printf("finish copy!");
    
    //关闭文件
    fclose(fpin);
    fclose(fpout);
    
}

//大奖赛分数：
void fprintfTest2(void){
    printf("此程序执行将大奖赛的计分结果直接存入文件\n\n");
    
    FILE *fp;//文件指针
    
    //打开和错误判断,最终用户输入的数据保存到record.txt的文件之中
    if ((fp=fopen("record.txt", "w"))==NULL)
    {
        printf("target file cannot open!");
        exit(0);
    }
    
    //变量定义
    int iJudger_Number,iSinger_SumNum,j,iCurr_SinggerNum;
    float fMark,fAver,fSum,fMax,fMin;
    
    printf("请输入评委总数和歌手总数:");//输入评委总数和歌手总数
    scanf("%d %d",&iJudger_Number,&iSinger_SumNum);
    
    //文件中打出表头
    fprintf(fp,"No.\t");
    for(j=1;j<=iJudger_Number;j++)
    {
        fprintf(fp,"评委%d\t",j);
    }
    fprintf(fp,"Max\tMin\tAve\n");
    
    //用户输入比赛选手信息
    iCurr_SinggerNum=1;
    while(iCurr_SinggerNum<=iSinger_SumNum)
    {
        fSum=0;
        fMax=0;
        fMin=10;
        j=1;
        printf("参赛者%d:",iCurr_SinggerNum);
        fprintf(fp,"%d\t",iCurr_SinggerNum);//在文件中打出No下面的数字，第几个参赛选手
        
        
        do
        {
            scanf("%f",&fMark);
            fprintf(fp, "%.2f\t", fMark);
            
            fSum=fSum+fMark;
            if(fMax<fMark)
            {
                fMax=fMark;
            }
            if(fMin>fMark)
            {
                fMin=fMark;
            }
            j++;
        }while(j<=iJudger_Number);
        
        fAver=(fSum-fMax-fMin)/(iJudger_Number-2); //计算平均成绩
        
        fprintf(fp,"%.2f\t%.2f\t%.2f\t\n",fMax,fMin,fAver);//输出后三项
        
        iCurr_SinggerNum++;
    }
    
    //关闭文件
    fclose(fp);

}
//实践1：从键盘输入一个文件名，以及一个以#结束的字符序列，将输入的字符保存到文件中去
void fileTest(void){
    printf("此程序执行从键盘输入一个文件名，以及一个以#结束的字符序列，将输入的字符保存到文件中去。\n");
    FILE *fp;
    char ch,fname[10];
    printf("文件名:");
    gets(fname);
    if((fp=fopen(fname,"w"))==NULL)
    {
        printf("cannot open!\n");
        exit(0);
    }
    while((ch=getchar())!='#')
    {
        fputc(ch,fp);
    }
    fclose(fp);
    

    
}
//此程序执行将文件file1.dat的内容输出到屏幕上并复制到文件file2.dat中
void fileTest2(void){
    printf("此程序执行将文件file1.dat的内容输出到屏幕上并复制到文件file2.dat中，请补充完整。\n");
    FILE *fp1,*fp2;
    char ch;
    
    //指针判断
    fp1=fopen("file1.dat","r");
    fp2=fopen("file2.dat","w");
    
    if(fp1==NULL)
    {
        printf("file cannot open !");
        exit(0);
    }
    if(fp2==NULL)
    {
        printf("file2 cannot open!");
        exit(0);
    }
    
    //执行过程
    while (!feof(fp1))
    {
        ch=fgetc(fp1);
        putchar(ch);
        fputc(ch,fp2);
    }
    fclose(fp1);
    fclose(fp2) ;
    
}

